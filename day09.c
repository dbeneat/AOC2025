#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {int id,x,y,xx,yy;} Point;
int cmpx(const Point* a,const Point* b){ return a->x<b->x?-1:1; }
int cmpy(const Point* a,const Point* b){ return a->y<b->y?-1:1; }
int cmpid(const Point* a,const Point* b){ return a->id<b->id?-1:1; }

uint64_t area(Point a,Point b){
    return (uint64_t)(abs(b.x-a.x)+1)*(abs(a.y-b.y)+1);
}

Point T[500];
char M[300][300]={{0}};

void fill(int i,int j){
    if(i<0 || i>=300 || j<0 || j>=300){ return; }
    if(M[i][j]!=0){ return; }
    M[i][j]='!';
    //fill(i,j);
    fill(i+1,j);
    fill(i,j-1);
    fill(i,j+1);
}

int lineok(int x1,int y1,int x2,int y2){
    if(x1>x2){ int temp=x1;x1=x2;x2=temp; }
    if(y1>y2){ int temp=y1;y1=y2;y2=temp; }
    for(int x=x1;x<=x2;x++){
        for(int y=y1;y<=y2;y++){
            if(M[y][x]=='!'){ return 0; }
        }
    }
    return 1;    
}

int rectok(Point a,Point b){
    if(!lineok(a.xx,a.yy,b.xx,a.yy)){ return 0; }
    if(!lineok(b.xx,a.yy,b.xx,b.yy)){ return 0; }
    if(!lineok(b.xx,b.yy,a.xx,b.yy)){ return 0; }
    if(!lineok(a.xx,b.yy,a.xx,a.yy)){ return 0; }
    return 1;
}


int main(void){
    uint64_t part1=0,part2=0;
    
    int nt=0;
    while(scanf("%d,%d",&T[nt].x,&T[nt].y)==2){
        T[nt].id=nt; nt++;
    }
    qsort(T,nt,sizeof(Point),(int(*)(const void*,const void*))cmpx);
    int prev=0,uid=0;
    for(int i=0;i<nt;i++){
        if(T[i].x>prev){ uid++;prev=T[i].x; }
        T[i].xx=uid;
    }
    qsort(T,nt,sizeof(Point),(int(*)(const void*,const void*))cmpy);
    prev=0,uid=0;
    for(int i=0;i<nt;i++){
        if(T[i].y>prev){ uid++;prev=T[i].y; }
        T[i].yy=uid;
    }
    qsort(T,nt,sizeof(Point),(int(*)(const void*,const void*))cmpid);


    for(int i=0;i<nt;i++){
        Point a=T[i],b=T[(i+1)%nt];
        int x1=a.xx,x2=b.xx,y1=a.yy,y2=b.yy;
        if(x1>x2){ int temp=x1;x1=x2;x2=temp; }
        if(y1>y2){ int temp=y1;y1=y2;y2=temp; }
        for(int x=x1;x<=x2;x++){
            for(int y=y1;y<=y2;y++){
                M[y][x]='O';
            }
        }
    }

    fill(0,0);
    /*
    for(int y=0;y<=100;y++){
        for(int x=0;x<=100;x++){
            if(M[y][x]!=0){
                printf("%c",M[y][x]);
            }
            else{
                printf(".");
            }
        }
        printf("\n");
    }
    */

    for(int i=0;i<nt;i++){
        for(int j=i+1;j<nt;j++){
            uint64_t a=area(T[i],T[j]);
            if(a>part1){ part1=a; }
            if(a>part2 && rectok(T[i],T[j])){ part2=a; }
        }
    }
    printf("%llu %llu\n",part1,part2);
    return 0;
}