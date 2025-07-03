#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int t,n;
	string s;
	cin>>t;
	while(t--){
		cin>>s;
		n=s.length();
		for(int i=1;i<n;++i){
			if(s[i]==s[i-1]){
				n=1;
				break;
			}
		}
		cout<<n<<"\n";
	}
}
