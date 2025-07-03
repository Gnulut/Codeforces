#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,n;
	vector<int> a,b;
	cin>>t;
	while(t--){
		cin>>n;
		a.resize(n);
		b.resize(n);
		for(auto&x:a)cin>>x;
		for(auto&x:b)cin>>x;
		bool bob_win=true;
		int l=0,r=n-1,bl=0,br=n-1;
		while(l<=r){
			if(a[l]!=b[bl]&&a[l]!=b[br]||a[r]!=b[bl]&&a[r]!=b[br]){
				bob_win=false;
				break;
			}
			if(a[l]==b[bl]){
				bl++;
			}else{
				br--;
			}
			l++;
		}
		l=0,r=n-1,bl=0,br=n-1;
		while(l<=r){
			if(a[l]!=b[bl]&&a[l]!=b[br]||a[r]!=b[bl]&&a[r]!=b[br]){
				bob_win=false;
				break;
			}
			if(a[r]==b[bl]){
				bl++;
			}else{
				br--;
			}
			r--;
		}
		cout<<(bob_win?"Bob\n":"Alice\n");
	}
}
