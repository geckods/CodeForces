#include <bits/stdc++.h>
using namespace std;

int main(){
	
//	#ifndef ONLINE_JUDGE
//    	freopen("input", "r", stdin);
//    	freopen("output", "w", stdout);
//	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    set<int> mySet;

    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }

    int i=0;
    int ans=0;
    while(i<n){
    	ans++;
	    mySet.insert(arr[i]);
    	cout<<mySet.size()<<" "<<i<<endl;
    	while(mySet.size()>0){
    		if(mySet.find(i+1)!=mySet.end())
	    		mySet.erase(i+1);
    		i++;
    		mySet.insert(arr[i]);
    	}
    }

    cout<<ans<<endl;
}
