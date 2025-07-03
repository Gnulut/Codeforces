#include<stdio.h>
#include<string.h>

int inquire(char *s){
	int res;
	printf("? %s\n",s);fflush(stdout);
	scanf("%d",&res);
	return res;
}

int main(){
	int t,n;
	char st[205]={};
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		char *bg=st+100,*ed=bg;
		while(ed-bg<n){
			*ed='0';
			if(!inquire(bg)){
				*ed='1';
				if(!inquire(bg)){
					*ed='\0';
					break;
				}
			}
			++ed;
		}
		while(ed-bg<n){
			--bg;
			*bg='0';
			if(!inquire(bg))
				*bg='1';
		}
		printf("! %s\n",bg);fflush(stdout);
		memset(bg,0,ed-bg);
	}
}
