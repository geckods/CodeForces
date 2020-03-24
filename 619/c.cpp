#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int t;
	cin>>t;

	while(t--){
		ll n,m;
		cin>>n>>m;

		ll z=n-m;
		//answer for a range of zeroes is countC2

		//need to divide the z into m+1 paritions.
		ll ans;

		if(m>=z){
			ans=z;
		}
		else{
			//divide z into m+1 partitions
			ll parsize=z/(m+1);
			ll extraz=z%(m+1);
			// cout<<parsize<<" "<<extraz<<endl;

			ans=((parsize)*(parsize+1)/2)*(m+1-extraz)+((parsize+1)*(parsize+2)/2)*(extraz);
		}

		cout<<((n*(n+1))/2)-ans<<endl;
	}
}