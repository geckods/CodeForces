#include <bits/stdc++.h>
using namespace std;


int findrepeat(string t, int len){
	
	int r=len-1;
	int l=0;

	if(r>=l){
		int mid=l+(r-l)/2;

	}

}

/*
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
        // If the element is present at the middle 
        // itself 
        if (arr[mid] == x) 
            return mid; 
  
        // If element is smaller than mid, then 
        // it can only be present in left subarray 
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 
  
        // Else the element can only be present 
        // in right subarray 
        return binarySearch(arr, mid + 1, r, x); 
    }
*/

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif

    string s;
    string t;
    cin>>s;
    cin>>t;

    int n=s.length();

    int zc=0;
    int oc=0;

    for(int i=0;i<n;i++){
    	if(s[i]=='0')zc++;
    	else oc++;
    }

}
