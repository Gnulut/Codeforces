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

//* remove or add one "/" to disable or enable this main
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

// int main(){ ios::sync_with_stdio(0);cin.tie(0);//cout.tie(0);
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto&x:a){
        cin>>x;
    }
    sort(a.begin(),a.end());
    int l=0,r=n-1;
    long long ans = 0, x=0;
    while(l<r){
        int mn = min((long long)a[l], a[r]-x);
        ans+=mn;
        x+=mn;
        a[l]-=mn;
        if(a[l]==0)l++;
        if(x==a[r]){
            ans++;
            a[r]=0;
            x=0;
            r--;
        }
    }
    if(l==r){
        int leftover = a[l]-x;
        ans+=(leftover+1)/2;
        x+=leftover/2;
    }
    if(x)++ans;
    cout<<ans<<"\n";
}