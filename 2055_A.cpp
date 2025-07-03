#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cout.tie(0);
	int t,n,a,b;
	cin>>t;
	while(t--){
		cin>>n>>a>>b;
		bool can = abs(a-b)%2==0;
		cout<<(can?"YES\n":"NO\n");
	}
}
