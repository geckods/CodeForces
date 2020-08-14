#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> intpair;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	// =

	ll n,m;
	cin>>n>>m;

	ll arr[m];
	vector<intpair> myVec;
	ll sum=0;
	for(int i=0;i<m;i++){
		cin>>arr[i];
		myVec.push_back({arr[i],i});
		sum+=arr[i];
	}

	if(sum<n){
		cout<<-1<<endl;
		return 0;
	}

	// sort in decreasing order, assign to next one while you can
	// the moment your rightsum is less than the leftover, go back, pick accordingly

	bool works=true;

	sort(myVec.begin(),myVec.end());
	reverse(myVec.begin(),myVec.end());


	ll currstart=0;
	ll currInd=0;
	ll leftOver=sum;

	ll lastFilled=-1;

	vector<intpair> ans;

	while(1){
		cerr<<" "<<currstart<<" "<<lastFilled<<" "<<currInd<<" "<<leftOver<<" "<<n-lastFilled-1<<endl;
		if(n-lastFilled-1 > leftOver){
			if(currstart==0)break;
			currstart--;
			leftOver+=myVec[currInd].first;
			currInd--;
			ans.erase(ans.end()-1);
			break;
		}

		// if(currstart+myVec[currInd].first-1>=n){
		// 	cout<<-1<<endl;
		// 	return 0;
		// }

		ans.push_back({myVec[currInd].second,currstart});
		lastFilled=max(lastFilled,currstart+myVec[currInd].first-1);
		leftOver-=myVec[currInd].first;
		currInd++;
		currstart++;
		if(lastFilled>n-1){
			cout<<-1<<endl;
			return 0;
		}

		if(lastFilled==n-1){
			break;
		}
	}

	// cerr<<ans.size()<<endl;
	// for(int i=0;i<ans.size();i++){
	// 	cerr<<ans[i].first<<" "<<ans[i].second<<endl;
	// }

	// cerr<<leftOver<<endl;
	// leftover

	if(currInd<m){
		cerr<<currstart<<" "<<currInd<<endl;
		ans.push_back({myVec[currInd].first,currstart});
		currstart+=myVec[currInd].first;
		// cerr<<currstart<<" "<<currInd<<endl;
		currInd++;		
	}

	// cerr<<currstart<<endl;

	while(currInd<m){
		ans.push_back({myVec[currInd].second,currstart});
		currstart+=myVec[currInd].first;
		currInd++;
	}

	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++){
		cout<<ans[i].second+1<<" ";
	}


}
