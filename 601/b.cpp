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

    int t;
    cin>>t;

    for(int test=0;test<t;test++){
    	ll n,m;
    	cin>>n>>m;

    	
    	ll sum=0;
    	vector<pair<ll,ll> > arr;
    	ll x;
    	for(int i=0;i<n;i++){
    		cin>>x;
    		arr.push_back(make_pair(x,i));
    		sum+=arr[i].first;
    	}

    	sort(arr.begin(),arr.end());

    	ll ans=0;
    	// cout<<n<<" "<<m<<endl;
    	if(n<3 || (m < n)){
    		cout<<-1<<endl;
    	}
    	else{
    		ans=sum*2;
    		ans+=(m-n)*(arr[0].first+arr[1].first);
    		cout<<ans<<endl;
    		for(int i=0;i<n-1;i++){
    			cout<<i+1<<" "<<i+2<<endl;
    		}
    		cout<<n<<" "<<1<<endl;
    		for(int i=n;i<m;i++){
    			cout<<arr[0].second+1<<" "<<arr[1].second+1<<endl;
    		}
    	}
    }
}