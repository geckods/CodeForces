#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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

    int end[n];
    int count=0;
    int ans=0;
    for(int i=0;i<n;i++){
    	if(i==0 || arr[i]>arr[i-1]){
    		count++;
    	}
    	else{
    		count=1;
    	}
    	end[i]=count;
    	ans=max(ans,end[i]);
    }

    int start[n];
	count=0;
    for(int i=n-1;i>=0;i--){
    	if(i==n-1 || arr[i]<arr[i+1]){
    		count++;
    	}
    	else{
    		count=1;
    	}
    	start[i]=count;
    	ans=max(ans,start[i]);
    }


    ans=max(ans,start[0]);
    ans=max(ans,end[n-1]);
    // cout<<ans<<endl;
    for(int i=1;i<n-1;i++){
    	if(arr[i-1]<arr[i+1]){
    		ans=max(ans,end[i-1]+start[i+1]);
    	}
    	else{
    		ans=max(ans,max(end[i-1],start[i+1]));
    	}
    }

    cout<<ans<<endl;
}