#include<bits/stdc++.h>
using namespace std;

int l,n,m;
//map<int,int> vis;
bool iswin(vector<vector<pair<int,int>>>&locations,vector<int>&ls,int idx=0,int mny=1,int mnx=1){
//	cout<<"doing "<<idx<<"  "<<mny<<"  "<<mnx<<"\n";
//	int map_id = idx*(n*m) + mny*(m) * mnx;
	if(idx==ls.size()||mny>n||mnx>m){
//		cout<<"hey\n";
		return false;
	}
//	if(vis[map_id]!=0){
////		cout<<"hoy\n";
//		return vis[map_id]==2;
//	}
	for(auto&lc:locations[idx]){
//		cout<<" loop: "<<lc.first<<" "<<lc.second<<"\n";
		if(lc.first<mny||lc.second<mnx)continue;
		if(!iswin(locations,ls,idx+1,lc.first+1,lc.second+1)){
//			cout<<"idx = "<<idx<<"  pos = "<<mny<<","<<mnx<<"   npos = "<<lc.first<<","<<lc.second<<"\n";
//			vis[map_id]=2;
			return true;
		}
	}
//	vis[map_id]=1;
	return false;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int t;
	vector<int> ls;
	vector<vector<pair<int,int>>> locations;
	locations.reserve(305);
	cin>>t;
	while(t--){
		cin>>l>>n>>m;
		ls.resize(l);
//		vis.clear();
		for(auto&lsi:ls)cin>>lsi;
		int num;
		locations.assign(l,vector<pair<int,int>>());
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				cin>>num;
				for(int k=0;k<ls.size();++k){
					if(ls[k]==num){
						locations[k].push_back({i,j});
					}
				}
			}
		}
		for(auto&lc:locations){
			sort(lc.begin(),lc.end(),greater<pair<int,int>>());
		}
//		cout<<"locs: \n";
//		for(auto&lcs:locations){
//			for(auto&lc:lcs){
//				cout<<lc.first<<","<<lc.second<<" ";
//			}
//			cout<<"\n";
//		}
//		cout<<"end locs\n";
		bool res = iswin(locations,ls);
		if(res)cout<<"T\n";
		else cout<<"N\n";
	}
}
