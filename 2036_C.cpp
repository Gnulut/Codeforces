#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,q;
	string s;
	int qi,qv;
	cin>>t;
	while(t--){
		cin>>s>>q;
		set<int> beau;
		for(int i=0;i<s.length()-3;++i){
			if(s[i]=='1'&&s[i+1]=='1'&&s[i+2]=='0'&&s[i+3]=='0'){
				beau.insert(i);
				i+=3;
			}
		}
		while(q--){
			cin>>qi>>qv;
			qi--;
			char c='0'+qv;
			if(s[qi]!=c){
				for(int i=max(0,qi-3);i<=qi;++i){
					if(s[i]=='1'&&s[i+1]=='1'&&s[i+2]=='0'&&s[i+3]=='0'){
						beau.erase(i);
						break;
					}
				}
				s[qi]=c;
				for(int i=max(0,qi-3);i<=qi;++i){
					if(s[i]=='1'&&s[i+1]=='1'&&s[i+2]=='0'&&s[i+3]=='0'){
						beau.insert(i);
						break;
					}
				}
			}
			if(!beau.empty()){
				cout<<"YES\n";
			}else{
				cout<<"NO\n";
			}
		}
	}
}
