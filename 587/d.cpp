#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
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

   	ll maxof=INT_MIN;

   	ll arr[n];
   	for(int i=0;i<n;i++){
   		cin>>arr[i];
   		maxof=max(maxof,arr[i]);
   	}

   	ll z=0;
   	ll rem=0;

   	for(int i=0;i<n;i++){
   		if(arr[i]==maxof)continue;
   		if(z==0)z=maxof-arr[i];
   		else z=gcd(z,maxof-arr[i]);
   		rem+=maxof-arr[i];
   	}

   	cout<<rem/z<<" "<<z<<endl;
}