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

    int i=0;
    int j=n-1;

    int asum=0;
    int bsum=0;

    while(i<=j){


    	if(arr[i]>arr[j]){
    		asum+=arr[i++];
    	}
    	else{
    		asum+=arr[j--];    		
    	}

    	if(i>j)break;

    	if(arr[i]>arr[j]){
    		bsum+=arr[i++];
    	}
    	else{
    		bsum+=arr[j--];    		
    	}

    }

    cout<<asum<<" "<<bsum<<endl;

}
