#include<bits/stdc++.h>
using namespace std;

long long modexp(long long b,long long e,long long m){
	long long r=1;
	while(e){
		if(e&1){
			r=r*b%m;
		}
		b=b*b%m;
		e>>=1;
	}
	return r;
}

int main(){
	int t;
	vector<int> n,k;
	cin>>t;
	n.resize(t);
	for(auto&ni:n)cin>>ni;
	k.resize(t);
	for(auto&ki:k)cin>>ki;
	for(int i=0;i<t;++i){
		cout<<modexp(2,k[i],1000000007)<<endl;
	}
}
