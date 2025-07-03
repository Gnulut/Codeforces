#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,a,b;
	cin>>t;
	while(t--){
		cin>>a>>b;
		if((a+2*b)&1){
			cout<<"NO\n";
		}else if(a==0&&b&1){
			cout<<"NO\n";
		}else{
			cout<<"YES\n";
		}
	}
}
