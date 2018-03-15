#include "abc.h"

int abc_x;
static void printABC(){
    fprintf(stdout, "This is ABC\n");
}

void printABCProxy(){
    printABC();
}
