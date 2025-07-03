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
    int n,a,b;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    int posx=0,posy=0;
    for(int i=0;i<500;++i){
        for(auto&c:s){
            if(c=='N')posy++;
            else if(c=='S')posy--;
            else if(c=='E')posx++;
            else if(c=='W')posx--;
            if(posx==a&&posy==b){
                cout<<"YES\n";
                return;
            }
        }
    }
    cout<<"NO\n";
}