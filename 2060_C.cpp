#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,n,k;
	cin>>t;
	while(t--){
		cin>>n>>k;
		vector<int> cnt(max(n,k)+1);
		for(int i=0,x;i<n;++i){
			cin>>x;
			cnt[x]++;
		}
		int ans=0;
		if(k%2==0){
			ans+=cnt[k/2]/2;
			cnt[k/2]=0;
		}
		for(int i=1;i<=k/2;++i){
			ans+=min(cnt[i],cnt[k-i]);
		}
		cout<<ans<<"\n";
	}
}
