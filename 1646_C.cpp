#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int popcnt(int x) { return __builtin_popcount(x); };
int popcnt(ll x) { return __builtin_popcountll(x); };
 
int topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
 
int lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }

void setmax(int &a, int b){ a = max(a,b); }
void setmax(ll &a, ll b){ a = max(a,b); }

void setmin(int &a, int b){ a = min(a,b); }
void setmin(ll &a, ll b){ a = min(a,b); }

long long modexp(long long base, long long exp, long long mod){
    long long result = 1;
    while(exp){
        if(exp&1){
            result = result*base%mod;
        }
        base = base*base%mod;
        exp >>= 1;
    }
    return result;
}

void solve();
void precompute();

//*
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
//*/

ll mx = 1000000ll*1000000ll;
vector<ll> facts;
void precompute(){
    facts.push_back(6);
    ll mult = 4;
    while(facts.back()*mult<=mx){
        facts.push_back(facts.back()*mult);
        mult++;
    }
}

//int main(){
void solve(){
    long long n;cin>>n;
    int ans = popcnt(n);
    for(int i=0;i<(1<<facts.size());++i){
        long long sum = 0;
        for(int j=0;j<facts.size();++j){
            if(i&(1<<j)){
                sum+=facts[j];
            }
        }
        if(sum>n)break;
        int new_ans = popcnt(i) + popcnt(n-sum);
        setmin(ans, new_ans);
    }
    cout<<ans<<"\n";
}