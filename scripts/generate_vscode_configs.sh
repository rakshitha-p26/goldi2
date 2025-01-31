#!/bin/bash

#config_paths=$(git ls-files --recurse-submodules | grep .vscode/settings.json)
config_paths=$(find -L . -path '*.vscode/settings.json' -o \( -name 'build' -o -name 'node_modules' -o -path './crosslab' \) -prune -false)
NL=$'\n'

for config_path in $config_paths; do
    dir=$(dirname $(dirname $config_path))
    while [ "$dir" != "." ]; do
        if [ ! -f "$dir/.vscode/settings.json" ]; then
            config_paths="$config_paths$NL$dir/.vscode/settings.json"
            mkdir -p "$dir/.vscode"
            touch "$dir/.vscode/.hidden"
            cat <<EOF > "$dir/.vscode/settings.json"
{
}
EOF
        fi
        dir=$(dirname $dir)
    done
done

config_paths=$(echo "$config_paths" | sort)

for config_path in $config_paths; do
    # find all subdirectories
    toplevel=$(dirname $(dirname $config_path))
    subdirs=$(echo "$config_paths" | grep "$toplevel")
    files_exclude=""
    files_watcherExclude=""
    for subdir in $subdirs; do
        if [ $subdir = $config_path ]; then continue; fi
        subdir_toplevel=$(dirname $(dirname $subdir))
        content=$(cat $subdir)
        content=$(python -c "import re;print(re.sub(r'(\n.*\/\/begin generated[\s\S]*?\/\/end generated)', '', \"\"\"$content\"\"\"))")
        rel_path=${subdir_toplevel/"$toplevel/"/""}
        files_exclude=$files_exclude$NL$(python -c "import re;"\
"m=re.search(r'\"files\.exclude\"[\s\S]*?{([\s\S]*?)}', \"\"\"$content\"\"\");"\
"print('\n'.join([s.strip().replace('\"','\"$rel_path/',1) for s in m.group(1).split('\n')]) if m else '');")
        files_watcherExclude=$files_watcherExclude$NL$(python -c "import re;"\
"m=re.search(r'\"files\.watcherExclude\"[\s\S]*?{([\s\S]*?)}', \"\"\"$content\"\"\");"\
"print('\n'.join([s.strip().replace('\"','\"$rel_path/',1) for s in m.group(1).split('\n')]) if m else '');")
        if [ -f "$subdir_toplevel/.vscode/.hidden" ]; then
            files_exclude=$files_exclude$NL'"'$rel_path'/.vscode": true,'
        fi
    done
    files_exclude=$(echo "$files_exclude" | sort | uniq -u | sed 's/^/        /')
    files_watcherExclude=$(echo "$files_watcherExclude" | sort | uniq -u | sed 's/^/        /')
    content=$(cat $config_path)
    # remove generated code
    content=$(python -c "import re;print(re.sub(r'(\n.*\/\/begin generated[\s\S]*?\/\/end generated)', '', \"\"\"$content\"\"\"))")

    if [[ ! $content =~ "\"files.exclude\"" ]]; then
        content=$(python -c "import re;print(re.sub(r'(.*)(,?)(\\n})', '\\\\1,\\\\n    \"files.exclude\": {\\n    }\\\\3', \"\"\"$content\"\"\",0,re.MULTILINE | re.DOTALL))")
    fi
    if [[ ! $content =~ "\"files.watcherExclude\"" ]]; then
        content=$(python -c "import re;print(re.sub(r'(.*)(,?)(\\n})', '\\\\1,\\\\n    \"files.watcherExclude\": {\\n    }\\\\3', \"\"\"$content\"\"\",0,re.MULTILINE | re.DOTALL))")
    fi
    # if config_path is clients

    content=$(python -c "import re;print(re.sub(r'(\"files\.exclude\": {[\s\S]*?)(,?)(\n.*})', \"\"\"\\\\1,\\\\n        //begin generated\\\\n$files_exclude\\\\n        //end generated\\\\3\"\"\", \"\"\"$content\"\"\",0,re.MULTILINE))")
    content=$(python -c "import re;print(re.sub(r'(\"files\.watcherExclude\": {[\s\S]*?)(,?)(\n.*})', \"\"\"\\\\1,\\\\n        //begin generated\\\\n$files_watcherExclude\\\\n        //end generated\\\\3\"\"\", \"\"\"$content\"\"\",0,re.MULTILINE))")
    content=$(python -c "import re;print(re.sub(r'{,', '{', \"\"\"$content\"\"\",0,re.MULTILINE))")
    echo "$content" > $config_path
done