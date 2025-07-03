#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cout.tie(0);
	int t,n;
	vector<int> a,b;
	cin>>t;
	while(t--){
		cin>>n;
		a.resize(n);
		for(auto&x:a){
			cin>>x;
		}
		for(auto&x:b){
			cin>>x;
		}
		bool can=true;
		int needed=0,idx=-1;
		for(int i=0,cnt;i<n;++i){
			if(a[i]<b[i]){
				if(idx!=-1){
					can=false;
					break;
				}else{
					idx=i;
					needed=b[i]-a[i];
				}
			}
		}
		if(can){
			for(int i=0;i<n;++i){
				if(i==idx)continue;
				int have=b[i]-a[i];
				if(have<needed){
					can=false;
					break;
				}
			}
		}
		cout<<(can?"YES\n":"NO\n");
	}
}
