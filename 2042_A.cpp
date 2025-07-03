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

#define vin(a,n) vector<int> a(n);for(auto&x:a)cin>>x;
void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int cnt[2]={};
    for(auto&c:s){
        cnt[c=='1']++;
    }
    if(0[cnt]>1[cnt])swap(0[cnt],1[cnt]);
    int mn = (1[cnt]-0[cnt])/2;
    int mx = 1[cnt]/2+0[cnt]/2;
    cout<<(mn<=k&&k<=mx&&(mn+k)%2==0?"YES":"NO")<<"\n";
}