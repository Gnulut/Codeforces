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
    int t,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<int> a(n),b(m);
        for(auto&x:a){
            cin>>x;
        }
        for(auto&x:b){
            cin>>x;
        }
        sort(a.rbegin(),a.rend()-1);
        while(a.size()>1&&a.back()<=a.front())a.pop_back();
        for(auto&x:b){
            if(x<=a.front()){
                x=1.1e9;
            }
        }
        sort(b.rbegin(),b.rend());
        for(int ai=0,bi=0;bi<m;++bi){
            while(ai+1<a.size()&&a[ai+1]>=b[bi]){
                ai++;
            }
            b[bi]=ai;
        }
        for(int i=1;i<=m;++i){
            long long ans=m/i;
            for(int j=i-1;j<m;j+=i){
                ans+=b[j];
            }
            cout<<ans<<" ";
        }
        cout<<"\n";
    }
}