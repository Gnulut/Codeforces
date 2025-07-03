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
    cin>>t;
    while(t--){
        cin>>n>>k;
        map<int,int> m;
        for(int i=0,x;i<n;++i){
            cin>>x;
            m[x]++;
        }
        vector<int> a;
        for(auto&ii:m){
            a.push_back(ii.second);
        }
        sort(a.begin(),a.end());
        int ans=a.size();
        for(int i=0;i<a.size()-1;i++){
            if(a[i]>k)break;
            k-=a[i];
            --ans;
        }
        cout<<ans<<'\n';
    }
}