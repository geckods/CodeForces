#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<ll,ll> primeFactors(ll n)
{
	map<ll,ll> myMap;
    while (n%2 == 0)  
    {  
    	myMap[2]++;
        n = n/2;  
    }  
  
    for (int i = 3; i <= sqrt(n); i = i + 2)  
    {  
        while (n % i == 0)  
        {  
        	myMap[i]++;
            n = n/i;  
        }  
    }  
  
    if (n > 2)  
    	myMap[n]++;
    return myMap;
}

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll x;
    cin>>x;

    map<ll,ll> factors = primeFactors(x);
    ll size = factors.size();

    ll ans=LLONG_MAX;

    ll ga,gb;

    for(int i=0;i<pow(2ll,size);i++){
    	ll a=1;
    	ll b=1;

    	ll j=i;
    	for(map<ll,ll>::iterator asd = factors.begin();asd!=factors.end();asd++){
    		if(j%2){
    			a*=pow(asd->first,asd->second);
    		}
    		else{
    			b*=pow(asd->first,asd->second);    			
    		}
    		j/=2;
	    	// cout<<asd->first<<" "<<asd->second<<endl;
    	}

    	// cout<<i<<" "<<a<<" "<<b<<endl;

    	if(max(a,b)<ans){
    		ans=max(a,b);
    		ga=a;
    		gb=b;
    	}
    }
    cout<<ga<<" "<<gb<<endl;
}