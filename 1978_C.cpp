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
    long long n,k;
    cin>>n>>k;
    if(k&1){
        cout<<"No\n";
        return;
    }
    long long mx = 0;
    for(int i=2;i<=n;++i){
        mx+=i^(i&1);
    }
    if(mx<k){
        cout<<"No\n";
        return;
    }
    vector<int> a(n);
    for(int i=0,val=n;k>0&&i<n;++i){
        int move_right = val-1;
        int self_before = n-val;
        int self_after = val-(i+1);
        int new_points = move_right + (self_after-self_before);
        if(new_points<=k){
            a[i]=val--;
            k-=new_points;
        }else{
            int move_right = (new_points-k)/2;
            //cout<<n<<"  "<<i+move_right<<endl;
            a[i+move_right]=val--;
            k=0;
        }
    }
    for(int i=0,val=1;i<n;++i){
        if(a[i]==0){
            a[i]=val++;
        }
    }
    cout<<"Yes\n";
    for(auto&x:a){
        cout<<x<<" ";
    }
    cout<<'\n';
}

/*
4 1 2 3
3 1 1 1
4 3 1 2
3 1 2 2

5 1 2 3 4
4 1 1 1 1

 0 = 0
 2 = 1 1
 4 = 2 0 2
 8 = 3 1 1 3
12 = 4 2 0 2 4
18 = 5 3 1 1 3 5
24 = 6 4 2 0 2 4 6
*/