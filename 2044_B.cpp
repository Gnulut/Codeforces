#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	string a,b;
	cin>>t;
	while(t--){
		cin>>a;
		b.clear();
		for(int i=a.size()-1;i>=0;--i){
			if(a[i]=='w'){
				b+='w';
			}else if(a[i]=='p'){
				b+='q';
			}else {
				b+='p';
			}
		}
		cout<<b<<"\n";
	}
}
