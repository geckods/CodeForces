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

    ll n;
    cin>>n;

    ll a[n];

    for(int i=0;i<n;i++){
    	cin>>a[i];
    }

    ll m;
    cin>>m;

    ll b[m];

    for(int i=0;i<m;i++){
    	cin>>b[i];
    }

    ll acum[n];
    acum[0]=a[0];
    for(int i=1;i<n;i++){
    	acum[i]=a[i]+acum[i-1];
    }

    ll bcum[m];
    bcum[0]=b[0];
    for(int i=1;i<m;i++){
    	bcum[i]=b[i]+bcum[i-1];
    }


    ll ap=0;
    ll bp=0;

    ll lastasum=0;
    ll lastbsum=0;

    ll ans=0;

    while(ap<n){
    	ll bind = lower_bound(bcum,bcum+m,acum[ap]-lastasum+lastbsum)-bcum;
    	// cout<<ap<<" "<<acum[ap]<<" "<<bind<<" "<<bcum[bind]<<" "<<ans<<endl;
    	if(bind==m){
    		cout<<-1<<endl;
    		return 0;
    	}

    	if(bcum[bind]!=acum[ap]-lastasum+lastbsum){
    		if(ap==n-1){
    			cout<<-1<<endl;
    			return 0;
    		}
    		else{
    			ap++;
    			continue;
    		}
    	}
    	else{
    		lastasum=acum[ap];
    		lastbsum=bcum[bind];
    		ap++;
    		ans++;
    		bp=bind;
    	}
    }

    if(bp!=m-1){
    	cout<<-1<<endl;
    }
    else{
	    cout<<ans<<endl;
	}
}