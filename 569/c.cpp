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

   	ll n,q;
   	cin>>n>>q;

   	ll arr[n];
   	for(int i=0;i<n;i++){
   		cin>>arr[i];
   	}

   	ll maxof=arr[0];
   	for(int i=0;i<n;i++){
   		maxof=max(arr[i],maxof);
   	}

   	int firstmaxind=0;
   	for(int i=0;i<n;i++){
   		if(arr[i]==maxof){
   			firstmaxind=i;
   			break;
   		}
   	}
	deque<ll> myDQ;


   	for(int i=0;i<n;i++){
   		myDQ.push_back(arr[i]);
   	}

	ll sol[firstmaxind+1][2];

   	for(int i=0;i<firstmaxind;i++){
   		ll a,b;
   		a = myDQ.front();
   		myDQ.pop_front();
   		b = myDQ.front();
   		myDQ.pop_front();

   		// cout<<i<<""

   		sol[i][0]=a;
   		sol[i][1]=b;

   		if(a>b){
   			myDQ.push_front(a);
   			myDQ.push_back(b);
   		}
   		else{
   			myDQ.push_front(b);
   			myDQ.push_back(a);	   			
   		}
   	}

   	vector<ll> myVec;
   	myDQ.pop_front();
   	while(!myDQ.empty()){
   		myVec.push_back(myDQ.front());
   		myDQ.pop_front();
   	}


   	ll quer;
   	for(int i=0;i<q;i++){
   		cin>>quer;
   		if(quer<=firstmaxind){
   			cout<<sol[quer-1][0]<<" "<<sol[quer-1][1]<<endl;
   		}
   		else{
   			cout<<maxof<<" "<<myVec[(quer-firstmaxind-1)%myVec.size()]<<endl;
   		}
   	}
}