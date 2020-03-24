#include <bits/stdc++.h>
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif

    int n,q;
    cin>>n>>q;

    int arr[q][2];
    for(int i=0;i<q;i++){
    	cin>>arr[i][0]>>arr[i][1];
    	arr[i][0]--;
    	arr[i][1]--;
    }

    int cumarr[n];
    for(int i=0;i<n;i++){
    	cumarr[i]=0;
    }

    for(int i=0;i<q;i++){
    	cumarr[arr[i][0]]++;
    	if(!(arr[i][1]==n-1)){
	    	cumarr[arr[i][1]+1]--;
	    }
//	    cout<<cumarr[0]<<" "<<cumarr[1]<<endl;
    }



   
    int minzero=1000000;
    int minone=1000000;
    int minj;

    int zerocount=0;
    int onecount=0;
    int curr=0;

    //if none of them create zeroes, you want to minimize the ones

    for(int i=0;i<q;i++){
    	cumarr[arr[i][0]]--;
    	if(arr[i][1]< n)
	    	cumarr[arr[i][1]+1]++;

	    curr=0;
	    zerocount=onecount=0;
	    for(int k=0;k<n;k++){
	    	curr+=cumarr[k];
	    	if(curr==0) zerocount++;
	    	else if (curr==1) onecount++;
	    }

	    cumarr[arr[i][0]]++;
		if(arr[i][1]< n)
	    	cumarr[arr[i][1]+1]--;
	    
	    if(zerocount<minzero || (zerocount==minzero && onecount<minone)){
	    	minzero=zerocount;
	    	minone=onecount;
	    	minj = i;
	    }
    }


//	cout<<minj<<endl;
/*
    int mycurr=0;
	for(int i=0;i<n;i++){
		mycurr+=cumarr[i];
		cout<<mycurr<<" ";
	}
	cout<<endl;
*/

    cumarr[arr[minj][0]]--;
    if(arr[minj][1]< n)
	    cumarr[arr[minj][1]+1]++;


	int maxcount=0;
	int count=0;
    for(int i=0;i<q;i++){
    	if(i==minj) continue;
    	cumarr[arr[i][0]]--;
    	if(arr[i][1]< n)
	    	cumarr[arr[i][1]+1]++;

	    curr=0;
	    count=0;
	    for(int k=0;k<n;k++){
	    	curr+=cumarr[k];
	    	if(curr!=0) count++;
	    }
	    if(count>maxcount) maxcount=count;

	    cumarr[arr[i][0]]++;
		if(arr[i][1]< n)
	    	cumarr[arr[i][1]+1]--;

    }
    cout<<maxcount<<endl;
}