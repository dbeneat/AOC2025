#include <stdio.h>
#include <stdint.h>

int main(void){
    uint64_t part1=0,part2=0;
    char buff[200];
    uint64_t beam[200]={0};
    while(fgets(buff,200,stdin)){
        for(int i=1;i<199;i++){
            char c=buff[i];
            if(c=='S'){ beam[i]=1; }
            if(c=='^' && beam[i]>0){
                beam[i-1]+=beam[i];beam[i+1]+=beam[i];
                beam[i]=0;part1++;
            }
        }
    }
    for(int i=0;i<200;i++){ part2+=beam[i]; }
    printf("%llu %llu\n",part1,part2);
    return 0;
}