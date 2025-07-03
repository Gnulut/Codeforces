#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int popcnt(int x) { return __builtin_popcount(x); };
int popcnt(ll x) { return __builtin_popcountll(x); };
 
int topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
 
int lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }

void setmax(int &a, int b){ a = max(a,b); }
void setmax(ll &a, ll b){ a = max(a,b); }

void setmin(int &a, int b){ a = min(a,b); }
void setmin(ll &a, ll b){ a = min(a,b); }

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


long long ans;
set<int> s2;
void generate_util(map<int,int>&prime_factors_count, map<int,int>::iterator it, long long cnum){
    if(it==prime_factors_count.end()){
        s2.insert(cnum);
        return;
    }
    auto it2=next(it);
    for(int i=0;i<=it->second;++i){
        generate_util(prime_factors_count, it2, cnum);
        cnum*=it->first;
    }
}

void generate(map<int,int>&prime_factors_count){
    s2.clear();
    generate_util(prime_factors_count, prime_factors_count.begin(), 1);
    s2.erase(1);
    if(prime_factors_count.size()==1){
        ans = ans*(prime_factors_count.begin()->first);
    }
    s2.erase(ans);
}


//int main(){
void solve(){
    int n;
    cin>>n;
    set<int> s;
    vector<int> a(n);for(auto&x:a)cin>>x, s.insert(x);
    sort(a.begin(),a.end());
    ans = 1;
    for(auto&x:a){
        ans = lcm(ans,x);
        if(ans>1e12){
            cout<<"-1\n";
            return;
        }
    }
    map<int,int> prime_factors_count;
    for(auto x:a){
        for(int i=2;i*i<=x;++i){
            if(x%i==0){
                int cnt=0;
                while(x%i==0){
                    x/=i;
                    cnt++;
                }
                setmax(prime_factors_count[i], cnt);
            }
            
        }
        if(x!=1){
            setmax(prime_factors_count[x], 1);
        }
    }
    generate(prime_factors_count);
    //for(auto&x:s2)cout<<x<<" ";cout<<"\n";
    if(s==s2){
        cout<<ans<<"\n";
    }else{
        cout<<"-1\n";
    }
}