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

    int rows[100] = {0};
    for(int i=99;i>=0;i--){
    	for(int j=0;j<n;j++){
    		if (arr[j]>i) rows[i]++;
    	}
    }

//    for(int i=0;i<100;i++){
//    	cout<<i<<" "<<rows[i]<<endl;
//    }

    int newrows[n];
    for(int i=0;i<n;i++){
    	newrows[i]=0;
    	for(int j=0;j<100;j++){
    		if (rows[j]>=n-i) newrows[i]++;
    	}
    }

    for(int i=0;i<n;i++){
    	cout<<newrows[i]<<" ";
    }
    cout<<endl;

}
