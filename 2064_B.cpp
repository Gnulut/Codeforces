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
    int t,n;
    vector<int> a,cnt;
    cin>>t;
    while(t--){
        cin>>n;
        a.resize(n);
        cnt.assign(n+1,0);
        for(auto&x:a){
            cin>>x;
            cnt[x]++;
        }
        int l=-1,r=-2;
        for(int li=0,ri=0;ri<n;++ri){
            if(cnt[a[ri]]==1){
                if(ri-li>r-l){
                    l=li,r=ri;
                }
            }else{
                li=ri+1;
            }
        }
        if(l!=-1)cout<<l+1<<" "<<r+1<<"\n";
        else cout<<"0\n";
    }
}