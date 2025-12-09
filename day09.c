#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {int x,y;} Point;
uint64_t area(Point a,Point b){
    return (uint64_t)(abs(b.x-a.x)+1)*(abs(a.y-b.y)+1);
}
int main(void){
    uint64_t part1=0;
    Point T[500];
    int nt=0;
    while(scanf("%d,%d",&T[nt].x,&T[nt].y)==2){ nt++; }
    for(int i=0;i<nt;i++){
        for(int j=i+1;j<nt;j++){
            uint64_t a=area(T[i],T[j]);
            if(a>part1){ part1=a; }
        }
    }
    printf("%llu\n",part1);
    return 0;
}