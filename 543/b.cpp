#include <bits/stdc++.h>
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif

    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }

    sort(arr,arr+n);

  //  int min=100000,mintwo=100000,max=0,maxtwo=0;
  	int min=arr[0];
  	int mintwo=arr[1];
  	int max=arr[n-1];
  	int maxtwo=arr[n-2];

    int ans=0;
    int minians;

    set<int> mySet;
    for(int i=0;i<n;i++){
    	mySet.insert(arr[i]);
    }


    for(int i=min+mintwo;i<=max+maxtwo;i++){
    	minians=0;
//    	cout<<i<<"------"<<endl;
    	for(int j=0;j<n;j++){
    		if(arr[j]>i/2) break;
    		if(mySet.find(i-arr[j])!=mySet.end()){
    			if(i%2==0 && arr[j]==i/2)continue;
    			minians++;
  //  			cout<<arr[j]<<" ";
    		}
    	}
    //	cout<<endl;
    	if(minians>ans) ans=minians;
    }

    cout<<ans<<endl;
}
