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
    int n;cin>>n;
    vin(a,n);
    sort(a.begin(),a.end());
    int ans=0,t=0;
    for(int i=0;i<n;++i){
        if((i==0||a[i-1]!=a[i])&&(i==n-1||a[i]!=a[i+1])){
            if(t==0){
                ans+=2;
            }
            t^=1;
        }else if(i==0||a[i-1]!=a[i]){
            ++ans;
        }
    }
    cout<<ans<<'\n';
}