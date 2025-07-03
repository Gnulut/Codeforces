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
    //cout.tie(0);B
    int t,k;
    cin>>t;
    while(t--){
        cin>>k;
        map<int,int> cnt;
        for(int i=0,x;i<k;++i){
            cin>>x;
            cnt[x]++;
        }
        k-=2;
        for(int i=1;;++i){
            if(k%i)continue;
            auto ita=cnt.find(i), itb=cnt.find(k/i);
            if(ita!=cnt.end()&&itb!=cnt.end()&&(ita!=itb||ita->second>=2)){
                cout<<i<<" "<<k/i<<"\n";
                break;
            }
        }
    }
}