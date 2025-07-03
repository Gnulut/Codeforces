#include<bits/stdc++.h>
using namespace std;

long long modexp(long long b,long long e,long long m){
	long long r=1;
	while(e){
		if(e&1)r=r*b%m;
		b=b*b%m;
		e>>=1;
	}
	return r;
}

int main(){
	const int mod = 1000*1000*1000+7;
	int t,n;
	vector<int> a;
	cin>>t;
	while(t--){
		cin>>n;
		a.resize(n);
		for(auto&ai:a)cin>>ai;
		int pf_sum=0,P=0,Q=modexp((long long)n*(n-1)/2%mod,mod-2,mod);
		for(auto&ai:a){
			P=(P+(long long)ai*pf_sum%mod)%mod;
			pf_sum=(pf_sum+ai)%mod;
		}
		int ans = (long long)P*Q%mod;
		cout<<ans<<"\n";
	}
}
