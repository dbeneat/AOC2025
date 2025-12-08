#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {int comp; uint64_t x,y,z; } Box;
int cmp(int* a,int*b){ return *a>*b?-1:1; }

int main(void){
    uint64_t part1=0,part2=0;
    Box T[1000]={{0}};
    int uid=0;
    int nb=0;
    while(scanf("%llu,%llu,%llu",&T[nb].x,&T[nb].y,&T[nb].z)==3){
        T[nb].comp=uid;nb++;uid++;
    }
    uint64_t prevmin=0;
    int merges=0;
    int iter=0;
    while(merges<nb-1){
        uint64_t d2min=-1;//very big number
        int imin=-1,jmin=-1;
        for(int i=0;i<nb;i++){
            for(int j=i+1;j<nb;j++){
                uint64_t dx=T[j].x-T[i].x;
                uint64_t dy=T[j].y-T[i].y;
                uint64_t dz=T[j].z-T[i].z;
                uint64_t d2=dx*dx+dy*dy+dz*dz;
                if(d2<d2min && d2>prevmin){ d2min=d2;imin=i;jmin=j; }
            }
        }
        iter++;
        prevmin=d2min;
        if(T[imin].comp!=T[jmin].comp){ merges++;part2=T[imin].x*T[jmin].x; }
        int u=T[imin].comp<T[jmin].comp?T[imin].comp:T[jmin].comp;
        int v=T[imin].comp<T[jmin].comp?T[jmin].comp:T[imin].comp;
        for(int k=0;k<nb;k++){
            if(T[k].comp==u){ T[k].comp=v; }
        }
        if(iter==1000){
            int hist[1000]={0};
            for(int i=0;i<nb;i++){ hist[T[i].comp]++; }
            qsort(hist,1000,sizeof(int),(int(*)(const void*,const void*))cmp);
            part1=hist[0]*hist[1]*hist[2];
        }
    }

    printf("\n%llu %llu\n",part1,part2);
    return 0;
}