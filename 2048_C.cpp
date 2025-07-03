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
    string s;
    cin>>t;
    while(t--){
        cin>>s;
        int cnt[2]={};
        for(auto&c:s){
            cnt[c&1]++;
        }
        if(cnt[0]==0){
            cout<<"1 1 1 "<<s.length()<<"\n";
            continue;
        }
        int len = 0;
        for(int i=0;i<s.length();++i){
            if(s[i]=='0'){
                len=s.length()-i;
                break;
            }
        }
        string ans = "";
        int ansi=0;
        for(int i=0;i<=s.length()-len;++i){
            string s2 = string(s.begin()+i,s.begin()+i+len);
            string s3 = s;
            for(int j2=s2.length()-1,j3=s3.length()-1;j2>=0;j2--,j3--){
                s3[j3]^=s2[j2]&1;
            }
            if(s3>ans){
                ansi=i;
                ans=s3;
            }
        }
        cout<<ansi+1<<" "<<ansi+len<<" 1 "<<s.length()<<"\n";
    }
}