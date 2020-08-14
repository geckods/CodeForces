#include <bits/stdc++.h>
#include <numeric>
using namespace std;
typedef long long ll;
#define endl '\n'
  
ll _mergeSort(ll arr[], ll temp[], ll left, ll right); 
ll merge(ll arr[], ll temp[], ll left, ll mid, ll right); 
  
/* This function sorts the input array and returns the  
number of inversions in the array */
ll mergeSort(ll arr[], ll array_size) 
{ 
    ll temp[array_size]; 
    return _mergeSort(arr, temp, 0, array_size - 1); 
} 
  
/* An auxiliary recursive function that sorts the input array and  
returns the number of inversions in the array. */

ll myLog(ll x){
	ll i=0;
	while(!(x&1)){
		i++;
		x=x>>1;
	}
	return i;
}

ll forwardInversion[21];
ll backwardInversion[21];
bool myforward=true;

ll _mergeSort(ll arr[], ll temp[], ll left, ll right) 
{ 
    ll mid, inv_count = 0; 
    if (right > left) { 
        /* Divide the array into two parts and  
        call _mergeSortAndCountInv()  
        for each of the parts */
        mid = (right + left) / 2; 
  
        /* Inversion count will be sum of  
        inversions in left-part, right-part  
        and number of inversions in merging */
        inv_count += _mergeSort(arr, temp, left, mid); 
        inv_count += _mergeSort(arr, temp, mid + 1, right); 
  
        /*Merge the two parts*/
        ll temp2 = merge(arr, temp, left, mid + 1, right);
        // cerr<<left<<" "<<mid+1<<" "<<right<<" "<<temp2<<endl;
        if(myforward)
	        forwardInversion[myLog(right-left+1)]+=temp2;
	   	else
	        backwardInversion[myLog(right-left+1)]+=temp2;

        inv_count += temp2;
    } 
    return inv_count; 
} 


  
/* This funt merges two sorted arrays  
and returns inversion count in the arrays.*/


ll merge(ll arr[], ll temp[], ll left, 
          ll mid, ll right) 
{ 
    ll i, j, k; 
    ll inv_count = 0; 
  
    i = left; /* i is index for left subarray*/
    j = mid; /* j is index for right subarray*/
    k = left; /* k is index for resultant merged subarray*/
    while ((i <= mid - 1) && (j <= right)) { 
        if (arr[i] <= arr[j]) { 
            temp[k++] = arr[i++]; 
        } 
        else { 
            temp[k++] = arr[j++]; 
  
            /* this is tricky -- see above  
            explanation/diagram for merge()*/
            inv_count = inv_count + (mid - i); 
        } 
    } 
  
    /* Copy the remaining elements of left subarray  
(if there are any) to temp*/
    while (i <= mid - 1) 
        temp[k++] = arr[i++]; 
  
    /* Copy the remaining elements of right subarray  
(if there are any) to temp*/
    while (j <= right) 
        temp[k++] = arr[j++]; 
  
    /*Copy back the merged elements to original array*/
    for (i = left; i <= right; i++) 
        arr[i] = temp[i]; 
  
    return inv_count; 
} 
  
// Driver code 
// THINGS TO REMEMBER
// ENDL is slow, '\n' is fast
// Clear everything (including graphs) between test cases
// use anti-anti-hash: https://codeforces.com/blog/entry/62393
// pb-ds: https://codeforces.com/blog/entry/11080
// check when to use LLONG_MAX/LLONG_MIN vs INT_MAX or INT_MIN
// You frequently suffer from confirmation bias - you trust your initial solution and miss simple things. 
// When you hit a roadblock, remember to rethink the solution ground up, not just try hacky fixes

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;

    ll tpn=1<<n;

    ll arr[tpn];
    for(int i=0;i<tpn;i++){
    	cin>>arr[i];
    }

    ll farr[tpn];
    ll barr[tpn];
    for(int i=0;i<tpn;i++){
    	farr[i]=arr[i];
    	barr[tpn-i-1]=arr[i];
    	// cerr<<i<<" "<<barr[i]<<endl;
    }

    memset(forwardInversion, 0, sizeof(forwardInversion));
    memset(backwardInversion, 0, sizeof(backwardInversion));
    myforward=true;

    mergeSort(farr, tpn);
    myforward=false;
    mergeSort(barr, tpn);

    // for(int i=0;i<=20;i++){
    // 	cerr<<i<<" "<<forwardInversion[i]<<" "<<backwardInversion[i]<<endl;
    // }

    ll currVal=0;
    ll m;
    cin>>m;
	ll ans=0;
	
	ll valcopy;
    ll temp=0;
    while(m--){
    	ll q;
    	cin>>q;
    	currVal^=(1<<q);
    	ans=0;
    	valcopy=0;
    	temp=0;

    	// cerr<<__gcd(1000000000000,1000000000000)<<endl;
    	gcd(1,2);

    	for(int i=20;i>=0;i--){
    		temp^=(currVal>>i)&1;
    		valcopy|=temp<<i;
    	}

    	// cerr<<currVal<<" "<<valcopy<<endl;

    	for(int i=0;i<=20;i++){
    		if(valcopy&1){
    			ans+=backwardInversion[i];
    		}
    		else{
    			ans+=forwardInversion[i];
    		}
    		valcopy=valcopy>>1;
    	}
    	cout<<ans<<endl;
    }
}
