#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int t,x,y,k;
	cin>>t;
	while(t--){
		cin>>x>>y>>k;
		int need_x = 2*((x+k-1)/k)-1;
		int need_y = 2*((y+k-1)/k);
		cout<<max(need_x,need_y)<<"\n";
	}
}
