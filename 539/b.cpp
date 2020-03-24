#include <bits/stdc++.h>
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif

    int n;
    cin>>n;

    int arr[n];
    int origsum;
    int minsum=0;
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    	minsum+=arr[i];
    }
    origsum=minsum;

    sort(arr,arr+n);


    int min=arr[0];

    int fac1,fac2,asdf,sum1,sum2;

    int myarr[101];
    for(int i=1;i<101;i++){
    	myarr[i]=0;
    }

    for(int i=n-1;i>0;i--){
    	if(myarr[arr[i]]==1) continue;
    	myarr[arr[i]]=1;
    	for(int j=2;j<=sqrt(arr[i]);j++){
//    		cout<<i<<" "<<j<<endl;
    		if(arr[i]%j==0){
    			fac1=j;
    			fac2=arr[i]/j;

    			sum1=(min+arr[i])-((min*fac1)+(arr[i]/fac1));
    			sum2=(min+arr[i])-((min*fac2)+(arr[i]/fac2));
    			asdf=origsum;

    			if(sum1>0){
    				asdf = origsum-sum1;
    			}

    			if(sum2>sum1){
    				asdf = origsum-sum2;
    			}
//    			cout<<i<<" "<<j<<" "<<asdf<<" "<<sum1<<" "<<sum2<<endl;
    			if(asdf<minsum)
	    			minsum=asdf;
//    			break;
    		}
    	}
    }
    cout<<minsum<<endl;
}