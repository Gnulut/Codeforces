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

const int nmax = 2.1e5;
const long long mod = 1e9+7;
long long comb[nmax]={};
void precompute(){
    comb[2]=1;
    for(int i=3;i<nmax;++i){
        comb[i] = comb[i-1]*i%mod*modexp(i-2, mod-2, mod)%mod;
    }
}

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto&x:a){
        cin>>x;
    }
    int cnt[32]={};
    for(long long i=0;i<31;i++){
        for(auto&x:a){
            if(x&(1ll<<i)){
                cnt[i]++;
            }
        }
    }
    vector<bool> can(n,true);
    for(long long i=0;i<32;++i){
        if(cnt[i]!=0&&cnt[i]!=n){
            for(int j=0;j<n;++j){
                if(a[j]&(1ll<<i)){
                    can[j]=false;
                }
            }
        }
        //for(auto&x:a){cout<<can[i];}cout<<"\n";
    }
    int cntcan = 0;
    for(int i=0;i<n;++i){
        cntcan+=can[i];
    }
    if(cntcan<2){
        cout<<"0\n";
    }else{
        long long ans = 2*comb[cntcan];
        for(long long i=1;i<=n-2;++i){
            ans=ans*i%mod;
        }
        cout<<ans<<"\n";
    }
}