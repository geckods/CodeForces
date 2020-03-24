#include <bits/stdc++.h>
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }

    int ans=0;
    for(int i=0;i<n-1;i++){
    	if(arr[i]==1){
    		if(arr[i+1]==2){
    			if(i>0 && arr[i-1]==3){
    				ans--;
    			}
    			ans+=3;
    		}
    		else{
    			ans+=4;
    		}
    	}
    	else if (arr[i]==2){
    		if(arr[i+1]==1){
    			ans+=3;
    		}
    		else{
    			cout<<"Infinite"<<endl;
    			return 0;
    		}
    	}
    	else{
    		if(arr[i+1]==1){
    			ans+=4;
    		}
    		else{
    			cout<<"Infinite"<<endl;
    			return 0;    			
    		}
    	}
    }

    cout<<"Finite"<<endl;
    cout<<ans<<endl;

}
