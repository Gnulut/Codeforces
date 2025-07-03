#include<bits/stdc++.h>
using namespace std;
const int siz=2.1e5;
long long a[siz];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long t,n,k;
	cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i=0;i<n;++i){
			cin>>a[i];
		}
		sort(a,a+n,greater<long long>());
		long long total = accumulate(a,a+n,0ll);
		int ans=1;
		for(int new_ans=2;new_ans<=n;++new_ans){
			long long need_add=(new_ans-(total%new_ans))%new_ans;
			if(need_add>k)continue;
			long long nk=k-need_add;
			long long ntotal=total+need_add+(nk/new_ans)*new_ans;
			if(a[0]<=ntotal/new_ans){
				ans=new_ans;
			}
		}
		cout<<ans<<"\n";
	}
}
