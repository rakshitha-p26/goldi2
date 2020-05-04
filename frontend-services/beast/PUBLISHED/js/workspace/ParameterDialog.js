/**
 * Created by maximilian on 12.05.17.
 */
/**
 * Provides a dialog to set the parameters for a Device
 */
class ParameterDialog extends Dialog {
    /**
     *
     * @param parameterDescriptions - Descriptions of the parameters to be editable in the dialog.
     * @param values - A object that provides the current values of the parameter
     * @param SetValuesCallback - Is called to apply the new values
     */
    constructor(parameterDescriptions, values, SetValuesCallback) {
        super({ modal: true, show: false, hide: false });
        this.parameterDescriptions = parameterDescriptions;
        this.SetValuesCallback = SetValuesCallback;
        this.values = values;
    }
    /**
     * get the dialog title
     * @returns {string} - the dialog title
     */
    getTitle() {
        return 'Editing Parameters';
    }
    getContent() {
        this.inputs = [];
        this.rows = [];
        const table = $('<table></table>');
        for (let paramDesc of this.parameterDescriptions) {
            const inputClass = workspace.INPUT_TYPES[paramDesc.type];
            const input = new inputClass(this.values[paramDesc.name] || paramDesc.defaultValue, paramDesc.validateFct);
            const row = $('<tr></tr>');
            row.append($('<td></td>')
                .text((paramDesc.displayName || paramDesc.name) + ':')
                .attr('title', paramDesc.description));
            row.append($('<td></td>')
                .append(input.ui)
                .attr('title', paramDesc.description));
            row.append($('<td></td>')
                .text(paramDesc.unit)
                .attr('title', paramDesc.description));
            table.append(row);
            input.initInput();
            this.inputs.push(input);
            this.rows.push(row);
        }
        this.addButton('Apply', 'glyphicon glyphicon-ok', () => this.apply());
        this.registerKeyListener((key) => {
            if (key == 13) {
                this.simulateButtonClick('Apply');
            }
        });
        return table;
    }
    /**
     * Validates the state of all the inputs in the dialog and marks invalid inputs
     * @returns {boolean} - Flag to indicate whether all values are valid
     */
    validate() {
        let isValid = true;
        for (let i in this.rows) {
            const valid = this.inputs[i].isValid();
            this.rows[i].toggleClass('beast-parameter-invalid', !valid);
            isValid = valid && isValid;
        }
        return isValid;
    }
    /**
     * Applies the modified values when they are valid and closes the dialog
     */
    apply() {
        if (this.validate()) {
            const newValues = {};
            for (let i in this.inputs) {
                newValues[this.parameterDescriptions[i].name] = this.inputs[i].getValue();
            }
            this.SetValuesCallback(newValues);
            this.close();
        }
    }
}
//# sourceMappingURL=ParameterDialog.js.map