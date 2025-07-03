#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int cnt[2]={};
		int n;
		cin>>n;
		for(int i=0,x;i<n;++i){
			cin>>x;
			cnt[x&1]++;
		}
		int ans = 0;
		if(cnt[0]){
			ans = 1+cnt[1];
		}else{
			ans = cnt[1]-1;
		}
		cout<<ans<<"\n";
	}
}
