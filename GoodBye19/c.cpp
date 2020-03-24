#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//=

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

    while(t--){

    	int n;
    	cin>>n;

    	ll arr[n];
    	ll sum=0;
    	ll xsum=0;

    	for(int i=0;i<n;i++){
    		cin>>arr[i];
    		sum+=arr[i];
    		xsum^=arr[i];
    	}


    	if(sum==xsum*2){
    		cout<<0<<endl<<endl;
    		continue;
    	}

    	vector<ll> ans;

    	if(sum%2!=0){
    		ans.push_back(1);
    		xsum^=1;
    		sum++;
    	}

    	if (sum<xsum*2){
    		//keep xsum the same, increase sum
    		ans.push_back((xsum*2-sum)/2);
    		ans.push_back((xsum*2-sum)/2);
    	}
    	else if (sum>xsum*2){
    		//do something
    		ans.push_back(xsum);
    		sum+=xsum;
    		xsum=0;
    		ans.push_back(sum);
    	}

    	cout<<ans.size()<<endl;
    	for(int i=0;i<ans.size();i++){
    		cout<<ans[i]<<" ";
    	}
    	cout<<endl;
    }
}