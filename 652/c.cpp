#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// THINGS TO REMEMBER
// ENDL is slow, '\n' is fast
// Clear everything (including graphs) between test cases
// use anti-anti-hash: https://codeforces.com/blog/entry/62393
// pb-ds: https://codeforces.com/blog/entry/11080
// check when to use LLONG_MAX/LLONG_MIN vs INT_MAX or INT_MIN
// You frequently suffer from confirmation bias - you trust your initial solution and miss simple things. 
// When you hit a roadblock, remember to rethink the solution ground up, not just try hacky fixes

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

 	ll t;
 	cin>>t;
 	while(t--){
 		ll n,k;
 		cin>>n>>k;

 		ll arr[n];
 		for(int i=0;i<n;i++){
 			cin>>arr[i];
 		}

 		sort(arr,arr+n);

 		ll friends[n];

 		vector<ll> friendsVec;

 		ll oc=0;
 		for(int i=0;i<k;i++){
 			cin>>friends[i];
 			if(friends[i]==1){
 				oc++;
 			} else {
				friendsVec.push_back(friends[i]);
 			}
 		}

 		sort(friendsVec.begin(),friendsVec.end());
 		for(int i=0;i<oc;i++){
 			friendsVec.push_back(1);
 		}
 		reverse(friendsVec.begin(),friendsVec.end());

 		ll ans=0;

 		ll backInd=n-1;
 		ll frontInd=0;

 		for(int i=0;i<k;i++){
 			// cerr<<i<<" "<<friendsVec[i]<<" "<<backInd<<" "<<frontInd<<endl;
 			if(friendsVec[i]==1){
 				ans+=2*arr[backInd];
 				backInd--;
 			}
 			else{
 				ans+=arr[backInd];
 				ans+=arr[frontInd];
 				backInd--;
 				frontInd+=friendsVec[i]-1;
 			}
 		}
 		cout<<ans<<endl;
 	}   
}
