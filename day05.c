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
    uint64_t interv[200][2]={{0}};
    while(scanf("%llu-%llu",&a,&b)==2){
        interv[nint][0]=a; interv[nint][1]=b;
        nint++;
    }
    qsort((double**) interv,nint,2*sizeof(uint64_t),cmp);
    while(scanf("%llu",&id)==1){
        for(int i=0; i<nint;i++){
            uint64_t a=interv[i][0],b=interv[i][1];
            if(id>=a && id<=b){ part1++; break; }
            if(id>b){ break; }
        }
    }
    uint64_t oldb=0;
    for(int i=0;i<nint;i++){
        uint64_t a=interv[i][0],b=interv[i][1];
        if(b<=oldb){ continue; }
        if(a<=oldb){ a=oldb+1; }
        part2+=b-a+1;
        oldb=b;
    }    
    printf("%llu %llu\n",part1,part2);
    return 0;
}