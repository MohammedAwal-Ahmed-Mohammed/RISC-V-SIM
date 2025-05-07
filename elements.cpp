#include <vector>
using namespace std;


//ALU CLASS
class ALU {
    private:
        //INPUTS
        int src1, src2;
        //OUTPUTS
        int output, zero;
    
    public:
        void inputs_setter (int a, int b) {
            src1 = a;
            src2 = b;
        }

    // THE START OF THE R TYPE OPERATIONS
        void ADD () {
            output = src1 + src2;
        }

        void SUB () {
            output = src1 - src2;
        }

        void XOR () {
            output = src1 xor src2;
        }
        
        void OR () {
            output = src1 or src2;
        }

        void AND () {
            output = src1 and src2;
        }

        void SLL () {
            output = src1 << src2;
        }

        void SRL () {
            output = src1 >> src2;
        }

        void SRA () {
            output = src1 >> src2;
        }

        void SLT () {
            output = (src1 < src2) ? 1 : 0;
        }

        void SLTU () {
            output = (src1 < src2) ? 1 : 0;
        }


        //THE START OF I TYPE OPERATIONS ARITH

        void ADDI () {
            output = src1 + src2;
        }


        void XORI () {
            output = src1 xor src2;
        }
        
        int ORI () {
            output = src1 or src2;
        }

        void ANDI () {
            output = src1 and src2;
        }

        int SLLI () {
            output = src1 << src2;
        }

        void SRLI () {
            output = src1 >> src2;
        }

        void SRAI () {
            output = src1 >> src2;
        }

        void SLTI () {
            output = (src1 < src2) ? 1 : 0;
        }

        void SLTUI () {
            output = (src1 < src2) ? 1 : 0;
        }

        // I TYPE OPERATIONS FOR LOAD

        void LB () {
            output = src1 + src2;
        }

        void LH () {
            output = src1 + src2;
        }

        void LW () {
            output = src1 + src2;
        }

        void LBU () {
            output = src1 + src2;
        }

        void LHU () {
            output = src1 + src2;
        }

        // THE START OF S TYPE INSTRUCTIONS

        void SB () {
            output = src1 + src2;
        }

        void SH () {
            output = src1 + src2;
        }

        void SW () {
            output = src1 + src2;
        }

        // NOW FOR THE BRANCH (B-TYPE) WHICH ARE ESSENTIALLY A MODIFIED S-TYPE

        void BEQ () {
            zero = (src1 == src2) ? 1 : 0;
        }

        void BNE () {
            zero = (src1 != src2) ? 1 : 0;
        }

        void BLT () {
            zero = (src1 < src2) ? 1 : 0;
        }

        void BGE () {
            zero = (src1 >= src2) ? 1 : 0;
        }

        void BLTU () {
            zero = (src1 < src2) ? 1 : 0;
        }

        void BGEU () {
            zero =  (src1 >= src2) ? 1 : 0;
        }

    
};

//REGISTER FILE CLASS
class REG_FILE {
    private:
        int RS1, RS2, RD;
        int registers[32];

    public:
        int read_reg1 () {
            return registers[RS1];
        }

        int read_reg2 () {
            return registers[RS2];
        }

        void write (int R) {
            registers[RD] = R;
        }
};

//INSTRUCTION MEM CLASS
class INSTRUCTION_MEM {
    
    private:
        int words;
        vector <int> mem;

        //INPUTS
        int ADDRESS;

        //OUTPUTS
        int current_instruction;
        // vector <int> instructions_to_store;
        

    public:
        void create_mem (int size) {
            words = size;
            mem.resize(words);
        }

        void write_mem (vector <int> prog) {
            for (int i=0; i < prog.size(); i++) {
                mem[i] = prog[i];
            }
        }

        void read_mem () {
            current_instruction = mem[ADDRESS];
        }

        void input_setter (int addr) {
            ADDRESS = addr;
        }
};

//DATA MEM CLASS
class DATA_MEM {
    private:
        int words;
        vector <int> mem;

        //INPUTS TO THE MEMORY
        int ADDRESS;
        int data_to_store;

        //OUTPUT OF THE MEMORY
        int loaded_data;

    public:
        void create_mem () {
            mem.resize(words);
        }

        void write_mem () {
            mem[ADDRESS] = data_to_store;
        }

        void read_mem ()  {
            loaded_data = mem[ADDRESS];
        }

        void set_mem_size (int size) {
            words = size;
        }

        void input_setter (int addr, int data) {
            ADDRESS = addr;
            data_to_store = data;
        }

};

//ADDER CLASS FOR THE TWO ADDERS
class ADDER {
    private:
        int src1, src2, output;

    public:
        void add () {
            output =  src1 + src2;
        }

        void inputs_setter (int a, int b) {
            src1 = a;
            src2 = b;
        }
};

//2_1 MUX CLASS
class MUX2_1 {
    private:
        //INPUTS
        int src0, src1, select;

        //OUTPUTS
        int output;

    public:
        void inputs_setter (int a, int b, int s) {
                src0 = a;
                src1 = b;
                select = s;
        }

        void output_setter () {
            output = (select == 0) ? src0 : src1;
        }
};

//SIGN EXTENDER CLASS
class SIGN_EXTENDER {
    private:
        //INPUT
        int IMM;

        //OUTPUT
        int extended_val;

    public:
        void input_setter (int a) {
            IMM = a;
        }

        void output_setter () {
            extended_val = IMM;
        }

};

//2R_SHIFTER
class SHIFTER_2R {
    private:
        //INPUT
        int extended_val;

        //OUTPUT
        int shifted_val;
    
    public:
        void input_setter (int a) {
            extended_val = a;
        }

        void out_setter () {
            shifted_val = extended_val << 2;
        }
};

//32BIT REG (PC)
class REG_32BIT {
    private:
        //INPUT
        int input_addr;

        //OUTPUT
        int output_addr;

    public:
        void input_setter (int a) {
            input_addr = a;
        }

        void output_setter () {
            output_addr = input_addr;
        }
};


//NOW ONTO THE CONTROL ELEMENTS

//CONTROL_UNIT CLASS

class CONTROL_UNIT {
    private:
        //INPUT
        int opcode;

        //OUTPUTS
        int branch, memRead, memtoReg, ALUop, memWrite, ALUsrc, regWrite;
        //ALL SIGNALS ARE 1-BIT AND THE ALUOP IS 2

    public:
        void input_setter (int a) {
            opcode = a;
        }

        //ALUop = 00 -> add (A and B) ... loads, stores, immediates
        //ALUop = 01 -> branch (compare A and B)
        //ALUop = 10 -> use funct3 and funct7.. R -TYPES
        void outputs_setter () {
                if (opcode == 51) { //R-TYPE
                    branch = 0;
                    memRead = 0;
                    memtoReg =0;
                    ALUop = 2;
                    memWrite = 0;
                    ALUsrc = 0;
                    regWrite = 1;
                }
                else if (opcode == 19) { //I-TYPE ARITHMETIC
                    branch = 0;
                    memRead = 0;
                    memtoReg = 0;
                    ALUop = 0;
                    memWrite = 0;
                    ALUsrc = 1;
                    regWrite = 1;
                }
                else if (opcode == 3) { //I-TYPE LOADS
                    branch = 0;
                    memRead = 1;
                    memtoReg = 1;
                    ALUop = 0;
                    memWrite = 0;
                    ALUsrc = 1;
                    regWrite = 1;
                }
                else if (opcode == 35) { //S-TYPE
                    branch = 0;
                    memRead = 0;
                    memtoReg = -1;
                    ALUop = 0;
                    memWrite = 1;
                    ALUsrc = 1;
                    regWrite = 0;
                }
                else if (opcode == 99) { //B-TYPE
                    branch = 0;
                    memRead = 0;
                    memtoReg = -1;
                    ALUop = 0;
                    memWrite = 1;
                    ALUsrc = 1;
                    regWrite = 0;
                }
        }
};