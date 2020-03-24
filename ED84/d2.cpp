#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> printDivisors(ll n) 
{ 
    vector<ll> tempVec;
    for (ll i=1; i*i<=n; i++) 
    { 
        if (n%i == 0) 
        { 
            tempVec.push_back(i);
            tempVec.push_back(n/i);
        } 
    } 
    return tempVec;
} 
 
ll setBitNumber(ll n) 
{ 
    n |= n >> 1; 
  
    n |= n >> 2; 
  
    n |= n >> 4; 
    n |= n >> 8; 
    n |= n >> 16; 
  
    n = n + 1; 
    return (n >> 1); 
}
 
 
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

    // ll ogt=t;

    // vector<ll> tempVec =printDivisors(4);
    // for(int i=0;i<tempVec.size();i++){
    //     cerr<<tempVec[i]<<endl;
    // }

    while(t--){
    	ll n;
    	cin>>n;
    	ll p[n];
    	for(int i=0;i<n;i++){
    		cin>>p[i];
    		p[i]--;
    	}
 
    	ll c[n];
    	for(int i=0;i<n;i++){
    		cin>>c[i];
    	}

        // if(ogt==10000 && ogt-t==59){
        //     cout<<n<<endl;
        //     for(int i=0;i<n;i++){
        //         cout<<p[i]<<" ";
        //     }
        //     cout<<endl;
        //     for(int i=0;i<n;i++){
        //         cout<<c[i]<<" ";
        //     }
        //     cout<<endl;

        // }
 
 
    	bool checked[n];
    	memset(checked,false,sizeof(checked));
 
    	ll ans=n;
    	for(int i=0;i<n;i++){
    		if(checked[i])continue;
    		vector<ll> temp;
    		temp.push_back(i);
    		ll curr=p[i];
    		while(curr!=i){
    			// cerr<<"HI"<<endl;
    			temp.push_back(curr);
    			checked[curr]=true;
    			curr=p[curr];
    		}
 
    		if(temp.size()==1){
    			ans=1;
    			break;
    		}

            ans=min(ans,(ll)temp.size());
            // cerr<<temp.size()<<endl;
            vector<ll> fact=printDivisors(temp.size());
            sort(fact.begin(),fact.end());
    		for(auto z:fact){
                if(z==temp.size())continue;
                // cerr<<z<<endl;
	    		bool works=true;
 
    			for(ll zz=0;zz<z;zz++){
    				works=true;
    				ll zzs=zz;
	    			while(zzs<temp.size()){
	    				if(c[temp[zzs]]==c[temp[zz]]){
		    				zzs+=z;
	    				}
	    				else{
	    					works=false;
	    					break;
	    				}
	    			}
	    			if(works)break;
    			}
 
    			if(works){
    				ans=min(ans,z);
                    break;
    			}
    		}
    	}
        // if(ogt!=10000)
        	cout<<ans<<endl;
    }
}