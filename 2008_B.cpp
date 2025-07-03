#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,n;
	string s;
	cin>>t;
	while(t--){
		cin>>n>>s;
		int nsq=1;
		while(nsq*nsq<n)++nsq;
		if(nsq*nsq!=n){
			cout<<"No\n";
			continue;
		}
		bool beau=true;
		for(int i=0;i<s.length()&&beau;++i){
			int y=i/nsq, x=i%nsq;
			if(y==0||x==0||y==nsq-1||x==nsq-1){
				if(s[i]!='1')
					beau=false;
			}else{
				if(s[i]!='0')
					beau=false;
			}
		}
		cout<<(beau?"Yes\n":"No\n");
	}
}
