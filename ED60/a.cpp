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

    int max=0;
    int maxind=0;
    for(int i=0;i<n;i++){
    	if(arr[i]>max){
    		max=arr[i];
    		maxind=i;
    	}
    }

    int j=0;
    int flag=0;
    int minians,ans=0;

    for(int i=0;i<n;i++){
    	if(arr[i]==max){
    		if(flag==0){
    			j=i;
    		}
    		flag=1;
    	}
    	else{
    		if(flag==1){
    			minians = i-j;
    			if(minians>ans) ans=minians;
    		}
    		flag=0;
    	}
    }
    if(flag==1){
	    minians = n-j;
	    if(minians>ans) ans=minians;
	}
    if(ans==0){
    	ans=1;
    }

    cout<<ans<<endl;
}
