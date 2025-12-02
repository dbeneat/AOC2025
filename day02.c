#include <stdio.h>
#include <stdint.h>
/*
    For part 1
    ----------
    patterns:
    level0: aa=11*a=11*n with 1<=n<=9
    level1: abab=101*ab=101*n with 10<=n<=99
    level2: abcabc=1001*abc=1001*n with 100<=n<=999
    etc.

    For part 2
    ----------
    patterns:
    aa, aaa, aaaaa, ... = 11*a, 111*a, 1111*a, ...
    abab, ababab, ... = 101*ab, 10101*ab, ...
    abcabc, abcabcabc = 1001*abc, 1001001*abc, ...

    "Z numbers"
    base 1: 1*10+1 =11, 11*10+1=111, 111*10+1=1111, etc.
    base 10: 1*100+1=101, 101*100+1=10101, etc.   
*/


uint64_t G(uint64_t a,uint64_t b){
    uint64_t res=0, base=1;
    for(int k=1;k<6;k++){
        for(unsigned int n=base; n<10*base; n++){
            uint64_t t=(10*base+1)*n;
            if(t>=a && t<=b){ res+=t; }
        }
        base*=10;
    }
    return res;
}


uint64_t H(uint64_t a,uint64_t b){
    uint64_t res=0, base=1;
    int found[3001]={0};//hash table to avoid double-counting. 3001=small prime
    for(int k=1;k<6;k++){
        uint64_t Z=10*base+1;
        while(Z<b){
            for(unsigned int n=base; n<10*base; n++){
                uint64_t t=Z*n;
                if(t>=a && t<=b){ 
                    int h=(t*3)%3001;
                    if(found[h]==0){ res+=t; found[h]=1; }
                }
            }
            Z=10*base*Z+1;
        }
        base*=10;
    }
    return res;
}


int main(void){
    uint64_t part1=0,part2=0;
    uint64_t a,b; char c;
    while(scanf("%llu-%llu%c",&a,&b,&c)==3){ part1+=G(a,b); part2+=H(a,b); }
    printf("%lld %lld",part1,part2);
    return 0;
}