#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int t;
	string s;
	cin>>t;
	while(t--){
		cin>>s;
		s.pop_back();
		s.pop_back();
		s.push_back('i');
		cout<<s<<"\n";
	}
}
