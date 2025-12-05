#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int cmp(const void* a,const void* b){
    const uint64_t (*row1)[2]=*(const uint64_t(**) [2]) a;
    const uint64_t (*row2)[2]=*(const uint64_t(**) [2]) b;
    return row1[0]<row2[0]?-1:1;
}


int main(void){
    uint64_t part1=0,part2=0;
    uint64_t a,b,id;
    int nint=0;
    uint64_t interv[1500][2]={{0}};
    while(scanf("%llu-%llu",&a,&b)==2){
        interv[nint][0]=a; interv[nint][1]=b;
        nint++;
    }
    while(scanf("%llu",&id)==1){
        interv[nint][0]=id; interv[nint][1]=id-1;
        nint++;
    }
    qsort((double**) interv,nint,2*sizeof(uint64_t),cmp);
    uint64_t lenA=0,lenB=0,lenC=0;
    // Sieve formula: len(A inter B) = len(A)+len(B)-len(A U B)
    // lenA:total measure of intervals
    // lenB: total measure of points
    // lenC: total measure of union (A U B)
    uint64_t oldb=0;
    for(int i=0;i<nint;i++){
        uint64_t a=interv[i][0],b=interv[i][1];
        if(a>b){ lenB+=1; continue; }
        if(b<=oldb){ continue; }
        if(a<=oldb){ a=oldb+1; }
        lenA+=b-a+1;
        oldb=b;
    }
    oldb=0;
    for(int i=0;i<nint;i++){
        uint64_t a=interv[i][0],b=interv[i][1];
        if(a>b){ b=a; }
        if(b<=oldb){ continue; }
        if(a<=oldb){ a=oldb+1; }
        lenC+=b-a+1;
        oldb=b;
    }
    part1=lenA+lenB-lenC;
    part2=lenA;   
    printf("%llu %llu\n",part1,part2);
    return 0;
}