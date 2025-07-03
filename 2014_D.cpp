#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t,n,d,k;
	vector<vector<int>> m;
	cin>>t;
	while(t--){
		m.clear();
		cin>>n>>d>>k;
		m.resize(n+1+d);
		for(int i=0,l,r,m_id=1;i<k;++i){
			cin>>l>>r;
			m[l].push_back(m_id);
			m[r+d].push_back(-m_id);
			++m_id;
		}
//		for(int i=0;i<=n;++i){
//			cout<<"msize:  "<<m[i].size()<<"   m:  ";
//			for(auto&x:m[i])cout<<x<<" ";cout<<"\n";
//		}
		set<int> missions;
		for(int i=1;i<d;++i){
			for(auto&val:m[i]){
				missions.insert(val);
			}
		}
		int brocnt=-1,broleave=0;
		int momcnt=1234567890,momleave=0;
		for(int i=d;i<=n;++i){
			for(auto&val:m[i]){
				if(val>0){
					missions.insert(val);
				}else{
					missions.erase(-val);
				}
			}
//			cout<<"i = "<<i<<"  siz = "<<missions.size()<<"\n";
			int new_ans=missions.size();
			if(brocnt<new_ans){
				brocnt=new_ans;
				broleave=i;
			}
			if(momcnt>new_ans){
				momcnt=new_ans;
				momleave=i;
			}
		}
		cout<<broleave-d+1<<" "<<momleave-d+1<<"\n";
	}
}
