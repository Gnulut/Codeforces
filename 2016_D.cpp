#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int si32_inf = 2147483647;

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

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n),b(m);
    for(auto&x:a)cin>>x;
    for(auto&x:b)cin>>x;
    vector<int> l(m+1);l[0]=-1;
    for(int i=0,ai=0;i<m;++i,++ai){
        while(ai<n){
            if(a[ai]>=b[i]){
                l[i+1]=ai;
                break;
            }
            ++ai;
        }
        if(ai>=n){
            l[i+1]=n;
        }
    }
    if(l.back()<n){
        // for(auto&x:l){cout<<x<<" ";}cout<<"\n";
        cout<<"0\n";
        return;
    }
    vector<int> r(m+1);r.back()=n;
    for(int i=m-1,ai=n-1;i>=0;--i,--ai){
        while(ai>-1){
            if(a[ai]>=b[i]){
                r[i]=ai;
                break;
            }
            --ai;
        }
        if(ai<=-1){
            r[i]=-1;
        }
    }
    int ans=si32_inf;
    for(int i=0;i<m;++i){
        if(l[i]<r[i+1]){
            ans=min(ans,b[i]);
        }
    }
    // for(auto&x:l){cout<<x<<" ";}cout<<"\n";
    // for(auto&x:r){cout<<x<<" ";}cout<<"\n";
    if(ans==si32_inf)ans=-1;
    cout<<ans<<"\n";
}