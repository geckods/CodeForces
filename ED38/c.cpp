#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 2e9

ll floorSqrt(ll x)  
{     
    // Base cases 
    if (x == 0 || x == 1)  
       return x; 
  
    // Do Binary Search for floor(sqrt(x)) 
    ll start = 1, end = x, ans;    
    while (start <= end)  
    {         
        ll mid = (start + end) / 2; 
  
        // If x is a perfect square 
        if (mid*mid == x) 
            return mid; 
  
        // Since we need floor, we update answer when mid*mid is  
        // smaller than x, and move closer to sqrt(x) 
        if (mid*mid < x)  
        { 
            start = mid + 1; 
            ans = mid; 
        }  
        else // If mid*mid is greater than x 
            end = mid-1;         
    } 
    return ans; 
} 


int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	ll t;
   	cin>>t;

   	// cout<<t<<endl;
   	set<ll> sq;

   	ll squares[44722];
   	for(ll i=0;i<44722;i++){
   		squares[i]=(ll)i*i;
   		sq.insert(squares[i]);
   	}

//36514 2

   	ll x;
   	for(ll test=0;test<t;test++){
   		cin>>x;
   		bool done=false;
   		for(ll i=1;i<44722;i++){
   			ll sum=squares[i]+x;
   			// cout<<i<<" "<<squares[i]<<" "<<x<<endl;
   			if(sq.find(sum)!=sq.end()){
   				//it is a perfect square
   				ll n = floorSqrt(sum);
   				ll m = n/i;
   				if(n/m==i){
   					cout<<n<<" "<<m<<endl;
 	  				done=true;
   					break;   					
   				}
   				else{
   					m++;
	   				if(n/m==i){
   						cout<<n<<" "<<m<<endl;
 		  				done=true;
   						break;   					
   					}
   				}
   			}
   		}

   		if(!done){
   			cout<<-1<<endl;
   		}

   	}

}