#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


bool better(ll a, ll b){
	if(a&(a^b))return true;
	return false;
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

   	vector<ll> a;
   	ll x;
   	for(int i=0;i<n;i++){
   		cin>>x;
   		a.push_back(x);
   	}

   	vector<ll> b;
   	for(int i=0;i<n;i++){
   		cin>>x;
   		b.push_back(x);
   	}

   	vector<int>myVec(n);
   	for(int i=0;i<n;i++){
   		myVec[i]=0;
   	}

   	for(int i=0;i<n;i++){
   		// myVec.push_back(unordered_set<int>());

   		for(int j=0;j<n;j++){
   			if(i==j)continue;
   			if(a[i]&(a[i]^a[j])){
   				myVec[i]++;
   			}
   		}
   	}

   	int peoplecount=n;
   	bool in[n];
   	for(int i=0;i<n;i++){
   		in[i]=true;
   	}

   	int thebad=-1;
   	while(1){
   		thebad=-1;
   		for(int i=0;i<n;i++){
   			if(in[i] && myVec[i]==peoplecount-1){
   				thebad=i;
   				break;
   			}
   		}

   		if(thebad==-1){
   			break;
   		}

   		in[thebad]=false;
   		peoplecount--;
   		for(int i=0;i<n;i++){
   			if(in[i]){
   				if(a[i]&(a[i]^a[thebad]))myVec[i]--;
   				// if(myVec[i].find(thebad)!=myVec[i].end()){
   				// 	myVec[i].erase(myVec[i].find(thebad));
   				// }
   			}
   		}
   	}

   	ll ans=0;
   	for(int i=0;i<n;i++){
   		if(in[i])ans+=b[i];
   	}
   	cout<<ans<<endl;
}