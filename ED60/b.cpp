#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif

    int n,m,k;
    cin>>n>>m>>k;

    int arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }

    int max=0;
    int maxtwo=0;

    for(int i=0;i<n;i++){
    	if(arr[i]>max){
    		maxtwo = max;
    		max=arr[i];
    	}
    	else if(arr[i]>maxtwo){
    		maxtwo = arr[i];
    	}
    }

//    cout<<max<<endl;
//    cout<<maxtwo<<endl;

    ll ans;
    ans=(m/(k+1))*(max*(k)+maxtwo);
//    cout<<k<<endl;

    int leftover = m-(m/(k+1))*(k+1);
    ans+=max*leftover;
    cout<<ans<<endl;
}