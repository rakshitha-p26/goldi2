/**
 * Created by maximilian on 30.05.17.
 */
const TABCONTENT_CODE = `
                <div class="tab-pane active flex-child col-flex-container" id="editor" role="tabpanel">
                    <!--editortoolbar-->

                    <div class="btn-toolbar" role="toolbar" >
                        <div class="btn-group btn-group-lg" role="group" >
                            <label class="switch"><input type="checkbox" data-toggle="toggle" data-placement="top" data-on="Move" data-off="Select" class="cb-pan"><div class="slider"></div></label>
                            <label class="switch"><input type="checkbox" data-toggle="toggle" data-placement="top" data-on="Simulation<br>off" data-off="Simulation<br>off" class="cb-connsim"><div class="slider"></div></label>
                            <button type="button" class="btn btn-default" data-toggle="tooltip" data-placement="top" title="Zoom In"><span class="glyphicon glyphicon-zoom-in"></span></button>
                            <button type="button" class="btn btn-default" data-toggle="tooltip" data-placement="top" title="Zoom Out"><span class="glyphicon glyphicon-zoom-out"></span></button>
                            <button type="button" class="btn btn-default" data-toggle="tooltip" data-placement="top" title="Rotate Left"><span class="glyphicon glyphicon-arrow-left"></span></button>
                            <button type="button" class="btn btn-default" data-toggle="tooltip" data-placement="top" title="Rotate Right"><span class="glyphicon glyphicon-arrow-right"></span></button>
                            <button type="button" class="btn btn-default" data-toggle="tooltip" data-placement="top" title="Save"><span class="glyphicon glyphicon-download-alt"></span></button>
                            <button type="button" class="btn btn-default" data-toggle="tooltip" data-placement="top" title="Extract component"><span class="gylphicon glyphicon-share"></span></button>
                            <button type="button" class="btn btn-default btn-parameter" data-toggle="tooltip" data-placement="top" title="Set parameter"><span class="glyphicon glyphicon-cog"></span></button>
                            <button type="button" class="btn btn-default btn-delete" data-toggle="tooltip" data-placement="top" title="Delete"><span class="glyphicon glyphicon-trash"></span></button>
                        </div>
                    </div>

                    <!--<div class="workspace flex-child">
                    </div>-->
                    
                    <div class="workspace flex-child"></div>
                    
                </div>

                
`;
const TAB_CODE = `
                 <li><a href="#editor" data-toggle="tab" role="tab"><span class="tabtitle">TestKomponente</span>&nbsp&nbsp</a><span
                 class="closetab">x
                 </span> </li>
`;
class EditorController {
    constructor(controller, contentContainer, tabContainer) {
        this.controller = controller;
        this.tabPanel = $($.parseHTML(TABCONTENT_CODE));
        contentContainer.append(this.tabPanel);
        const $ws = this.tabPanel.find(".workspace");
        this.workspace = new Workspace.Workspace($ws.parent(), this, { showToolbox: false, "devices": [
                { "type": "OSC", "id": "dev0", "x": 64, "y": 152 },
                { "type": "NOT", "id": "dev1", "x": 176, "y": 104 },
                { "type": "LED", "label": "LED", "color": "#0000ff", "bgColor": "#000000", "id": "dev2", "x": 280, "y": 96 },
                { "type": "LED", "id": "dev3", "x": 280, "y": 168 },
                { "type": "Joint", "id": "dev4", "x": 216, "y": 208, "state": { "direction": 0 } }
            ],
            "connectors": [
                { "from": "dev1.in0", "to": "dev0.out0" },
                { "from": "dev2.in0", "to": "dev1.out0" },
                { "from": "dev3.in0", "to": "dev4.out0" },
                { "from": "dev4.in0", "to": "dev0.out0" }
            ]
        });
        $ws.remove();
        this.tabPanel.find("svg").addClass("workspace flex-child");
        //Bind Toolbar events
        this.tabPanel.find(".btn-delete").click(() => this.workspace.removeSelection());
        this.tabPanel.find(".btn-parameter").click(() => this.workspace.editSelectionParameters());
        this.tabPanel.find(".cb-connsim").change(() => this.workspace.setShowConnectorState(this.tabPanel.find(".cb-connsim")[0].checked));
        this.tabPanel.find(".cb-pan").change(() => this.workspace.setDragMode(this.tabPanel.find(".cb-pan")[0].checked ? "pan" : 'select'));
        this.tab = $($.parseHTML(TAB_CODE));
        tabContainer.append(this.tab);
        this.tab.find(".closetab").click((e) => { e.preventDefault(); e.stopPropagation(); this.controller.closeEditor(this); });
        this.tab.click(() => this.controller.selectEditor(this));
    }
    getLibraryComponent(identifier, workspace) {
    }
    ;
    circuitModified(workspace) {
    }
    ;
    openCompoundComponent(identifier, workspace) {
    }
    ;
    activateTab() {
        this.tabPanel.show();
        this.tab.addClass("active");
    }
    deactivateTab() {
        this.tabPanel.hide();
        this.tab.removeClass("active");
    }
    remove() {
        this.tab.remove();
        this.tabPanel.remove();
    }
}
//# sourceMappingURL=editorController.js.map