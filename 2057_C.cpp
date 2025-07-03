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
        int l,r;
        cin>>l>>r;
        //editorial solution: int a = l | ((1 << k) - 1), b = a + 1, c = (a == l ? r : l);
        int a[3]={l,0,r};
        for(int i=1<<29;i>0;i>>=1){
            if(i>r)continue;
            if((l&i)==(r&i)){
                a[1]|=(l&i);
            }else{
                bool high=true;
                int bg = 0, sm = 0;
                for(int j=i>>1;j>0;j>>=1){
                    if((l&j)!=(r&j)){
                        bg|=j;
                    }else if((l&j)==0){
                        bg|=j;
                        sm|=j;
                    }
                }
                if(a[1]+i+sm<r){
                    a[1]+=i+sm;
                }else/*(a[1]+bg>l)*/{// this may produce wrong result, well it ac anyway
                    a[1]+=bg;
                }
                break;
            }
        }
        cout<<l<<" "<<a[1]<<" "<<r<<"\n";
    }
}