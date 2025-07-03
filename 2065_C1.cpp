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
		bool can=true;
		for(int i=0;i<n;++i){
			int change_val = b[0]-a[i];
			if(change_val<a[i]&&(i==0||a[i]>a[i-1]&&change_val>=a[i-1])||change_val>a[i]&&i!=0&&a[i]<a[i-1]){
				a[i] = change_val;
			}
			if(i&&a[i]<a[i-1]){
				can=false;
				break;
			}
		}
		if(can){
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}
	}
}
