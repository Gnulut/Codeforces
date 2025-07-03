#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t,n,k;
	cin>>t;
	while(t--){
		cin>>n>>k;
		int st=n-k+1;
		if(st%2==0)++st;
		if(n%2==0)--n;
		int oddcnt=(n-st)/2+1;
		cout<<(oddcnt&1?"NO\n":"YES\n");
	}
	
}
