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

    ll n,m;
    cin>>n>>m;

    ll type[m];
    ll left[m];
    ll right[m];


    for(int i=0;i<m;i++){
    	cin>>type[i]>>left[i]>>right[i];
    	left[i]--;
    	right[i]--;
    }

    int marked[n];
    memset(marked,0,sizeof(marked));

    for(int i=0;i<m;i++){
    	if(type[i]==1){
    		for(int j=left[i]+1;j<=right[i];j++){
    			marked[j]=1;//the ith element must be greater than or equal to the i-1th
    		}
    	}
    }

    int arr[n];
    for(int i=0;i<n;i++){
    	arr[i]=1000000;
    }

    // for(int i=0;i<n;i++){
    // 	cout<<marked[i]<<" ";
    // }
    // cout<<endl;


    int tobeless[n];
    memset(tobeless,0,sizeof(tobeless));

    for(int i=0;i<m;i++){
    	if(type[i]==0){
    		bool done=false;
    		for(int j=left[i]+1;j<=right[i];j++){
    			if(marked[j]!=1){
    				tobeless[j]=1;
    				done=true;
    				break;
    			}
    		}

    		if(!done){
    			cout<<"NO"<<endl;
    			return 0;
    		}
    	}
    }

    for(int i=0;i<n;i++){
    	if(tobeless[i]){
    		arr[i]=arr[i-1]-1;
    	}
    }

    cout<<"YES"<<endl;
    for(int i=0;i<n;i++){
    	cout<<arr[i]<<" ";
    }
    cout<<endl;
}