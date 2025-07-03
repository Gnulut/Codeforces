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
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<int> a(n);
        for(auto&x:a){
            cin>>x;
        }
        bool can=false;
        for(int i=0;i<n;++i){
            if(a[i]==-1)continue;
            bool fnd=false;
            for(int j=i+1;j<n;++j){
                if(a[j]==-1)continue;
                if(abs(a[i]-a[j])%k==0){
                    fnd=true;
                    a[j]=-1;
                }
            }
            if(fnd){
                a[i]=-1;
            }else{
                can=true;
                cout<<"YES\n"<<i+1<<"\n";
                break;
            }
        }
        if(!can){
            cout<<"NO\n";
        }
    }
}