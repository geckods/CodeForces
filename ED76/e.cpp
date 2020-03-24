#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef pair<int,int> intpair;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k1,k2,k3;

    cin>>k1>>k2>>k3;

    int n=k1+k2+k3;

    int arr[n];

    int x;

    for(int i=0;i<k1;i++){
    	cin>>x;
    	x--;
    	arr[x]=0;
    }

    for(int i=0;i<k2;i++){
    	cin>>x;
    	x--;
    	arr[x]=1;
    }

    for(int i=0;i<k3;i++){
    	cin>>x;
    	x--;
    	arr[x]=2;
    }

    int prefz[n];


    int curr=0;
    for(int i=0;i<n;i++){
    	if(arr[i]==0)curr++;
    	prefz[i]=curr;
    	// cout<<i<<" "<<prefz[i]<<endl;
    }

    int suffixtmo[n];

    curr=0;
    for(int i=n-1;i>=0;i--){
    	if(arr[i]==2){
    		curr++;
    	}
    	else if (arr[i]==1){
    		curr--;
    	}
    	suffixtmo[i]=curr;
    }

    int sufft[n];
    curr=0;
    for(int i=n-1;i>=0;i--){
    	if(arr[i]==2){
    		curr++;
    	}
    	sufft[i]=curr;
    }

    int suffo[n];
    curr=0;
    for(int i=n-1;i>=0;i--){
    	if(arr[i]==1){
    		curr++;
    	}
    	suffo[i]=curr;
    }



    int ans=k1+min(k2,k3);
    ans=min(ans,k2+min(k1,k3));
    ans=min(ans,k3+min(k2,k1));
    ans=min(ans,k1+k2);
    ans=min(ans,k3+k2);
    ans=min(ans,k3+k1);


    int bestsuf[n];
    int besttmo=INT_MIN;
    int bestind=0;

    for(int i=n-1;i>=0;i--){
    	if(suffixtmo[i]>besttmo){
    		besttmo=suffixtmo[i];
    		bestind=i;
    	}
    	bestsuf[i]=bestind;
    }

    //everything is ones and twos
    // int asdfans=k1;
    for(int i=0;i<n-1;i++){
    	ans=min(ans,k1+suffo[i+1]+k3-sufft[i]);
    }


    int minians;
    for(int i=0;i<n;i++){
    	minians=0;
    	//i is the last element in the first partition
    	// cout<<"I:"<<i<<endl;
    	minians+=(i+1)-prefz[i];//convert these to zero
    	// cout<<"ans:"<<minians<<endl;
    	minians+=(k1-prefz[i]);//convert these to non-zero
    	// cout<<k1-prefz[i]<<endl;
    	// cout<<"ans:"<<minians<<endl;
    	if(i<n-1){
    		int currsuf=bestsuf[i+1];

    		ans=min(ans,minians+sufft[i+1]);

    		if(suffixtmo[currsuf]<0){
    			ans=min(ans,minians+suffo[i+1]);
    		}
    		else{
	    		// cout<<currsuf<<endl;
	    		int numonesonright = suffo[currsuf];
	    		// cout<<numonesonright<<endl;
	    		minians+=numonesonright;
	    		int numtwosonleft = sufft[i+1]-sufft[currsuf];
	    		// cout<<sufft[i+1]<<" "<<numtwosonleft<<endl;
	    		minians+=numtwosonleft;
	    	}
    	}

    	ans=min(ans,minians);
    }
    cout<<ans<<endl;
}

    //to-do - nothing in first partition