#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,n;
	vector<int> a;
	cin>>t;
	while(t--){
		cin>>n;
		a.resize(n);
		for(auto&x:a)cin>>x;
		if(n>2){
			cout<<"NO\n";
		}else{
			cout<<(a.back()-a.front()>1?"YES\n":"NO\n");
		}
	}
}
