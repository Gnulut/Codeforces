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
    int n;
    string g[2];
    cin>>n>>g[0]>>g[1];
    string ans = string(1,g[0][0]);
    bool bottom = false;
    for(int i=1;i<n;++i){
        if(!bottom){
            if(g[0][i]!=g[1][i-1]){
                int idx = g[1][i-1]=='0';
                bottom = idx==1;
            }
        }
        if(bottom){
            ans+=g[1][i-1];
        }else{
            ans+=g[0][i];
        }
    }
    ans+=g[1][n-1];
    vector<vector<int>> cnt(2, vector<int>(n, 0));
    cnt[0][0]=1;
    for(int i=0;i<n;++i){
        if(i+1<n&&g[0][i+1]==ans[i+1]){
            cnt[0][i+1]+=cnt[0][i];
        }
        if(g[1][i]==ans[i+1]){
            cnt[1][i]+=cnt[0][i];
        }
    }
    for(int i=0;i<n-1;++i){
        if(g[1][i+1]==ans[i+2]){
            cnt[1][i+1]+=cnt[1][i];
        }
    }
    cout<<ans<<"\n"<<cnt[1][n-1]<<"\n";
}