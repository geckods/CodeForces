#include <bits/stdc++.h>
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	int n,m;
   	cin>>n>>m;

   	vector<string> myVec;

   	for(int i=0;i<n;i++){
   		string s;
   		cin>>s;
   		myVec.push_back(s);
   	}

   	bool islegit[n][m];
   	for(int i=0;i<n;i++){
   		for(int j=0;j<m;j++){
   			islegit[i][j]=true;
   		}
   	}

   	for(int i=0;i<n;i++){
   		map<char,int> myMap;
   		for(int j=0;j<m;j++){
   			myMap[myVec[i][j]]++;
   		}
   		for(int j=0;j<m;j++){
   			if(myMap[myVec[i][j]]>1){
   				islegit[i][j]=false;
   			}
   		}
   	}

   	for(int j=0;j<m;j++){
   		map<char,int> myMap;
   		for(int i=0;i<n;i++){
   			myMap[myVec[i][j]]++;
   		}
   		for(int i=0;i<n;i++){
   			if(myMap[myVec[i][j]]>1){
   				islegit[i][j]=false;
   			}
   		}
   	}

   	string ans;
   	for(int i=0;i<n;i++){
   		for(int j=0;j<m;j++){
   			if(islegit[i][j])ans+=myVec[i][j];
   		}
   	}
   	cout<<ans<<endl;



}
