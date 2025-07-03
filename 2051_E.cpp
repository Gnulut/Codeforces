#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t,n,reputation;
	cin>>t;
	while(t--){
		cin>>n>>reputation;
		vector<int> a(n),b(n);
		for(auto&x:a)cin>>x;
		for(auto&x:b)cin>>x;
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		set<int> prices;
		for(auto&x:a)prices.insert(x);
		for(auto&x:b)prices.insert(x);
		long long ans=0;
		int happy_buyer_idx=0,mad_buyer_idx=0;
		int current_buyer=n,current_negative=0;
		for(auto&price:prices){
			while(happy_buyer_idx<n&&a[happy_buyer_idx]<price){
				happy_buyer_idx++;
				current_negative++;
			}
			while(mad_buyer_idx<n&&b[mad_buyer_idx]<price){
				mad_buyer_idx++;
				current_buyer--;
				current_negative--;
			}
			if(current_negative<=reputation)
				ans = max(ans,(long long)current_buyer*price);
		}
		cout<<ans<<"\n";
	}
}
