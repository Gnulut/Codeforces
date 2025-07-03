#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,x,y,k;
	cin>>t;
	while(t--){
		cin>>x>>y>>k;
		int mn = min(x,y);
		cout<<"0 0 "<<mn<<" "<<mn<<"\n";
		cout<<"0 "<<mn<<" "<<mn<<" 0\n";
	}
}
