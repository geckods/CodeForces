#include <bits/stdc++.h>
using namespace std;

int mylog2(int x){
	if(x==1)return 0;
	return 1+mylog2(x/2);
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
	    int n;
	    cin>>n;
	    int arr[32];
	    memset(arr,0,sizeof(arr));
	    int x;
	    for(int i=0;i<n;i++){
	    	cin>>x;
	    	arr[mylog2(x)]++;
	    }

	    for(int i=0;i<12;i++){
	    	arr[i+1]+=arr[i]/2;
	    }

	    if(arr[11]>0){
	    	cout<<"YES"<<endl;
	    }
	    else{
	    	cout<<"NO"<<endl;
	    }


	}

}
