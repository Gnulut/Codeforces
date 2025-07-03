#include<bits/stdc++.h>
using namespace std;


int main(){
	int t,n;
	cin>>t;
	string s;
	while(t--){
		cin>>n>>s;
		int cnt[256]={};
		for(auto&c:s){
			cnt[c]++;
		}
		priority_queue<pair<int,char>> pq;
		for(char c='a';c<='z';++c){
			pq.push({cnt[c],c});
		}
		string ans="";
		while(pq.top().first!=0){
			pair<int,char> ic=pq.top();pq.pop();
			if(ans.size()&&ic.second==ans.back()&&pq.top().first!=0){
				pair<int,char> ic2=pq.top();pq.pop();
				ans+=ic2.second;
				ic2.first--;
				pq.push(ic2);
			}else{
				ans+=ic.second;
				ic.first--;
			}
			pq.push(ic);
		}
		cout<<ans<<"\n";
	}
}
