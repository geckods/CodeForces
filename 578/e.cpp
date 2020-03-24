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

   	vector<string> myVec;
   	for(int i=0;i<n;i++){
   		string s;
   		cin>>s;
   		myVec.push_back(s);
   	}

   	string ans;

   	ans+=myVec[0];

   	for(int i=1;i<n;i++){
   		int bmin=0;
   		int bmax=min(myVec[i].length(),ans.length());

   		// int prevmid=-1;
   		// int bmid=0;
   		while(bmax>0){
   			// prevmid=bmid;
   			int bmid=bmax;
   			bool works=true;
   			for(int z=0;z<bmid;z++){
   				if(myVec[i][z]!=ans[ans.length()-z-1]){
   					works=false;
   					break;
   				}
   			}

   			if(works)break;

   			// if(works){
   				// bmin=bmid;
   			// }
   			// else{
   				// bmax=bmid-1;
   			// }
   			bmax--;
   		}

   		bmax++;

   		for(int z=0;z<bmax;z++){
   			if(myVec[i][z]!=ans[ans.length()-z-1]){
   				bmax--;
   				break;
   			}
   		}


   		for(int j=bmax;j<myVec[i].size();j++){
   			ans+=myVec[i][j];
   		}
   	}
   	cout<<ans<<endl;
}