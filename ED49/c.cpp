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
    	int n;
    	cin>>n;
    	int arr[n];
    	for(int i=0;i<n;i++){
    		cin>>arr[i];
    	}

    	map<int,int> myMap;

    	for(int i=0;i<n;i++){
    		myMap[arr[i]]++;
    	}

    	vector<int> myVec;

    	for(int i=0;i<n;i++){
    		if(myMap[arr[i]]>=2){
    			myMap[arr[i]]-=2;
    			myVec.push_back(arr[i]);
    		}
    	}

    	sort(myVec.begin(),myVec.end());

    	double minval = DBL_MAX;
    	int ans1,ans2;
    	for(int i=0;i<myVec.size()-1;i++){
    		int curr=myVec[i];
//    		cout<<"HI"<<endl;
    		int next=myVec[i+1];
    		if((double)curr/next + (double)next/curr < minval){
    			minval = (double)curr/next + (double)next/curr;
    			ans1=curr;
    			ans2=next;
    		}
    	}

    	cout<<ans1<<" "<<ans1<<" "<<ans2<<" "<<ans2<<endl;

    }
}