#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


// A utility function to get minimum of two numbers  
ll minVal(ll x, ll y) { return (x < y)? x: y; }  
  
// A utility function to get the  
// middle index from corner indexes.  
ll getMid(ll s, ll e) { return s + (e -s)/2; }  
  
/* A recursive function to get the 
minimum value in a given range  
of array indexes. The following  
are parameters for this function.  
  
    st --> Poller to segment tree  
    index --> Index of current node in the  
           segment tree. Initially 0 is  
           passed as root is always at index 0  
    ss & se --> Starting and ending indexes  
                of the segment represented  
                by current node, i.e., st[index]  
    qs & qe --> Starting and ending indexes of query range */
ll RMQUtil(ll *st, ll ss, ll se, ll qs, ll qe, ll index)  
{  
    // If segment of this node is a part  
    // of given range, then return  
    // the min of the segment  
    if (qs <= ss && qe >= se)  
        return st[index];  
  
    // If segment of this node 
    // is outside the given range  
    if (se < qs || ss > qe)  
        return LLONG_MAX;  
  
    // If a part of this segment 
    // overlaps with the given range  
    ll mid = getMid(ss, se);  
    return minVal(RMQUtil(st, ss, mid, qs, qe, 2*index+1),  
                RMQUtil(st, mid+1, se, qs, qe, 2*index+2));  
}  
  
// Return minimum of elements in range 
// from index qs (query start) to  
// qe (query end). It mainly uses RMQUtil()  
ll RMQ(ll *st, ll n, ll qs, ll qe)  
{  
    // Check for erroneous input values  
    if (qs < 0 || qe > n-1 || qs > qe)  
    {  
        // cout<<"Invalid Input";  
        return -1;  
    }  
  
    return RMQUtil(st, 0, n-1, qs, qe, 0);  
}  
  
// A recursive function that constructs 
// Segment Tree for array[ss..se].  
// si is index of current node in segment tree st  
ll constructSTUtil(ll arr[], ll ss, ll se, 
                                ll *st, ll si)  
{  
    // If there is one element in array, 
    // store it in current node of  
    // segment tree and return  
    if (ss == se)  
    {  
        st[si] = arr[ss];  
        return arr[ss];  
    }  
  
    // If there are more than one elements,  
    // then recur for left and right subtrees  
    // and store the minimum of two values in this node  
    ll mid = getMid(ss, se);  
    st[si] = minVal(constructSTUtil(arr, ss, mid, st, si*2+1),  
                    constructSTUtil(arr, mid+1, se, st, si*2+2));  
    return st[si];  
}  
  
/* Function to construct segment tree  
from given array. This function allocates 
memory for segment tree and calls constructSTUtil() to  
fill the allocated memory */
ll *constructST(ll arr[], ll n)  
{  
    // Allocate memory for segment tree  
  
    //Height of segment tree  
    ll x = (ll)(ceil(log2(n)));  
  
    // Maximum size of segment tree  
    ll max_size = 2*(ll)pow(2, x) - 1;  
  
    ll *st = new ll[max_size];  
  
    // Fill the allocated memory st  
    constructSTUtil(arr, 0, n-1, st, 0);  
  
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

    ll n,m;
    cin>>n>>m;

    ll q;
    cin>>q;

    char grid[n][m];
    string s;
    for(int i=0;i<n;i++){
    	cin>>s;
    	for(int j=0;j<m;j++){
    		grid[i][j]=s[j];
    	}
    }

    int count;

    ll greenrows[n][m];
    for(int j=0;j<n;j++){
    	count=0;
    	for(int i=n-1;i>=0;i--){
    		if(grid[i][j]=='G'){
    			count++;
    		}
    		else{
    			count=0;
    		}
    		greenrows[i][j]=count;
    	}
    }

    ll yellowrows[n][m];
    for(int j=0;j<n;j++){
    	count=0;
    	for(int i=n-1;i>=0;i--){
    		if(grid[i][j]=='Y'){
    			count++;
    		}
    		else{
    			count=0;
    		}
    		yellowrows[i][j]=count;
    	}
    }

    ll redrows[n][m];
    for(int j=0;j<n;j++){
    	count=0;
    	for(int i=n-1;i>=0;i--){
    		if(grid[i][j]=='R'){
    			count++;
    		}
    		else{
    			count=0;
    		}
    		redrows[i][j]=count;
    	}
    }

    ll bluerows[n][m];
    for(int j=0;j<n;j++){
    	count=0;
    	for(int i=n-1;i>=0;i--){
    		if(grid[i][j]=='B'){
    			count++;
    		}
    		else{
    			count=0;
    		}
    		bluerows[i][j]=count;
    	}
    }

    ll* greenseg[m];
    for(int i=0;i<n;i++){
    	greenseg[i]=constructST(greenrows[i],m);
    } 

    ll* blueseg[m];
    for(int i=0;i<n;i++){
    	blueseg[i]=constructST(bluerows[i],m);
    } 

    ll* redseg[m];
    for(int i=0;i<n;i++){
    	redseg[i]=constructST(redrows[i],m);
    } 

    ll* yellowseg[m];
    for(int i=0;i<n;i++){
    	yellowseg[i]=constructST(yellowrows[i],m);
    }

    ll greensq[n][m];
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		ll bmin=0;
    		ll bmax=min(greenrows[i][j],m-j);
    		// cerr
    		ll prevmid=-1;
    		while(bmin<bmax){
    			ll bmid=(bmin+bmax)/2;
    			if(bmid==prevmid)bmid++;
    			cerr<<bmid<<" "<<RMQ(greenseg[i],m,j,j+bmid-1)<<endl;
    			if(RMQ(greenseg[i],m,j,j+bmid-1)<bmid){
    				bmax=bmid-1;
    			}
    			else{
    				bmin=bmid;
    			}
    			prevmid=bmid;
    		}
    		cerr<<"GREEN: "<<i<<" "<<j<<" "<<bmin<<" "<<bmax<<" "<<endl;
    		greensq[i][j]=bmin;
    	}
    }

    ll redsq[n][m];
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		ll bmin=0;
    		ll bmax=min(redrows[i][j],m-j);
    		ll prevmid;

    		while(bmin<bmax){
    			ll bmid=bmin+ceil((double)bmax-bmin)/2;
    			if(bmid==prevmid)bmid++;

    			if(RMQ(redseg[i],m,j,j+bmid-1)<bmid){
    				bmax=bmid-1;
    			}
    			else{
    				bmin=bmid;
    			}
    			prevmid=bmid;
    		}
    		redsq[i][j]=bmin;
    	}
    }

    ll yellowsq[n][m];
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		ll bmin=0;
    		ll bmax=min(yellowrows[i][j],m-j);
    		ll prevmid;
    		while(bmin<bmax){
    			ll bmid=bmin+ceil((double)bmax-bmin)/2;
    			if(bmid==prevmid)bmid++;
    			if(RMQ(yellowseg[i],m,j,j+bmid-1)<bmid){
    				bmax=bmid-1;
    			}
    			else{
    				bmin=bmid;
    			}
    			prevmid=bmid;
    		}
    		yellowsq[i][j]=bmin;
    	}
    }

    ll bluesq[n][m];
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		ll bmin=0;
    		ll bmax=min(bluerows[i][j],m-j);
    		ll prevmid;
    		while(bmin<bmax){
    			ll bmid=bmin+ceil((double)bmax-bmin)/2;
    			if(bmid==prevmid)bmid++;    			
    			if(RMQ(blueseg[i],m,j,j+bmid-1)<bmid){
    				bmax=bmid-1;
    			}
    			else{
    				bmin=bmid;
    			}
    			prevmid=bmid;
    		}
    		bluesq[i][j]=bmin;
    	}
    }

    ll ansval[n][m];

    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		ansval[i][j]=0;
    		if(redsq[i][j]>0 && i+redsq[i][j]<n && j+redsq[i][j]<m){
				// cerr<<i<<" "<<j<<" "<<redsq[i][j]<<" "<<greensq[i][j+redsq[i][j]]<<endl;   			
    			if(greensq[i][j+redsq[i][j]]>=redsq[i][j] && yellowsq[i+redsq[i][j]][j]>=redsq[i][j] && bluesq[i+redsq[i][j]][j+redsq[i][j]]>=redsq[i][j]){
    				ansval[i][j]=redsq[i][j];
    			}
    		}
    		cout<<i<<" "<<j<<" "<<ansval[i][j]<<endl;
    	}
    }

  
    // int arr[] = {1, 3, 2, 7, 9, 11};  
    // int n = sizeof(arr)/sizeof(arr[0]);  
  
    // // Build segment tree from given array  
    // int *st = constructST(arr, n);  
  
    // int qs = 1; // Starting index of query range  
    // int qe = 5; // Ending index of query range  
  
    // // Print minimum value in arr[qs..qe]  
    // cout<<"Minimum of values in range ["<<qs<<", "<<qe<<"] "<< 
    // "is = "<<RMQ(st, n, qs, qe)<<endl;  
  
    return 0;  
}  
