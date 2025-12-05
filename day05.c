#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {uint64_t a,b;} Range;
int cmp(const Range* R,const Range* S){ return R->a<S->a?-1:1; }

int main(void){
    uint64_t part1=0,part2=0;
    int nr=0; 
    Range T[1500]={{0}};
    while(scanf("%llu-%llu",&T[nr].a,&T[nr].b)==2){ nr++; }
    while(scanf("%llu",&T[nr].a)==1){ nr++; }
    qsort(T,nr,sizeof(Range),(int(*)(const void*,const void*))cmp);
    // Sieve formula: len(A inter B) = len(A)+len(B)-len(A U B)
    //    lenA: total measure of intervals
    //    lenB: total measure of points
    //    lenC: total measure of union (A U B)
    uint64_t lenA=0,lenB=0,lenC=0;
    uint64_t oldb=0;
    for(int i=0;i<nr;i++){
        uint64_t a=T[i].a,b=T[i].b;
        if(b==0){ lenB+=1; continue; }
        if(b<=oldb){ continue; }
        if(a<=oldb){ a=oldb+1; }
        lenA+=b-a+1; oldb=b;
    }
    oldb=0;
    for(int i=0;i<nr;i++){
        uint64_t a=T[i].a,b=T[i].b;
        if(b==0){ b=a; }
        if(b<=oldb){ continue; }
        if(a<=oldb){ a=oldb+1; }
        lenC+=b-a+1; oldb=b;
    }
    part1=lenA+lenB-lenC; part2=lenA;
    printf("%llu %llu\n",part1,part2);
    return 0;
}