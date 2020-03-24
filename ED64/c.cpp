#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> intpair;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    int z;
    cin>>z;

    int arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }

    sort(arr,arr+n);

    int ans=0;
    int k;
    set<intpair> myset;


    for(int i=n-1;i>=0;i--){
    	myset.insert(make_pair(arr[i],i));
    	set<intpair>::iterator k = myset.lower_bound(make_pair(arr[i]+z,0));
    	if(k!=myset.end() || (*k).first >= arr[i]+z){
    		ans+=1;
    		if(!myset.empty()){
	    		myset.erase(k);
	    	}
    		if(!myset.empty()){
	    		myset.erase(myset.find(make_pair(arr[i], i)));
	    	}
    	}
    }

    cout<<ans<<endl;
}