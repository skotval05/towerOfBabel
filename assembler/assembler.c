#include <stdio.h>
#include <string.h>

enum operation {

    // misc ops [000]

    NOP = 000000,
    HLT = 000111,

    // arithmetic ops [001]
    
    ADD = 001000,
    SUB = 001001,
    DEC = 001010,
    INC = 001011,

    // bitwise logic ops [010]

    AND = 010000,
    ORR = 010001,
    XOR = 010010,
    NOT = 010011,
    EQL = 010100,

    // shift ops [011]

    LSL = 011000,
    LSR = 011001,
    ASL = 011010,
    ASR = 011011,

    // jumping ops [100]
    
    JMP = 100000,
    JZR = 100001,
    JEV = 100010,
    JOF = 100011,
    JNG = 100100,

    // stack ops [101]
    
    PSH = 101000,
    POP = 101001,

    // memory ops [110]
    
    MOV = 110000,
    LDA = 110001,
    LDI = 110010,
    STR = 110011,
    SWP = 110100

    // a secret third op [111]
};

struct macro_arg {
    char * name;
    int value;
};

struct macro {
    char * name;
    struct macro_arg * args;
    size_t argc;

    char * program;

};

int main(int argc, char* argv[]) {

    short terminalOutput = 0;

    // we want 2 args! input file and output file!
    if (argc != 2) {
        printf("Incorrect number of arguments - %d is not 2 arguments.", argc);
        return -1;
    }
    if (strcmp(argv[1], "hexdump") == 0) {
        // in hexdump mode, output will be the terminal.
        terminalOutput = 1;
    }

    // parse line by line. Look for the .start header first.
    
    //for each line in input file:
    //  remove the whitespace from the line
    //  check first character for header, flag, or macro def
    //  use a state machine to determine which section of the program we're in, change upon finding a new header
    //  if it is a flag, define a flag and note the line number.
    //  if it is an instruction, append the instruction binary to the running list.
    //  if it is a macro, check if it is defined.
    //      if it is defined, replace it with the 'program' member of the macro and recursively lex that.
    //  if it is a header, change the state of the program that we're observing.
    //
    //  going to bed. do this later.

    return 0;
}
