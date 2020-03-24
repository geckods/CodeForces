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
    	ll n,m,k;
    	cin>>n>>m>>k;
    	if(n<0) n*=-1;
    	if(m<0) m*=-1;
    	if(k<max(n,m)){
    		cout<<-1<<endl;
    	}
    	else{
    		ll ans=0;
    		ans+=(min(n,m));
    		if((max(n,m)-min(n,m))%2==0){
    			if((k-min(n,m))%2==0){
    				ans+=(k-min(m,n));
    			}
    			else{
    				ans+=(k-min(m,n)-2);			
    			}
    		}
    		else{
    			if((k-min(n,m))%2==0){
    				ans+=(k-min(m,n)-1);    				
    			}
    			else{
    				ans+=(k-min(m,n)-1);    				    				
    			}

    		}
	    	cout<<ans<<endl;
    	}
    }
}