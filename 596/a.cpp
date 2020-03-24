#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll countSetBits(ll n)
{ 
    ll count = 0; 
    while (n) 
    { 
    	n &= (n-1) ; 
    	count++; 
    } 
    return count; 
}

// ll maxcountSetBits(ll n) 
// { 
//     ll count = 0; 
//     ll i=1;
//     while (n){
//     	if(n%2){
//     		count+=i;
//     	}
//     	i*=2;
//     	n/=2;
//     }
//     return count; 
// } 

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	ll n,p;
   	cin>>n>>p;

   	ll ans=INT_MAX;
   	for(int i=1;i<=5000;i++){
   		// cout<<n+i*p<<" "<<maxcountSetBits(n+i*p)<<endl;
   		if(countSetBits(n-i*p) <= i && (n-i*p)>=i){
   			ans=min(ans,(ll)i);
   		}
   	}

   	if(ans!=INT_MAX){
	   	cout<<ans<<endl;
	}
	else{
		cout<<-1<<endl;
	}

}
