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

    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }

    stack<int> dist;

    for(int i=1;i<n-1;i++){
    	if(arr[i-1]==1 && arr[i]==0 && arr[i+1]==1){
    		dist.push(i);
    	}
    }

    int ans=0;
    while(!dist.empty()){
    	if(dist.size()==1){
    		ans++;
    		dist.pop();
    	}
    	else{
    		int top1=dist.top();
    		dist.pop();
    		int top2=dist.top();
    		ans++;
    		if(abs(top1-top2)==2){
    			dist.pop();
    		}
    	}
    }

    cout<<ans<<endl;
}