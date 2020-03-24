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
   	for(int i=0;i<n;i++){
   		cin>>arr[i];
   	}

   	int counts[6] = {0};

   	for(int i=0;i<n;i++){
   		switch(arr[i]){
   		case(4):
   			counts[0]++;
   			break;
   		case(8):
   			if(counts[0]>0){
				counts[0]--;
				counts[1]++;
			}
			break;
		case(15):
			if(counts[1]>0){
				counts[1]--;
				counts[2]++;
			}
			break;
		case(16):
			if(counts[2]>0){
				counts[2]--;
				counts[3]++;
			}
			break;
		case(23):
			if(counts[3]>0){
				counts[3]--;
				counts[4]++;
			}
			break;
		case(42):
			if(counts[4]>0){
				counts[4]--;
				counts[5]++;
			}
			break;
   		}
   	}

   	cout<<n-6*counts[5]<<endl;
}