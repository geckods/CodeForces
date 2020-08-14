#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// THINGS TO REMEMBER
// ENDL is slow, '\n' is fast
// Clear everything (including graphs) between test cases
// use anti-anti-hash: https://codeforces.com/blog/entry/62393
// pb-ds: https://codeforces.com/blog/entry/11080
// check when to use LLONG_MAX/LLONG_MIN vs INT_MAX or INT_MIN
// You frequently suffer from confirmation bias - you trust your initial solution and miss simple things. 
// When you hit a roadblock, remember to rethink the solution ground up, not just try hacky fixes

typedef pair<ll,ll> intpair;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

 	ll n,m;
 	cin>>n>>m;

 	ll food[n];
 	for(int i=0;i<n;i++){
 		cin>>food[i];
 	}

 	ll foodDemand[m];
 	memset(foodDemand,0,sizeof(foodDemand));

 	ll likes[m][2];

 	for(int i=0;i<m;i++){
 		cin>>likes[i][0]>>likes[i][1];
 		likes[i][0]--;
 		likes[i][1]--;
 		foodDemand[likes[i][0]]++;
 		foodDemand[likes[i][1]]++;
 	}

 	// for(int i=0;i<n;i++){
 	// 	cerr<<i<<" "<<food[i]<<" "<<foodDemand[i]<<endl;
 	// }

 	bool skip[m];
 	memset(skip,false,sizeof(skip));

 	for(int i=0;i<m;i++){
 		ll likes1 = likes[i][0];
 		ll likes2 = likes[i][1];

 		ll diff1 = foodDemand[likes1]-food[likes1];
 		ll diff2 = foodDemand[likes2]-food[likes2];

		if(min(diff1,diff2)<=0){
			skip[i]=true;
			foodDemand[likes1]--;
			foodDemand[likes2]--;
		} 		
 	}


 	vector<pair<intpair,ll>> myVec;



 	for(int i=0;i<m;i++){
 		if(skip[i])continue;
 		ll likes1 = likes[i][0];
 		ll likes2 = likes[i][1];

 		ll diff1 = foodDemand[likes1]-food[likes1];
 		ll diff2 = foodDemand[likes2]-food[likes2];

 		intpair pair1 = {diff1, -foodDemand[likes1]};
 		intpair pair2 = {diff2, -foodDemand[likes2]};

 		// min[]
 		// cerr<<i<<" "<<min(pair1,pair2).first<<" "<<min(pair1,pair2).second<<endl;

 		myVec.push_back({min(pair1,pair2),i});
 	}

 	sort(myVec.begin(),myVec.end());
 	reverse(myVec.begin(),myVec.end());

 	for(int i=0;i<m;i++){
 		if(skip[i])
	 		myVec.push_back({{0,0},i});
 	}

 	ll foodCopy[n];
 	for(int i=0;i<n;i++){
 		foodCopy[i]=food[i];
 	}

 	for(int i=0;i<m;i++){
 		ll currDude = myVec[i].second;

 		ll likes1 = likes[currDude][0];
 		ll likes2 = likes[currDude][1];

 		if(foodCopy[likes1]<=0 && foodCopy[likes2]<=0){
 			cout<<"DEAD"<<endl;
 			return 0;
 		}
 		else{
 			foodCopy[likes1]--;
 			foodCopy[likes2]--;
 		}
 	}


 	cout<<"ALIVE"<<endl;
 	for(int i=0;i<m;i++){
 		cout<<myVec[i].second+1<<" ";
 	}
 	cout<<endl;
 	// bool foodWillFinish[n];
 	// memset(foodWillFinish,false,sizeof(foodWillFinish));

 	// for(int i=0;i<n;i++){
 	// 	if(foodDemand[i]>=food[i]){
 	// 		foodWillFinish[i]=true;
 	// 	}
 	// }

 	// bool dudeNoProblem[m];
 	// memset(dudeNoProblem, false, sizeof(dudeNoProblem));



}