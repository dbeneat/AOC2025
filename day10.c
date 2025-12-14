#include <stdio.h>
#include <stdint.h>


int btns[15]={0};

typedef struct {int comb, pattern, popcount;} Entry;

Entry T[1<<15]={{0}};

int nlights;
int target[12];
int nb;

int solve(void){
	int all0=1;
	int anyneg=0;
	//printf("called with target=[ ");
	for(int i=0;i<nlights;i++){
		//printf("%d ",target[i]);
		all0=all0&&target[i]==0;
		anyneg=anyneg||target[i]<0;
	}
	//printf("]\n");
	if(all0){ /*printf("all 0\n");*/ return 0; }
	if(anyneg){ /*printf("some <0\n");*/ return 999999; }
			
	int patt=0;
	for(int i=0;i<nlights;i++){
		if(target[i]%2){
			patt|=1<<i;	
		}
	}
	int min=999999;
	int temp[12]={0};
	for(int comb=0;comb<1<<nb;comb++){
		if(T[comb].pattern==patt){
			//printf("found: %d %d %d\n",T[comb].comb,T[comb].pattern,T[comb].popcount);	
			
			for(int i=0;i<nlights;i++){
				temp[i]=target[i];
			}
			int cmb=comb;
			int ind=0;
			while(cmb){
				if(cmb%2){
					int b=btns[ind];
					int ind2=0;
					while(b){
						if(b%2==1){
							target[ind2]--;
						}
						ind2++;
						b>>=1;
					}
					
				}
				ind++;
				cmb>>=1;
			}
			for(int i=0;i<nlights;i++){
				target[i]/=2;
			}
			int res=T[comb].popcount+2*solve();
			for(int i=0;i<nlights;i++){
				target[i]=temp[i];
			}
			if(res<min){ min=res; }
			
		}

		
	}

	return min;
}

	
int main(void){
	uint64_t part2=0;
	char buff[300];
	while(fgets(buff,300,stdin)){
		//printf("%s",buff);
		nb=0;
		int ind=0;
		while(buff[ind]!=']'){
			ind++;
		}
		ind+=2;
		
		while(buff[ind]=='('){
			int btn=0;
			ind++;
			while(1){
				btn|=1<<(buff[ind]-'0');
				//printf("btn=%d %c\n",btn,buff[ind]);
				ind++;
				if(buff[ind]==')'){ break; }
				ind++;
			}
			ind+=2;
			printf("btn=%d %c\n",btn,buff[ind]);
			btns[nb]=btn;
			nb++;	
		}
		nlights=0;
		int t=0;
		ind++;
		while(buff[ind]!='}'){
			if(buff[ind]==','){
				target[nlights]=t;
				printf("[%d]",t);
				t=0;
				nlights++;
			}
			else{
				t=10*t+buff[ind]-'0';
			}
			ind++;
		}
		target[nlights]=t;
		printf("[%d]",t);
		nlights++;
		printf("btn=%d nlights=%d\n",nb,nlights);
		

		for(int comb=1;comb<1<<nb;comb++){
			int a=comb;
			int patt=0;
			int popc=0;
			for(int i=0;i<nb;i++){
				if(a%2){ patt^=btns[i];popc++; }
				a=a>>1;
			}
			T[comb].comb=comb;T[comb].pattern=patt;T[comb].popcount=popc;
		}
		//for(int i=0;i<64;i++){
		//	printf("%d %d %d\n",T[i].comb,T[i].pattern,T[i].popcount);
		//}

		int sol=solve();
		printf("sol:%d\n",sol);
		part2+=sol;



	}





	

	printf("%llu\n",part2);
    return 0;
}
