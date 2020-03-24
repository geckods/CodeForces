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

   	ll n,k;
   	cin>>n>>k;

   	string s;
   	cin>>s;

   	ll rightrout[n+1];
   	ll currright=LLONG_MAX;

   	for(int i=n;i>=1;i--){
   		if(s[i-1]=='1')currright=i;
   		rightrout[i]=currright;
   	}

   	ll curr=n;
   	ll ans=0;
   	while(curr>=1){
   		ll theright=rightrout[max(1ll,curr-k)];
   		//it's not (max(1ll,theright-k), you gotta binary search to find the first thing in the range which has no better router option for being selected i.e. first number which has rightrout = theright
   		if(theright < ((curr)*(curr+1)-(max(1ll,theright-k))*(max(1ll,theright-k)-1))/2){
   			ans+=theright;
   			curr=theright-k-1;
   		}
   		else{
   			ans+=curr;
   			curr--;
   		}
   	}

   	cout<<ans<<endl;
}
