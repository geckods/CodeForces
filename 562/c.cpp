#include <bits/stdc++.h>
using namespace std;

bool check(int arr[],int n,int m,int x){
	
	int currlo = 0;
	
	for(int i=0;i<n;i++){
//		cout<<i<<" "<<arr[i]<<" "<<currlo<<endl;
		if(arr[i]>currlo){
			if((arr[i]+x)%m >= currlo){
				if(arr[i]+x >= m){
					//it wrapped around and passed the lowest
					//do nothing
				}
				else{
					currlo=arr[i];//the new lowest 
				}
			}
			else{
				currlo=arr[i];
			}
		}
		else{
			//arr[i]<=currlo
			if(arr[i]+x >= currlo){
				//do nothing
			}
			else{
				//can't reach currlo
				return false;
			}
		}
	}

	return true;
}

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    //binary search the answer. beaut

    int n,m;
    cin>>n>>m;
    int arr[n];

    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }

    int lo,hi,mid;
    lo=0;
    hi=m-1;

    int prevmid=-1;

    // cout<<check(arr,n,m,1)<<endl;
    // return 0;

    // if(check(arr,n,m,0)){
    // 	cout<<0<<endl;
    // 	return 0;
    // }

    while(1){
//		cout<<lo<<" "<<hi<<endl;
		mid=(lo+hi)/2;

    	if(prevmid==mid){
    		break;
    	}

    	if(check(arr,n,m,mid)){
    		hi = mid;
    	}
    	else{
    		lo=mid+1;
    	}
    	
    	prevmid=mid;
    }

    cout<<mid<<endl;
}