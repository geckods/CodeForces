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

	// #ifndef ONLINE_JUDGE
 //    	freopen("input", "r", stdin);
 //    	freopen("output", "w", stdout);
	// #endif
	// ios_base::sync_with_stdio(false);
 //   	cin.tie(NULL);

   	ll n;
   	cin>>n;
   	fflush(stdout);

   	ll bmin=0;
   	ll bmax=1e9;

   	ll bmid;
   	ll count=0;
   	while(bmin<bmax){
   		bmid=(bmin+bmax)/2;
   		cout<<"> "<<bmid<<endl;
	   	fflush(stdout);
	   	count++;


	   	ll x;
	   	cin>>x;
	   	fflush(stdout);
	   	if(x==1){
	   		bmin=bmid+1;
	   	}
	   	else{
	   		bmax=bmid;
	   	}
   	}

   	ll themax=bmax;
   	//as
   	ll ans=0;
   	srand(time(0));
   	ll diff=rand();
   	for(int i=count;i<60;i++){

   		if(i-count >= n)break;

   		cout<<"? "<<(diff*i)%n + 1<<endl;
	   	fflush(stdout);
	   	ll x;
	   	cin>>x;

	   	if(x==themax)continue;

   		if(ans==0){
   			ans=themax-x;
   		}
   		else{
   			ans=gcd(ans,themax-x);
   		}
   	}

   	cout<<"! "<<themax-(n-1)*ans<<" "<<ans<<endl;
   	fflush(stdout);
}