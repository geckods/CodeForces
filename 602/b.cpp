#include <bits/stdc++.h>
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    for(int test=0;test<t;test++){
    	int n;
    	cin>>n;

    	int arr[n];
    	for(int i=0;i<n;i++){
    		cin>>arr[i];
    	}

    	int ans[n];
    	int curr=0;

    	
    	set<int> mySet;

    	for(int i=1;i<=n;i++){
    		mySet.insert(-i);
    	}

    	bool works=true;
    	for(int i=0;i<n;i++){
    		if(arr[i]>curr){
    			ans[i]=arr[i];
    			curr=arr[i];
    			mySet.erase(mySet.find(-arr[i]));
    		}
    		else{
    			auto it = mySet.lower_bound(-curr);
    			if(it==mySet.end()){
    				works=false;
    				break;
    			}
    			ans[i]=-1*(*it);
    			mySet.erase(it);
    		}
    	}

    	if(!works){
    		cout<<-1<<endl;
    	}
    	else{
    		for(int i=0;i<n;i++){
    			cout<<ans[i]<<" ";
    		}
    		cout<<endl;
    	}

    }
}