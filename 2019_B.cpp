#include<bits/stdc++.h>
using namespace std;
const int siz=1.1e5;
long long a[siz];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long t,n,q;
	cin>>t;
	map<long long,long long> m;
	while(t--){
		m.clear();
		cin>>n>>q;
		for(int i=0;i<n;++i){
			cin>>a[i];
		}
		long long seqs=0,interseq=0;
		for(int i=0;i<n;++i){
			seqs+=(n-i-1)-max(0,(i-1));
			interseq+=(n-i-1)-i;
			if(i<n-1){
				m[interseq]+=a[i+1]-a[i]-1;
			}
			m[seqs]+=1;
		}
		//cout<<"\n";
		for(long long i=0,qi;i<q;++i){
			cin>>qi;
			cout<<m[qi]<<" ";
		}
		cout<<"\n";
	}
}
