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
    vector<long long> a(n),b(n);
    for(auto&x:a)cin>>x;
    for(auto&x:b)cin>>x;

    long long ans = 0;
    for(int i=0;i<n;++i){
        ans+=a[i]*b[i];
    }
    long long maxadd = 0;
    for(int i=0;i<n;++i){
        {// odd
            long long add = 0;
            for(int l=i-1,r=i+1;l>=0&&r<n;--l,++r){
                add += (a[l]*b[r] + a[r]*b[l]) - (a[l]*b[l] + a[r]*b[r]);
                maxadd = max(maxadd,add);
            }
        }
        {// even
            long long add = 0;
            for(int l=i,r=i+1;l>=0&&r<n;--l,++r){
                add += (a[l]*b[r] + a[r]*b[l]) - (a[l]*b[l] + a[r]*b[r]);
                maxadd = max(maxadd,add);
            }
        }
    }
    ans += maxadd;
    cout<<ans<<"\n";
}