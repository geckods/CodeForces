#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;

typedef tree <
pair<int,int>,
null_type,
less<pair<int,int> >,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;

    int arr[m];
    for(int i=0;i<m;i++){
    	cin>>arr[i];
    	arr[i]--;
    }

    bool messaged[n];

    ordered_set mySet;
    map<int,int> friendtotime;

    int themin[n];
    int themax[n];


    for(int i=0;i<n;i++){
    	mySet.insert({i,i});
    	friendtotime[i]=i;
    	themin[i]=themax[i]=i;
    }



    for(int i=0;i<m;i++){
    	int curr=arr[i];
    	int lasttime=friendtotime[curr];
    	int temp=mySet.order_of_key({lasttime,curr});

    	themin[curr]=min(themin[curr],0);
    	if(temp > themax[curr]){
    		themax[curr]=temp;
    	}
    	// cout<<curr<<" "<<lasttime<<" "<<mySet.order_of_key({lasttime,curr})<<endl;

    	mySet.erase(mySet.find({lasttime,curr}));
    	friendtotime[curr]=-(i+1);

    	mySet.insert({-(i+1),curr});
    }

    for(int i=0;i<n;i++){
    	int lasttime=friendtotime[i];
    	int temp=mySet.order_of_key({lasttime,i});

    	if(temp > themax[i]){
    		themax[i]=temp;
    	}

    }

    for(int i=0;i<n;i++){
    	cout<<themin[i]+1<<" "<<themax[i]+1<<endl;
    }

}