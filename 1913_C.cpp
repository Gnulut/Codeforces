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

// int main(){
//     ios::sync_with_stdio(0);cin.tie(0);//cout.tie(0);
//     // precompute
//     precompute();
//     // end of precompute
//     int t;
//     cin>>t;
//     while(t--){
//         solve();
//     }
// }

void precompute(){
    
}

int main(){
// void solve(){
    int m;
    cin>>m;
    int cnt[32]={};
    while(m--){
        int cmd, val;
        cin>>cmd>>val;
        if(cmd==1){
            cnt[val]++;
        }else{
            int req = 0;
            for(int i=30;i>=0;--i){
                req = req*2;
                if(val&(1<<i)){
                    req++;
                }
                int take = min(cnt[i], req);
                req-=take;
            }
            if(req==0){
                cout<<"YES\n";
            }else{
                cout<<"NO\n";
            }
        }
    }
}