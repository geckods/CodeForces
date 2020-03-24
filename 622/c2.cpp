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

    ll dpf[n];
    ll dpb[n];

    ll leftless[n];
    stack<pair<ll,ll>> myStack;
    for(int i=0;i<n;i++){
    	while(!myStack.empty() && myStack.top().first>arr[i])myStack.pop();
    	if(myStack.empty()){
    		leftless[i]=INT_MIN;
    	}
    	else{
    		leftless[i]=myStack.top().second;
    	}
    	myStack.push({arr[i],i});
    }

    ll rightless[n];
    stack<pair<ll,ll>> myStack2;
    for(int i=n-1;i>=0;i--){
    	while(!myStack2.empty() && myStack2.top().first>arr[i])myStack2.pop();
    	if(myStack2.empty()){
    		rightless[i]=INT_MIN;
    	}
    	else{
    		rightless[i]=myStack2.top().second;
    	}
    	// cerr<<i<<" "<<rightless[i]<<" "<<my<<endl;
    	myStack2.push({arr[i],i});
    }


    // vector<pair<ll,ll>>myVec;
    // for(int i=0;i<n;i++){
    // 	myVec.push_back({arr[i],i});
    // }

    // sort(myVec.begin(),myVec.end());

    // ll suffixmin[n];
    // suffixmin[n-1]=myVec[n-1].second;
    // for(int i=n-2;i>=0;i--){
    // 	suffixmin[i]=min(suffixmin[i+1],myVec[i].second);
    // }

    // ll suffixmax[n];
    // suffixmax[n-1]=myVec[n-1].second;
    // for(int i=n-2;i>=0;i--){
    // 	suffixmax[i]=max(suffixmax[i+1],myVec[i].second);
    // }


    // ll earliestgreater[n];

    // for(int i=n-1;i>=0;i--){
    // 	int j=upper_bound(myVec.begin(),myVec.end(),make_pair(myVec[i].first,(ll)INT_MAX))-myVec.begin();
    // 	if(j==n){
    // 		earliestgreater[myVec[i].second]=INT_MAX;
    // 	}
    // 	else{
    // 		earliestgreater[myVec[i].second]=suffixmin[j];
    // 	}
    // }

    dpf[0]=arr[0];
    for(int i=1;i<n;i++){
    	// cerr<<i<<endl;
    	if(arr[i]>arr[i-1]){
    		dpf[i]=dpf[i-1]+arr[i];
    	}
    	else{
    		ll minians=0;
    		if(leftless[i]==INT_MIN){
    			minians=(i+1)*arr[i];
    		}
    		else{
	    		minians=dpf[leftless[i]];
	    		minians+=(i-leftless[i])*arr[i];    			
    		}
    		dpf[i]=minians;
    	}
    	// cerr<<i<<" "<<dpf[i]<<endl;
    }


    // ll latestgreater[n];

    // int j=n;
    // for(int i=n-1;i>=0;i--){
    // 	int j=upper_bound(myVec.begin(),myVec.end(),make_pair(myVec[i].first,(ll)INT_MAX))-myVec.begin();
    // 	// cerr<<i<<" "<<j<<endl;
    // 	if(j==n){
    // 		latestgreater[myVec[i].second]=INT_MIN;
    // 	}
    // 	else{
    // 		latestgreater[myVec[i].second]=suffixmax[j];
    // 	}
    // }


    dpb[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--){
    	// cerr<<i<<" "<<latestgreater[i]<<endl;
    // cerr<<i<<" "<<latestgreater[i]<<endl;
    	// cerr<<i<<" "<<rightless[i]<<endl;
    	if(arr[i]>arr[i+1]){
    		dpb[i]=dpb[i+1]+arr[i];
    	}
    	else{
    		ll minians=0;
    		if(rightless[i]==INT_MIN){
    			minians=(n-i)*arr[i];
    		}
    		else{
	    		minians=dpb[rightless[i]];
	    		minians+=(rightless[i]-i)*arr[i];    			
    		}
    		dpb[i]=minians;
    	}
    	// cerr<<i<<" "<<dpb[i]<<endl;
    }

    ll ansj=-1;
    ll currbest=0;
    for(int i=0;i<n;i++){
    	// cerr<<i<<" "<<dpf[i]<<" "<<dpb[i+1]<<" "<<dpf[i]+dpb[i+1]<<endl;

    	if(i<n-1 && dpf[i]+dpb[i+1]>currbest){
    		currbest=dpf[i]+dpb[i+1];
    		ansj=i;
    	}
        else if (i==n-1 && dpf[i]>currbest)ansj=i;
    }

    cerr<<ansj<<endl;

	vector<ll> tempVec;
	tempVec.push_back(arr[ansj]);
	ll curr=arr[ansj];
	for(int j=ansj-1;j>=0;j--){
		curr=min(curr,arr[j]);
		tempVec.push_back(curr);
	}
	reverse(tempVec.begin(),tempVec.end());
	curr=arr[ansj+1];
    tempVec.push_back(curr);
	for(int j=ansj+2;j<n;j++){
		curr=min(curr,arr[j]);
		tempVec.push_back(curr);   		
	}

	for(int i=0;i<n;i++){
		cout<<tempVec[i]<<" ";
	}

	cout<<endl;

}
