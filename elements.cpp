


/*
we building alu based the operations
*/
class ALU {
    private:
        int A,B;
    
    public:
    // THE START OF THE R TYPE OPERATIONS
        int ADD (int RS1, int RS2) {
            return RS1 + RS2;
        }

        int SUB (int RS1, int RS2) {
            return RS1 - RS2;
        }

        int XOR (int RS1, int RS2) {
            return RS1 xor RS2;
        }
        
        int OR (int RS1, int RS2) {
            return RS1 or RS2;
        }

        int AND (int RS1, int RS2) {
            return RS1 and RS2;
        }

        int SLL (int RS1, int RS2) {
            return RS1 << RS2;
        }

        int SRL (int RS1, int RS2) {
            return RS1 >> RS2;
        }

        int SRA (int RS1, int RS2) {
            return RS1 >> RS2;
        }

        int SLT (int RS1, int RS2) {
            return (RS1 < RS2) ? 1 : 0;
        }

        int SLTU (int RS1, int RS2) {
            return (RS1 < RS2) ? 1 : 0;
        }


        //THE START OF I TYPE OPERATIONS ARITH

        int ADDI (int RS1, int IMM) {
            return RS1 + IMM;
        }


        int XORI (int RS1, int IMM) {
            return RS1 xor IMM;
        }
        
        int ORI (int RS1, int IMM) {
            return RS1 or IMM;
        }

        int ANDI (int RS1, int IMM) {
            return RS1 and IMM;
        }

        int SLLI (int RS1, int IMM) {
            return RS1 << IMM;
        }

        int SRLI (int RS1, int IMM) {
            return RS1 >> IMM;
        }

        int SRAI (int RS1, int IMM) {
            return RS1 >> IMM;
        }

        int SLTI (int RS1, int IMM) {
            return (RS1 < IMM) ? 1 : 0;
        }

        int SLTUI (int RS1, int IMM) {
            return (RS1 < IMM) ? 1 : 0;
        }

        // I TYPE OPERATIONS FOR LOAD

        int LB (int RS1, int IMM) {
            return RS1 + IMM;
        }

        int LH (int RS1, int IMM) {
            return RS1 + IMM;
        }

        int LW (int RS1, int IMM) {
            return RS1 + IMM;
        }

        int LBU (int RS1, int IMM) {
            return RS1 + IMM;
        }

        int LHU (int RS1, int IMM) {
            return RS1 + IMM;
        }

        // THE START OF S TYPE INSTRUCTIONS

        int SB (int RS1, int IMM) {
            return RS1 + IMM;
        }

        int SH (int RS1, int IMM) {
            return RS1 + IMM;
        }

        int SW (int RS1, int IMM) {
            return RS1 + IMM;
        }

        // NOW FOR THE BRANCH (B-TYPE) WHICH ARE ESSENTIALLY A MODIFIED S-TYPE

        int BEQ (int RS1, int RS2) {
            return (RS1 == RS2) ? 1 : 0;
        }

        int BNE (int RS1, int RS2) {
            return (RS1 != RS2) ? 1 : 0;
        }

        int BLT (int RS1, int RS2) {
            return (RS1 < RS2) ? 1 : 0;
        }

        int BGE (int RS1, int RS2) {
            return (RS1 >= RS2) ? 1 : 0;
        }

        int BLTU (int RS1, int RS2) {
            return (RS1 < RS2) ? 1 : 0;
        }

        int BGEU (int RS1, int RS2) {
            return (RS1 >= RS2) ? 1 : 0;
        }


    
};