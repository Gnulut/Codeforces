#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		int w=0,h=0;
		for(int i=0,a,b;i<n;++i){
			cin>>a>>b;
			w=max(w,a);
			h=max(h,b);
		}
		cout<<2*(w+h)<<endl;
	}
}
