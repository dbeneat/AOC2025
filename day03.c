#include <stdio.h>
#include <stdint.h>

uint64_t solve(char t[],int summands){
    uint64_t T[200]={0};
    uint64_t R[200]={0};
    int len; for(len=0;t[len]>='0';len++){ T[len]=t[len]-'0'; }

    for(int it=0;it<summands;it++){
        uint64_t m=0;
        for(int i=0;i<len;i++){
            uint64_t new=10*m+T[i];
            m=R[i]>m?R[i]:m;
            R[i]=new;
        }     
    }
    uint64_t m=0;
    for(int i=0;i<len;i++){ m=R[i]>m?R[i]:m; R[i]=m; }
    return R[len-1];
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