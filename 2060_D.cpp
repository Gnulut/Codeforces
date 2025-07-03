#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		vector<int> v(n);
		for(auto&x:v)cin>>x;
		bool can=true;
		for(int i=1;i<n;++i){
			if(v[i]<v[i-1]){
				can=false;
				break;
			}
			v[i]-=v[i-1];
		}
		cout<<(can?"YES\n":"NO\n");
	}
}
