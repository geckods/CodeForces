#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isPrime(int n) 
{ 
    if (n <= 1) 
        return false; 
  
    for (int i = 2; i < n; i++) 
        if (n % i == 0) 
            return false; 
  
    return true; 
} 

int main(){

    #ifndef ONLINE_JUDGE
        freopen("input", "r", stdin);
        freopen("output", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<ll> primes;
    ll primecount=1;
    ll n;

    cin>>n;

    ll primecheck = 2;
    while(1){
    	while(!isPrime(primecheck)){
    		primecheck++;
    	}

    	primecount*=primecheck;
    	if(primecount>n){
    		break;
    	}
    	else{
    		primecheck++;
    		primes.push_back(primecheck);
    	}
    }