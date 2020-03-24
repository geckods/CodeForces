//upsolving on 8.3.19

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }

    int i=0;
    int j=n-1;

    ll sum1=0;
    ll sum2=0;

    ll max=0;

    while(i<=j){
//    	cout<<i<<" "<<j<<" "<<sum1<<endl;
    	if(sum1==sum2){
    		if(sum1>max){
    			max=sum1;
    		}
    		sum1+=arr[i++];
    	}
    	else if (sum1<sum2){
    		sum1+=arr[i++];	
    	}
    	else{
    		sum2+=arr[j--];
    	}
    }

    if(sum1==sum2 && sum1>max)max=sum1;

    cout<<max<<endl;
}