#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int t,n;
	cin>>t;
	vector<int> a;
	while(t--){
		cin>>n;
		a.resize(n);
		int middle=-1;
		for(auto it=a.begin();it!=a.end();++it){
			cin>>*it;
			if(abs(*it)>1){
				middle=it-a.begin();
			}
		}
		if(middle==-1){
			int l=0,r=0;
			int mn=0,mx=0;
			for(int i=0;i<n;++i){
				mn=min(0,mn+a[i]);
				mx=max(0,mx+a[i]);
				l=min(l,mn);
				r=max(r,mx);
			}
			cout<<r-l+1<<'\n';
			while(l<=r){
				cout<<l++<<" ";
			}
			cout<<"\n";
		}else{
			set<int> ans;
			{
				int mn=0,mx=0;
				for(int i=0;i<middle;++i){
					mn=min(0,mn+a[i]);
					mx=max(0,mx+a[i]);
					ans.insert(mn);
					ans.insert(mx);
				}
			}
			{
				int mn=0,mx=0;
				for(int i=middle+1;i<n;++i){
					mn=min(0,mn+a[i]);
					mx=max(0,mx+a[i]);
					ans.insert(mn);
					ans.insert(mx);
				}
			}
			int mn=0,mx=0;
			int val=0;
			for(int i=middle-1;i>=0;--i){
				val+=a[i];
				mn=min(mn,val);
				mx=max(mx,val);
			}
			mn+=a[middle];
			mx+=a[middle];
			int mn2=0,mx2=0;
			val=0;
			for(int i=middle+1;i<n;++i){
				val+=a[i];
				mn2=min(mn2,val);
				mx2=max(mx2,val);
			}
			mn+=mn2;
			mx+=mx2;
			while(mn<=mx){
				ans.insert(mn++);
			}
			cout<<ans.size()<<"\n";
			for(auto&x:ans){
				cout<<x<<" ";
			}
			cout<<"\n";
		}
	}
}
