#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint64_t area(int xa,int ya,int xb,int yb){
    return (uint64_t)(abs(xb-xa)+1)*(abs(yb-ya)+1);
}
int main(void){
    uint64_t part1=0;
    int T[500][2];
    int nt=0;
    while(scanf("%d,%d",&T[nt][0],&T[nt][1])==2){ nt++; }
    for(int i=0;i<nt;i++){
        for(int j=0;j<nt;j++){
            uint64_t a=area(T[i][0],T[i][1],T[j][0],T[j][1]);
            if(a>part1){ part1=a; }
        }
    }
    printf("%llu\n",part1);
    return 0;
}