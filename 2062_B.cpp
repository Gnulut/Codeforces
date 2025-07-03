#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int popcnt(int x) { return __builtin_popcount(x); };
int popcnt(ll x) { return __builtin_popcountll(x); };
 
int topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
 
int lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }


int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    //cout.tie(0);
    int t,n;
    vector<int> a;
    cin>>t;
    while(t--){
        cin>>n;
        a.resize(n);
        for(auto&x:a){
            cin>>x;
        }
        bool can=true;
        for(int i=0;i<n;++i){
            int l=i,r=n-i-1;
            can&=a[i]>=max(l*2+1,r*2+1);
            if(!can)break;
        }
        cout<<(can?"YES\n":"NO\n");
    }
}