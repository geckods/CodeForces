#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef pair<ll,ll> intpair;

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
    	ll n,m;
    	cin>>n>>m;

    	bool unlockedHighestB = false;
    	ll highestB = -1;

    	vector<intpair> myVec;
    	ll a,b;
    	for(int i=0;i<m;i++){
    		cin>>a>>b;
    		myVec.push_back({a,b});
    		highestB = max(highestB, b);
    	}

    	sort(myVec.begin(),myVec.end());
    	// reverse(myVec.begin(),myVec.end());

  //   	ll ans=0;
  //   	ll pointer = 0;

  //   	ll largestBSoFar = -1;
  //   	while(n>0 && pointer<m && myVec[pointer].first >= highestB){
  //   		largestBSoFar = max(largestBSoFar, myVec[pointer].second);
  //   		ans+=myVec[pointer].first;
  //   		n--;
  //   		pointer++;
  //   	}

  //   	// cout<<pointer<<endl;

  //   	if(n==0){
  //   		cout<<ans<<endl;
  //   		continue;
  //   	}

		// ll leftMax = largestBSoFar*n;
		// for(int i=pointer;i<m;i++){
		// 	leftMax = max(leftMax, myVec[i].first+max(myVec[i].second,largestBSoFar)*(n-1));
		// 	// cout<<leftMax<<endl;
		// }

		// cout<<ans+leftMax<<endl;

		ll sufA[m];
		sufA[m-1]=myVec[m-1].first;
		for(int i=m-2;i>=0;i--){
			sufA[i]=sufA[i+1]+myVec[i].first;
		}

		ll ans = 0;
		if(n <= m){
			ans = sufA[m-n];
		}
		ll ogn = n;
		for(int i=0;i<m;i++){
			n = ogn;
			// this will be my B;
			ll lb = lower_bound(myVec.begin(), myVec.end(), make_pair(myVec[i].second,-1ll)) - myVec.begin();
			// cerr<<i<<" "<<myVec[i].first<<" "<<myVec[i].second<<" "<<" "<<lb<<" "<<sufA[2]<<endl;
			ll minians = 0;
			if(lb<m)
				minians = sufA[max(m-n,lb)];
			// cerr<<minians<<endl;
			if(lb > m-n){
				n-=m-lb;
				if(lb > i){
					minians+=myVec[i].first;
					n--;					
				}
				minians+=myVec[i].second*(n);
				// cerr<<n<<" "<<minians<<endl;
			}
			ans=max(ans,minians);
		}

	    cout<<ans<<endl;
    }
}