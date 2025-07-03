#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int popcnt(int x) { return __builtin_popcount(x); };
int popcnt(ll x) { return __builtin_popcountll(x); };
 
int topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
 
int lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }

bool has(ll n){
    while(n){
        if(n%10==7){
            return true;
        }
        n/=10;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    //cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ans=100;
        if(has(n)){
            cout<<"0\n";
            continue;
        }
        for(ll i=0,cval=0;i<11;++i){
            cval = cval*10+9;
            for(ll j=1,nval=n;j<11;++j){
                nval+=cval;
                if(has(nval)){
                    ans=min((ll)ans,j);
                    break;
                }
            }
        }
        cout<<ans<<"\n";
    }
}

/*
https://codeforces.com/contest/2067/submission/305717149
#include <bits/stdc++.h>
    
using namespace std;    
    
void solve() {
    int n;
    cin >> n;
    for (int l = 0; l <= 9; l++) {
        string s = to_string(n - l);
        int md = 0;
        for (auto c: s) {
            if (c <= '7') {
                md = max(md, c - '0');
            }
        }
        if (l >= 7 - md) {
            cout << l << '\n';
            return;
        }
    }
}
    
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
*/