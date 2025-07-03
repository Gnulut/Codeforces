#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a(n),cnt(105);
		for(auto&x:a){
			cin>>x;
			cnt[x]++;
		}
		int ans=n-*max_element(cnt.begin(),cnt.end());
		cout<<ans<<"\n";
	}
}
