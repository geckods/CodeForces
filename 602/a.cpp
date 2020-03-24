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

    	vector<pair<int,int> > myVec;
    	int x,y;

    	int highestmin=INT_MIN;
    	int lowestmax=INT_MAX;

    	for(int i=0;i<n;i++){
    		cin>>x>>y;
    		highestmin=max(highestmin,x);
    		lowestmax=min(lowestmax,y);
    		// myVec.push_back(make_pair(x,y));
    	}

    	cout<<max(highestmin-lowestmax,0)<<endl;

    	// sort(myVec.begin(),myVec.end());

    	// int currmin;
    	// int currmax;

    	// int ans=INT_MAX;

    	// currmin=myVec[0].first;
    	// currmax=myVec[0].first;

    	// for(int i=1;i<n;i++){
    	// 	if(myVec[i].first>currmax){
    	// 		currmax=myVec[i].first;
    	// 	}
    	// 	if(myVec[i].second<currmin){
    	// 		currmin=myVec[i].second;
    	// 	}
    	// }

    	// ans=min(ans,currmax-currmin);


    	// currmin=myVec[0].second;
    	// currmax=myVec[0].second;

    	// for(int i=1;i<n;i++){
    	// 	if(myVec[i].first>currmax){
    	// 		currmax=myVec[i].first;
    	// 	}
    	// 	if(myVec[i].second<currmin){
    	// 		currmin=myVec[i].second;
    	// 	}
    	// }

    	// ans=min(ans,currmax-currmin);

    	// cout<<ans<<endl;

    }
}
