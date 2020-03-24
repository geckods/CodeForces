#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> intpair;

ll mostFrequent(ll arr[], ll n) 
{ 
    sort(arr, arr + n); 
  
    ll max_count = 1, res = arr[0], curr_count = 1; 
    for (ll i = 1; i < n; i++) { 
        if (arr[i] == arr[i - 1]) 
            curr_count++; 
        else { 
            if (curr_count > max_count) { 
                max_count = curr_count; 
                res = arr[i - 1]; 
            } 
            curr_count = 1; 
        } 
    } 
  
    if (curr_count > max_count) 
    { 
        max_count = curr_count; 
        res = arr[n - 1]; 
    } 
  
    return res; 
}

bool isAP(vector<intpair> myVec){
	set<ll> seendiffs;
	sort(myVec.begin(),myVec.end());
    for(int i=1;i<myVec.size();i++){
    	seendiffs.insert(myVec[i].first-myVec[i-1].first);
    }
    if(seendiffs.size()==1){
    	return true;
    }
    else{
    	return false;
    }
}


int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;


    vector<intpair> arr;

    ll x;
    for(int i=0;i<n;i++){
    	cin>>x;
    	arr.push_back(make_pair(x,i));
    }

    // if(n==2||n==3){
    // 	cout<<1<<endl;
    // 	return 0;
    // }


    sort(arr.begin(),arr.end());


    ll diffprev[n];
    // ll diffaccross[n];

    set<ll> seendiffs;
    for(int i=1;i<n;i++){
    	diffprev[i]=arr[i].first-arr[i-1].first;
    	seendiffs.insert(diffprev[i]);
    	// cout<<diffprev[i]<<endl;
    	// if(i<n-1){
    	// 	diffaccross[i]=arr[n+1].first-arr[n-1].first;
    	// }
    }

    if(seendiffs.size()>3){
    	cout<<-1<<endl;
    	return 0;
    }

    // cout<<seendiffs.size()<<endl;
    if(seendiffs.size()==1){
    	cout<<arr[0].second+1<<endl;
    	return 0;
    }


    if(n<10){//special case, tough to tell which is actual diff
    	for(int i=0;i<n;i++){
	    	vector<intpair> newVec;
    		for(int j=0;j<n;j++){
    			if(i!=j)newVec.push_back(arr[j]);
    		}
    		if(isAP(newVec)){
    			cout<<arr[i].second+1<<endl;
    			return 0;
    		}
    	}
    	cout<<-1<<endl;
    	return 0;
 	}
    else{
    	ll diff[n-1];
    	for(int i=1;i<n;i++){
    		diff[i-1]=diffprev[i];
    	}
    	ll actualdiff=mostFrequent(diff,n-1);
    	ll ans=-1;
    	for(int i=1;i<n;i++){
    		if(diffprev[i]!=actualdiff){
    			if(i>1 || diffprev[2]!=actualdiff){
    				ans=i;
    			}
    			else{
    				ans=0;
    			}

    			if(ans!=-1){
    				vector<intpair> newVec;
    				for(int z=0;z<n;z++){
    					if(z!=ans)newVec.push_back(arr[z]);
    				}
			    	if(isAP(newVec)){
    					cout<<arr[ans].second+1<<endl;
    					return 0;
    				}
    				else{
    					ans=-1;
			    	}
    			}

    		}
    	}
    	cout<<-1<<endl;

    }
}