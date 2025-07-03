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
    int n;
    cin>>n;
    vector<pair<int,int>> a(n);
    for(auto&ii:a){
        cin>>ii.first>>ii.second;
    }
    int ansl=0,ansr=1e9;
    while(ansl<ansr){
        int ansm = (ansl+ansr)/2;
        int l=0,r=0;
        for(auto&ii:a){
            l-=ansm,r+=ansm;
            l=max(l,ii.first);
            r=min(r,ii.second);
            if(l>r)break;
        }
        if(l>r){
            ansl=ansm+1;
        }else{
            ansr=ansm;
        }
    }
    cout<<ansr<<"\n";
}