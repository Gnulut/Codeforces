#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,a,b;
	cin>>t;
	while(t--){
		cin>>a>>b;
		if(a>=b){
			cout<<a<<"\n";
			continue;
		}
		int dif = b-a;
		if(a<=dif){
			cout<<"0\n";
			continue;
		}
		cout<<a-dif<<"\n";
	}
}
