#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll power(ll x, ll y, ll p) 
{ 
    ll res = 1;      // Initialize result 
  
    x = x % p;  // Update x if it is more than or  
                // equal to p 
  
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p;   
    } 
    return res; 
} 


int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,q;
    cin>>n>>q;

    string s;
    cin>>s;

    ll arr[n];
    for(int i=0;i<n;i++){
    	arr[i]=s[i]-'0';
    }

    ll cum[n];
    ll sum=0;
    for(int i=0;i<n;i++){
    	sum+=arr[i];
    	cum[i]=sum;
    }

    ll quer[q][2];
    for(int i=0;i<q;i++){
    	cin>>quer[i][0]>>quer[i][1];
    	quer[i][0]--;
    	quer[i][1]--;
    }

    for(int i=0;i<q;i++){
    	ll onecount=0;
    	if(quer[i][0]==0){
    		onecount=cum[quer[i][1]];
    	}
    	else{
    		onecount=cum[quer[i][1]]-cum[quer[i][0]-1]; 		
    	}

	    ll ans=power(2,quer[i][1]-quer[i][0]+1,1000000007)-power(2,quer[i][1]-quer[i][0]+1-onecount,1000000007);
//	    cout<<i<<" "<<onecount<<" "<<quer[i][1]-quer[i][0]+1<<endl;
	  //   for(int j=0;j<quer[i][1]-quer[i][0]+1;j++){
	  //   	if(onecount>0){
	  //   		ans|=1;
	  //   		onecount--;
	  //   	}
			// if(j<quer[i][1]-quer[i][0])	ans=ans<<1;
	    	ans%=1000000007;
	    	if(ans<0) ans+=1000000007;
//	    }
	    cout<<ans<<endl;
    }
}
