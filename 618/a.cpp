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

    int n;
    cin>>n;

    vector<ll> arr;
    ll x;
    for(int i=0;i<n;i++){
    	cin>>x;
    	arr.push_back(x);
    }

    //largest unique bit should be first

    int count[32] = {0};
    int num[32] = {0};

    for(int i=0;i<n;i++){
    	ll x=arr[i];
    	for(int j=0;j<32;j++){
    		if(x%2==1){
    			count[j]++;
    			num[j]=arr[i];
    		}
    		x/=2;
    	}
    }

    int z;
    for(z=31;z>=0;z--){
    	if(count[z]==1){
    		break;
    	}
    }

    // cout<<z<<endl;

    vector<int> ans;
    if(z>=0){
	    ans.push_back(num[z]);
	    arr.erase(find(arr.begin(),arr.end(),num[z]));
    }
    bool used=false;
    for(int i=0;i<arr.size();i++){
    	ans.push_back(arr[i]);
    }

    // cerr<<"HI"<<endl;
    // sort(ans.begin(),ans.end());
    // reverse(ans.begin(),ans.end());

    for(int i=0;i<ans.size();i++){
    	cout<<ans[i]<<" ";
    }
    cout<<endl;



}
