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

    int t;
    cin>>t;

    for(int test=0;test<t;test++){
    	int n;
    	cin>>n;

    	int arr[2*n];
    	for(int i=0;i<2*n;i++){
    		cin>>arr[i];
    	}

    	//on the left, make a left to right sum and max and min suffix
    	//on the right, make a right to left sum and max and min prefix

    	int leftsum[n+1];//represents the excess of 2s over ones including this
    	int count=0;
    	leftsum[0]=0;
    	for(int i=0;i<n;i++){
    		if(arr[i]==2)count++;
    		else count--;
    		leftsum[i+1]=count;
    	}

    	int rightsum[n+1];//excess of 2s over ones
    	rightsum[n]=0;
    	count=0;
    	for(int i=n-1;i>=0;i--){
    		if(arr[n+i]==2)count++;
    		else count--;
    		rightsum[i]=count;
    	}

    	int rightmax[n+1];
    	int rightmin[n+1];

    	rightmin[0]=rightmax[0]=rightsum[0];
    	for(int i=1;i<=n;i++){
    		rightmin[i]=min(rightmin[i-1],rightsum[i]);
    		rightmax[i]=max(rightmax[i-1],rightsum[i]);    		
    	}

    	int ans=2*n;

    	// for(int i=0;i<=n;i++){
    	// 	cout<<rightmax[i]<<" ";
    	// }
    	// cout<<endl;

    	int newrightmin[n+1];
    	for(int i=0;i<=n;i++){
    		newrightmin[i]=rightmin[n-i];
    	}


    	// for(int i=0;i<=n;i++){
    	// 	cout<<newrightmin[i]<<" ";
    	// }
    	// cout<<endl;



    	for(int i=0;i<=n;i++){
    		//eating i on the right side
    		int lookfor=-1*leftsum[n-i];

    		// cout<<i<<" "<<lookfor<<endl;

    		int rightans=0;
    		int mini;
    		if(rightsum[0]<=lookfor){
    			mini=lower_bound(rightmax,rightmax+n+1,lookfor)-rightmax;
    		}
    		else{
    			mini=n-(upper_bound(newrightmin,newrightmin+n+1,lookfor)-newrightmin-1);
    		}
    		// cout<<mini<<endl;

    		if(mini!=n+1 && mini!=-1){
    			ans=min(ans,i+mini);
    		}

    	}

    	cout<<ans<<endl;

   	}
}