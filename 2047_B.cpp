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
    string s;
    cin>>n>>s;
    int cnt[26]={};
    for(auto&c:s){
        cnt[c-'a']++;
    }
    int mn = 20, mx = 0;
    for(int i=0;i<26;++i){
        if(cnt[i])mn = min(mn,cnt[i]);
        mx = max(mx,cnt[i]);
    }
    
    int chmn, chmx;
    for(int i=0;i<26;++i){
        if(cnt[i]==mn){
            chmn=i;
            break;
        }
    }
    for(int i=26-1;i>=0;--i){
        if(cnt[i]==mx){
            chmx=i;
            break;
        }
    }
    for(auto&c:s){
        if(c==chmn+'a'){
            c=chmx+'a';
            break;
        }
    }
    cout<<s<<"\n";
}