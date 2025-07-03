#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	string s;
	cin>>t;
	while(t--){
		cin>>s;
		int cnt[10]={},sum=0;
		for(auto&c:s){
			cnt[c-'0']++;
			sum+=c-'0';
		}
		sum%=9;
		bool fnd=false;
		int req = (9-sum)%9;
//		cout<<"req = "<<req<<"\n";
		for(int i=0;i<=min(2,cnt[3]);++i){
			int nreq = (req + i*3)%9;
			if(nreq&1)nreq+=9;
//			cout<<"i = "<<i<<"  nreq = "<<nreq<<"\n";
			nreq/=2;
			if(cnt[2]>=nreq){
				cout<<"YES\n";
				
				fnd=true;
				break;
			}
		}
		if(!fnd)cout<<"NO\n";
	}
}
