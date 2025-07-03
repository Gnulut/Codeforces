#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t,n,k,l;
	cin>>t;
	while(t--){
		cin>>n>>k>>l;
		k*=2;
		l*=2;
		vector<int> scare(n);
		for(int i=0;i<n;++i){
			cin>>scare[i];
			scare[i]*=2;
		}
		int cpos=k,time=scare[0],next_scare=1;
		//cout<<"init: "<<cpos<<"  time "<<time<<"\n";
		while(cpos<l&&next_scare<n){
			int dif = scare[next_scare]-cpos;
			if(dif<0){
				int difdif=min(0,dif+time);
				cpos = cpos + difdif + k;
				next_scare++;
			}else{
				int difdif=max(0,dif-time);
				int dtime=difdif/2;
				time+=dtime;
				cpos = cpos + dtime + k;
				next_scare++;
			}
			//cout<<"next scare = "<<next_scare<<"  time = "<<time<<"\n";
		}
		if(cpos<l)time+=l-cpos;
		cout<<time<<"\n";
	}
}
