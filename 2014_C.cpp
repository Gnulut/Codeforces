#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t,n;
	vector<int> a;
	cin>>t;
	while(t--){
		cin>>n;
		a.resize(n);
		for(auto&ai:a)cin>>ai;
		if(n<=2){
			cout<<"-1\n";
			continue;
		}
		int need_below=(n+2)/2;
		sort(a.begin(),a.end());
		int max_avg=a[need_below-1];
		long long sum= accumulate(a.begin(),a.end(),0ll);
		if(sum>(long long)max_avg*n*2ll){
			cout<<"0\n";
			continue;
		}
		cout<<((long long)max_avg*n*2ll)-sum+1<<"\n";
	}
}
