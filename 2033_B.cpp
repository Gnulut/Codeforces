#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,n;
	int g[505][505];
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				cin>>g[i][j];
			}
		}
		long long ans=0;
		for(int y=-n-1;y<n;++y){
			int plus=0;
			for(int yy=y,x=0;x<n;++x,++yy){
				if(yy>=0&&yy<n){
					plus=max(plus,-g[yy][x]);
				}
			}
			ans+=plus;
		}
		cout<<ans<<'\n';
	}
}
/*

 1  1 -1 -1  3
-3  1  4  4 -4
-1 -1  3  0 -5
 4  5  3 -3 -1
 3  1 -3 -1  5
0 0 3 3 3 1 5 4 0
*/
