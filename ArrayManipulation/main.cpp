#include <iostream>

int main(int argc, char* argv[]){
    int* pArray = new int[1024];

    std::cout << sizeof(pArray) << std::endl;

    free(pArray);
    return 0;
}
