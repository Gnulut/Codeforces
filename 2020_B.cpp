#include<bits/stdc++.h>
using namespace std;
 
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	long long t,n;
	cin>>t;
	while(t--){
		cin>>n;
		
		long long l=1,r=n*3;
		while(l<=r){
			long long m = (l+r)/2;
			long long sq = sqrt(m);
			while(sq>0&&(sq-1)*(sq-1)>=m)sq--;
			while((sq+1)*(sq+1)<=m)sq++;
			if(m-sq>=n){
				r=m-1;
			}else{
				l=m+1;
			}
			//cout<<l<<" "<<r<<"\n";
		}
		cout<<l<<"\n";
	}
}
