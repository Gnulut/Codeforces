#include<bits/stdc++.h>
using namespace std;
 
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	unsigned long long t,a,b,c,d;
	cin>>t;
	while(t--){
		cin>>b>>c>>d;
		bitset<64> ba=0,bb=b,bc=c,bd=d;
		bool can=true;
		for(int i=63;i>=0;--i){
			if(bd[i]==0){
				if(bb[i]==1&&bc[i]==0){
					can=false;
					break;
				}
				ba[i]=1;
				if(bb[i]==0&&bc[i]==0){
					ba[i]=0;
				}
			}else{
				if(bb[i]==0&&bc[i]==1){
					can=false;
					break;
				}
				ba[i]=0;
				if(bb[i]==0&&bc[i]==0){
					ba[i]=1;
				}
			}
		}
		a=ba.to_ullong();
		if(can)cout<<a<<"\n";
		else cout<<"-1\n";
	}
}
