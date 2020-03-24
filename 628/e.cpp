#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

bool isPerfectSquare(ll x) 
{   
  long double sr = sqrt((long double)x);   
  return ((sr - floor(sr)) == 0); 
} 

map<ll,ll> primeFactors(ll n)  
{  
	map<ll,ll> temp;
    while (n%2 == 0)  
    {  
    	temp[2]++;
        n = n/2;  
    }  
  
    for (int i = 3; i <= sqrt(n); i = i + 2)  
    {  
        while (n % i == 0)  
        {  
        	temp[i]++;
            n = n/i;  
        }  
    }  
  
    // This condition is to handle the case when n  
    // is a prime number greater than 2  
    if (n > 2)  
    	temp[n]++;
    return temp;
}  
  

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }

    map<ll,ll> primeFac[n];
    for(int i=0;i<n;i++){
    	primeFac[i]=primeFactors(arr[i]);
    }


    for(int len=1;len<50;len++){
    // cerr<<"HI"<<" "<<len<<" "<<<<endl;
    	if(len>n)break;
    	for(int i=0;i<n-len+1;i++){
    		map<ll,ll> temp;
    		for(int j=i;j<i+len;j++){
    			for(auto a: primeFac[j]){
    				temp[a.first]+=a.second;
    			}
    		}
    		bool works=true;
    		for(auto a: temp){
    			if(a.second%2==1){
    				works=false;
    				break;
    			}
    		}
    		if(works){
    			cout<<len<<endl;
    			return 0;
    		}
    	}
    // cerr<<"HI"<<" "<<len<<endl;

    }
    cout<<-1<<endl;

}
