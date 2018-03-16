#include <map>
#include <string>
#include <string.h>
#include <iostream>

struct KeyStatusPair{
    char strKeyID[256];
    int keyStatus;
};
std::string printKeyStatus(int IN){
    switch(IN){
    case 0:
        return "kA";
    case 1:
        return "kB";
    default:
        return "kEnd";
    }
}
void updateKeyStatusFromMap(void** pArray, int* nArraySize){
    std::map<std::string, int> mapTemp;
    mapTemp.insert(std::make_pair("kID_001", 0));
    mapTemp.insert(std::make_pair("kID_002", 0));
    mapTemp.insert(std::make_pair("kID_003", 1));
    mapTemp.insert(std::make_pair("kID_004", 1));

    if(mapTemp.size()){
        KeyStatusPair* p_arrResult = (KeyStatusPair*)malloc(sizeof(KeyStatusPair) * mapTemp.size());
        *nArraySize = mapTemp.size();
        int nMaxKeyIDSize = sizeof(p_arrResult[0].strKeyID) / sizeof(char);
        int index = 0;
        for(auto it = mapTemp.begin(); it != mapTemp.end(); it++, index++){
            strncpy(p_arrResult[index].strKeyID, it->first.c_str(), nMaxKeyIDSize);
            p_arrResult[index].keyStatus = it->second;
        }
        *(KeyStatusPair**)pArray = p_arrResult;
    }
}
int main(int argc, char* argv[]){
    KeyStatusPair* arrKeyStatusPair = NULL;
    int n_arrKeyStatusPairSize = 0;
    updateKeyStatusFromMap((void**)&arrKeyStatusPair, &n_arrKeyStatusPairSize);
    for(int i = 0; i < n_arrKeyStatusPairSize; i++){
        std::cout << arrKeyStatusPair[i].strKeyID << " " << printKeyStatus(arrKeyStatusPair[i].keyStatus) << std::endl;
    }
    if(arrKeyStatusPair != NULL){
        free(arrKeyStatusPair);
        arrKeyStatusPair = NULL;
        n_arrKeyStatusPairSize = 0;
    }
    return 0;
}
