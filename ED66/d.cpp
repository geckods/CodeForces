#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> intpair;
// A utility function to get the 
// middle index of given range. 
ll getMid(ll s, ll e)  
{ 
    return s + (e - s) / 2; 
} 
  
/*  A recursive function to get the sum of 
    values in given range of the array.  
    The following are parameters for this 
    function. 
  
    st       -> Poller to segment tree 
    node     -> Index of current node in  
                the segment tree . 
    ss & se  -> Starting and ending indexes  
                of the segment represented 
                by current node, i.e., st[node] 
    l & r    -> Starting and ending indexes  
                of range query */
intpair MaxUtil(intpair* st, ll ss, ll se, ll l,  
            ll r, ll node) 
{ 
    // If segment of this node is completely 
    // part of given range, then return  
    // the max of segment 
    if (l <= ss && r >= se) 
        return st[node]; 
  
    // If segment of this node does not 
    // belong to given range 
    if (se < l || ss > r) 
        return make_pair(LLONG_MIN,-1); 
  
    // If segment of this node is partially 
    // the part of given range 
    ll mid = getMid(ss, se); 
      
    return max(MaxUtil(st, ss, mid, l, r,  
                       2 * node + 1), 
               MaxUtil(st, mid + 1, se, l,  
                       r, 2 * node + 2)); 
} 
  
// Return max of elements in range from 
// index l (query start) to r (query end). 
intpair getMax(intpair* st, ll n, ll l, ll r) 
{ 
    // Check for erroneous input values 
    if (l < 0 || r > n - 1 || l > r)  
    { 
        // printf("Invalid Input"); 
        return make_pair(LLONG_MIN, -1); 
    } 
  
    return MaxUtil(st, 0, n - 1, l, r, 0); 
} 
  
// A recursive function that constructs Segment 
// Tree for array[ss..se]. si is index of  
// current node in segment tree st 
intpair constructSTUtil(ll arr[], ll ss, ll se,  
                    intpair* st, ll si) 
{ 
    // If there is one element in array, store 
    // it in current node of segment tree and return 
    if (ss == se)  
    { 
        st[si].first = arr[ss];
        st[si].second = ss;
        return st[si]; 
    } 
  
    // If there are more than one elements, then 
    // recur for left and right subtrees and  
    // store the max of values in this node 
    ll mid = getMid(ss, se); 

    intpair ans1=constructSTUtil(arr, ss, mid, st,si * 2 + 1);
    intpair ans2=constructSTUtil(arr, mid + 1, se,st, si * 2 + 2);
    
    if(ans1>ans2){
    	st[si].first = ans1.first;
    	st[si].second = ans1.second;
    }
    else{
    	st[si].first = ans2.first;
    	st[si].second = ans2.second;
    }      
    return st[si]; 
} 
  
/* Function to construct segment tree from given array. 
   This function allocates memory for segment tree.*/
intpair* constructST(ll arr[], ll n) 
{ 
    // Height of segment tree 
    ll x = (ll)(ceil(log2(n))); 
  
    // Maximum size of segment tree 
    ll max_size = 2 * (ll)pow(2, x) - 1; 
  
    // Allocate memory 
    intpair* st = new intpair[max_size]; 
  
    // Fill the allocated memory st 
    constructSTUtil(arr, 0, n - 1, st, 0); 
  
    // Return the constructed segment tree 
    return st; 
}

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	ll n,k;
   	cin>>n>>k;

   	ll last = n-1;
   	ll onk = k;

   	ll arr[n];
   	for(ll i=0;i<n;i++){
   		cin>>arr[i];
   	}

   	ll cum[n];
   	cum[n-1]=arr[n-1];
   	for(ll i=n-2;i>=0;i--){
   		cum[i]=cum[i+1]+arr[i];
   	}

   	intpair* st = constructST(cum,n);

   	ll ans=0;

   	// for(int i=0;i<n;i++){
   	// 	cout<<getMax(st,n,i,i)<<endl;
   	// }

   	while(onk>0){

   		// if(last<onk-1){
   		// 	while(1);
   		// }

   		intpair newlast;
   		if(onk==1){
   			newlast.second=0;
   		}
   		else{
   			newlast = getMax(st,n,onk-1,last);
   		}
   		ll mini = cum[newlast.second];
   		// cout<<onk<<" "<<last<<" "<<newlast.first<<" "<<newlast.second<<endl;
   		if(last != n-1){
   			mini-=cum[last+1];
   		}
   		ans+=onk*mini;
   		last = newlast.second-1;
   		onk--;
   	}

   	cout<<ans<<endl;
}

