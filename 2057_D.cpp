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
        int n,q;
        cin>>n>>q;
        vector<int> a(n);
        set<pair<int,int>> s;//val,pos
        for(int i=0;i<n;++i){
            int&x=a[i];
            cin>>x;
            s.insert({x,i});
        }
        cout<<(prev(s.end())->first - s.begin()->first) - abs(prev(s.end())->second-s.begin()->second)<<" ";
        while(q--){
            int pos,val;
            cin>>pos>>val;
            pos--;
            s.erase({a[pos],pos});
            a[pos]=val;
            s.insert({a[pos],pos});
            cout<<(prev(s.end())->first - s.begin()->first) - abs(prev(s.end())->second-s.begin()->second)<<" ";
        }
        cout<<"\n";
    }
}