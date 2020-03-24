#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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

    ll arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }

    vector<ll> bestVec;
    ll bestSum=0;

    for(int i=0;i<n;i++){
    	//ith is max
    	ll minisum=0;
    	ll curr;
    	vector<ll> tempVec;
    	tempVec.push_back(arr[i]);
    	minisum+=arr[i];
    	curr=arr[i];
    	for(int j=i-1;j>=0;j--){
    		curr=min(curr,arr[j]);
    		minisum+=curr;
    		tempVec.push_back(curr);
    	}
    	reverse(tempVec.begin(),tempVec.end());
    	curr=arr[i];
    	for(int j=i+1;j<n;j++){
    		curr=min(curr,arr[j]);
    		minisum+=curr;
    		tempVec.push_back(curr);   		
    	}

    	if(minisum>bestSum){
    		bestSum=minisum;
    		bestVec=tempVec;
    	}
    }

    // cout<<bestSum<<endl;
    for(int i=0;i<n;i++){
    	cout<<bestVec[i]<<" ";
    }
    cout<<endl;
}