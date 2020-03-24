#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// bool works(int n, vector<pair<ll,ll> > myVec, int entry){
// 	if(n==0){
// 		if(entry==0)
// 			return false;
// 		else
// 			return true;
// 	}

// 	int curr=myVec.size()-n;

// 	if(entry==0){
// 		if(myVec[curr].first==1||myVec[curr].first==2){
// 			return works(n-1,myVec,0);
// 		}
// 		else{
// 			if(myVec[curr].second==1||myVec[curr].second==2){
// 				return false;
// 			}
// 			else{
// 				return works(n-1,myVec,1);				
// 			}
// 		}
// 	}
// 	else{
// 		if(myVec[curr].second==1||myVec[curr].second==2){
// 			return works(n-1,myVec,1);
// 		}
// 		else{
// 			if(myVec[curr].first==1||myVec[curr].first==2){
// 				return false;
// 			}
// 			else{
// 				return works(n-1,myVec,0);				
// 			}
// 		}		
// 	}
// }

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	ll q;
   	cin>>q;

   	for(int test=0;test<q;test++){
   		ll n;
   		cin>>n;

   		string top;
   		cin>>top;
   		string bottom;
   		cin>>bottom;

   		vector<pair<ll,ll> > arr;
   		for(int i=0;i<n;i++){
   			arr.push_back(make_pair(top[i]-'0',bottom[i]-'0'));
   		}

   		int entry=0;
   		bool works=true;
   		for(int i=0;i<n;i++){
			if(entry==0){
				if(arr[i].first==1||arr[i].first==2){
					entry=0;
				}
				else{
					if(arr[i].second==1||arr[i].second==2){
						works=false;
						break;
					}
					else{
						entry=1;
					}
				}
			}
			else{
				if(arr[i].second==1||arr[i].second==2){
					entry=1;
				}
				else{
					if(arr[i].first==1||arr[i].first==2){
						works=false;
						break;
					}
					else{
						entry=0;
					}
				}		
			}
   		}

   		if(entry==0)works=false;

   		if(works){
   			cout<<"YES"<<endl;
   		}
   		else{
   			cout<<"NO"<<endl;
   		}
   	}
}