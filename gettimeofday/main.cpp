#include <sys/time.h>
#include <stdio.h>
#include <stdint.h>

int64_t getINTTime(){
    int64_t result;
    struct timeval tv;
    tv.tv_sec = tv.tv_usec = 0;
    gettimeofday(&tv, NULL);
    //result = (tv.tv_sec * 1000LL) + (tv.tv_usec / 1000LL);
    result = tv.tv_sec + (tv.tv_usec / 1000LL * 1000LL);

    return result;
}

double getDoubleTime() {
    struct timeval tv;
    tv.tv_sec = tv.tv_usec = 0;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + (tv.tv_usec / (1000.0 * 1000.0));
}

int main(int argc, char* argv[]){
    int64_t n64Time = getINTTime();
    double dTime = getDoubleTime();
    fprintf(stdout, "INT: %ld, Double: %f\n", n64Time, dTime);

    return 0;
}
