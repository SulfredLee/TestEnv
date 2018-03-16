#include <iostream>
#include <string>
#include <string.h>

int main(int argc, char* argv[]){
    {
        // copy from string to char array
        char* charArray = (char*)malloc(sizeof(char) * 1024);
        memset(charArray, 'A', 1024);
        std::string strTemp;
        strTemp.resize(strlen(charArray));
        std::cout << "before: " << strTemp[0] << std::endl;
        memcpy(&strTemp[0], charArray, strlen(charArray));
        std::cout << "after: " << strTemp[0] << std::endl;
    }
    {
        // free memory
        char* charArray = NULL;
        std::cout << "before free" << std::endl;
        if (charArray != NULL){
            free(charArray);
        }
        std::cout << "after free" << std::endl;
    }
    return 0;
}
