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

    ll n,k;
    cin>>n>>k;

    vector<intpair> myVec;

    ll arr[n];
    ll x;
    for(int i=0;i<n;i++){
    	cin>>x;
    	arr[i]=x;
    	myVec.push_back({x,i});
    }

    sort(myVec.begin(),myVec.end());
    // reverse(myVec.begin(),myVec.end());

    // check if second will do

    ll toIns = k-2;

    if(toIns==n-2){
    	ll evenMax = 0;
    	ll oddMax = 0;
    	for(int i=0;i<n;i++){
    		if(i%2==1){
    			oddMax=max(oddMax,arr[i]);
    		}
    		else{
    			evenMax=max(evenMax,arr[i]);
    		}
    	}
    	cout<<min(evenMax,oddMax)<<endl;
    	return 0;
    }

    if(toIns==0){
    	cout<<myVec[0].first<<endl;
    	return 0;
    }

    bool seen[n];
    memset(seen,false,sizeof(seen));
    ll sc=0;

    if(k%2==1)toIns--;

    for(int i=0;i<n;i++){

    	if(sc>=toIns){
    		cout<<myVec[i].first<<endl;
    		return 0;
    	}

    	bool isNew = true;
    	if(myVec[i].second>0 && seen[myVec[i].second-1]){
    		isNew=false;
    	}

    	if(myVec[i].second<n-1 && seen[myVec[i].second+1]){
    		isNew=false;
    	}

    	seen[myVec[i].second]=true;

    	sc++;
    	if(isNew){
    		sc++;
    	}


    }

}