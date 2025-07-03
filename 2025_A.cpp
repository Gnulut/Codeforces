#include<bits/stdc++.h>
using namespace std;

int main(){
	int x;
	string s,t;
	cin>>x;
	while(x--){
		cin>>s>>t;
		int ans=s.size()+t.size();
		int same=0;
		for(int i=0;i<s.size()&&i<t.size();++i){
			if(s[i]!=t[i]){
				break;
			}
			same=i;
		}
		ans-=same;
		cout<<ans<<endl;
	}
}
