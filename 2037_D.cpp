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
    int t,n,m,L;
    cin>>t;
    while(t--){
        cin>>n>>m>>L;
        queue<pair<int,int>> q;
        for(int i=0,l,r;i<n;++i){
            cin>>l>>r;
            q.push({l,r-l+2});
        }
        vector<pair<int,int>> pu;
        for(int i=0;i<m;++i){
            int x,val;
            cin>>x>>val;
            pu.push_back({x,val});
        }
        int ans=0,cpower=1;
        priority_queue<int> avpu;
        auto itpu = pu.begin();
        while(!q.empty()){
            int npos=q.front().first,req_power=q.front().second;q.pop();
            while(itpu!=pu.end()&&itpu->first<npos){
                avpu.push(itpu->second);
                itpu++;
            }
            while(cpower<req_power&&!avpu.empty()){
                cpower+=avpu.top();avpu.pop();
                ++ans;
            }
            if(cpower<req_power){
                ans=-1;
                break;
            }
        }
        cout<<ans<<"\n";
    }
}