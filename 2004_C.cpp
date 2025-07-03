#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,n,k;
	vector<int> a;
	cin>>t;
	while(t--){
		cin>>n>>k;
		a.resize(n);
		for(auto&x:a)cin>>x;
		sort(a.begin(),a.end(),greater<int>());
		long long sum=0;
		for(int i=0;i<n;++i){
			if(i%2==0){
				sum+=a[i];
			}else{
				int plus = min(a[i-1]-a[i],k);
				k-=plus;
				sum-=min(a[i-1],a[i]+plus);
			}
		}
		cout<<sum<<"\n";
	}
}
