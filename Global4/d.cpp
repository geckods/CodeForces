//generate primes
//prime*2 = total degree sequence
//try to allot

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isPrime(int n) 
{ 
    // Corner case 
    if (n <= 1) 
        return false; 
  
    // Check from 2 to n-1 
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

    int n;
    cin>>n;

    int i=n;
    while(!isPrime(i))i++;

    cout<<i<<endl;
    for(int z=1;z<n;z++){
    	cout<<z<<" "<<(z+1)<<endl;
    }
    cout<<1<<" "<<n<<endl;

    i-=n;

    queue<int> myQ;
    for(int i=1;i<=n;i++){
    	myQ.push(i);
    }

    while(i>0){
    	int a,b;
    	a = myQ.front();
    	myQ.pop();
    	myQ.push(myQ.front());
    	myQ.pop();
    	b = myQ.front();
    	myQ.pop();
    	cout<<a<<" "<<b<<endl;
    	i--;
    }

}