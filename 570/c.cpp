#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	ll q;
   	cin>>q;

   	for(int quer=0;quer<q;quer++){
   		ll k,n,a,b;
   		cin>>k>>n>>a>>b;

   		if(n*b>=k){
   			cout<<-1<<endl;
   			continue;
   		}

   		//let him just play x turns
//   		x*a + (n-x)*b < k 

   		ll min=0;
   		ll max=n;
   		ll mid;
   		ll midplusone;
   		ll evalmid;
   		ll evalmidplusone;


   		while(1){
   			mid=(min+max)/2;
   			midplusone=mid+1;
   			evalmid=mid*a + (n-mid)*b;
   			evalmidplusone=midplusone*a + (n-midplusone)*b;
   			if(evalmid<k && (mid==n || evalmidplusone>=k)){
   				cout<<mid<<endl;
   				break;
   			}
   			else if (evalmid>=k){
   				max=mid-1;
   			}
   			else if (evalmidplusone<k){
   				min=midplusone;
   			}
   		}
   	}
}