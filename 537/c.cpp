#include <bits/stdc++.h>
using namespace std;


int getnumberbeforeindex(int arr[], int l, int r,int x){
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
        // If the element is present at the middle 
        // itself 
        if (arr[mid] == x){
        	while(arr[mid]==x)
        		mid++;
            return mid-1;
        }
  
        // If element is smaller than mid, then 
        // it can only be present in left subarray 
        if (arr[mid] > x) 
            return getnumberbeforeindex(arr, l, mid - 1, x); 
  
        // Else the element can only be present 
        // in right subarray 
        return getnumberbeforeindex(arr, mid + 1, r, x); 
    } 
  
    // We reach here when element is not 
    // present in array 
    return r;
}

int getnumberbeforeindexfirst(int arr[], int l, int r,int x){
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
        // If the element is present at the middle 
        // itself 
        if (arr[mid] == x){
        	while(arr[mid]==x)
        		mid--;
            return mid+1;
        }
  
        // If element is smaller than mid, then 
        // it can only be present in left subarray 
        if (arr[mid] > x) 
            return getnumberbeforeindex(arr, l, mid - 1, x); 
  
        // Else the element can only be present 
        // in right subarray 
        return getnumberbeforeindex(arr, mid + 1, r, x); 
    } 
  
    // We reach here when element is not 
    // present in array 
    return r;
}

int find(int arr[],int x,int y,int k){
//	if(y==x+1){
//
//	}
	cout<<x<<" "<<y<<" ";
	cout<<getnumberbeforeindex(arr,0,k,y-1)<<" ";
	cout<<getnumberbeforeindexfirst(arr,0,k,x)<<" ";
	cout<<endl;
	return getnumberbeforeindex(arr,0,k,y-1)-getnumberbeforeindexfirst(arr,0,k,x);
}

int compute(int arr[], int x, int y,int A, int B, int len){
	int ans;
//	cout<<i<<endl;

// x is inclusive, y is exclusive
//	if(i>2*len-2){
//		cout<<"ERROR"<<endl;
//		return 0;
//	}

	int nobetween = find(arr,x,y,len);
//	cout<<x<<" "<<y<<" "<<nobetween<<endl;

	if(nobetween==0) return A;

	if(x+1==y){
		if(nobetween==0){
			return A;
		}
		else{
			return nobetween*B;
		}
	}
	else{
		//burn current
		ans = nobetween*B*(y-x);
		int otherans = compute(arr,x,(x+y)/2,A,B,len)+compute(arr,(x+y)/2,y,A,B,len);
		if(ans<otherans) return ans;
		else return otherans;
	}
}



int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif

    int n,k,A,B;
    cin>>n;
    cin>>k;
    cin>>A;
    cin>>B;

    int len = pow(2,n);
//    int arr[len*2-1];

//    for(int i=0;i<len*2-1;i++){
//    	arr[i]=0;
//    }

    int a[k];
//    int a;
    for(int i=0;i<k;i++){
    	cin>>a[i];
    	a[i]-=1;
//    	cin>>a;

//    	arr[len-1+a-1]++;
    }
    sort(a,a+k);


//    for(int i=len-1;i<2*len-1;i++){
//    	cin>>arr[len];
//    }

//    for(int i=len-2;i>=0;i--){
//    	arr[i]=arr[2*i+1]+arr[2*i+2];
//   }
/*
	for(int i=0;i<len*2-1;i++){
    	cout<<arr[i]<<" ";
    }
    cout<<endl;
*/
    cout<<compute(a,0,len,A,B,k)<<endl;
}
