#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void swap(int arr[], int a, int b){
	int c = arr[a];
	arr[a]=arr[b];
	arr[b]=c;
}

void solve(int arr[], int a, int n){
	if(a>=n-1)return;

	int minelem=INT_MAX;
	int minind=0;

	// cerr<<a<<" "<<n<<endl;

	for(int i=a;i<n;i++){
		if(arr[i]<minelem){
			minelem=arr[i];
			minind=i;
		}
	}

	for(int i=minind;i>a;i--){
		swap(arr,i,i-1);
	}

	if(minind==a)minind++;
	solve(arr,minind,n);

}


int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin>>q;

    for(int quer=0;quer<q;quer++){
    	int n;
    	cin>>n;

    	int arr[n];
    	for(int i=0;i<n;i++){
    		cin>>arr[i];
    		arr[i]--;
    	}

    	// cerr<<"HI"<<endl;
    	solve(arr, 0, n);

    	for(int i=0;i<n;i++){
    		cout<<arr[i]+1<<" ";
    	}
    	cout<<endl;

    }
}