#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,n;
	cin>>t;
	vector<int> edges;
	while(t--){
		cin>>n;
		edges.clear();
		for(int i=2;i<=n;++i){
			int a=1,x=i,r=0;
			while(true){
				cout<<"? "<<a<<" "<<x<<endl;
				cin>>r;
				if(r==a||r==x)break;
				a=r;
			}
			edges.push_back((a<<16)+x);
		}
		cout<<"!";
		for(auto&x:edges)cout<<" "<<(x>>16)<<" "<<(x%(1<<16));
		cout<<endl;
	}
	return 0;
}
