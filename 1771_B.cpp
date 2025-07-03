#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int popcnt(int x) { return __builtin_popcount(x); };
int popcnt(ll x) { return __builtin_popcountll(x); };
 
int topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
 
int lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }

long long modexp(long long base, long long exp, long long mod){
    long long result = 1;
    while(exp){
        if(exp&1){
            result = result*base%mod;
        }
        base = base*base%mod;
        exp>>=1;
    }
    return result;
}

void solve();
void precompute();

int main(){
    ios::sync_with_stdio(0);cin.tie(0);//cout.tie(0);
    // precompute
    precompute();
    // end of precompute
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}

void precompute(){
    
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> a(m);
    for(auto&ii:a){
        cin>>ii.first>>ii.second;
        int mx = max(ii.first,ii.second);
        int mn = min(ii.second,ii.first);
        ii.first = mx;
        ii.second = mn;
    }
    sort(a.begin(),a.end());
    auto ait = a.begin();
    long long ans = 0;
    for(int i=1,l=1;i<=n;++i){
        while(ait<a.end()&&ait->first==i){
            l = max(l,ait->second+1);
            ++ait;
        }
        ans += i-l+1;
    }
    cout<<ans<<"\n";
}