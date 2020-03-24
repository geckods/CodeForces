#include <bits/stdc++.h>
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	int n;
   	cin>>n;
   	int a[n];
   	int b[n];

   	for(int i=0;i<n;i++){
   		cin>>a[i];
   	}

   	for(int i=0;i<n;i++){
   		cin>>b[i];
   	}

   	multiset<int> mySet;

   	for(int i=0;i<n;i++){
   		mySet.insert(b[i]);
   	}

   	for(int i=0;i<n;i++){
   		multiset<int>::iterator msi = mySet.lower_bound(n-a[i]);
   		if(msi == mySet.end()){
   			msi = mySet.lower_bound(0);
   		}
   		// cout<<i<<" "<<n<<" "<<(a[i]+*msi)%n<<endl;
   		 cout<<(a[i]+*msi)%n<<" ";
   		mySet.erase(msi);
   	}
   	cout<<endl;
}
