#include <stdio.h>
#include <stdint.h>

int sp=0;
uint64_t stack[5]={0};
uint64_t res=0;
void calc(char c){
    if(c>='0'){ stack[sp]=10*stack[sp]+c-'0'; }
    else if(c=='+'){
            res=0;
            for(int i=0;i<=sp;i++){ res=res+stack[i]; }
            sp=0; stack[sp]=0;
    }
    else if(c=='*'){
            res=1;
            for(int i=0;i<=sp;i++){ res=res*stack[i]; }
            sp=0; stack[0]=0;
    }
    else if(c=='#' && stack[sp]>0){ sp++;stack[sp]=0; }
}

int main(void){
    uint64_t part1=0,part2=0;
    char buff[5][4000]={{0}};
    int nr=0;
    while(fgets(buff[nr],4000,stdin)){ nr++; }
    int col=0;
    while(buff[0][col]!=0 && buff[0][col]!='\n'){
        int newcol=col+1;
        while(buff[nr-1][newcol]==' '){ newcol++; }
        for(int i=0;i<nr-1;i++){
            calc('#');
            for(int j=col;j<newcol;j++){ calc(buff[i][j]); } 
        }
        calc(buff[nr-1][col]);
        part1+=res;
        col=newcol;
    }
    int nc=col;
    for(int j=nc-1;j>=0;j--){
        calc('#');
        for(int i=0;i<nr-1;i++){ calc(buff[i][j]); }
        char op=buff[nr-1][j];
        if(op=='+' || op=='*'){ calc(op); part2+=res; }    
    }
    
    printf("%llu %llu\n",part1,part2);
    return 0;
}