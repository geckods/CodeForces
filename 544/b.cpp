#include <bits/stdc++.h>
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif

    int n;
    int k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    	arr[i]%=k;
    }

    int countarr[k];
    for(int i=0;i<k;i++){
    	countarr[i]=0;
    }

    for(int i=0;i<n;i++){
//    	cout<<i<<" "<<arr[i]<<endl;
    	countarr[arr[i]]++;
    }

    int ans=0;
    if(k%2==0){
    	ans=countarr[0]/2+countarr[k/2]/2;
    	for(int i=1;i<k/2;i++){
    		ans+=min(countarr[i],countarr[k-i]);
    	}
    }
    else{
    	ans=countarr[0]/2;
    	for(int i=1;i<=k/2;i++){
//    		cout<<ans<<endl;
    		ans+=min(countarr[i],countarr[k-i]);
    	}
    }
    cout<<ans*2<<endl;

    
}
