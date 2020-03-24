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

    // cout<<__gcd(8,0)<<endl;

    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }

    map<int,int> myMap;    
    multiset<int> occSet;

    int ans=0;

    for(int i=0;i<n;i++){
    	myMap[arr[i]]++;
    	if(myMap[arr[i]]==1){
    		occSet.insert(1);
    	}
    	else{
    		occSet.erase(occSet.find(myMap[arr[i]]-1));
    		occSet.insert(myMap[arr[i]]);
    	}

    	// for(auto a = occSet.begin();a!=occSet.end();a++){
    	// 	cout<<*a<<" ";
    	// }
    	// cout<<endl;


    	if(occSet.size()==1){
    		ans=max(ans,i+1);
    		continue;
    	}
    	else

    	if(*occSet.begin() == 1){
    		if(*next(occSet.begin())==*prev(occSet.end())){
    			ans=max(ans,i+1);
    		}
    	}
    	
    	if(*occSet.begin() == *prev(prev(occSet.end())) && *prev(prev(occSet.end())) == *prev(occSet.end())-1){
    		ans=max(ans,i+1);
    	}

    }
    cout<<ans<<endl;
}
