#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef pair<ll,ll> intpair;

ll getMid(ll s, ll e)  
{ 
    return s + (e - s) / 2; 
} 

ll MaxUtil(ll* st, ll ss, ll se, ll l,  
            ll r, ll node) 
{ 
    // If segment of this node is completely 
    // part of given range, then return  
    // the max of segment 
    if (l <= ss && r >= se) 
        return max(st[node],0ll); 
  
    // If segment of this node does not 
    // belong to given range 
    if (se < l || ss > r) 
        return 0; 
  
    // If segment of this node is partially 
    // the part of given range 
    ll mid = getMid(ss, se); 
      
    return (MaxUtil(st, ss, mid, l, r,  
                       2 * node + 1)+ 
               MaxUtil(st, mid + 1, se, l,  
                       r, 2 * node + 2)); 
} 
  
void updateValue(ll arr[], ll* st, ll ss, ll se,  
                 ll index, ll value, ll node) 
{ 
    if (index < ss || index > se)  
    { 
        cout << "Invalid Input" << endl; 
        return; 
    } 
      
    if (ss == se)  
    {    
        // update value in array and in segment tree 
        arr[index] = value; 
        st[node] = value; 
    } 
    else { 
            ll mid = getMid(ss, se); 
              
            if (index >= ss && index <= mid) 
                updateValue(arr, st, ss, mid, index,  
                            value, 2 * node + 1); 
            else
                updateValue(arr, st, mid + 1, se,  
                            index, value, 2 * node + 2); 
              
            st[node] = (max(0ll,st[2 * node + 1])+
                       max(0ll,st[2 * node + 2])); 
    } 
    return; 
} 
  
ll getMax(ll* st, ll n, ll l, ll r) 
{ 
    // Check for erroneous input values 
    if (l < 0 || r > n - 1 || l > r)  
    { 
        printf("Invalid Input"); 
        return -1; 
    } 
  
    return MaxUtil(st, 0, n - 1, l, r, 0); 
} 
  
ll constructSTUtil(ll arr[], ll ss, ll se,  
                    ll* st, ll si) 
{ 
    // If there is one element in array, store 
    // it in current node of segment tree and return 
    if (ss == se)  
    { 
        st[si] = arr[ss]; 
        return arr[ss]; 
    } 
  
    // If there are more than one elements, then 
    // recur for left and right subtrees and  
    // store the max of values in this node 
    ll mid = getMid(ss, se); 
      
    st[si] = (max(0ll,constructSTUtil(arr, ss, mid, st,  
                                 si * 2 + 1))+ 
                 max(0ll,constructSTUtil(arr, mid + 1, se,  
                                 st, si * 2 + 2))); 
      
    return st[si]; 
} 
  
/* Function to construct segment tree from given array. 
   This function allocates memory for segment tree.*/
ll* constructST(ll arr[], ll n) 
{ 
    // Height of segment tree 
    ll x = (ll)(ceil(log2(n))); 
  
    // Maximum size of segment tree 
    ll max_size = 2 * (ll)pow(2, x) - 1; 
  
    // Allocate memory 
    ll* st = new ll[max_size]; 
  
    // Fill the allocated memory st 
    constructSTUtil(arr, 0, n - 1, st, 0); 
  
    // Return the constructed segment tree 
    return st; 
} 

/*  
    int arr[] = { 1, 3, 5, 7, 9, 11 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    // Build segment tree from given array 
    int* st = constructST(arr, n); 
  
    // Print max of values in array 
    // from index 1 to 3 
    cout << "Max of values in given range = " 
         << getMax(st, n, 1, 3) << endl; 
  
    // Update: set arr[1] = 8 and update 
    // corresponding segment tree nodes. 
    updateValue(arr, st, 0, n - 1, 1, 8, 0); 
  
    // Find max after the value is updated 
    cout << "Updated max of values in given range = " 
         << getMax(st, n, 1, 3) << endl; 
*/      
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

    ll target[n];
    ll sum=0;
    for(int i=0;i<n;i++){
    	cin>>target[i];
    	sum+=target[i];
    }

    ll q;
    cin>>q;

    map<intpair,ll> updateMap; 

    ll* st = constructST(target,n);

    for(int i=0;i<q;i++){
    	ll s,t,u;
    	cin>>s>>t>>u;

    	
    	//check map of s,t to see what it currently is
    	ll toplusadd=0; 
    	ll tominusadd=0; 

    	toplusadd=updateMap[{s,t}];//have one less update on this
    	tominusadd=u;//have one more update on this
    	updateMap[{s,t}]=u;

    	if(tominusadd!=0 && toplusadd==0){
    		sum--;
    	}

    	if(tominusadd==0 && toplusadd!=0){
    		sum++;
    	}

    	//segtree for max of array
	    // Update: set arr[1] = 8 and update 
	    // corresponding segment tree nodes. 
	    // updateValue(arr, st, 0, n - 1, 1, 8, 0); 

    	if(tominusadd>0)
	    	updateValue(target,st,0,n-1,tominusadd-1, target[tominusadd-1]-1, 0);

	    if(toplusadd>0)
	    	updateValue(target,st,0,n-1,toplusadd-1, target[toplusadd-1]+1, 0);

	    // for(int i=0;i<n;i++){
	    // 	cout<<i<<" "<<target[i]<<endl;
	    // }
	    // cout<<sum<<endl;
	    cout<<max(sum,getMax(st,n,0,n-1))<<endl;
	    // cout<<endl;
    }
}