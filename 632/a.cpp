#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MAXN 500000

bool prime[MAXN+1]; 
void SieveOfEratosthenes() 
{ 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=MAXN; p++) 
    { 
        if (prime[MAXN] == true) 
        { 
            for (int i=p*p; i<=MAXN; i += p) 
                prime[i] = false;
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

    // =

    ll t;
    cin>>t;
    while(t--){
    	ll n,m;
    	cin>>n>>m;
    	bool currBlack=true;
    	bool hasDone=false;
    	if((n*m)%2==1){
    		for(int i=0;i<n;i++){
    			for(int j=0;j<m;j++){
    				if(currBlack){
    					cout<<"B";
    				}
    				else{
    					cout<<"W";
    				}
    				currBlack=!currBlack;
    			}
    			cout<<endl;
    		}
    	}
    	else{
    		for(int i=0;i<n;i++){
    			currBlack=(i%2)==0;
    			for(int j=0;j<m;j++){
    				if(currBlack){
    					cout<<"B";
    				}
    				else{
    					if(j==m-1 && (i==0||i==n-1) && !hasDone){
    						cout<<"B";
    						hasDone=true;
    					}
    					else{
	    					cout<<"W";
    					}
    				}
    				currBlack=!currBlack;
    			}
    			cout<<endl;
    		}
    	}
    }


    
}
