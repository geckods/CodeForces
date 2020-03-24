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

    ll t;
    cin>>t;

    for(int test=0;test<t;test++){
    	int n;
    	cin>>n;

    	int arr[n];
    	for(int i=0;i<n;i++){
    		cin>>arr[i];
    	}

    	map<int,int> myMap;
    	int ans=INT_MAX;

    	for(int i=0;i<n;i++){
    		myMap[arr[i]]=-1;
    	}

    	for(int i=0;i<n;i++){
    		if(myMap[arr[i]]!=-1)
	    		ans=min(ans,i-myMap[arr[i]]+1);
    		myMap[arr[i]]=i;
    	}

    	if(ans >= INT_MAX -2){
    		cout<<-1<<endl;
    	}
    	else{
    		cout<<ans<<endl;
    	}

    }
}