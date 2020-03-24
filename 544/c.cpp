#include <bits/stdc++.h>
using namespace std;


int binarySearch(int arr[], int l, int r, int x) 
{ 
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
  
    // We reach here when element is not 
    // present in array 
    return l; 
} 

int main(){
    
    #ifndef ONLINE_JUDGE
        freopen("input", "r", stdin);
        freopen("output", "w", stdout);
    #endif

//    int arr[10] = {1,1,1,5,6,7,9,11,13,22};

    //binary search returns the index of the number greater than or equal to x

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<int> v(arr,arr+n);
    sort(v.begin(),v.end());

    int max=0;
    int ans;
    for(int i=0;i<n;i++){
        vector<int>::iterator upper = upper_bound(v.begin(),v.end(),v[i]+5);
        ans=(upper-v.begin());
//        cout<<i<<" "<<v[i]<<" "<<ans<<" "<<ans-i<<endl;
        if(ans-i>max) max=ans-i;
    }
    cout<<max<<endl;

//    cout<<binarySearch(arr,0,9,1)<<endl;
}