#include<bits/stdc++.h>
using namespace std;

bool share(string&a,string&b){
	if(a.front()==b.front()||a.front()==b.back()||a.back()==b.front()||a.back()==b.back())
		return true;
	return false;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int t,n,q;
	cin>>t;
	vector<string> poss={"BG", "BR", "BY", "GR", "GY", "RY"};
	vector<string> a;
	map<string,vector<int>> m;
	while(t--){
		cin>>n>>q;
		a.resize(n);
		for(auto&s:a)cin>>s;
		m.clear();
		for(int i=0;i<n;++i){
			m[a[i]].push_back(i);
		}
		int l,r;
		while(q--){
			cin>>l>>r;
			if(l>r){
				swap(l,r);
			}
			--l;--r;
			if(share(a[l],a[r])){
				cout<<r-l<<"\n";
				continue;
			}
			int ans=1234567890;
			//for(auto&sv:m){	cout<<sv.first<<"\t";	for(auto&x:sv.second)cout<<x<<" ";cout<<"\n";}
			for(auto&s:poss){
				if(s==a[l]||s==a[r])continue;
				auto it=upper_bound(m[s].begin(),m[s].end(),l);
				if(it!=m[s].end()){
					ans=min(ans,(*it-l)+abs(r-*it));
					//cout<<"go right: "<<l<<"  "<<r<<"  "<<*it<<"\n";
				}
				it = lower_bound(m[s].begin(),m[s].end(),l);
				if(it!=m[s].begin()&&m[s].size()!=0){
					--it;
					ans=min(ans,l-*it+r-*it);
					//cout<<"go left : "<<l<<"  "<<r<<"  "<<*it<<"\n";
				}
			}
			if(ans!=1234567890)cout<<ans<<"\n";
			else cout<<"-1\n";
		}
	}
}

/*
		"BG" 	"BR" 	"BY" 	"GR" 	"GY" 	"RY"
"BG"	x		x		x		x		x       BR/BY/GR/GY
"BR"    x       x       x       x       BG/BY/GR/RY     x
"BY"
"GR"
"GY"
"RY"
*/
