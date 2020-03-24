#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353

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

    ll n;
    cin>>n;

    ll arr[n];

    ll digitcount[11];
    for(int i=0;i<11;i++){
    	digitcount[i]=0;
    }

    for(int i=0;i<n;i++){
    	cin>>arr[i];

    	// if(arr[i]==1000000000)
    	ll j=0;
    	while(arr[i]/(ll)pow(10,j)>0){
    		// cout<<arr[i]<<" "<<j<<" "<<arr[i]/pow(10,j)<<endl;
    		j++;
    	}
    	// j--;
    	digitcount[j]++;
    	// cout<<arr[i]<<" "<<j<<" "<<pow(10,j)<<endl;
    }

    // cout<<digitcount[9]<<endl;

    ll ans=0;

    for(int i=0;i<n;i++){
	    ll j=1;
	    while(arr[i]/j > 0) j*=10;
	    j/=10;

	    ll digitsums[11][2];
	    // memset(digitsums,0,sizeof(digitsums));
	    for(int k=0;k<11;k++){
	    	digitsums[k][0]=digitsums[k][1]=0;
	    }

	    while(j>0){
	    	ll jlog =(ll)(log10(j));
	    	for(int k=1;k<11;k++){
	    		ll mulfac=jlog*2;
	    		if(jlog>k){
	    			// mulfac-=((ll)log10(j)-1);
	    			mulfac=2*k+(jlog-k);
	    		}
	    		ll mult=(ll)pow(10ll,mulfac);
	    		mult%=MOD;
	    		digitsums[k][0]+=(((arr[i]/j)%10)*mult)%MOD;
	    		digitsums[k][0]%=MOD;

	    		ll mulfac2;
	    		if(jlog>=k){
	    			mulfac2=2*k+(jlog-k);
	    		}
	    		else{
	    			mulfac2=2*jlog+1;
	    		}

	    		// cout<<k<<" "<<mulfac<<" "<<mulfac2<<endl;

	    		if(mulfac2==19){
	    			mult=(ll)pow(10ll,18);
	    			mult%=MOD;
	    			mult*=10;
	    			mult%=MOD;
	    		}
	    		else{
		    		mult=(ll)pow(10ll,mulfac2);
		    		mult%=MOD;
	    		}
	    		digitsums[k][1]+=(((arr[i]/j)%10)*mult)%MOD;
	    		digitsums[k][1]%=MOD;
	    	}
	    	j/=10;
	    }

	    for(int k=0;k<11;k++){
	    	// if(digitsums[k][0]<0)digitsums[k][0]+=MOD;
	    	// if(digitsums[k][1]<0)digitsums[k][1]+=MOD;


	    	// cout<<k<<" "<<digitsums[k][0]<<endl;
	    	// cout<<k<<" "<<digitsums[k][1]<<endl;
	    }
	    // partone/=100;
	    // cout<<partone<<endl;
	    for(int k=1;k<11;k++){
	    	// cout<<k<<" "<<digitcount[k]<<endl;
	    	// cout<<digitcount[k]<<endl;
		    ans+=((digitcount[k])*digitsums[k][0])%MOD;
		    ans%=MOD;
		    ans+=((digitcount[k])*digitsums[k][1])%MOD;
		    ans%=MOD;
		    // digitsums[k]*=10;
		    // digitsums[k]%=MOD;
		    // ans+=((digitcount[k])*digitsums[k])%MOD;
		    ans%=MOD;
	    }
    }

    // if(ans<0) ans+=MOD;

    cout<<ans<<endl;
}