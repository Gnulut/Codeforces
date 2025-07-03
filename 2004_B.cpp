#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	pair<int,int> p[2];
	cin>>t;
	while(t--){
		cin>>p[0].first>>p[0].second>>p[1].first>>p[1].second;
		sort(p,p+2);
		if(p[0].second<p[1].first){//outside
			cout<<"1\n";
		}else if(p[0]==p[1]){//same
			cout<<p[0].second-p[0].first<<"\n";
		}else if(p[0].second==p[1].second){//share end
			cout<<p[1].second-p[1].first+1<<"\n";
		}else if(p[0].first==p[1].first){//share start
			cout<<p[0].second-p[0].first+1<<"\n";
		}else if(p[0].second>=p[1].first&&p[1].second>p[0].second){//intersect
			cout<<p[0].second-p[1].first+2<<"\n";
		}else{//inside
			cout<<p[1].second-p[1].first+2<<"\n";
		}
	}
}
