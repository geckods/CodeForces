#include <bits/stdc++.h>
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin>>q;

    for(int quer=0;quer<q;quer++){
    	int n;
    	cin>>n;

    	int arr[n];
    	for(int i=0;i<n;i++){
    		cin>>arr[i];
    	}

    	sort(arr,arr+n);

    	bool two=false;
    	for(int i=1;i<n;i++){
    		if(arr[i]==arr[i-1]+1){
    			two=true;
    			break;
    		}
    	}

    	if(two){
    		cout<<2<<endl;
    	}
    	else{
    		cout<<1<<endl;
    	}
    }

}
