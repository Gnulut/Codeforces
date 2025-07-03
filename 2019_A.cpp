#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,n,k;
	int a[105];
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;++i){
			cin>>a[i];
		}
		int mx[2]={};
		for(int i=0;i<n;++i){
			mx[i&1]=max(mx[i&1],a[i]);
		}
		cout<<max(mx[0]+(n+1)/2,mx[1]+(n/2))<<"\n";
	}
}
