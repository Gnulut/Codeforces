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
		sort(a.begin(),a.end());
		int ans=0;
		for(int i=1;i<n;++i){
			if(a[i]==a[i-1]){
				ans++;
				++i;
			}
		}
		cout<<ans<<"\n";
	}
}
