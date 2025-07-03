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
    int t,n,k;
    vector<int> a;
    cin>>t;
    while(t--){
        cin>>n>>k;
        a.assign(n,0);
        int val=1,opt=k-1;
        while(true){
            if(opt>=n)break;
            a[opt]=val++;
            opt+=k;
            
        }
        for(auto&x:a){
            if(x==0){
                x=val++;
            }
            cout<<x<<" ";
        }
        cout<<"\n";
    }
}