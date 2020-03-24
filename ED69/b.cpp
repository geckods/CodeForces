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
    int max=INT_MIN;
    int maxind=-1;
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    	if(arr[i]>max){
    		max=arr[i];
    		maxind=i;
    	}
    }

    int a,b;
    a=maxind-1;
    b=maxind+1;

    int currmax=max;

    while(a>=0 || b<n){
    	// cout<<a<<" "<<b<<endl;
    	if(a<0 || ((b<n)&&arr[b]>arr[a])){
    		// cout<<"HI"<<endl;
    		if(arr[b]>currmax){
    			cout<<"NO"<<endl;
    			return 0;
    		}
    		else{
    			currmax=arr[b];
    			b++;
    		}
    	}
    	else if (b>=n || ((a>=0)&&(arr[a]>arr[b]))){
    		if(arr[a]>currmax){
    			cout<<"NO"<<endl;
    			return 0;
    		}
    		else{
    			currmax=arr[a];
    			a--;
    		}
    	}
    }

    cout<<"YES"<<endl;
}