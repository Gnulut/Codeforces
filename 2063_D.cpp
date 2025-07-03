#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t,n[2];
	vector<int> a[2];
	cin>>t;
	while(t--){
		cin>>n[0]>>n[1];
		deque<int> dq[2];
		for(int i=0;i<2;++i){
			a[i].resize(n[i]);
			for(auto&x:a[i]){
				cin>>x;
			}
			sort(a[i].begin(),a[i].end());
			for(int j=0,l=0,r=n[i]-1;j<n[i];++j){
				if(j%2==0){
					dq[i].push_back(a[i][l++]);
				}else{
					dq[i].push_back(a[i][r--]);
				}
			}
		}
		int kmax = min(min(n[0],n[1]),(n[0]+n[1])/3);
		vector<pair<int,int>> points[2];
		vector<int> points_single[2];
		long long ans=0;
		cout<<kmax<<"\n";
		for(int k=1;k<=kmax;++k){
			if(dq[0].size()>=2&&dq[1].size()>=2){
				pair<int,int> line[2];
				for(int i=0;i<2;++i){
					line[i].first=dq[i].front();dq[i].pop_front();
					line[i].second=dq[i].front();dq[i].pop_front();
				}
				int two_dq=0, one_dq=1;
				if(line[1].second-line[1].first>line[0].second-line[0].first){
					swap(two_dq,one_dq);
				}
				dq[one_dq].push_front(line[one_dq].second);
				dq[one_dq].push_front(line[one_dq].first);
				points_single[one_dq].push_back(dq[one_dq].back());
				dq[one_dq].pop_back();
				ans+=line[two_dq].second-line[two_dq].first;
				points[two_dq].push_back(line[two_dq]);
			}else if(dq[0].size()==1||dq[1].size()==1){
				int two_dq = dq[0].size()==1, one_dq = 1-two_dq;
				pair<int,int> line;
				line.first=dq[two_dq].front();dq[two_dq].pop_front();
				line.second=dq[two_dq].front();dq[two_dq].pop_front();
				points_single[one_dq].push_back(dq[one_dq].back());
				dq[one_dq].pop_back();
				ans+=line.second-line.first;
				points[two_dq].push_back(line);
			}else{// these three else if branch can be evaluated once only, using 3 loop (if(){-loop} else if(){-loop} else {-loop}) though it doesnt matter much
				int two_dq = dq[0].size()==0, removal_dq = 1-two_dq;
				pair<int,int> removal_line = points[removal_dq].back();points[removal_dq].pop_back();
				dq[two_dq].push_back(points_single[two_dq].back());
				points_single[two_dq].pop_back();
				ans -= removal_line.second-removal_line.first;
				pair<int,int> line;
				line.first=dq[two_dq].front();dq[two_dq].pop_front();
				line.second=dq[two_dq].front();dq[two_dq].pop_front();
				ans+=line.second-line.first;
				//points_single[one_dq].push_back(/*something*/);// standard procedure, not needed
				//points[two_dq].push_back(line); //standard procedure, not needed
				line.first=dq[two_dq].front();dq[two_dq].pop_front();
				line.second=dq[two_dq].front();dq[two_dq].pop_front();
				ans+=line.second-line.first;
				//points_single[one_dq].push_back(/*something*/);// standard procedure, not needed
				//points[two_dq].push_back(line); //standard procedure, not needed
			}
			cout<<ans<<" ";
		}
		cout<<"\n";
	}
}
