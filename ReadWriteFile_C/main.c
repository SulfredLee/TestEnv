#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* GetField(char* line, int num)
{
    const char* tok;
    for (tok = strtok(line, ",");
         tok && *tok;
         tok = strtok(NULL, ",\n")){
        if (!--num)
            return tok;
    }
    return NULL;
}
void GetData(char* line){
    const char* tok;
    int nCol = 1;
    for (tok = strtok(line, ",");
         tok && *tok;
         tok = strtok(NULL, ",\n")){
        fprintf(stdout, "Col %d is %s\n", nCol++, tok);
    }
}
int main(int argc, char* argv[]){
    char strFileName[] = "./output.txt";
    FILE *fp = fopen(strFileName, "wb");
    {
        int i = 0;
        for(i = 0; i < 3; i++){
            char strData[] = "id001,0\n";
            if(fp != NULL){
                fputs(strData, fp);
            }
        }
    }
    fclose(fp);

    FILE* stream = fopen(strFileName, "r");
    char line[1024];
    while (fgets(line, 1024, stream)){
        char* tmp = strdup(line);
        GetData(tmp);
        // fprintf(stdout, "Field 2 would be %s\n", GetField(tmp, 2));
        // NOTE strtok clobbers tmp
        free(tmp);
    }
    return 0;
}
