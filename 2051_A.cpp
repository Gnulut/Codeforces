#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		vector<int> a(n),b(n);
		for(auto&x:a)cin>>x;
		for(auto&x:b)cin>>x;
		int ans=0;
		for(int i=0;i<n-1;++i){
			if(a[i]>b[i+1]){
				ans+=a[i]-b[i+1];
			}
		}
		ans+=a.back();
		cout<<ans<<"\n";
	}
}
