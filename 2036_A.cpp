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
		bool perf=true;
		for(int i=1;i<n;++i){
			int dif = abs(a[i]-a[i-1]);
			if(dif!=5&&dif!=7){
				perf=false;
				break;
			}
		}
		cout<<(perf?"YES":"NO")<<"\n";
	}
}
