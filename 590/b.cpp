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

   	ll n,k;
   	cin>>n>>k;

   	ll arr[n];
   	for(int i=0;i<n;i++){
   		cin>>arr[i];
   	}

   	queue<ll> myQ;
   	set<ll> mySet;

   	for(int i=0;i<n;i++){
   		ll curr=arr[i];
   		if(mySet.find(curr)==mySet.end()){

   			if(myQ.size()==k){
   				ll old = myQ.front();
   				myQ.pop();
   				mySet.erase(mySet.find(old));
   			}

   			mySet.insert(curr);
   			myQ.push(curr);
   		}
   	}

   	cout<<myQ.size()<<endl;
   	stack<ll> myStack;
   	while(!myQ.empty()){
   		myStack.push(myQ.front());
   		myQ.pop();
   	}

   	while(!myStack.empty()){
   		cout<<myStack.top()<<" ";
   		myStack.pop();
   	}
}