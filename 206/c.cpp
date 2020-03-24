#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll altcost(ll arr[], ll cum[],  ll n, ll i, ll j, bool isleft, ll l, ll r){
	if((j-i+1)%2 == 0){
		ll left = cum[(i+j)/2]*l;
		if(i>0)left-=cum[i-1]*l;
		ll right = cum[j]*r;
		if((i+j)/2>0)right = cum[(i+j)/2 -1]*r;
		return left+right;
	}
	else{

		ll left=0;
		if((i+j)/2>0){
			left = cum[(i+j)/2-1]*l;
		}
		if(i>0)left-=cum[i-1]*l;

		ll right = cum[j]*r;
		right -= cum[(i+j)/2]*r;

		ll mid=0;
		if(isleft){
			mid=arr[(i+j)/2]*l;
		}
		else{
			mid=arr[(i+j)/2]*r;			
		}
		// cerr<<"LRM"<<" "<<left<<" "<<right<<" "<<mid<<endl;
		// cerr<<"L:"<<" "<<l<<endl;
		return left+right+mid;
	}
}

ll leftcost(ll arr[], ll cum[], ll i, ll j, ll l, ll r, ll ql, ll qr){
	ll cost=cum[j];
	if(i>0){
		cost-=cum[i-1];
	}

	cost*=l;
	cost+=(j-i)*ql;
	return cost;
}

ll rightcost(ll arr[], ll cum[], ll i, ll j, ll l, ll r, ll ql, ll qr){
	ll cost=cum[j];
	if(i>0){
		cost-=cum[i-1];
	}

	cost*=r;
	cost+=(j-i)*qr;
	return cost;
}


int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,l,r,ql,qr;

    cin>>n>>l>>r>>ql>>qr;
    ll arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }
    // cerr<<"HI"<<endl;



    //alternate till a point

    //start left
    ll ans=LLONG_MAX;

    int currmin=0;
    int currmax=(n-1);
    ll cum[n];
    cum[0]=arr[0];
    for(int i=1;i<n;i++){
    	cum[i]=arr[i]+cum[i-1];
    }

    
  	ll minians=0;
  	ll minterm=0;

  	// ll newans=0;
  	// bool lastleft;

  	// if(arr[currmin]*l<=arr[currmax]*r){
  	// 	newans+=arr[currmin]*l;
  	// 	currmin++;
  	// 	lastleft=true;
  	// }
  	// else{
  	// 	newans+=arr[currmax]*r;
  	// 	currmax--;
  	// 	lastleft=false;
  	// }

  	// while(currmin<=currmax){
  	// 	ll leftcost = arr[currmin]*l;
  	// 	ll rightcost = arr[currmax]*r;


  	// 	if(lastleft)leftcost+=ql;
  	// 	else rightcost+=qr;
  	// 	// cerr<<currmin<<" "<<currmax<<" "<<leftcost<<" "<<rightcost<<" "<<newans<<endl;

  	// 	if(leftcost<=rightcost){
  	// 		lastleft=true;
  	// 		newans+=leftcost;
  	// 		currmin++;
  	// 	}
  	// 	else{
  	// 		lastleft=false;
  	// 		newans+=rightcost;
  	// 		currmax--;  			
  	// 	}
  	// }
  	// cout<<newans<<endl;
  	// return 0;

    // while(currmin<=currmax){
    // 	if(currmin==0)
	   //  	minterm=min(leftcost(arr, cum,currmin,currmax,l,r,ql,qr),rightcost(arr, cum,currmin,currmax,l,r,ql,qr));
	   //  else
	   //  	minterm=min(leftcost(arr, cum,currmin,currmax,l,r,ql,qr),rightcost(arr, cum,currmin,currmax,l,r,ql,qr)+qr);
    // 	cerr<<currmin<<" "<<currmax<<" "<<minians<<" "<<minterm<<endl;

    // 	if(altcost(arr, cum, n, currmin, currmax,true,l,r)<minterm){
    // 		minians+=arr[currmin]*l;
    // 		currmin++;
    // 	}
    // 	else{
    // 		minians+=minterm;
    // 		break;
    // 	}

	   //  minterm=min(leftcost(arr, cum,currmin,currmax,l,r,ql,qr)+ql,rightcost(arr, cum,currmin,currmax,l,r,ql,qr));
    // 	cerr<<currmin<<" "<<currmax<<" "<<minians<<" "<<minterm<<endl;

    // 	if(altcost(arr, cum, n, currmin, currmax,false,l,r) < minterm){
    // 		minians+=arr[currmax]*r;
    // 		currmax--;
    // 	}
    // 	else{
    // 		minians+=minterm;
    // 		break;
    // 	}
    // }
    // cerr<<minians<<endl;

    // ans=min(ans,minians);

    // minians=0;
    // currmin=0;
    // currmax=(n-1);
    // while(currmin<=currmax){

    // 	if(currmax==(n-1))
	   //  	minterm=min(leftcost(arr, cum,currmin,currmax,l,r,ql,qr),rightcost(arr, cum,currmin,currmax,l,r,ql,qr));
	   //  else
	   //  	minterm=min(leftcost(arr, cum,currmin,currmax,l,r,ql,qr)+ql,rightcost(arr, cum,currmin,currmax,l,r,ql,qr));


    // 	cerr<<currmin<<" "<<currmax<<" "<<minians<<" "<<minterm<<endl;

    // 	if(altcost(arr, cum, n, currmin, currmax,false,l,r) < minterm){
    // 		minians+=arr[currmax]*r;
    // 		currmax--;
    // 	}
    // 	else{
    // 		minians+=minterm;
    // 		break;
    // 	}

	   //  minterm=min(leftcost(arr, cum,currmin,currmax,l,r,ql,qr),rightcost(arr, cum,currmin,currmax,l,r,ql,qr)+qr);
    // 	cerr<<currmin<<" "<<currmax<<" "<<minians<<" "<<minterm<<endl;
    // 	// cerr<<altcost(arr, cum, n, currmin, currmax,true,l,r)<<endl;
    // 	if(altcost(arr, cum, n, currmin, currmax,true,l,r) < minterm){
    // 		// cerr<<"HI"<<endl;
    // 		minians+=arr[currmin]*l;
    // 		currmin++;
    // 	}
    // 	else{
    // 		minians+=minterm;
    // 		break;
    // 	}
    // }

    // cerr<<minians<<endl;    

    // ans=min(ans,minians);

    // cout<<ans<<endl;
    if(n==1){
    	cout<<arr[0]*min(l,r)<<endl;
    	return 0;
    }

    if(n%2==0){
    	ll dp[n][2];
    	//dp[i] represents the range from ((n-1)/2 - i) to ((n-1)/2 + i +1)
    	//dp[i][0] represents leftstart
    	dp[0][0]=min(arr[((n-1)/2)]*l + arr[((n-1)/2)+1]*r,arr[((n-1)/2)]*l + arr[((n-1)/2)+1]*l+ql);
    	dp[0][1]=min(arr[((n-1)/2)]*l + arr[((n-1)/2)+1]*r,arr[((n-1)/2)]*r + arr[((n-1)/2)+1]*r+qr);

    	// cout<<dp[0][0]<<" "<<dp[0][1]<<endl;
    	for(int i=1;i<n/2;i++){
    		dp[i][0]=min(arr[((n-1)/2)-i]*l+arr[((n-1)/2)+i+1]*r+dp[i-1][0],arr[((n-1)/2)-i]*l+arr[((n-1)/2)+i+1]*r+dp[i-1][1]+qr);
    		dp[i][0]=min(dp[i][0],leftcost(arr, cum, ((n-1)/2)-i, ((n-1)/2)+i+1, l, r, ql, qr));

    		dp[i][1]=min(arr[((n-1)/2)-i]*l+arr[((n-1)/2)+i+1]*r+dp[i-1][1],arr[((n-1)/2)-i]*l+arr[((n-1)/2)+i+1]*r+dp[i-1][0]+ql);
    		// cout<<dp[i][1]<<endl;
    		dp[i][1]=min(dp[i][1],rightcost(arr, cum, ((n-1)/2)-i, ((n-1)/2)+i+1, l, r, ql, qr));
    	}
    	cout<<min(dp[((n-1))/2][0],dp[((n-1))/2][1])<<endl;
    }
    else{
    	ll dp[n][2];
    	//dp[i] represents the range from (n/2-i-1) to (n/2+i+1)
    	//dp[i][0] represents leftstart
    	dp[0][0]=min(arr[(n/2)-1]*l+arr[(n/2)+1]*r+arr[(n/2)]*l,arr[(n/2)-1]*l+arr[n/2]*l+ql+arr[(n/2)+1]*l+ql);
    	dp[0][1]=min(arr[(n/2)-1]*l+arr[(n/2)+1]*r+arr[(n/2)]*r,arr[(n/2)-1]*r+arr[n/2]*r+qr+arr[(n/2)+1]*r+qr);

    	// cout<<dp[0][0]<<" "<<dp[0][1]<<endl;

    	for(int i=1;i<n/2;i++){
    		dp[i][0]=min(arr[(n/2)-i-1]*l+arr[(n/2)+i+1]*r+dp[i-1][0],arr[(n/2)-i-1]*l+arr[(n/2)+i+1]*r+dp[i-1][1]+qr);
    		dp[i][0]=min(dp[i][0],leftcost(arr, cum, (n/2)-i-1, (n/2)+i+1, l, r, ql, qr));

    		dp[i][1]=min(arr[(n/2)-i-1]*l+arr[(n/2)+i+1]*r+dp[i-1][1],arr[(n/2)-i-1]*l+arr[(n/2)+i+1]*r+dp[i-1][0]+ql);
    		dp[i][1]=min(dp[i][1],rightcost(arr, cum, (n/2)-i-1, (n/2)+i+1, l, r, ql, qr));
    	}
    	cout<<min(dp[n/2-1][0],dp[n/2-1][1])<<endl;
    }
}
