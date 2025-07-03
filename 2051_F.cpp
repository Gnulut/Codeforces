#include<bits/stdc++.h>
using namespace std;

int main(){
	//ios::sync_with_stdio(0);cin.tie(0);
	int t,n,m,q;
	cin>>t;
	while(t--){
		cin>>n>>m>>q;
		vector<pair<int,int>> segments={{m,m}};
		while(q--){
			int pos;
			cin>>pos;
			if(segments.front()==pair<int,int>({1,n})){//full
				cout<<n<<" ";
				continue;
			}
			// if any segment is pos
			bool middle=false;
			for(auto&segment:segments){
				if(segment.first<=pos&&pos<=segment.second){
					middle=true;
					break;
				}
			}
			if(middle){
				int size=segments.size();
				int erase_after=-1;
				for(int i=0;i<size;++i){
					if(i==0){
						if(segments[i].first!=1){
							segments.push_back({1,1});
						}
					}
					if(i==size-1){
						if(segments[i].second!=n){
							segments.push_back({n,n});
						}
					}
					if(segments[i].first<=pos&&pos<=segments[i].second){
						if(segments[i].first==segments[i].second&&segments[i].first!=1&&segments[i].first!=n){
							erase_after=i;
						}
					}else{
						if(segments[i].second<pos){
							segments[i].second++;
						}else{
							segments[i].first--;
						}
					}
				}
				if(erase_after!=-1){
					segments.erase(segments.begin()+erase_after);
				}
			}else{// no segment selected
				for(auto&segment:segments){
					if(segment.second<pos){
						segment.second++;
					}else{
						segment.first--;
					}
				}
			}
//			cout<<"\n"<<"outputing segments: ";
//			for(auto&segment:segments){
//				cout<<segment.first<<" "<<segment.second<<"   ";
//			}
//			cout<<"\n";
			sort(segments.begin(),segments.end());
			for(int i=1;i<segments.size();){
				if(segments[i].first<=segments[i-1].second+1){
					segments[i-1].second=segments[i].second;
					segments.erase(segments.begin()+i);
				}else{
					i++;
				}
			}
			int ans=0;
			for(auto&segment:segments){
				ans+=segment.second-segment.first+1;
			}
			cout<<ans<<" ";
//			cout<<"\n"<<"outputing segments: ";
//			for(auto&segment:segments){
//				cout<<segment.first<<" "<<segment.second<<"   ";
//			}
//			cout<<"\n";
		}
		cout<<"\n";
	}
}
