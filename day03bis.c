#include <stdio.h>
#include <stdint.h>

uint64_t solve(char t[],int summands){
    uint64_t T[200]={0};
    int len; for(len=0;t[len]>='0';len++){ T[len]=t[len]-'0'; }
    int start=0;
    uint64_t res=0;
    for(int k=summands-1;k>=0;k--){
        unsigned int best=0;   
        for(int i=start;i<len-k;i++){ if(T[i]>best){start=i+1;best=T[i];} }
        res=10*res+best;
    }
    return res;
}


int main(void){
    uint64_t part1=0,part2=0;
    char buff[200];
    while(fgets(buff,200,stdin)){
        part1+=solve(buff,2);
        part2+=solve(buff,12);
    }
    printf("%llu %llu\n",part1,part2);
    return 0;
}