#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MAXN 1000001 
  
// stores smallest prime factor for every number 
int spf[MAXN]; 
  
// Calculating SPF (Smallest Prime Factor) for every 
// number till MAXN. 
// Time Complexity : O(nloglogn) 
void sieve() 
{ 
    spf[1] = 1; 
    for (int i=2; i<MAXN; i++) 
  
        // marking smallest prime factor for every 
        // number to be itself. 
        spf[i] = i; 
  
    // separately marking spf for every even 
    // number as 2 
    for (int i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
  
    for (int i=3; i*i<MAXN; i++) 
    { 
        // checking if i is prime 
        if (spf[i] == i) 
        { 
            // marking SPF for all numbers divisible by i 
            for (int j=i*i; j<MAXN; j+=i) 
  
                // marking spf[j] if it is not  
                // previously marked 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 
  
// A O(log n) function returning primefactorization 
// by dividing by smallest prime factor at every step 
vector<int> getFactorization(int x) 
{ 
    vector<int> ret; 
    while (x != 1) 
    { 
        ret.push_back(spf[x]); 
        x = x / spf[x]; 
    } 
    return ret; 
} 

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // generatePrimeFactors(); 

    int t;
    cin>>t;

    for(int test=0;test<t;test++){
    	int n;
    	cin>>n;
    	ll arr[n];
    	for(int i=0;i<n;i++){
    		cin>>arr[i];
    	}

    	sort(arr,arr+n);

    	int i=0;
    	int j=n-1;

    	ll hypothesis = arr[i]*arr[j];
    	bool done=false;
    	int previ=1;

    	while(i<=j){
    		// cout<<arr[i]<<" "<<arr[j]<<" "<<arr[i]*arr[j]<<endl;
    		if(arr[i]*arr[j]!=hypothesis){
    			cout<<-1<<endl;
    			done = true;
    			break;
    		}

    		if(i<n){
	    		for(int minii = previ+1;minii<arr[i];minii++){
	    			if(hypothesis%minii == 0){
	    				// cout<<previ<<endl;
	    				// cout<<minii<<endl;
	    				done = true;
	    				cout<<-1<<endl;
	    				break;
	    			}
	    		}
	    	}
    		if(done) break;

    		previ = arr[i];
    		i++;
    		j--;
    	}


    	if(!done){
	    	if(i>j){
	    		i--;
	    		j++;
	    	}

	    	for(int minii = arr[i]+1;minii<arr[j];minii++){
	    		// cout<<minii<<endl;
		    	if(hypothesis%minii == 0){
		    		// cout<<previ<<endl;
		    		// cout<<minii<<endl;
		    			done = true;
		    			cout<<-1<<endl;
		    			break;
		    	}
		    }
		}


    	// map<int,int> countMap;


    	// if(calculateNoOFactors(hypothesis)-2 != n){
    	// 	cout<<-1<<endl;
    	// 	done = true;
    	// }

    	// set<ll> mySet;
    	// for(int i=0;i<n;i++){
    	// 	mySet.insert(arr[i]);
    	// }

    	// for(int i=2;i*i<=hypothesis;i++){
    	// 	if(hypothesis%i==0){
    	// 		if(mySet.find(i)==mySet.end() || mySet.find(hypothesis/i)==mySet.end()){
    	// 			cout<<-1<<endl;
    	// 			done = true;
    	// 			break;
    	// 		}
    	// 	}
    	// }

    	if(!done){
    		cout<<hypothesis<<endl;
    	}
    }
}
