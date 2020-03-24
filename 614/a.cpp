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

    int n,q;
    cin>>n>>q;

    int arr[n][2];

    for(int i=0;i<n;i++){
    	arr[i][0]=arr[i][1]=0;
    }

    int blockcount=0;

    for(int i=0;i<q;i++){
    	int r,c;
    	cin>>r>>c;
    	r--;c--;

    	if(arr[c][r]){
    		arr[c][r]=0;
    		if(c>0 && arr[c-1][1-r])blockcount--;
    		if(arr[c][1-r])blockcount--;
    		if(c<n-1 && arr[c+1][1-r])blockcount--;
    	}
    	else{
    		arr[c][r]=1;
    		if(c>0 && arr[c-1][1-r])blockcount++;
    		if(arr[c][1-r])blockcount++;
    		if(c<n-1 && arr[c+1][1-r])blockcount++;
    	}
    	if(blockcount>0){
    		cout<<"NO"<<endl;
    	}
    	else{
    		cout<<"YES"<<endl;
    	}

    }


}
