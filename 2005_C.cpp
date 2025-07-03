#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int t,n,m;
	vector<string> s;s.reserve(1005);
	vector<vector<vector<int>>> cnt,DP;
	vector<int> narekcount;
	cnt.reserve(1005);
	DP.reserve(1005);
	narekcount.reserve(1005);
	cin>>t;
	string fnd="narek";
	bool isnarek[256]={};
	isnarek['n']=true;
	isnarek['a']=true;
	isnarek['r']=true;
	isnarek['e']=true;
	isnarek['k']=true;
	while(t--){
		cin>>n>>m;
		s.resize(n);
		cnt.assign(n,vector<vector<int>>(5,vector<int>(5,-1000000000)));
		for(auto&si:s)cin>>si;
		narekcount.assign(n,0);
		for(int i=0;i<n;++i){
			for(auto&c:s[i]){
				narekcount[i]+=isnarek[c];
			}
		}
		for(int i=0;i<n;++i){//for each string;
			for(int st=0;st<5;++st){//for each start char
				string::iterator itf=fnd.begin()+st;
				int len=0;
				for(auto&c:s[i]){
					if(c==*itf){
						len++;
						cnt[i][st][distance(fnd.begin(),itf)]=max(cnt[i][st][distance(fnd.begin(),itf)],len*2-narekcount[i]);
						if(++itf==fnd.end()){
							itf=fnd.begin();
						}
					}
				}
			}
		}
//		for(int i=0;i<n;++i){
//			for(int st=0;st<5;++st){
//				for(int ed=0;ed<5;++ed){
//					cout<<cnt[i][st][ed]<<" ";
//				}
//				cout<<"\n";
//			}
//			cout<<"\n";
//		}
		DP.assign(n,vector<vector<int>>(5,vector<int>(5,-1000000000)));
		for(int i=0;i<n;++i){
			for(int ed=0;ed<5;++ed){
				DP[i][0][ed]=cnt[i][0][ed];
			}
			for(int j=0;j<i;++j){
				for(int st=0;st<5;++st){
					int mx=-1234567890;
					for(int jst=0;jst<5;++jst){
						mx=max(mx,DP[j][jst][(st+4)%5]);
					}
					for(int ed=0;ed<5;++ed){
						DP[i][st][ed]=max(DP[i][st][ed],mx+cnt[i][st][ed]);
					}
				}
			}
		}
		int ans=0;
		for(int i=0;i<n;++i){
			for(int st=0;st<5;++st){
				for(int ed=0;ed<5;++ed){
					ans=max(ans,DP[i][st][ed]-(ed!=4)*((ed+1)*2));
				}
			}
		}
//		for(int i=0;i<n;++i){
//			for(int st=0;st<5;++st){
//				for(int ed=0;ed<5;++ed){
//					cout<<DP[i][st][ed]<<" ";
//				}
//				cout<<"\n";
//			}
//			cout<<"\n";
//		}
		cout<<ans<<"\n";
	}
}
