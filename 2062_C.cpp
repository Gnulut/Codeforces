#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int popcnt(int x) { return __builtin_popcount(x); };
int popcnt(ll x) { return __builtin_popcountll(x); };
 
int topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
 
int lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }

void op(vector<ll>&a){
    for(int i=0;i<a.size()-1;++i){
        a[i]=a[i+1]-a[i];
    }
    a.pop_back();
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    //cout.tie(0);
    int t,n;
    vector<ll> a;
    cin>>t;
    while(t--){
        cin>>n;
        a.resize(n);
        for(auto&x:a){
            cin>>x;
        }
        ll ans=accumulate(a.begin(),a.end(),0ll);
        while(a.size()>1){
            op(a);
            ans=max(ans,abs(accumulate(a.begin(),a.end(),0ll)));
        }
        cout<<ans<<"\n";
    }
}