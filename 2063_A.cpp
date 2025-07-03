#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,a,b;
	cin>>t;
	while(t--){
		cin>>a>>b;
		int ans = 0;
		if(a==1){
			ans++;
			a++;
			if(b==1)b++;
		}
		ans+=b-a;
		cout<<ans<<"\n";
	}
}
