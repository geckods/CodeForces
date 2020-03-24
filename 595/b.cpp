#include <bits/stdc++.h>
using namespace std;

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

	    int arr[n];
	    for(int i=0;i<n;i++){
	    	cin>>arr[i];
	    	arr[i]--;
	    }

	    int ans[n];
	    for(int i=0;i<n;i++){
	    	ans[i]=0;
	    }

	    for(int i=0;i<n;i++){
	    	if(ans[i]!=0)continue;

	    	int j=1;
	    	int curr=arr[i];
	    	vector<int> temp;
	    	temp.push_back(curr);
	    	while(curr!=i){
	    		curr=arr[curr];
	    		temp.push_back(curr);
	    		j++;
	    	}

	    	for(int z=0;z<temp.size();z++){
	    		ans[temp[z]]=j;
	    	}
	    }

	    for(int i=0;i<n;i++){
	    	cout<<ans[i]<<" ";
	    }
	    cout<<endl;

    }
}
