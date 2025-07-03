#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		int cnt=0;
		for(int i=0,x;i<n*2;++i){
			cin>>x;
			cnt+=x;
		}
		cout<<(cnt&1)<<" "<<min(cnt,2*n-cnt)<<"\n";
	}
}
