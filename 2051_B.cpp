#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,n,a[3];
	cin>>t;
	while(t--){
		cin>>n;
		int total=0;
		for(auto&ai:a){
			cin>>ai;
			total+=ai;
		}
		int ans = n/total*3;
		n%=total;
		for(auto&ai:a){
			if(n<=0)break;
			n-=ai;
			ans++;
		}
		cout<<ans<<"\n";
	}
}
