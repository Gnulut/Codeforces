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
    map<int,int> cnt;
    for(int i=0,x;i<n;++i){
        cin>>x;
        cnt[x]++;
    }
    vector<pair<int,int>> a(cnt.begin(),cnt.end());
    int ans = 0;
    //for(auto&x:a)cout<<x.first<<" "<<x.second<<"\n";
    for(int i=0,j=0,nans=0;i<a.size();++i){
        if(i==0||a[i].first>a[i-1].first+1){
            nans=a[i].second;
            j=i;
        }else{ 
            nans+=a[i].second;
            while(j+k<=i){
                nans-=a[j].second;
                j++;
            }
        }
        ans=max(ans,nans);
    }
    cout<<ans<<"\n";
}