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

    int n;
    cin>>n;
    int arr[n];

    int max=0;
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    	if(arr[i]>max)max=arr[i];
    }

    int count[max];
    for(int i=0;i<=max;i++){
    	count[i]=0;
    }

    for(int i=0;i<n;i++){
    	count[arr[i]]++;
    }

    int maxcount=0;
    int maxind=-1;

    for(int i=0;i<=max;i++){
    	if(count[i]>maxcount){
    		maxcount = count[i];
    		maxind=i;
    	}
    }

    int k = n-maxcount;
    cout<<k<<endl;

    int i=0;
    while(arr[i]!=maxind)i++;
    while(i>0){
    	if(arr[i-1]>arr[i]){
    		cout<<2<<" "<<i<<" "<<i+1<<endl;
    	}
    	else{
    		cout<<1<<" "<<i<<" "<<i+1<<endl;    		
    	}
    	arr[i-1]=arr[i];
    	i--;
    }
    while(arr[i]!=maxind)i++;
    while(i<n-1){
    	if(arr[i+1]==arr[i]){
    		i++;
    		continue;
    	}
    	else if(arr[i+1]>arr[i]){
    		cout<<2<<" "<<i+2<<" "<<i+1<<endl;
    	}
    	else{
    		cout<<1<<" "<<i+2<<" "<<i+1<<endl;    		
    	}
    	arr[i+1]=arr[i];
    	i++;
    }
}
