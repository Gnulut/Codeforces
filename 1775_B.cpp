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

vector<int> cnt(2.01e5);
void solve(){
    int n;
    cin>>n;
    vector<vector<int>> a(n);
    for(auto&x:a){
        int m;
        cin>>m;
        x.resize(m);
        for(auto&y:x){
            cin>>y;
            cnt[y]++;
        }
    }
    bool can = false;
    for(auto&x:a){
        bool can2=true;
        for(auto&y:x){
            if(cnt[y]==1){
                can2=false;
                break;
            }
        }
        if(can2){
            can=true;
        }
    }
    for(auto&x:a)for(auto&y:x)cnt[y]--;
    cout<<(can?"YES\n":"No\n");
}