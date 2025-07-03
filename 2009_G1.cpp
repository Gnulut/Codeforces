#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int t,n,k,q;
	vector<int> a;
	cin>>t;
	while(t--){
		cin>>n>>k>>q;
		a.resize(n+1);
		for(int i=1;i<=n;++i){
			cin>>a[i];
		}
		vector<int> cnt(2*n+1);
		multiset<int> mx_cnts;
		vector<int> ans(n+1);
		for(int i=1;i<k;++i){
			int num = n-i+a[i];
			if(cnt[num])mx_cnts.erase(mx_cnts.find(cnt[num]));
			cnt[num]++;
			mx_cnts.insert(cnt[num]);
		}
		for(int i=k;i<=n;++i){
			int num = n-i+a[i];
			if(cnt[num])mx_cnts.erase(mx_cnts.find(cnt[num]));
			cnt[num]++;
			mx_cnts.insert(cnt[num]);
			ans[i]=k-*prev(mx_cnts.end());
			//cout<<"ans["<<i<<"] = "<<ans[i]<<"\n";
			int j=i-k+1;
			num=n-j+a[j];
			mx_cnts.erase(mx_cnts.find(cnt[num]));
			cnt[num]--;
			if(cnt[num])mx_cnts.insert(cnt[num]);
		}
		for(int qc=0,l,r;qc<q;++qc){
			cin>>l>>r;
			cout<<ans[r]<<"\n";
		}
	}
}
