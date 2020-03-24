#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<ll,ll> intpair;


typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

ll getMid(ll s, ll e)  
{ 
    return s + (e - s) / 2; 
} 
  
/*  A recursive function to get the sum of 
    values in given range of the array.  
    The following are parameters for this 
    function. 
  
    st       -> Pointer to segment tree 
    node     -> Index of current node in  
                the segment tree . 
    ss & se  -> Starting and ending indexes  
                of the segment represented 
                by current node, i.e., st[node] 
    l & r    -> Starting and ending indexes  
                of range query */
ll MaxUtil(ll* st, ll ss, ll se, ll l,  
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
        return -1; 
  
    // If segment of this node is partially 
    // the part of given range 
    ll mid = getMid(ss, se); 
      
    return max(MaxUtil(st, ss, mid, l, r,  
                       2 * node + 1), 
               MaxUtil(st, mid + 1, se, l,  
                       r, 2 * node + 2)); 
} 
  
/* A recursive function to update the nodes which 
   have the given index in their range. The following 
   are parameters st, ss and se are same as defined 
   above index -> index of the element to be updated.*/
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
              
            st[node] = max(st[2 * node + 1],  
                       st[2 * node + 2]); 
    } 
    return; 
} 
  
// Return max of elements in range from 
// index l (query start) to r (query end). 
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
  
// A recursive function that constructs Segment 
// Tree for array[ss..se]. si is index of  
// current node in segment tree st 
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
      
    st[si] = max(constructSTUtil(arr, ss, mid, st,  
                                 si * 2 + 1), 
                 constructSTUtil(arr, mid + 1, se,  
                                 st, si * 2 + 2)); 
      
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

    ll p[n];
    map<ll,ll> myMap;
    for(int i=0;i<n;i++){
    	cin>>p[i];
    	myMap[p[i]]=i;
    }

    ll q[n];
    for(int i=0;i<n;i++){
    	cin>>q[i];
    	q[i]--;
    }

    ll* st=constructST(p,n);

    ll firstZero=n;
    ll lastInd=-1;

    // ll zeroes[n];
    // ll queries[n];
    // memset(zeroes,0,sizeof(zeroes));
    // memset(queries,0,sizeof(queries));

    // ll* zst=constructSTSUM(zeroes,n);
    // ll* qst=constructSTSUM(queries,n);

    // set<intpair> mySet;
    ordered_set zTree;
    ordered_set qTree;

    for(int i=0;i<n;i++){
    	// cerr<<i<<endl;
    	cout<<getMax(st,n,0,n-1)<<" ";

    	ll theQ=q[i];
    	auto it = zTree.upper_bound(q[i]);

    	// cerr<<i<<endl;
    	// for(auto it=zTree.begin();it!=zTree.end();it++){
    	// 	cerr<<*it<<endl;
    	// }

    	// cerr<<zTree.order_of_key(*it)<<" "<<*it<<endl;
    	if(it==zTree.begin() || zTree.size()==0){
	    	// cerr<<"HI"<<endl;
    	}
    	else{
	    	it--;
	    	if(*(qTree.find_by_order(zTree.order_of_key(*it)))<q[i]){
	    		theQ=q[i];
	    	}
	    	else{
	    		theQ=*(qTree.find_by_order(zTree.order_of_key(*it)));
                while(1){
                    auto asdf=zTree.upper_bound(theQ);
                    asdf--;
                    if(*(qTree.find_by_order(zTree.order_of_key(*asdf)))<=theQ){
                        break;
                    }
                    else{
                        theQ=*(qTree.find_by_order(zTree.order_of_key(*asdf)));
                    }
                }
	    	}
    	}
    	// cerr<<zTree.order_of_key(*it)<<" "<<*it<<endl;
    	// cerr<<*qTree.find_by_order(zTree.order_of_key(*it))<<endl;



    	ll temp=getMax(st,n,0,theQ);
    	ll tempind=myMap[temp];

    	// cerr<<i<<" "<<q[i]<<" "<<*it<<" "<<theQ<<" "<<temp<<" "<<tempind<<endl;
     //    for(auto it:zTree)cerr<<it<<endl;
     //    cerr<<endl;
     //    for(auto it:qTree)cerr<<it<<endl;
    	// for(int i=0;i<n;i++){
    	// 	cerr<<p[i]<<" ";
    	// }
    	// cerr<<endl;
    	updateValue(p,st,0,n-1,tempind,0,0);
    	// updateValueSUM(zeroes,zst,n,tempind,1);
    	// updateValueSUM(queries,qst,n,q[i],1);

    	zTree.insert(tempind);
    	qTree.insert(q[i]);

    	// if(theQ==q[i]){
    	// 	mySet.insert({tempind,q[i]});
    	// }
    	// else{
    	// 	ll xx;
    	// 	xx=(*it).first;
    	// 	mySet.erase(it);
    	// 	if(xx<tempind){
	    // 		mySet.insert({xx,q[i]});
	    // 		mySet.insert({tempind,theQ});    			
    	// 	}
    	// 	else{
	    // 		mySet.insert({tempind,q[i]});
	    // 		mySet.insert({xx,theQ});    			    			
    	// 	}
    	// }

    	// cerr<<i<<endl;
    	// for(auto it=mySet.begin();it!=mySet.end();it++){
    	// 	cerr<<it->first<<" "<<it->second<<endl;
    	// }
    	// zeroes[tempind]++;
    	// queries[q[i]]++;
    	// firstZero=min(firstZero,tempind);
    	// lastInd=max(lastInd,theQ);
    	// for(int i=0;i<n;i++){
    	// 	cerr<<p[i]<<" ";
    	// }
    	// cerr<<endl;
    }
    cout<<endl;

    //i need prefix maximums with index in quick time

}    