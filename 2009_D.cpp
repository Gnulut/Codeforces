//#include<bits/stdc++.h>
//using namespace std;
//
//int main(){
//	ios::sync_with_stdio(0);cin.tie(0);
//	int t,n,x,y;
//	vector<int> ps[2],doub;
//	cin>>t;
//	while(t--){
//		cin>>n;
//		ps[0].clear(),ps[1].clear(),doub.clear();
//		set<int> s[2];
//		for(int i=0;i<n;++i){
//			cin>>x>>y;
//			s[y].insert(x);
//			ps[y].push_back(x);
//			if(s[y^1].count(x)){
//				doub.push_back(x);
//			}
//		}
//		long long ans=(long long)doub.size()*((ps[0].size()-1)+(ps[1].size())-1);
//		sort(ps[0].begin(),ps[0].end());sort(ps[1].begin(),ps[1].end());
//		vector<int>::iterator itl=ps[1].begin(),itr;
//		for(auto&point:ps[0]){
//			itl=lower_bound(itl,ps[1].end(),point-1);
//			if(itl==ps[1].end())break;
//			if(*itl>point-1)continue;
//			itr=lower_bound(itl,ps[1].end(),point+1);
//			if(itr==ps[1].end()||*itr>point+1)continue;
//			++ans;
//		}
//		itl=ps[0].begin();
//		for(auto&point:ps[1]){
//			itl=lower_bound(itl,ps[0].end(),point-1);
//			if(itl==ps[0].end())break;
//			if(*itl>point-1)continue;
//			itr=lower_bound(itl,ps[0].end(),point+1);
//			if(itr==ps[0].end()||*itr>point+1)continue;
//			++ans;
//		}
//		cout<<ans<<"\n";
//	}
//}

#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int t,n,x,y;
	vector<int> ps[2];
	cin>>t;
	while(t--){
		cin>>n;
		ps[0].clear(),ps[1].clear();
		for(int i=0;i<n;++i){
			cin>>x>>y;
			ps[y].push_back(x);
		}
		for(int i=0;i<2;++i)
			sort(ps[i].begin(),ps[i].end());
		long long ans=0;
		for(int i=0;i<2;++i){
			vector<int>&arr_now=ps[i],&arr_other=ps[i^1];
			vector<int>::iterator itl=arr_other.begin(),itr;
			for(auto&x:arr_now){
				while(itl!=arr_other.end()&&*itl<x-1){
					++itl;
				}
				if(itl==arr_other.end())break;
				if(*itl==x){
					ans+=arr_other.size()-1;
				}else if(*itl==x-1){
					itr=itl+1;
					if(itr==arr_other.end())continue;
					if(*itr==x){
						ans+=arr_other.size()-1;
						++itr;
						if(itr!=arr_other.end()&&*itr==x+1)
							++ans;
					}else if(*itr==x+1){
						++ans;
					}
				}
				//cout<<"i = "<<i<<"  x = "<<x<<"  ans = "<<ans<<"\n";
			}
		}
		cout<<ans<<"\n";
	}
}
