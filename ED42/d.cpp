#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> intpair;

bool compare(intpair a, intpair b){
	return a.second<b.second;
}

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;

    ll x;
    vector<ll> arr;

    priority_queue<intpair,vector<intpair>, greater<intpair> > myPQ;

    for(int i=0;i<n;i++){
    	cin>>x;
    	myPQ.push(make_pair(x,(ll)i));
    }

    vector<intpair> ans;

    while(!myPQ.empty()){
    	if(myPQ.size()==1){
    		ans.push_back(myPQ.top());
    		myPQ.pop();
    	}
    	else{
    		intpair a,b;
    		a = myPQ.top();
    		myPQ.pop();
    		b = myPQ.top();
    		myPQ.pop();

    		if(a.first==b.first){
    			myPQ.push(make_pair(b.first*2, b.second));
    		}
    		else{
    			ans.push_back(a);
    			myPQ.push(b);
    		}
    	}
    }

    sort(ans.begin(),ans.end(),compare);

    // reverse(ans.begin(), ans.end());

    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
    	cout<<ans[i].first<<" ";
    }
    cout<<endl;
}
