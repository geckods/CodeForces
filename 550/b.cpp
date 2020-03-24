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

    int evens=0;
    for(int i=0;i<n;i++){
    	if(arr[i]%2==0) evens++;
    }

    sort(arr,arr+n);

    int odds = n-evens;

    int count = abs(evens-odds)-1;
    ll sum=0;
    bool checkeven = (evens>odds);

//    cout<<count<<endl;

    for(int i=0;i<n;i++){
    	if(count<=0){
    		break;
    	}
    	if((arr[i]%2==0 && checkeven) || (arr[i]%2==1 && !checkeven)){
    		sum+=arr[i];
    		count--;
    	}
    }

    cout<<sum<<endl;
}