#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,n,m;
	vector<vector<int>> a;
	cin>>t;
	while(t--){
		cin>>n>>m;
		a.resize(n);
		for(int li,i=0;i<n;++i){
			cin>>li;
			a[i].resize(li);
			for(int j=0;j<li;++j){
				cin>>a[i][j];
			}
		}
		vector<int> mex(n);
		for(int i=0;i<n;++i){
			int mexi=0;
			sort(a[i].begin(),a[i].end());
			for(int j=0;j<a[i].size();++j){
				if(a[i][j]>mexi)break;
				mexi=a[i][j]+1;
			}
			mex[i]=mexi;
		}
		cout<<"mex array = ";
		for(auto&i:mex)cout<<i<<" ";cout<<"\n";
		int mx_mex=*max_element(mex.begin(),mex.end());
		int free_up_to = min(m,mx_mex+1);
		cout<<"free up to = "<<free_up_to<<"\n";
		long long ans = free_up_to*(long long)(free_up_to+1);
		if(mx_mex<m){
			long long st = free_up_to+1, ed = m;
			long long cnt = ed-st+1;
			ans+=(st+ed)*cnt/2;
		}
		cout<<ans<<"\n";
	}
}
