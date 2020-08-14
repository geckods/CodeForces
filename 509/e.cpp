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

    ll n;
    cin>>n;

    ll arr[n-1][2];

    ll maxNode = 0;

    map<ll,ll> numOcc;

    for(int i=0;i<n-1;i++){
    	cin>>arr[i][0]>>arr[i][1];
    	arr[i][0]--;
    	arr[i][1]--;
    	if(arr[i][0]>arr[i][1]){
    		swap(arr[i][0],arr[i][1]);
    	}
    }

    for(int i=0;i<n-1;i++){
    	if(arr[i][1]!=n-1){
    		cout<<"NO"<<endl;
    		return 0;
    	} else {
    		numOcc[arr[i][0]]++;
    	}
    }

    vector<intpair> myVec;

    ll currUnused = 0;
    for(auto it:numOcc){
    	if(it.second==0)continue;
    	while(numOcc[currUnused]>0)currUnused++;
    	ll currNode = n-1;
    	for(int i=0;i<it.second-1;i++){
	    	if(currUnused>it.first){
	    		cout<<"NO"<<endl;
	    		return 0;
	    	}

    		myVec.push_back({currNode,currUnused});
    		currNode=currUnused;
    		currUnused++;
	    	while(numOcc[currUnused]>0)currUnused++;
    	}

    	myVec.push_back({currNode, it.first});
    }

    cout<<"YES"<<endl;
    for(int i=0;i<myVec.size();i++){
    	cout<<myVec[i].first+1<<" "<<myVec[i].second+1<<endl;
    }


}