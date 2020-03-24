#include <bits/stdc++.h>
using namespace std;
const int N = 20000;
typedef long long ll;
// array to store inverse of 1 to N 
ll factorialNumInverse[N + 1]; 
  
// array to precompute inverse of 1! to N! 
ll naturalNumInverse[N + 1]; 
  
// array to store factorial of first N numbers 
ll fact[N + 1]; 
  
// Function to precompute inverse of numbers 
void InverseofNumber(ll p) 
{ 
    naturalNumInverse[0] = naturalNumInverse[1] = 1; 
    for (int i = 2; i <= N; i++) 
        naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p; 
} 
// Function to precompute inverse of factorials 
void InverseofFactorial(ll p) 
{ 
    factorialNumInverse[0] = factorialNumInverse[1] = 1; 
  
    // precompute inverse of natural numbers 
    for (int i = 2; i <= N; i++) 
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p; 
} 
  
// Function to calculate factorial of 1 to N 
void factorial(ll p) 
{ 
    fact[0] = 1; 
  
    // precompute factorials 
    for (int i = 1; i <= N; i++) { 
        fact[i] = (fact[i - 1] * i) % p; 
    } 
} 
  
// Function to return nCr % p in O(1) time 
ll Binomial(ll N, ll R, ll p) 
{ 
    // n C r = n!*inverse(r!)*inverse((n-r)!) 
    ll ans = ((fact[N] * factorialNumInverse[R]) 
              % p * factorialNumInverse[N - R]) 
             % p; 
    return ans; 
}

int power(int x, unsigned int y, int p) 
{ 
    int res = 1;      // Initialize result 
  
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

int genzero(a,b,c,n,arr){
	if(n==1){
		return a;
	}
	return genzero()
}

//precompute factorial mod p up till n

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif

    ll p = 1000000007; 
    InverseofNumber(p); 
    InverseofFactorial(p); 
    factorial(p);

    int a,b,c;

    int n,l,r;
    cin>>n>>l>>r;

    int nextthreepow = l;
    while(nextthreepow%3!=0) nextthreepow++;

    int prevthreepow = r;
    while(prevthreepow%3!=0) prevthreepow--;

    a = (prevthreepow-nextthreepow)/3 + 1;
    b = a-1;
    if(l==nextthreepow-2) b++;
    if(r>prevthreepow) b++;

    c = a-1;
    if(l<nextthreepow) c++;
    if(r==prevthreepow+2)c++;

    ll ans=0;
//    cout<<"nextthreepow"<<nextthreepow<<"prevthreepow"<<prevthreepow<<endl;
//    cout<<"a"<<a<<"b"<<b<<"c"<<c<<endl;
/*
    if(a>0 && b>0 && c>0){
    	ans = power(r-l+1,n-1,p);
    }
    for(int i=0;i<=n;i++){
    	if(((n-i)%2)!=0) continue;
    	ans+=power(a,Binomial(n,i,p),p)*power(b,Binomial(n-i, (n-i)/2,p),p)*power(c,Binomial((n-i)/2, (n-i)/2,p),p);
//    	cout<<"ASDF"<<Binomial(n-i, (n-i)/2,p)<<endl;
//    	cout<<
//    	cout<<power((n-i)/2,c,p)<<endl;
    	cout<<i<<": "<<ans<<endl;
    }
*/



    cout<<ans<<endl;

}
