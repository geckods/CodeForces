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

    if(arr[0]!=arr[n-1]){
    	cout<<n-1<<endl;
    	return 0;
    }
    else{
    	int j=0;
    	int k=n-1;
    	while(arr[j]==arr[0])j++;
    	while(arr[k]==arr[0])k--;
    	// cout<<j<<" "<<k<<endl;
    	cout<<max(k,n-j-1)<<endl;
    	return 0;
    }
}
