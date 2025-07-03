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
        exp >>= 1;
    }
    return result;
}

void solve();
void precompute();

//*
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

vector<int> is_prime(1.01e5,1);
void precompute(){
    is_prime[0]=is_prime[1]=false;
    for(int i=0;i<400;++i){
        if(is_prime[i]){
            for(int j=i*i;j<is_prime.size();j+=i){
                is_prime[j]=false;
            }
        }
    }
}

//int main(){
void solve(){
    int n,r;
    cin>>n>>r;r*=2;
    int alone=0,happy=0;
    for(int i=0,x;i<n;++i){
        cin>>x;
        alone+=x&1;
        x-=x&1;
        happy+=x;
        r-=x;
    }
    int seats = r/2;
    if(seats>=alone){
        happy+=alone;
    }else{
        happy+= seats - (alone-seats);
    }
    cout<<happy<<"\n";
}