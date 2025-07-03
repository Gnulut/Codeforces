#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int t,n,m;
	cin>>t;
	vector<int> a[705];
	while(t--){
		cin>>n>>m;
		int mx=0;
		for(int i=0;i<n;++i){
			a[i].resize(m);
			for(auto&x:a[i]){
				cin>>x;
				mx=max(mx,x);
			}
		}
		int cnt[mx+1]={};
		int dy[]={0,0,-1,1},dx[]={-1,1,0,0};
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				for(int k=0;k<4;++k){
					int y=i+dy[k],x=j+dx[k];
					if(y>=0&&y<n&&x>=0&&x<m&&a[y][x]==a[i][j]){
						cnt[a[i][j]]=2;
					}else if(cnt[a[i][j]]==0){
						cnt[a[i][j]]=1;
					}
				}
			}
		}
		int ans = accumulate(cnt+1,cnt+mx+1,0)-*max_element(cnt+1,cnt+mx+1);
		cout<<ans<<"\n";
	}
}
