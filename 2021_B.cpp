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
    int n,x;
    cin>>n>>x;
    vector<int> freq(n);
    for(int i=0;i<n;++i){
        int val;
        cin>>val;
        if(val<n)freq[val]++;
    }
    int ans=0;
    for(int i=0;i<n;++i){
        if(freq[i]==0)break;
        if(i+x<n)freq[i+x]+=freq[i]-1;
        ++ans;
    }
    cout<<ans<<'\n';
}