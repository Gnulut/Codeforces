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
    int n;
    string s;
    cin>>n>>s;
    int size = n-1;
    int ans = 1000;
    for(int i=0;i<size;++i){
        vector<int> vals(size);
        int mn = 1000,sum=0;
        for(int j=0;j<n;++j){
            if(j<i){
                vals[j]=s[j]-'0';
            }else if(j==i){
                vals[j]=10*(s[j]-'0')+(s[j+1]-'0');
                j++;
            }else{
                vals[j-1]=s[j]-'0';
            }
            int idx = j-(j>i);
            mn = min(mn,vals[idx]);
            sum+=vals[idx] - (vals[idx]==1);
        }
        if(mn<=0){
            ans=0;
            break;
        }
        ans=min(ans,max(sum,1));
    }
    cout<<ans<<"\n";
}