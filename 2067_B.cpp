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
        cnt.assign(2000,0);
        int minval=n,maxval=0;
        for(auto&x:a){
            cin>>x;
            cnt[x]++;
            maxval=max(maxval,x);
            minval=min(minval,x);
        }
        if(n&1){
            cout<<"No\n";continue;
        }
        bool can=true;
        for(int i=minval;i<=maxval;++i){
            if(cnt[i]==0)continue;
            if(cnt[i]==1){
                can=false;
            }
            cnt[i+1]+=cnt[i]-2;
        }
        cout<<(can?"Yes\n":"No\n");
    }
}