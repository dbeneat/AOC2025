#include <stdio.h>
#include <string.h>
#include <stdint.h>

typedef struct {int id;char name[5];int nei[25];} Node;
Node T[700]={{0}};
uint64_t mem[700]={0};
int nn=0;

int id(char name[5]){//First valid id is 1. 0=null pointer
    for(int i=1;i<=nn;i++){
        if(strcmp(name,T[i].name)==0){ return i; }
    }
    nn++;strcpy(T[nn].name,name);T[nn].id=nn;return nn;
}

void cleanmem(void){ for(int i=0;i<700;i++){ mem[i]=-1; } }

uint64_t _nbpaths(int a,int b){
    if(mem[a]!=(uint64_t)-1){ return mem[a]; }
    uint64_t res=a==b;
    for(int j=0;T[a].nei[j]>0;j++){
        res+=_nbpaths(T[a].nei[j],b);
    }
    mem[a]=res;
    return res;
}

uint64_t nbpaths(int a,int b){ cleanmem();return _nbpaths(a,b); }

int main(void){
    uint64_t part1=0,part2=0;
    char a[5];
    while(scanf("%[^:]:", a)==1){
        int i=id(a);
        for(int j=0;getc(stdin)!='\n';j++){
            scanf("%[a-z]^\n",a);
            T[i].nei[j]=id(a);
        }
    }
    /*
    for(int i=0;i<nn;i++){
        printf("%d %s ( ",T[i].id,T[i].name);
        for(int j=0;T[i].nei[j]>0;j++){ printf("%s ",T[T[i].nei[j]].name); }
        printf(")\n");

    }
    */
    //https://stackoverflow.com/questions/3427843/gcc-compile-error-cast-specifies-array-type
    #define X(name1,name2) nbpaths(id((char[5]){name1}),id((char[5]){name2}))
    part1=X("you","out");
    part2=X("svr","dac")*X("dac","fft")*X("fft","out");
    part2+=X("svr","fft")*X("fft","dac")*X("dac","out");
    printf("%llu %llu\n",part1,part2);
    return 0;
}