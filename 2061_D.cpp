#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,n,m;
	cin>>t;
	while(t--){
		cin>>n>>m;
		multiset<int> a,b;
		long long suma=0,sumb=0;
		for(int i=0,x;i<n;++i){
			cin>>x;
			a.insert(x);
			suma+=x;
		}
		for(int i=0,x;i<m;++i){
			cin>>x;
			sumb+=x;
			auto it=a.find(x);
			if(it!=a.end()){
				a.erase(it);
			}else{
				b.insert(x);
			}
		}
		if(suma!=sumb){
			cout<<"No\n";
			continue;
		}
		bool can=true;
		while(can&&a.size()&&b.size()){
			auto a_mx_it = prev(a.end());
			auto b_mx_it = prev(b.end());
			if(*a_mx_it>*b_mx_it){
				can=false;
				break;
			}
			queue<int> q({*b_mx_it});
			b.erase(b_mx_it);
			while(!q.empty()&&a.size()){
				int num=q.front();q.pop();
				//cout<<"num = "<<num<<"\n";
				int a_smallest = *a.begin();
				if(num<a_smallest){
					//<<"hey\n";
					can=false;
					break;
				}
				auto it=a.find(num);
				if(it!=a.end()){
					a.erase(it);
					continue;
				}
				int bg=(num+1)/2,sm=num/2;
				q.push(bg);
				q.push(sm);
			}
			
		}
		if(a.size()||b.size())can=false;
		cout<<(can?"Yes\n":"No\n");
	}
}
