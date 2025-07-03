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

pair<int, long long> observe(int n,int k){
    if(n<k)return {0,0};
    int m = (n+1)/2;
    pair<int, long long> cnt_sum = observe(m-(n&1),k);
    cnt_sum.second += cnt_sum.second + (long long)cnt_sum.first * m;
    cnt_sum.first *= 2;
    if(n&1){
        cnt_sum.first += 1;
        cnt_sum.second += m;
    }
    return cnt_sum;
}

void solve(){
    int n,k;
    cin>>n>>k;
    cout<<observe(n,k).second<<"\n";
}