#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef pair<int,int> intpair;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }

    //we need to bfs

    //store target, start

    set<intpair> jumpSet;

    int ans[n];
    for(int i=0;i<n;i++){
    	ans[i]=INT_MAX;
    }


    int jumplo,jumphi;


    queue<intpair>myQ;

    for(int i=0;i<n;i++){

		jumplo=i-arr[i];
		jumphi=i+arr[i];

		if(jumplo>=0)
	    	jumpSet.insert({jumplo,i});
    
    	if(jumphi<n)
	    	jumpSet.insert({jumphi,i});

    	if((jumplo>=0 && arr[jumplo]%2!=arr[i]%2) || (jumphi<n && arr[jumphi]%2!=arr[i]%2)){
    		ans[i]=1;
    		myQ.push({i,1});
    	}
    }

    while(!myQ.empty()){
    	intpair frontpair = myQ.front();
    	myQ.pop();

    	int curr=frontpair.first;
    	int currval=frontpair.second;

    	// cerr<<curr<<" "<<currval<<endl;

		auto it = jumpSet.lower_bound({curr,-1});
		while(it!=jumpSet.end() && it->first==curr){
			if(ans[it->second]==INT_MAX){
				ans[it->second]=currval+1;
				myQ.push({it->second,currval+1});
			}
			it++;
		}    	
    }

    for(int i=0;i<n;i++){
    	if(ans[i]==INT_MAX)ans[i]=-1;
    	cout<<ans[i]<<" ";
    }
    cout<<endl;
}