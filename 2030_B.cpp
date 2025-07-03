#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		cout<<0;
		--n;
		if(n--){
			cout<<1;
			if(n>0){
				cout<<string(n,'0');
			}
		}
		cout<<"\n";
	}
}
