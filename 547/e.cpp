#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

	// #ifndef ONLINE_JUDGE
 //    	freopen("input", "r", stdin);
 //    	freopen("output", "w", stdout);
	// #endif
	// ios_base::sync_with_stdio(false);
 //   	cin.tie(NULL);

   	ll n,h;
   	cin>>h>>n;

   	ll d[n];
   	for(int i=0;i<n;i++){
   		cin>>d[i];
   	}

   	ll cum[n];
   	cum[0]=d[0];

   	ll mincycle=LLONG_MAX;
   	ll mincycleind=-1;

   	for(int i=1;i<n;i++){
   		cum[i]=cum[i-1]+d[i];
   		if(cum[i]<mincycle){
   			mincycle=cum[i];
   			mincycleind=i;
   		}
   	}

   	if(cum[0]<mincycle){
   		mincycle=cum[0];
   		mincycleind=0;
   	}



   	ll cycleeffect=cum[n-1];

   	ll ans=0;

   	// cout<<mincycle<<" "<<cycleeffect<<endl;

   	if(h>(-1)*mincycle){
   		if(cycleeffect>=0){
   			cout<<-1<<endl;
   			return 0;
   		}
   		else{
   			cycleeffect*=(-1);
   		}

   		if(mincycle<0) mincycle*=(-1);

   		ans+=n*((h-mincycle)/cycleeffect);
   		h-=((h-mincycle)/cycleeffect)*cycleeffect;
   	}

   	// cout<<ans<<endl;

   	int i=0;
   	while(h>0){
   		// cout<<i<<" "<<h<<endl;
   		h+=d[i%n];
   		ans++;
   		i++;
   	}

   	cout<<ans<<endl;
}
