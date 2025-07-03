#include<bits/stdc++.h>
using namespace std;
const int siz=2.1e5;
int loc[siz],cmd[siz][11];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
    int t,n,m;
    cin>>t;
   	vector<int> at[siz];
    while(t--){
    	cin>>n>>m;
    	for(int i=0,a,d,k;i<m;++i){
    		cin>>a>>d>>k;
    		cmd[a][d]=max(cmd[a][d],k);
		}
		for(int i=1;i<=n;++i){
			loc[i]=i;
			at[i].clear();
			at[i].push_back(i);
		}
		for(int i=1;i<=n;++i){
			for(int d=1;d<=10;++d){
				if(cmd[i][d]==0)continue;
				int nxt=i+d;
				if(loc[i]!=loc[nxt]){// not in the same group;
					vector<int> *sm=&at[loc[i]],*bg=&at[loc[nxt]];
					int new_pos = loc[nxt];
//					cout<<i<<" "<<nxt<<" "<<d<<"  "<<sm->size()<<"  "<<bg->size()<<"\n";
					if(sm->size()>=bg->size()){
						sm=&at[loc[nxt]];
						bg=&at[loc[i]];
						new_pos = loc[i];
					}
					
					for(auto&x:*sm){
						bg->push_back(x);
						loc[x]=new_pos;
					}
					sm->clear();
				}
				cmd[nxt][d]=max(cmd[nxt][d],cmd[i][d]-1);
				cmd[i][d]=0;
			}
//			cout<<"at: ";
//			for(int i=1;i<=n;++i){
//				cout<<i<<": ";
//				for(auto&y:at[i]){
//					cout<<y<<" ";
//				}
//				cout<<"\n";
//			}cout<<"\n";
		}
		int ans=0;
		for(int i=1;i<=n;++i){
			if(at[i].size())++ans;
		}
//		cout<<"at: ";
//		for(int i=1;i<=n;++i){
//			cout<<i<<": ";
//			for(auto&y:at[i]){
//				cout<<y<<" ";
//			}
//			cout<<"\n";
//		}
//		cout<<"loc: ";
//		for(int i=1;i<=n;++i){
//			cout<<loc[i]<<" ";
//		}cout<<"\n";
		cout<<ans<<"\n";
	}
}

