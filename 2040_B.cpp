#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		int num=1,i=1,ans=1;
		for(;num<n;++i){
			if(i&1){
				num++;
				++ans;
			}else{
				num*=2;
			}
		}
		cout<<ans<<"\n";
	}
}

