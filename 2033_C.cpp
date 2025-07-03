#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,n;
	int a[(int)1.1e5];
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;++i){
			cin>>a[i];
		}
		for(int i=1;i<n/2;++i){
			if(a[i]==a[i-1]){
				swap(a[i],a[n-1-i]);
			}else{
				if(a[n-1-i]==a[n-i]){
					swap(a[i],a[n-1-i]);
				}
			}
		}
		int ans=0;
		for(int i=1;i<n;++i){
			ans+=a[i]==a[i-1];
		}
		cout<<ans<<"\n";
	}
}
