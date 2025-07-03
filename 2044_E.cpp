#include<bits/stdc++.h>
using namespace std;

int main(){
	long long t,k,l1,r1,l2,r2;
	cin>>t;
	while(t--){
		cin>>k>>l1>>r1>>l2>>r2;
		long long ans=0;
		while(r2>=l1){
//			if(l2<=l1&&r1<=r2){// area 1 inside area 2
//				ans+=r1-l1+1;
//			}else if(l1<=l2&&r2<=r1){// area 2 inside area 1
//				ans+=r2-l2+1;
//			}else if(l2<=l1&&l1<=r2){// area 1 left slice with area 2
//				ans+=r2-l1+1;
//			}else if(l2<=r1&&r1<=r2){// area 1 right slice with area 2
//				ans+=r1-l2+1;
//			}else{// out of range
//			}
			if(min(r1,r2)-max(l1,l2)>=0){
				ans += min(r1,r2) - max(l1,l2) + 1;
			}
			r2 /= k;
			l2 = l2/k + !!(l2%k);
		}
		cout<<ans<<"\n";
	}
}
