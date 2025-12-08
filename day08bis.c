#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {int comp; uint64_t x,y,z; } Box;
typedef struct {int i,j; uint64_t d2; } Pair;
int cmpPairs(Pair* a,Pair*b){ return a->d2<b->d2?-1:1; }
int cmp(int* a,int*b){ return *a>*b?-1:1; }

Pair P[500*999]={{0}};

int main(void){
    uint64_t part1=0,part2=0;
    Box T[1000]={{0}};
    int uid=0;
    int nb=0;
    while(scanf("%llu,%llu,%llu",&T[nb].x,&T[nb].y,&T[nb].z)==3){
        T[nb].comp=uid;nb++;uid++;
    }
    int np=0;
    for(int i=0;i<nb;i++){
        for(int j=i+1;j<nb;j++){
            Box a=T[i],b=T[j];
            uint64_t dx=b.x-a.x;
            uint64_t dy=b.y-a.y;
            uint64_t dz=b.z-a.z;
            uint64_t d2=dx*dx+dy*dy+dz*dz;
            if(d2>500000000)continue;//Exclude pairs with big d2
            P[np].i=i;P[np].j=j;P[np].d2=d2;
            np++;
        }
    }
    qsort(P,np,sizeof(Pair),(int(*)(const void*,const void*))cmpPairs);
    int merges=0;
    int iter=0;
    while(merges<nb-1){
        Pair p=P[iter];
        Box a=T[p.i],b=T[p.j];
        if(a.comp!=b.comp){
            merges++;part2=a.x*b.x; 
            int u=a.comp<b.comp?a.comp:b.comp;
            int v=a.comp<b.comp?b.comp:a.comp;
            for(int k=0;k<nb;k++){ if(T[k].comp==u){ T[k].comp=v; } }
        }
        iter++;
        if(iter==1000){
            int hist[1000]={0};
            for(int i=0;i<nb;i++){ hist[T[i].comp]++; }
            qsort(hist,1000,sizeof(int),(int(*)(const void*,const void*))cmp);
            part1=hist[0]*hist[1]*hist[2];
        }   
    }
    printf("%llu %llu\n",part1,part2);
    return 0;
}