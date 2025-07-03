#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,n;
	vector<int> v;
	cin>>t;
	while(t--){
		cin>>n;
		v.resize(n);
		for(auto&x:v){
			cin>>x;
		}
		sort(v.begin(),v.end());
		int a=-1,b=-1,c=-1,d=-1;
		for(int i=n-1;i>0;--i){
			if(v[i]==v[i-1]){
				a=i-1;
				b=i;
				break;
			}
		}
		if(a==-1||b==-1){
			cout<<"-1\n";
			continue;
		}
		for(int i=1;i<n;++i){
			if(i==a||i==b||i==b+1&&i==2)continue;
			int j=i-1;
			while(j==b||j==a)--j;
			int dif = v[i]-v[j];
			if(v[a]*2>dif){
				c=j;
				d=i;
				break;
			}
		}
		if(c==-1||d==-1){
			cout<<"-1\n";
			continue;
		}
		cout<<v[a]<<" "<<v[b]<<" "<<v[c]<<" "<<v[d]<<"\n";
	}
}
