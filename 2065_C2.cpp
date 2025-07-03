#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int t,n,m;
	vector<int> a,b;
	cin>>t;
	while(t--){
		cin>>n>>m;
		a.resize(n);
		for(auto&x:a){
			cin>>x;
		}
		b.resize(m);
		for(auto&x:b){
			cin>>x;
		}
		sort(b.begin(),b.end());
		{
			int change_val = b[0]-a[0];
			if(change_val<a[0]){
				a[0]=change_val;
			}
		}
		bool can=true;
//		cout<<"b: ";
//		for(auto&x:b)cout<<x<<" ";
//		cout<<"\n";
		for(int i=1;i<n;++i){
			auto it = lower_bound(b.begin(),b.end(),a[i-1]+a[i]);
//			cout<<"i = "<<i<<" ";
			if(it!=b.end()){
//				cout<<" i = "<<i<<"\n";
				if(a[i]<a[i-1]){
					a[i]=*it-a[i];
				}else if(a[i]>a[i-1]){
					int new_val = *it-a[i];
					if(a[i-1]<=new_val&&new_val<a[i]){
						a[i]=new_val;
					}
				}
			}
			if(a[i]<a[i-1]){
				can=false;
				break;
			}
		}
//		for(auto&x:a){
//			cout<<x<<" ";
//		}
		if(can){
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}
	}
}
