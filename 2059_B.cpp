#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int t,n,k;
	vector<int> a;
	cin>>t;
	while(t--){
		cin>>n>>k;
		a.resize(n);
		for(auto&x:a){
			cin>>x;
		}
		if(n==2){
			cout<<(1+(a[1]==1))<<"\n";
			continue;
		}
		if(n==3){
			cout<<(1+(a[1]==1&&a[2]==1))<<"\n";
			continue;
		}
		if(k==n){
			int ans=1;
			for(int i=1;i<n;i+=2){
				if(a[i]!=(i+1)/2){
					break;
				}
				++ans;
			}
			cout<<ans<<"\n";
			continue;
		}
		{
			int ans=2;
			int start=1,end=start+n-k;
			for(int i=start;i<=end;++i){
				if(a[i]!=1){
					ans=1;
					break;
				}
			}
			cout<<ans<<"\n";
		}
	}
}
