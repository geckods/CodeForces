#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll getSum(ll BITree[], ll index) 
{ 
    ll sum = 0; // Iniialize result 
  
    // index in BITree[] is 1 more than the index in arr[] 
    index = index + 1; 
  
    // Traverse ancestors of BITree[index] 
    while (index>0) 
    { 
        // Add current element of BITree to sum 
        sum += BITree[index]; 
  
        // Move index to parent node in getSum View 
        index -= index & (-index); 
    } 
    return sum; 
} 
  
// Updates a node in Binary Index Tree (BITree) at given index 
// in BITree. The given value 'val' is added to BITree[i] and  
// all of its ancestors in tree. 
void updateBIT(ll BITree[], ll n, ll index, ll val) 
{ 
    // index in BITree[] is 1 more than the index in arr[] 
    index = index + 1; 
  
    // Traverse all ancestors and add 'val' 
    while (index <= n) 
    { 
    // Add 'val' to current node of BI Tree 
    BITree[index] += val; 
  
    // Update index to that of parent in update View 
    index += index & (-index); 
    } 
} 
  
// Constructs and returns a Binary Indexed Tree for given 
// array of size n. 
ll *constructBITree(ll arr[], ll n) 
{ 
    // Create and initialize BITree[] as 0 
    ll *BITree = new ll[n+1]; 
    for (ll i=1; i<=n; i++) 
        BITree[i] = 0; 
  
    // Store the actual values in BITree[] using update() 
    for (ll i=0; i<n; i++) 
        updateBIT(BITree, n, i, arr[i]); 
  
    // Uncomment below lines to see contents of BITree[] 
    //for (int i=1; i<=n; i++) 
    //     cout << BITree[i] << " "; 
  
    return BITree; 
} 


int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	ll n;
   	cin>>n;

   	ll asd[n];
   	for(int i=0;i<n;i++){
   		cin>>asd[i];
   	}

   	ll arr[n];
   	for(int i=0;i<n;i++){
   		arr[i]=i+1;
   	}

   	ll *BITree = constructBITree(arr,n);


   	ll ansarr[n];
   	memset(ansarr,0,sizeof(ansarr));

   	for(int i=n-1;i>=0;i--){

   		// for(int j=0;j<n;j++){
   		// 	cout<<j<<" "<<getSum(BITree,j)-getSum(BITree,j-1)<<" "<<getSum(BITree,j)<<endl;
   		// }
   		// cout<<endl;



   		ll bmin=0;
   		ll bmax=n;
   		ll bmid;

   		while(bmin<bmax){
   			bmid=(bmin+bmax)/2;
   			ll thecurr = getSum(BITree, bmid);
   			// cout<<bmid<<" "<<thecurr<<" "<<asd[i]<<endl;
   			if(thecurr<=asd[i]){
   				if(getSum(BITree, bmid+1)>asd[i]){
   					bmin=bmax=bmid;
   					break;
   				}
   				bmin=bmid+1;
   			}
   			else if (thecurr>asd[i]){
   				bmax=bmid-1;
   			}
   			else{
   				bmin=bmax=bmid;
   				break;
   			}
   		}
   		// cout<<endl;

   		if(getSum(BITree, bmin)>asd[i])bmin--;

   		ansarr[i]=bmin+2;

   		updateBIT(BITree,n,bmin+1,-(bmin+2));
   	}

   	for(int i=0;i<n;i++){
   		cout<<ansarr[i]<<" ";
   	}
   	cout<<endl;
}