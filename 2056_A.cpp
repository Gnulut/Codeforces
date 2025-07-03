#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t,n,m,x,y;
	cin>>t;
	while(t--){
		cin>>n>>m;
		int peri=4*m;
		cin>>x>>y;
		int stx=x,sty=y,edx=stx+m,edy=sty+m;
		while(--n){
			cin>>x>>y;
			int stx2=stx+x,sty2=sty+y;
			peri = peri + 4*m - 2*((edx-stx2)+(edy-sty2));
			stx=stx2;
			sty=sty2;
			edx=stx+m;
			edy=sty+m;
		}
		cout<<peri<<"\n";
	}
}
