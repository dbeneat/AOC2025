#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct {uint64_t sum,mul;} Res;

int main(void){
    uint64_t part1=0;
    Res T[2000]; for(int i=0;i<2000;i++){ T[i].sum=0;T[i].mul=1; }
    char buff[5000];
    char sep[3]=" \n";
    int col=0;
    while(fgets(buff,5000,stdin)){
        //printf("\n\n");
        char* tok=strtok(buff,sep);
        while(tok){
            
            //printf("%d:%s ",col,tok);
            //printf("[%u]",tok[0]);
            switch(tok[0]){
                case '+': T[col].mul=0; col++; break;
                case '*': T[col].sum=0; col++; break;
                default: {
                    uint64_t n=_strtoui64(tok,NULL,10);
                    T[col].sum+=n;T[col].mul*=n;
                    col++;
                }
                break;
            }
            tok=strtok(NULL,sep);
        }
        col=0;
    }
    //for(int i=0;T[i].sum+T[i].mul>1 && i<2000;i++){printf("(%llu %llu)",T[i].sum,T[i].mul);}
    for(int i=0;T[i].sum+T[i].mul>1 && i<2000;i++){ part1+=T[i].sum+T[i].mul; }
    printf("%llu\n",part1);
    
    return 0;
}