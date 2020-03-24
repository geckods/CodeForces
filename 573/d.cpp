#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;

    ll arr[n];
    map<ll,ll> myMap;
    ll sum=0;
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    	myMap[arr[i]]++;
    	sum+=arr[i];
    }

    bool twocount=false;
    for(map<ll,ll>::iterator i=myMap.begin();i!=myMap.end();i++){
    	if(i->second == 2){
    		if(i->first==0 || myMap[i->first-1]>0){
    			cout<<"cslnb"<<endl;
    			return 0;
    			//first guy loses
    		}
    		else{
    			if(!twocount){
    				twocount=true;
    			}
    			else{
	    			cout<<"cslnb"<<endl;
    				return 0;

    				//first guy loses
    			}
    		}
    	}
    	else if (i->second > 2){
    		cout<<"cslnb"<<endl;
    		return 0;
    		//first guy loses
    	}
    }


    sum-=((n)*(n-1))/2;

    if(sum%2==0){
    	cout<<"cslnb"<<endl;
    	return 0;
    	//first guy loses
    }

    cout<<"sjfnb"<<endl;
}
    // if(twocount>1)

