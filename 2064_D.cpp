#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int popcnt(int x) { return __builtin_popcount(x); };
int popcnt(ll x) { return __builtin_popcountll(x); };
 
int topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
 
int lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }

const int maxn = 2.01e5;
const int maxbit = 32;
int next_mb[maxn][maxbit];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    //cout.tie(0);
    int t,n,q;
    vector<int> a;
    cin>>t;
    while(t--){
        cin>>n>>q;
        a.resize(n);
        for(auto&x:a){
            cin>>x;
        }
        a.push_back(0);
        reverse(a.begin(),a.end());
        for(int i=0;i<maxbit;++i){
            next_mb[n+1][i]=n+1;
        }
        for(int i=n;i>=0;--i){
            for(int j=0;j<maxbit;++j){
                next_mb[i][j]=next_mb[i+1][j];
            }
            int tb = topbit(a[i]);
            for(int j=0;j<=tb;++j){
                next_mb[i][j]=i;
            }
        }
        // for(int i=0;i<10;++i){
        //     for(int j=0;j<=n;++j){
        //         cout<<next_mb[j][i]<<" ";
        //     }
        //     cout<<"\n";
        // }
        for(int i=1;i<a.size();++i){
            a[i]^=a[i-1];
        }
        while(q--){
            int x;
            cin>>x;
            int cpos=0;
            while(true){
                int tb = topbit(x);
                int npos = next_mb[cpos+1][tb];
                // cout<<"x: "<<x<<" cpos: "<<cpos<<" npos: "<<npos<<" tb: "<<tb<<"\n";
                if(npos==n+1){
                    cpos=n;
                    break;
                }
                x^=(a[npos-1]^a[cpos]);
                cpos=npos-1;
                if(x>=(a[npos]^a[npos-1])){
                    x^=(a[npos]^a[npos-1]);
                    cpos++;
                    if(x==0)break;
                }else{
                    break;
                }
            }
            cout<<cpos<<" ";
        }
        cout<<"\n";
    }
}