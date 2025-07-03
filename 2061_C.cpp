#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int t,n;
	vector<int> a,status;
	cin>>t;
	while(t--){
		cin>>n;
		a.resize(n);
		status.assign(n,0);
		for(auto&x:a){
			cin>>x;
		}
//		bool can=true;
//		for(int i=0,mn=0,mx=0;i<n;++i){
//			mx=min(mx,(i+1)/2);
//			if(a[i]<mn||a[i]>mx){
//				mn++;
//				mx++;
//				status[i]=-1;
//				if(i){
//					if(status[i-1]==-1){
//						can=false;
//						break;
//					}
//					status[i-1]=1;
//				}
//				if(i+1<n){
//					status[i+1]=1;
//				}
//				if(i&&i+1<n){
//					if(a[i-1]!=a[i+1]-1){
//						can=false;
//						break;
//					}
//				}
//			}else{
//				mx++;
//			}
//		}
//		for(auto&x:status){
//			cout<<" "<<x;
//		}
//		cout<<"\n";
//		if(!can){
//			cout<<"fail: 0\n";
//			continue;
//		}
		queue<pair<int,int>> poss;// how many L, prev;
		poss.push({0,0});
		for(int i=0;i<n&&poss.size();++i){
			int rep=poss.size();
			while(rep--){
				pair<int,int> total_prev=poss.front();
				poss.pop();
				if(total_prev.first==a[i]){
					poss.push({total_prev.first,1});
				}
				if(total_prev.second!=-1){
					poss.push({total_prev.first+1,-1});
				}
			}
		}
		cout<<poss.size()<<"\n";
	}
}
