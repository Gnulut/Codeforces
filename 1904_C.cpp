#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

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
    int n,k;
    cin>>n>>k;
    vector<long long> a(n);
    for(auto&x:a)cin>>x;
    if(k>2){
        cout<<"0\n";
        return;
    }
    sort(a.begin(),a.end());
    long long mn = a.front();
    for(int i=1;mn&&i<n;++i){
        long long dif = a[i]-a[i-1];
        mn=min(mn,dif);
    }
    if(k==2){
        for(int i=0;mn&&i<n;++i){
            for(int j=i+1;mn&&j<n;++j){
                long long dif = a[j]-a[i];
                auto it = lower_bound(a.begin(),a.end(),dif);
                if(it!=a.end()){
                    mn=min(mn,(*it-dif));
                }
                if(it!=a.begin()){
                    mn=min(mn,dif-*(it-1));
                }
            }
        }
    }
    cout<<mn<<"\n";
}