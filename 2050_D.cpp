#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	string s;
	cin>>t;
	while(t--){
		cin>>s;
		for(int i=0;i<s.length();++i){
			int best_idx=i,need=s[i]+2;
			for(int j=i+1;j<s.length()&&need<='9';++j){
				if(s[j]>=need){
					best_idx=j;
					need=s[j]+2;
				}else{
					need++;
				}
			}
			if(best_idx==i)continue;
			int dif = best_idx-i;char nval = s[best_idx]-dif;
			for(int j=best_idx-1;j>=i;--j){
				s[j+1]=s[j];
			}
			s[i]=nval;
		}
		cout<<s<<"\n";
	}
}
