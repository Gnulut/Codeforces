#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n%2==0){
			cout<<"-1\n";
			continue;
		}
		vector<int> a(n);
		int num=1;
		for(int i=n/2;i<n;++i){
			a[i]=num++;
		}
		for(int i=n/2-1;i>=0;--i){
			a[i]=num++;
		}
		for(auto&x:a)cout<<x<<" ";
		cout<<"\n";
	}
}
