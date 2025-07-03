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
    int ans=0, nx=1, nr=2;
    for(auto&x:a){
        nx-=x;
        while(nx<0){
            nx+=nr*4;
            nr+=2;
        }
        if(nx==0){
            ans++;
            nx+=nr*4;
            nr+=2;
        }
    }
    cout<<ans<<"\n";
}