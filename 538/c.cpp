#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<ll,ll> primeFactors(ll n)  
{  
    // Print the number of 2s that divide n  
	map<ll,ll> myMap;
    while (n % 2 == 0)  
    {  
    	myMap[2]++;
        n = n/2;  
    }  
  
    // n must be odd at this point. So we can skip  
    // one element (Note i = i +2)  
    for (int i = 3; i <= sqrt(n); i = i + 2)  
    {  
        // While i divides n, print i and divide n  
        while (n % i == 0)  
        {  
            // cout << i << " ";  
            myMap[i]++;
            n = n/i;  
        }  
    }  
  
    // This condition is to handle the case when n  
    // is a prime number greater than 2  
    if (n > 2)  
    	myMap[n]++;

	return myMap;        // cout << n << " ";  
}  


int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	ll n,b;
   	cin>>n>>b;

   	map<ll,ll> bMap = primeFactors(b);
   	map<ll,ll> nMap;

   	ll ans=LLONG_MAX;
   	for(map<ll,ll>::iterator a = bMap.begin();a!=bMap.end();a++){
   		
   		ll theprime=a->first;

   		ll nc=n;
   		ll count=0;

   		while(nc>0){
   			count+=nc/theprime;
   			nc/=theprime;
   		}

   		ans=min(ans,count/a->second);
   	}
   	cout<<ans<<endl;
}