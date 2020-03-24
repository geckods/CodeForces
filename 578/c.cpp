#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);


   	ll n,m,q;
   	cin>>n>>m>>q;

   	ll gc = gcd(n,m);

   	// if(n==m)gc=1;

   	for(int i=0;i<q;i++){
   		ll sx,sy,ex,ey;

   		cin>>sx>>sy>>ex>>ey;

   		sy--;
   		ey--;

   		ll smap;
   		ll emap;

   		if(sx==1){
   			smap=sy;
   		}
   		else{
   			smap=(sy/(double)m)*n;
   		}

   		if(ex==1){
   			emap=ey;
   		}
   		else{
   			emap=(ey/(double)m)*n;   			
   		}
   		// cout<<gc<<endl;
   		// cout<<smap<<" "<<emap<<endl;
   		// cout<<(emap/((double)n/m))<<endl;

   		if(smap/(n/gc) != emap/(n/gc)){
   			cout<<"NO"<<endl;
   		}
   		else{
   			cout<<"YES"<<endl;
   		}
   	}
}