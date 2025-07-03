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

// int main(){
//     ios::sync_with_stdio(0);cin.tie(0);//cout.tie(0);
//     int t;
//     cin>>t;
//     while(t--){
//         solve();
//     }
// }

int main(){
    ios::sync_with_stdio(0);cin.tie(0);//cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges(n+1);
    for(int i=0,u,v;i<m;++i){
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    vector<bool> vis(n+1);
    vis[1]=true;
    priority_queue<int, vector<int>, greater<int>> q;q.push(1);
    vector<int> ans;
    while(!q.empty()){
        int node = q.top();q.pop();
        ans.push_back(node);
        for(auto&node2:edges[node]){
            if(!vis[node2]){
                vis[node2]=true;
                q.push(node2);
            }
        }
    }
    for(auto&x:ans){
        cout<<x<<" ";
    }
    cout<<"\n";
}