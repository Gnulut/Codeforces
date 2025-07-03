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

/* remove or add one "/" to disable or enable this main
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

void precompute(){
    
}

int main(){ ios::sync_with_stdio(0);cin.tie(0);//cout.tie(0);
// void solve(){
    int n;
    cin>>n;
    long long p=1,cnt=0;
    for(int i=1;i<=n;++i){
        if(gcd(i,n)==1){
            p=p*i%n;
            ++cnt;
        }
    }
    if(p==1){
        p=0;
    }else{
        cnt--;
    }
    cout<<cnt<<"\n";
    for(int i=1;i<n;++i){
        if(p&&i==p)continue;
        if(gcd(i,n)==1)cout<<i<<" ";
    }
    cout<<"\n";
}