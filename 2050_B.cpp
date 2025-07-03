#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		vector<int> a[2];
		for(int i=0;i<n;++i){
			int x;
			cin>>x;
			a[i&1].push_back(x);
		}
		bool can=true;
		long long sum[2]={};
		for(int i=0;i<2;++i){
			sum[i]=accumulate(a[i].begin(),a[i].end(),0ll);
		}
		can&=sum[0]/((n+1)/2)==sum[1]/(n/2);
		can&=sum[0]%((n+1)/2)==0;
		can&=sum[1]%(n/2)==0;
		cout<<(can?"YES\n":"NO\n");
	}
}
