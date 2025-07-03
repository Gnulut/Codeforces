#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,n,k;
	vector<int> val;
	cin>>t;
	while(t--){
		cin>>n>>k;
		val.assign(max(n,k),0);
		for(int b,c,i=0;i<k;++i){
			cin>>b>>c;
			val[b-1]+=c;
		}
		sort(val.begin(),val.end(),greater<int>());
		cout<<accumulate(val.begin(),val.begin()+n,0ll)<<endl;
	}
}
