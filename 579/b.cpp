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
   		int n;
   		cin>>n;

   		// int arr[4*n];
   		map<int,int> myMap;
   		int x;
   		vector<int> myVec;
   		for(int i=0;i<n*4;i++){
   			cin>>x;
   			myMap[x]++;
   		}

   		bool done=false;
   		for(auto i = myMap.begin();i!=myMap.end();i++){
   			// cerr<<i->first<<" "<<i->second<<endl;
   			if(i->second%2==1){
   				// cerr<<"HI"<<endl;
   				cout<<"NO"<<endl;
   				done=true;
   				break;
   			}
   			else{
   				for(int j=0;j<(i->second)/2;j++){
   					myVec.push_back(i->first);
   				}
   			}
   		}

   		if(done)continue;

   		sort(myVec.begin(),myVec.end());

   		// for(int i=0;i<myVec.size();i++){
   		// 	cout<<myVec[i]<<" ";
   		// }
   		// cout<<endl;

   		int prod=myVec[0]*myVec[myVec.size()-1];

   		for(int i=0;i<myVec.size()/2;i++){
   			if(myVec[i]*myVec[myVec.size()-i-1]!=prod){
   				cout<<"NO"<<endl;
   				done=true;
   				break;
   			}
   		}

   		if(done)continue;
   		cout<<"YES"<<endl;


   	}
}