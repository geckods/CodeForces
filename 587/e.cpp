#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll countDigit(ll n) 
{ 
    ll count = 0; 
    while (n != 0) { 
        n = n / 10; 
        ++count; 
    } 
    return count; 
}

ll howmany(ll x){
	ll digcount = countDigit(x);
	ll ans=0;
	for(int i=1;i<digcount;i++){
		ans+=i*9*pow(10ll,i-1);
	}

	ans+=digcount*(x-pow(10ll,digcount-1)+1);
	return ans;
}


int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	ll i=1;
   	ll size=0;

	vector<ll> myVec;
	// ll currsize=1;
   	while(size<1e9){
   		// currsize=1;
   		// for(ll j=1;j<=i;j++){
   		size+=howmany(i);
   		// 	if((j==9||j==99||j==999||j==9999||j==99999||j==999999||j==9999999||j==99999999||j==999999999||j==9999999999)  /*&& countDigit(j)!=countDigit(j+1)*/)currsize++;
   		// }
   		// cout<<i<<" "<<size<<endl;
   		myVec.push_back(size+1);
   		i++;
   		// if(i%10000==0){
   			// cerr<<i<<" "<<size<<endl;
   		// }
   	}

   	// for(int i=0;i<10;i++){
   	// 	cout<<myVec[i]<<endl;
   	// }

   	int q;
   	cin>>q;
   	// cout<<q<<endl;
   	for(int quer=0;quer<q;quer++){
   		ll x;
   		cin>>x;
	   	int lb = upper_bound(myVec.begin(),myVec.end(),x)-1-myVec.begin();
	   	if(lb==-1){
	   		cout<<1<<endl;
	   		continue;
	   	}

	   	int currind=myVec[lb];
	   	int j=1;
	   	while(currind<x){
	   		currind+=countDigit(j);
	   		j++;
	   	}

	   	// cout<<lb<<" "<<myVec[lb]<<" "<<j<<" "<<currind<<endl;
	   	if(currind==x){
	   		//print first char of j
	   		cout<<to_string(j)[0]<<endl;
	   	}
	   	else{
	   		j--;
	   		currind-=countDigit(j);
	   		cout<<to_string(j)[x-currind]<<endl;
	   		//print 
	   	}


	   	// cout<<lb<<" "<<myVec[lb]<<endl;
   	}

}