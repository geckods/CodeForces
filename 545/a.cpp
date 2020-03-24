#include <bits/stdc++.h>
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }
    
    int prev=arr[0];
    int zc=0;
    int oc=0;
    if(prev==1)zc++;
    else oc++;

    int max=0;
    int curr;
    int newans;

    for(int i=1;i<n;i++){
    	curr=arr[i];
//    	cout<<i<<" "<<arr[i]<<" "<<zc<<" "<<oc<<endl;
    	if(curr==prev){
		    if(prev==1)zc++;
    		else oc++;
    	}
    	else{
    		newans=min(zc,oc);
    		if(newans>max)max=newans;
    		if(curr==1)zc=1;
    		else oc=1;
    	}
    	prev=curr;
    }

    newans=min(zc,oc);
    if(newans>max)max=newans;


    cout<<max*2<<endl;
}
