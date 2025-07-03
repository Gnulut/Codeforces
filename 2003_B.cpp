#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,n;
	vector<int> a;
	cin>>t;
	while(t--){
		cin>>n;
		a.resize(n);
		for(auto&ai:a)cin>>ai;
		sort(a.begin(),a.end());
		cout<<a[n/2]<<"\n";
	}
}
