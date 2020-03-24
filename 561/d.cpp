#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll projectmin(ll i, ll sumtillnow, ll curr, ll k){
	if(i==k){
		return curr;
	}
	else{
		ll next=sumtillnow+curr+1;
		return pow((ll)2,k-i-1)*next;
	}
}

ll projectmax(ll i, ll sumtillnow, ll curr, ll k, ll m){
	if(i==k){
		return curr;
	}
	else{
		ll next=sumtillnow+curr+m;
		return pow((ll)2,k-i-1)*next;
	}
}


int main(){
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin>>q;

    for(int quer=0;quer<q;quer++){
    	ll a,b,m;
    	cin>>a>>b>>m;

    	ll min=0,max=0,prevmax=0;

    	ll i=0;
    	while(max<b){
    		min=pow((ll)2,i)*(a+1);
    		max=pow((ll)2,i)*(a+m);
    		i++;
    	}

    	if(min>b){
    		if(a==b){
    			cout<<1<<" "<<a<<endl;
    			continue;
    		}
    		cout<<-1<<endl;
    		continue;
    	}
    	else{
			cout<<i+1<<" ";
			cout<<a<<" ";
			ll sumtillnow=a;
			ll last=a;
			for(int j=0;j<i;j++){
				ll mymin=sumtillnow+1;
				ll mymax=sumtillnow+m;
				while(1){
					ll mymid=(mymin+mymax)/2;
					ll rangemin=projectmin(j+1,sumtillnow,mymid,i);
					ll rangemax=projectmax(j+1,sumtillnow,mymid,i,m);
					// cerr<<"I"<<i<<" J"<<j<<" MYMIN"<<mymin<<" MYMAX"<<mymax<<" sumtillnow"<<sumtillnow<<" mymid"<<mymid<<" last"<<last<<" rangemin"<<rangemin<<" rangemax"<<rangemax<<" "<<endl;

					if(rangemin>b){
						mymax=mymid-1;
						continue;
					}
					else if(rangemax<b){
						mymin=mymid+1;
						continue;
					}

					cout<<mymid<<" ";
					sumtillnow+=mymid;
					last=mymid;
					break;
				}			
			}
			cout<<endl;
    	}
    }
}