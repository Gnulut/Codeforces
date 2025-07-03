#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int t,a,b;
	cin>>t;
	while(t--){
		cin>>a>>b;
		if(b%2==0)b--;
		if(a%2==0)a++;
		int odd_cnt=(b-a)/2+1;
		cout<<odd_cnt/2<<"\n";
	}
}
