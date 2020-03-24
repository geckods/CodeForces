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
    	ll n;
    	cin>>n;

    	vector<ll> ans;
    	for(int i=1;i*i<=n;i++){
    		ans.push_back(n/i);
    	}

    	int size=ans.size();
    	for(int i=0;i<size;i++){
    		int temp=n/ans[i];
    		if(temp!=ans[i])
	    		ans.push_back(temp);
    	}

    	ans.push_back(0);

    	sort(ans.begin(),ans.end());
    	cout<<ans.size()<<endl;
    	for(int i=0;i<ans.size();i++){
    		cout<<ans[i]<<" ";
    	}
    	cout<<endl;

    }
}