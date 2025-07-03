#include<stdio.h>

int main(){
	long long t,a,b;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld",&a,&b);
		if(b>a){
			a=b;
		}
		printf("%lld\n",a+1);
	}
}
