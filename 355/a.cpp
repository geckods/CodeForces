#include <bits/stdc++.h>
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif

    int n,h;
    cin>>n>>h;
    int arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }

    int height = 0;
    for(int i=0;i<n;i++){
    	if (arr[i]>h) height+=1;
    	height+=1;
    }

    cout<<height;
}