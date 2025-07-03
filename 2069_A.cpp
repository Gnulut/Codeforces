#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int t,n;
	vector<int> a;
	cin>>t;
	while(t--){
		cin>>n;
		a.resize(n-2);
		for(auto&x:a){
			cin>>x;
		}
		bool can=true;
		for(int i=1;i<a.size()-1;++i){
			if(a[i]==0&&a[i-1]==1&&a[i+1]==1){
				can=false;
				break;
			}
		}
		cout<<(can?"YES\n":"NO\n");
	}
}
