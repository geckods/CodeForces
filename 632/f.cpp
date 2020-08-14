#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MAXN 700001

// bool prime[MAXN+1]; 
// void SieveOfEratosthenes() 
// { 
//     memset(prime, true, sizeof(prime)); 
  
//     for (int p=2; p*p<=MAXN; p++) 
//     { 
//         if (prime[MAXN] == true) 
//         { 
//             for (int i=p*p; i<=MAXN; i += p) 
//                 prime[i] = false;
//         } 
//     }   
// } 

ll spf[MAXN]; 
  
void sieve() 
{ 
    spf[1] = 1; 
    for (int i=2; i<MAXN; i++)   
        spf[i] = i; 
  
    for (int i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
  
    for (int i=3; i*i<MAXN; i++) 
    { 
        if (spf[i] == i) 
        { 
            for (int j=i*i; j<MAXN; j+=i) 
  
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
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

    ll n;
    cin>>n;

    // SieveOfEratosthenes();
    sieve();

    // prime[1]=false;
    // prime[0]=false;

    spf[0]=spf[1]=-1;

    ll cumPrime[n+1];
    ll curr=0;

    for(int i=0;i<=n;i++){
    	if(spf[i]==i)curr++;
    	cumPrime[i]=curr;
    	// cerr<<i<<" "<<prime[i]<<" "<<spf[i]<<" "<<cumPrime[i]<<endl;
    }

    ll totSum=0;
    ll currDiv=1;
    // while(totSum<n-1){
    	// cerr<<n<<" "<<n/currDiv<<" "<<cumPrime[n/currDiv]<<endl;
	for(int i=0;i<cumPrime[n];i++){
		cout<<1<<" ";
	}

	vector<ll> myVec;
	for(int i=2;i<=n;i++){
		if(spf[i]!=i)myVec.push_back(i/spf[i]);
	}
	sort(myVec.begin(),myVec.end());

	for(int i=0;i<myVec.size();i++){
		cout<<myVec[i]<<" ";
	}

	// curr=2;
	// while(curr<=n){
	// 	while(curr<=n && spf[curr]==curr)curr++;
	// 	if(curr>n)break;
	// 	cout<<curr/spf[curr]<<" ";
	// 	curr++;
	// }
    	// totSum+=cumPrime[n/currDiv];
    	// currDiv++;
    // }
}
