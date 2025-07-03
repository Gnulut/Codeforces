#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int t,n;
	vector<int> cnt;
	cin>>t;
	while(t--){
		cin>>n;
		cnt.clear();
		{
			vector<int> tmp(n);
			for(int i=0;i<n;++i){
				for(int j=0;j<n;++j){
					cin>>tmp[j];
				}
				int ans=0;
				for(int j=n-1;j>=0;--j){
					if(tmp[j]!=1){
						break;
					}
					++ans;
				}
				cnt.push_back(ans);
			}
		}
		sort(cnt.begin(),cnt.end());
		int ans=0;
		for(int i=0;i<n;++i){
			if(ans<=cnt[i]){
				++ans;
			}
		}
		cout<<ans<<"\n";
	}
}
