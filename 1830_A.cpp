#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int popcnt(int x) { return __builtin_popcount(x); };
int popcnt(ll x) { return __builtin_popcountll(x); };
 
int topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
 
int lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }

long long modexp(long long base, long long exp, long long mod){
    long long result = 1;
    while(exp){
        if(exp&1){
            result = result*base%mod;
        }
        base = base*base%mod;
        exp>>=1;
    }
    return result;
}

void solve();
void precompute();

//* remove or add one "/" to disable or enable this main
int main(){
    ios::sync_with_stdio(0);cin.tie(0);//cout.tie(0);
    // precompute
    precompute();
    // end of precompute
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
//*/

void precompute(){
    
}

// int main(){ ios::sync_with_stdio(0);cin.tie(0);//cout.tie(0);
void solve(){
    int n;
    cin>>n;
    vector<vector<pair<int,int>>> enables(n+1);
    for(int i=1,u,v;i<n;++i){
        cin>>u>>v;
        enables[u].push_back({i,v});
        enables[v].push_back({i,u});
    }
    int ans = 0;
    vector<bool> drawn(n+1);
    drawn[1]=true;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq[2], *pnow=pq, *pnext=pq + 1;
    for(auto&x:enables[1]){
        pnow->push(x);
        drawn[x.second]=true;
    }
    while(!pnow->empty()){
        ++ans;
        while(!pnow->empty()){
            auto [idx, val] = pnow->top();pnow->pop();
            for(auto&[nidx, nval]:enables[val]){
                if(!drawn[nval]){
                    drawn[nval]=true;
                    if(nidx>idx){
                        pnow->push({nidx,nval});
                    }else{
                        pnext->push({nidx,nval});
                    }
                }
            }
        }
        swap(pnow,pnext);
    }
    cout<<ans<<"\n";
}