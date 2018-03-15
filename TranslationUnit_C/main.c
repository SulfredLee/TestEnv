#include <stdio.h>
#include "lib/abc.h"
#include "lib/foo.h"

int main(int argc, char* argv[]){
    printFoo();
    printABCProxy();
    //printf("Here is abc_a: %d\n", abc_x);
    return 0;
}
