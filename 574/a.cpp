#include <bits/stdc++.h>
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin>>n>>k;

    int arr[n];
    int count[k];

    memset(count,0,sizeof(count));
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    	arr[i]--;
    	count[arr[i]]++;
    }

    bool hasodd=0;

    int ans=0;
    for(int i=0;i<k;i++){
    	ans+=(count[i]/2)*2;
    	count[i]%=2;
    }

    if((n-ans)%2==0){
	    ans+=(n-ans)/2;
	}
	else{
	    ans+=(n-ans)/2;
		ans++;		
	}

    cout<<ans<<endl;

}
