#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,l,r;
	cin>>t;
	while(t--){
		cin>>l>>r;
		int ans=0,dif=1;
		while(l<=r){
			++ans;
			l+=dif++;
		}
		cout<<ans<<"\n";
	}
}
