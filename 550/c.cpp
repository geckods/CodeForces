#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }

    sort(arr,arr+n);


    for(int i=0;i<n-2;i++){
    	if(arr[i+2]==arr[i]){
    		cout<<"NO"<<endl;
    		return 0;
    	}
    }
    cout<<"YES"<<endl;

    cout<<n/2 + n%2<<endl;
    for(int i=0;i<n;i+=2){
    	cout<<arr[i]<<" ";
    }
    cout<<endl;

    cout<<n/2<<endl;;

    int i;
    if(n%2==0){
    	i=n-1;
    }
    else{
    	i=n-2;
    }

    for(;i>=0;i-=2){
    	cout<<arr[i]<<" ";
    }
    cout<<endl;
}