#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,n;
	vector<int> a;
	cin>>t;
	while(t--){
		cin>>n;
		a.resize(n);
		for(auto&ai:a){
			cin>>ai;
		}
		int ans = (n-1)*(*max_element(a.begin(),a.end())-*min_element(a.begin(),a.end()));
		cout<<ans<<endl;
	}
}
