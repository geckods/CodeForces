#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//looked at editorial to solve

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin>>q;

    for(int quer=0;quer<q;quer++){
    	int n;
    	cin>>n;

    	int arr[n];

    	map<int,int> minmap;
    	map<int,int> maxmap;

    	for(int i=0;i<n;i++){
    		maxmap[i]=-1;
    		minmap[i]=n+1;
    	}

    	set<int> mySet;
    	for(int i=0;i<n;i++){
    		cin>>arr[i];
    		arr[i]--;
    		mySet.insert(arr[i]);
    		if(minmap[arr[i]]==n+1)minmap[arr[i]]=i;
    		maxmap[arr[i]]=i;
    	}

    	// vector<int> myVec;
    	// for(auto it=mySet.begin();it!=mySet.end();it++){
    	// 	myVec.push_back(*it);
    	// }

    	// int prefixmax[n];
    	// prefixmax[0]=maxmap[0];
    	// for(int i=1;i<n;i++){
    	// 	prefixmax[i]=max(maxmap[i],prefixmax[i-1]);
    	// }


    	// int suffixmin[n];
    	// suffixmin[n-1]=minmap[n-1];
    	// for(int i=n-2;i>=0;i--){
    	// 	suffixmin[i]=min(minmap[i],suffixmin[i+1]);
    	// }



    	// for(int i=0;i<n;i++){
	    // 	cout<<i<<" "<<prefixmax[i]<<" "<<suffixmin[i]<<endl;
	    // 	cout<<i<<" "<<maxmap[i]<<" "<<minmap[i]<<endl;
	    // }

    	// int backsolve[n];
    	// memset(backsolve,0,sizeof(backsolve));

    	// backsolve[n-1]=0;
    	// for(int i=n-2;i>=0;i--){
    	// 	backsolve[i]=backsolve[i+1];
    	// 	if(suffixmin[i+1]<maxmap[i]){
    	// 		backsolve[i]++;
    	// 	}
    	// }

    	// // for(int i=0;i<n;i++){
    	// // 	cout<<i<<" "<<backsolve[i]<<endl;
    	// // }

    	int ans=mySet.size()-1;    

    	// int curr=0;
    	// int minians;
    	// for(int i=0;i<n-1;i++){

    	// 	if(i>0 && prefixmax[i-1]>minmap[i]){
    	// 		curr++;
    	// 	}
    	// 	minians=curr+backsolve[i+1];
    	// 	if(prefixmax[i]>suffixmin[i+1]){
    	// 		minians++;
    	// 	}
    	// 	cout<<i<<" "<<curr<<" "<<backsolve[i]<<" "<<minians<<endl;
    	// 	ans=min(ans,minians);
    	// }


    	int currrangesize=0;
    	int currminind=n;
    	for(int i=n-1;i>=0;i--){
    		if(maxmap[i]==-1)continue;
    		if(maxmap[i]<currminind){
    			currrangesize++;
    			currminind=minmap[i];
    		}
    		else{
    			currminind=minmap[i];
    			currrangesize=1;
    		}
    		// cout<<i<<" "<<currrangesize<<endl;
    		ans=min(ans,(int)mySet.size()-currrangesize);
    	}

    	// cout<<"HI"<<endl;



    	cout<<ans<<endl;
    }
}