#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,n,m;
	cin>>t;
	while(t--){
		cin>>n>>m;
		int ans=0;
		string s;
		while(n--){
			cin>>s;
			m-=s.length();
			ans+=m>=0;
		}
		cout<<ans<<"\n";
	}
}
