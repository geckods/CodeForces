#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;

    while(t--){
    	ll ogn,ogd;
    	cin>>ogn>>ogd;

    	//seems overkill, but binary search for next value of x that changes it

    	ll x=0;
    	ll curr=ceil(((double)ogd)/(x+1));

    	bool done=false;
    	while(curr+x>ogn){
            // cout<<x<<" "<<curr<<endl;
    		if(x>=ogn){
    			cout<<"NO"<<endl;
    			done=true;
    			break;
    		}
    		else{
    			ll bmin=x+1;
    			ll bmax=1e9+7;
    			ll bmid;
                ll newcurr;
    			while(bmin<bmax){
	    			bmid=(bmin+bmax)/2;
    				newcurr=ceil(((double)ogd)/(bmid+1));
    				if(newcurr<curr){
    					bmax=bmid;
    				}
    				else{
    					bmin=bmid+1;
    				}
    			}
    			x=bmid;
    		}
            curr=ceil(((double)ogd)/(x+1));
    	}
    	if(done)continue;
    	cout<<"YES"<<endl;
    }

}
