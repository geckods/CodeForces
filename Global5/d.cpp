#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int minVal(int x, int y) { return (x < y)? x: y; }  
  
// A utility function to get the  
// middle index from corner indexes.  
int getMid(int s, int e) { return s + (e -s)/2; }  
  
/* A recursive function to get the 
minimum value in a given range  
of array indexes. The following  
are parameters for this function.  
  
    st --> Pointer to segment tree  
    index --> Index of current node in the  
           segment tree. Initially 0 is  
           passed as root is always at index 0  
    ss & se --> Starting and ending indexes  
                of the segment represented  
                by current node, i.e., st[index]  
    qs & qe --> Starting and ending indexes of query range */
int RMQUtil(int *st, int ss, int se, int qs, int qe, int index)  
{  
    // If segment of this node is a part  
    // of given range, then return  
    // the min of the segment  
    if (qs <= ss && qe >= se)  
        return st[index];  
  
    // If segment of this node 
    // is outside the given range  
    if (se < qs || ss > qe)  
        return INT_MAX;  
  
    // If a part of this segment 
    // overlaps with the given range  
    int mid = getMid(ss, se);  
    return minVal(RMQUtil(st, ss, mid, qs, qe, 2*index+1),  
                RMQUtil(st, mid+1, se, qs, qe, 2*index+2));  
}  
  
// Return minimum of elements in range 
// from index qs (quey start) to  
// qe (query end). It mainly uses RMQUtil()  
int RMQ(int *st, int n, int qs, int qe)  
{  
    // Check for erroneous input values  
    if (qs < 0 || qe > n-1 || qs > qe)  
    {  
        cout<<"Invalid Input";  
        return -1;  
    }  
  
    return RMQUtil(st, 0, n-1, qs, qe, 0);  
}  
  
// A recursive function that constructs 
// Segment Tree for array[ss..se].  
// si is index of current node in segment tree st  
int constructSTUtil(int arr[], int ss, int se, 
                                int *st, int si)  
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
    int mid = getMid(ss, se);  
    st[si] = minVal(constructSTUtil(arr, ss, mid, st, si*2+1),  
                    constructSTUtil(arr, mid+1, se, st, si*2+2));  
    return st[si];  
}  
  
/* Function to construct segment tree  
from given array. This function allocates 
memory for segment tree and calls constructSTUtil() to  
fill the allocated memory */
int *constructST(int arr[], int n)  
{  
    // Allocate memory for segment tree  
  
    //Height of segment tree  
    int x = (int)(ceil(log2(n)));  
  
    // Maximum size of segment tree  
    int max_size = 2*(int)pow(2, x) - 1;  
  
    int *st = new int[max_size];  
  
    // Fill the allocated memory st  
    constructSTUtil(arr, 0, n-1, st, 0);  
  
    // Return the constructed segment tree  
    return st;  
}

int whichWay(int *st, int m, int lo, int hi, int limit){
	int mymid = getMid(lo,hi);
	if(RMQ(st, m, lo, mymid)<=limit){
		return 0;
	}
	else{
		return 1;
	}
}

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	int n;
   	cin>>n;

   	int themin=INT_MAX;
   	int themax=INT_MIN;

   	vector<int> myVec;
   	set<pair<int,int> > mySet;

   	int x;
   	for(int i=0;i<n;i++){
   		cin>>x;
   		myVec.push_back(x);
   		themin=min(themin,x);
   		themax=max(themax,x);
   		mySet.insert(make_pair(x,i));
   	}

   	if(themin*2>=themax){
   		for(int i=0;i<n;i++){
   			cout<<-1<<" ";
   		}
   		cout<<endl;
   		return 0;
   	}

   	for(int i=0;i<n;i++){
   		myVec.push_back(myVec[i]);
   	}

   	int m=2*n;
   	int arr[m];
   	for(int i=0;i<m;i++){
   		arr[i]=myVec[i];
   	}

   	int *st = constructST(arr, m);
   	//RMQ(st, m, lo, hi)

   	int hascircle[n];
   	memset(hascircle,0,sizeof(hascircle));


   	int limit;

   	// cout<<m<<endl;
   	for(int i=n-1;i>=0;i--){
   		if(arr[i]%2==0){
   			limit=arr[i]/2;
   			limit--;
   		}
   		else{
   			limit=arr[i]/2;
   		}

   		if(RMQ(st,m,i+1,i+n) > limit){
   			hascircle[i]=-1;
   		}
   		else{
   			//binary search for the value;
   			int bmin=i+1;
   			int bmax=i+n;
   			int prevmid=-1;
   			int bmid=0;
   			while(prevmid!=bmid){
   				prevmid=bmid;
   				bmid=getMid(bmin,bmax);
   				// cout<<i<<" "<<bmin<<" "<<bmax<<" "<<bmid<<endl;

   				if(RMQ(st,m,bmin,bmid)<=limit){
   					bmax=bmid;
   				}
   				else{
   					bmin=bmid+1;
   				}
   			}
   			// cout<<i<<" "<<bmax<<endl;
   			hascircle[i]=bmax;
   		}
   	}

   	for(int i=n-1;i>=0;i--){
   		if(hascircle[i]!=-1){
   			hascircle[i]-=i;
   		}
   	}

   	// for(int i=0;i<n;i++){
   	// 	cout<<hascircle[i]<<" ";
   	// }
   	// cout<<endl;

   	int minnotminus=INT_MAX;
   	int minnotminusind=-1;
   	for(int i=0;i<n;i++){
   		if(hascircle[i]==-1)continue;
   		if(hascircle[i]<minnotminus){
   			minnotminus=hascircle[i];
   			minnotminusind=i;
   		}
   	}


   	int currbest=minnotminus+1;
   	for(int i=minnotminusind-1;i>=minnotminusind-n;i--){
   		int ind=i;
   		if(ind<0){
   			ind+=n;
   		}

   		if(hascircle[ind]==-1){
   			hascircle[ind]=currbest;
   		}
   		else{
	   		hascircle[ind]=min(hascircle[ind],currbest);
   		}

   		currbest=min(currbest,hascircle[ind]);
   		currbest++;
   	}

   	for(int i=0;i<n;i++){
   		cout<<hascircle[i]<<" ";
   	}


}