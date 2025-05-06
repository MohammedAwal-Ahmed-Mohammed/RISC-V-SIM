#include <vector>
using namespace std;


//ALU CLASS
class ALU {
    private:
        int src1, src2, output, zero;
    
    public:
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
class adder {
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
class {
    private:
        //INPUTS
        int src0, src1;

        //OUTPUTS
        int output;

    public:
        void output_setter (int select)
};
