#include <stdio.h>
#include "foo.h"

void printFoo(){
    fprintf(stdout, "This is Foo\n");
}

static void printHappy(){
    fprintf(stdout, "This is Happy\n");
}
