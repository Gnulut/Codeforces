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
    int t,x,y;
    cin>>t;
    while(t--){
        cin>>x>>y;
        if(y>x+1){
            cout<<"No\n";
        }else{
            int dif = ((y-x)%9+9)%9;
            // cout<<dif<<"\n";
            if(dif==1){
                cout<<"Yes\n";
            }else{
                cout<<"No\n";
            }
        }
    }
}