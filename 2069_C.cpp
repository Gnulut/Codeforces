#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	ll msize=2.1e5;
	ll pow2[msize]={};
	pow2[0]=1;
	for(ll i=1;i<msize;++i){
		pow2[i]= (pow2[i-1]*2)%mod;
	}
	ll t,n;
	vector<ll> a;
	cin>>t;
	while(t--){
		cin>>n;
		a.resize(n);
		for(auto&x:a){
			cin>>x;
		}
		vector<ll> ones,threes;
		ll cnt=0;
		for(auto&x:a){
			if(x==2)++cnt;
			else if(x==3){
				threes.push_back(cnt);
			}else if(x==1){
				ones.push_back(cnt);
			}
		}
		if(ones.empty()||threes.empty()||ones.size()+threes.size()==n){
			cout<<"0\n";
			continue;
		}
//		cout<<"ones: ";for(auto&x:ones)cout<<x<<" ";cout<<endl;
//		cout<<"threes: ";for(auto&x:threes)cout<<x<<" ";cout<<endl;
		while(!ones.empty()&&ones.back()>=threes.back()){
			ones.pop_back();
		}
		if(ones.empty()){
			cout<<"0\n";
			continue;
		}
		ll three_idx = threes.size()-1;
		ll ans=0,adder=0;
		ll total_ones_dif = 0;
		for(ll ones_idx = ones.size()-1;ones_idx>=0;ones_idx--){
			if(ones_idx!=ones.size()-1){
				ll ones_dif = ones[ones_idx+1]-ones[ones_idx];
				for(ll i=1;i<=ones_dif;++i){
					adder = (adder*2+1)%mod;
				}
			}
			while(three_idx>=0&&threes[three_idx]-ones[ones_idx]>0){
				ll val = threes[three_idx]-ones[ones_idx];
				adder = ((adder+(pow2[val]-1))%mod+mod)%mod;
				--three_idx;
			}
			ans = (ans+adder)%mod;
		}
		while(ans<0)ans+=mod;
		cout<<ans%mod<<"\n";
	}
}
