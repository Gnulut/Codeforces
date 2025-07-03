#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,n;
	string s;
	cin>>t;
	while(t--){
		cin>>n>>s;
		int cnt[2][26]={};
		for(int i=0;i<n-(n&1);++i){
			cnt[i&1][s[i]-'a']++;
		}
		int ans=0;
		for(int i=0;i<2;++i){
			ans+=accumulate(cnt[i],cnt[i]+26,0)-*max_element(cnt[i],cnt[i]+26);
		}
		if((n&1)==0){
			cout<<ans<<"\n";
			continue;
		}
		for(int i=n-2;i>=0;--i){
			cnt[i&1][s[i]-'a']--;
			cnt[i&1][s[i+1]-'a']++;
			int new_ans=0;
			for(int j=0;j<2;++j){
				new_ans+=accumulate(cnt[j],cnt[j]+26,0)-*max_element(cnt[j],cnt[j]+26);
			}
			//cout<<"i = "<<i<<"  "<<new_ans<<"\n";
			ans=min(ans,new_ans);
		}
		cout<<ans+1<<"\n";
	}
}
