#include <stdio.h>

int toint(char t[]){
    int r=0;
    while(t[0]!='\n'){r=r*10+t[0]-'0';t++;}
    return r;
}

int main(void){
    int part1=0,part2=0;
    char buff[20];
    int old=50;
    int n=50;
    while(fgets(buff,20,stdin)){
        int d=toint(buff+1);
        int q=d/100; int r=d%100;
        if(buff[0]=='L'){n=n-r;}
        if(buff[0]=='R'){n=n+r;}
        part2+=((old>0)&&(n<=0 || n>=100))+q;
        n=(n+100)%100;
        part1+=n==0;
        old=n;
    }
    printf("%d %d\n",part1,part2);
    return 0;
}