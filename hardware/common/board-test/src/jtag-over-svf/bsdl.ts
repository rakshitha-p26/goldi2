import { binToHex } from "./util"

// Generated by https://quicktype.io
//
// To change quicktype's target language, run command:
//
//   "Set quicktype target language"

export interface bsdlRaw {
    component_name:                     string;
    generic_parameter:                  GenericParameter;
    logical_port_description:           LogicalPortDescription[];
    standard_use_statement:             string;
    component_conformance_statement:    string;
    device_package_pin_mappings:        DevicePackagePinMapping[];
    scan_port_identification:           ScanPortIdentification[];
    instruction_register_description:   InstructionRegisterDescription;
    optional_register_description:      OptionalRegisterDescription | OptionalRegisterDescription[];
    register_access_description:        RegisterAccessDescription[];
    boundary_scan_register_description: BoundaryScanRegisterDescription;
    bsdl_extensions:                    null;
    compliance_enable_description:      null;
    design_warning:                     null;
    grouped_port_identification:        null;
    intest_description:                 null;
    power_port_association_description: null;
    register_assembly_description:      null;
    register_association_description:   null;
    register_constraints_description:   null;
    register_fields_description:        null;
    register_mnemonics_description:     null;
    runbist_description:                null;
    system_clock_description:           null;
    use_statement:                      null;
}

export interface BoundaryScanRegisterDescription {
    fixed_boundary_stmts:   FixedBoundaryStmts;
    segment_boundary_stmts: null;
}

export interface FixedBoundaryStmts {
    boundary_length:   string;
    boundary_register: BoundaryRegister[];
}

export interface BoundaryRegister {
    cell_number: string;
    cell_info:   CellInfo;
}

export interface CellInfo {
    cell_spec:             CellSpec;
    input_or_disable_spec: InputOrDisableSpec | null;
}

export interface CellSpec {
    cell_name: string;
    port_id:   string | string[];
    function:  Function;
    safe_bit:  "0" | "1" | "X";
}

export enum Function {
    Bidir = "BIDIR",
    Control = "CONTROL",
    Internal = "INTERNAL",
    ObserveOnly = "OBSERVE_ONLY",
}

export interface InputOrDisableSpec {
    control_cell:   string;
    disable_value:  "0" | "1";
    disable_result: DisableResult;
}

export enum DisableResult {
    Z = "Z",
}

export interface DevicePackagePinMapping {
    pin_mapping_name: string;
    pin_map:          PinMap[];
}

export interface PinMap {
    port_name: string;
    pin_list:  string[];
    parseinfo: Array<ParseinfoEnum | number | null>;
}

export enum ParseinfoEnum {
    Port = "port",
}

export interface GenericParameter {
    default_device_package_type: string;
}

export interface InstructionRegisterDescription {
    instruction_length:  string;
    instruction_opcodes: InstructionOpcode[];
    instruction_capture: string[];
    instruction_private: string | string[];
}

export interface InstructionOpcode {
    instruction_name: string;
    opcode_list:      string[];
}

export interface LogicalPortDescription {
    identifier_list: string[];
    pin_type:        PinType;
    port_dimension:  PortDimensionClass | PortDimensionEnum | string;
}

export enum PinType {
    In = "in",
    Inout = "inout",
    Linkage = "linkage",
    Out = "out",
}

export interface PortDimensionClass {
    bit_vector: string[];
}

export enum PortDimensionEnum {
    Bit = "bit",
}

export interface OptionalRegisterDescription {
    idcode_register:   string;
    usercode_register?: string;
}

export interface RegisterAccessDescription {
    register:                 Register;
    instruction_capture_list: InstructionCaptureList[];
}

export interface InstructionCaptureList {
    instruction_name: string;
    pattern:          null;
}

export interface Register {
    reg_name:    string;
    reg_length?: string;
}

export interface ScanPortIdentification {
    tap_scan_in?:    string;
    tap_scan_mode?:  string;
    tap_scan_out?:   string;
    tap_scan_clock?: TapScanClock;
}

export interface TapScanClock {
    frequency:  string;
    halt_value: string;
}

export type boundaryCell = {
    cellNumber: number
    port: string
    function: string
    safeBit: "0" | "1" | "X"
    controllCell?: string
    disableValue?: "0" | "1"
    disableResult?: "0" | "1" | "Z"
    enableValue?: "0" | "1"
}

export interface bsdlData {
    ports: Array<string>
    instructionLength: number
    idcode: string
    instructions: {
        idcode: string
        sample: string
        extest: string
    }
    boundaryCellsLength: number
    boundaryCells: Array<boundaryCell>
}

export function parseBsdl(bsdl: bsdlRaw): bsdlData {
    const ports = new Array<string>()
    for (const desc of bsdl.logical_port_description) {
        if (desc.port_dimension === "bit") {
            ports.push(desc.identifier_list.join(''))
        } else if (Object.keys(desc.port_dimension)) {
            const bit_vector = (desc.port_dimension as any).bit_vector
            const low = parseInt(bit_vector[0])
            const high = parseInt(bit_vector[2])
            if (low > high) console.error("something went wrong while parsing ports from bsdl file")
            for (let i = low; i < high; i++) {
                ports.push(desc.identifier_list[0] + "(" + i + ")")
            }
        } else {
            console.error("something went wrong while parsing ports from bsdl file")
        }
    }
    const instructionLength = parseInt(bsdl.instruction_register_description.instruction_length)
    const instructions = {
        idcode: binToHex(bsdl.instruction_register_description.instruction_opcodes.find(elem => elem.instruction_name == "IDCODE")!.opcode_list[0]),
        sample: binToHex(bsdl.instruction_register_description.instruction_opcodes.find(elem => elem.instruction_name == "SAMPLE")!.opcode_list[0]),
        extest: binToHex(bsdl.instruction_register_description.instruction_opcodes.find(elem => elem.instruction_name == "EXTEST")!.opcode_list[0])
    }
    const idcode = Array.isArray(bsdl.optional_register_description) ? 
        binToHex((bsdl.optional_register_description as any)[0].idcode_register) :
        binToHex((bsdl.optional_register_description as any).idcode_register)
    const boundaryCellsLength = parseInt(bsdl.boundary_scan_register_description.fixed_boundary_stmts.boundary_length)
    const boundaryCells = new Array<boundaryCell>()
    for (const desc of bsdl.boundary_scan_register_description.fixed_boundary_stmts.boundary_register) {
        boundaryCells.push({
            cellNumber: parseInt(desc.cell_number),
            port: Array.isArray(desc.cell_info.cell_spec.port_id) ? (desc.cell_info.cell_spec.port_id as any).join('') : desc.cell_info.cell_spec.port_id,
            function: desc.cell_info.cell_spec.function,
            safeBit: desc.cell_info.cell_spec.safe_bit,
            controllCell: desc.cell_info.input_or_disable_spec?.control_cell,
            disableValue: desc.cell_info.input_or_disable_spec?.disable_value,
            disableResult: desc.cell_info.input_or_disable_spec?.disable_result,
            enableValue: desc.cell_info.input_or_disable_spec?.disable_value ? 
                desc.cell_info.input_or_disable_spec.disable_value == "1" ?
                    "0" : 
                    "1" : 
                undefined
        })
    }

    return {
        ports: ports,
        instructionLength: instructionLength,
        instructions: instructions,
        idcode: idcode,
        boundaryCellsLength: boundaryCellsLength,
        boundaryCells: boundaryCells
    }
}