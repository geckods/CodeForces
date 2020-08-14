#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// THINGS TO REMEMBER
// ENDL is slow, '\n' is fast
// Clear everything (including graphs) between test cases
// use anti-anti-hash: https://codeforces.com/blog/entry/62393
// pb-ds: https://codeforces.com/blog/entry/11080
// check when to use LLONG_MAX/LLONG_MIN vs INT_MAX or INT_MIN
// You frequently suffer from confirmation bias - you trust your initial solution and miss simple things. 
// When you hit a roadblock, remember to rethink the solution ground up, not just try hacky fixes

map<ll,ll> primeFactors(ll n)  
{  
    // Print the number of 2s that divide n  
    map<ll,ll> ret;

    while (n % 2 == 0)  
    {  
        ret[2]++;
        n = n/2;  
    }  
  
    // n must be odd at this point. So we can skip  
    // one element (Note i = i +2)  
    for (int i = 3; i <= sqrt(n); i = i + 2)  
    {  
        // While i divides n, print i and divide n  
        while (n % i == 0)  
        {  
            ret[i]++;
            n = n/i;  
        }  
    }  
  
    // This condition is to handle the case when n  
    // is a prime number greater than 2  
    if (n > 2)
        ret[n]++;

    return ret;
}  

bool getAnswer(ll n){
    map<ll,ll> pf = primeFactors(n);
    // true is first dude wins

    bool isPowerOfTwo = (pf.size()==1);
    if(isPowerOfTwo){
        if(pf[2]==1){
            return true;
        }
        return false;
    }

    bool isOneTwo = (pf[2]==1);

    ll x = 0;
    for(auto it:pf){
        if(it.first==2){
            continue;
        }
        x+=it.second;
    }

    if(isOneTwo){
        return x>1;
    }
    else {
        return true;
    }
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


    while(t--){
        ll n;
        cin>>n;

        if(n==1){
            cout<<"FastestFinger"<<endl;
            continue;
        } else if (n==2){
            cout<<"Ashishgup"<<endl;
            continue;            
        }

        if(n%2==1){
            cout<<"Ashishgup"<<endl;
            continue;
        }

        if(getAnswer(n)){
            cout<<"Ashishgup"<<endl; 
        }
        else{
            cout<<"FastestFinger"<<endl;            
        }
    }
}