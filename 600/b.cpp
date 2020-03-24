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

   	bool in[1000000+1];

   	for(int i=1;i<=1000000;i++){
   		in[i]=false;
   	}

   	vector<int> ans;

   	int count=0;
   	bool works=true;

   	unordered_set<int> currday;


   	int temp;
   	for(int i=0;i<n;i++){
   		//process the ith guy, then if it is zero, then break
   		if(arr[i]>0){
   			if(currday.find(arr[i])!=currday.end()){
   				works=false;
   				break;
   			}
   			else{
   				currday.insert(arr[i]);
   				in[arr[i]]=true;
   				count++;
   			}
   		}
   		else{
   			temp=abs(arr[i]);
   			if(!in[temp]){
   				works=false;
   				break;
   			}
   			else{
   				in[temp]=false;
   				count--;
   			}
   		}

   		if(count==0){
   			currday.clear();
   			ans.push_back(i);
   		}
   	}

   	if(count!=0){
   		works=false;
   	}

   	if(works){
	   	cout<<ans.size()<<endl;
	   	for(int i=0;i<ans.size();i++){
	   		if(i==0){
	   			cout<<ans[i]+1<<" ";
	   		}
	   		else{
	   			cout<<ans[i]-ans[i-1]<<" ";
	   		}
	   	}
	   	cout<<endl;
	}
	else{
		cout<<-1<<endl;
	}
}