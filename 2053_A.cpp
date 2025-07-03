#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int popcnt(int x) { return __builtin_popcount(x); };
int popcnt(ll x) { return __builtin_popcountll(x); };
 
int topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
 
int lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }

void solve();

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    //cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto&x:a){
        cin>>x;
    }
    bool can=false;
    for(int i=1;i<n;++i){
        int mn = min(a[i],a[i-1]);
        int mx = max(a[i],a[i-1]);

        if(mn*2>mx){
            can=true;
            break;
        }
    }
    cout<<(can?"YES\n":"NO\n");
}