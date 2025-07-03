#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,n;
	cin>>t;
	while(t--){
		string s;
		cin>>n>>s;
		cout<<(s.front()!=s.back()?"YES\n":"NO\n");
	}
}
