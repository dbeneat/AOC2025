#include <stdio.h>
#include <stdbool.h>

int main(void){
    int part1=0,part2=0;
    char buff[200][200]={{0}};
    int row=0;
    while(fgets(buff[row+1]+1,198,stdin)){ row++; }
    bool changed=true,first=true;
    while(changed){
        changed=false;
        for(int i=1;i<=row;i++){
            for(int j=1;j<=row;j++){
                #define T(i,j) (buff[i][j]=='@' || buff[i][j]=='x')
                if(T(i,j)){
                    int nei=T(i-1,j-1)+T(i-1,j)+T(i-1,j+1);
                    nei+=T(i,j-1)+T(i,j+1);
                    nei+=T(i+1,j-1)+T(i+1,j)+T(i+1,j+1);
                    if(nei<4){
                        changed=true;
                        buff[i][j]='x';
                        if(first){ part1++; }
                        part2++;                    
                    }
                }    
            }
        }
        for(int i=1;i<=row;i++){
            for(int j=1;j<=row;j++){
                if(buff[i][j]=='x'){ buff[i][j]='.'; }    
            }
        }
        first=false;
    }

    printf("%d %d\n",part1,part2);
    return 0;
}