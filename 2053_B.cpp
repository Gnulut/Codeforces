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
    vector<pair<int,int>> v(n);
    vector<int> cnt(2*n+1), sum(2*n+1);
    for(auto&ii:v){
        cin>>ii.first>>ii.second;
        if(ii.first==ii.second){
            cnt[ii.first]++;//count
            sum[ii.first]=1;//availability
        }
    }
    for(int i=1;i<=2*n;++i){
        sum[i]+=sum[i-1];
    }
    for(auto&ii:v){
        bool can = true;
        if(ii.first==ii.second){
            can&=cnt[ii.first]==1;
        }else{
            can&=(sum[ii.second]-sum[ii.first-1])<ii.second-ii.first+1;
        }
        cout<<(can?'1':'0');
    }
    cout<<'\n';
}