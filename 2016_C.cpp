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
    int n,k;
    cin>>n>>k;
    vector<int> a(n),b(n);
    for(auto&x:a){
        cin>>x;
    }
    for(auto&x:b){
        cin>>x;
    }
    int value = -1;
    bool can=true;
    for(int i=0;i<n;++i){
        if(b[i]!=-1){
            int new_val = a[i]+b[i];
            if(value==-1){
                value=new_val;
            }else{
                if(value!=new_val){
                    can=false;
                    break;
                }
            }
        }else{

        }
    }
    if(!can){
        cout<<"0\n";
    }else if(value==-1){
        int ans = k+1 - (*max_element(a.begin(),a.end())-*min_element(a.begin(),a.end()));
        cout<<ans<<"\n";
    }else{
        int ans=1;
        for(int i=0;i<n;++i){
            if(b[i]!=-1)continue;
            int need = value-a[i];
            if(need>k||need<0){
                ans=0;
                break;
            }
        }
        cout<<ans<<"\n";
    }
}