#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int t,n;
	vector<int> a,b;
	cin>>t;
	while(t--){
		cin>>n;
		a.resize(n);
		b.resize(n);
		for(auto&x:a){
			cin>>x;
		}
		for(auto&x:b){
			cin>>x;
		}
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		int cnta=1,cntb=1;
		for(int i=1;i<n;++i){
			if(a[i]!=a[i-1]){
				++cnta;
			}
			if(b[i]!=b[i-1]){
				++cntb;
			}
		}
		bool can = (cnta>=2)&&(cntb>=2)||(cnta>=3)||(cntb>=3);
		cout<<(can?"YES\n":"NO\n");
	}
}
