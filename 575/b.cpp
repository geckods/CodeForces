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

   	int q;
   	cin>>q;

   	for(int quer=0;quer<q;quer++){
 		int n,k;
   		cin>>n>>k;
   		int arr[n];
   		int x;
   		int oddcount=0;
   		for(int i=0;i<n;i++){
   			cin>>x;
   			arr[i]=x%2;
   			if(arr[i]==1)
	   			oddcount++;
   		}

   		// cout<<oddcount<<endl;

   		if(oddcount<k || (oddcount%2 != k%2)){
   			cout<<"NO"<<endl;
   			continue;
   		}
   		else{
   			cout<<"YES"<<endl;
   			int toprintcount=k;
   			for(int i=0;i<n;i++){
   				if(arr[i]==1 && toprintcount>1){
   					cout<<i+1<<" ";
   					toprintcount--;
   				}
   			}

   			cout<<n<<endl;
   		}



   	}
}