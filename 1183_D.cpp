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
    vector<int> cnt(n+1);
    for(int i=0,x;i<n;++i){
        cin>>x;
        cnt[x]++;
    }
    vector<int> vals;
    for(int i=1;i<=n;++i){
        if(cnt[i]){
            vals.push_back(cnt[i]);
        }
    }
    sort(vals.begin(),vals.end());
    int ans = 0, mx = n;
    for(int i=vals.size()-1;mx>0&&i>=0;--i){
        int get = min(mx,vals[i]);
        ans+=get;
        mx=get-1;
    }
    cout<<ans<<"\n";
}