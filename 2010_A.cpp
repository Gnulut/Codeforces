#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,n;
	vector<int> a;
	cin>>t;
	while(t--){
		cin>>n;
		a.resize(n);
		int sum=0;
		for(int i=0;i<n;++i){
			cin>>a[i];
			sum += a[i] * (i&1?-1:1);
		}
		cout<<sum<<endl;
	}
}
