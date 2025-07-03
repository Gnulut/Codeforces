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
        cin>>n;
        vector<int> a;
        for(int i=0,x;i<n;++i){
            cin>>x;
            if(x||!a.empty()){
                a.push_back(x);
            }
        }
        while(!a.empty()&&a.back()==0)a.pop_back();
        if(a.empty()){
            cout<<"0\n";
            continue;
        }
        int ans=1;
        for(auto&x:a){
            if(x==0){
                ans=2;
                //break;
            }
        }
        cout<<ans<<"\n";
    }
}