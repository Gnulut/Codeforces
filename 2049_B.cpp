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
    int t;
    cin>>t;
    while(t--){
        int n;
        string s;
        cin>>n>>s;
        bool can=true;
        if(s[0]=='s')s[0]='.';
        if(s[n-1]=='p')s[n-1]='.';
        char c='.';
        for(auto&x:s){
            if(x!='.'){
                if(x!=c){
                    if(c=='.'){
                        c=x;
                    }else{
                        can=false;
                        break;
                    }
                }
            }
        }
        cout<<(can?"YES\n":"NO\n");
    }
}