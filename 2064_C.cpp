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
    // ios::sync_with_stdio(0);cin.tie(0);
    //cout.tie(0);
    int t,n;
    vector<ll> a;
    cin>>t;
    while(t--){
        cin>>n;
        ll ans = 0;
        a.clear();
        for(ll i=0,ai;i<n;++i){
            cin>>ai;
            if(a.empty()){
                if(ai>0){
                    ans+=ai;
                }else{
                    a.push_back(ai);
                }
            }else{
                ll align = (ai>0?1:-1)*(a.back()>0?1:-1);
                if(align<0){
                    a.push_back(ai);
                }else{
                    a.back()+=ai;
                }
            }
        }
        if(!a.empty()&&a.back()<0){
            ans+=-a.back();
            a.pop_back();
        }
        if(!a.empty()){
            ll extr_ans=0;
            ll minsum = 0;
            for(int i=0;i<a.size();i+=2){
                minsum-=a[i];
            }
            extr_ans=minsum;
            for(int i=1;i<a.size();i+=2){
                minsum+=a[i]+a[i-1];
                extr_ans=max(extr_ans,minsum);
            }
            ans+=extr_ans;
        }
        cout<<ans<<"\n";
    }
}