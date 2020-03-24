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

   	int initarr[n][m];
   	int finalarr[n][m];

   	for(int i=0;i<n;i++){
   		for(int j=0;j<m;j++){
   			cin>>initarr[i][j];
   		}
   	}

//   	cout<<n<<" "<<m<<endl;


   	for(int i=0;i<n;i++){
   		for(int j=0;j<m;j++){
   			cin>>finalarr[i][j];
   		}
   	}
/*
   	for(int i=0;i<n;i++){
   		for(int j=0;j<m;j++){
   			cout<<finalarr[i][j]<<" ";
   		}
   		cout<<endl;
   	}
*/

   	int j;
   	for(int sum=0;sum<n+m-1;sum++){
   		vector<int> resultveca;
//   		set<int> result;
   		vector<int> resultvecb;
//   		set<int> firstset;
//   		set<int> secondset;

   		for(int i=0;i<=sum;i++){
   			j=sum-i;
   			if(i<0||j<0||i>=n||j>=m) continue;
   			resultveca.push_back(initarr[i][j]);
   			resultvecb.push_back(finalarr[i][j]);
   		}


//   		vector<int>::iterator ra,rb;

   		sort(resultveca.begin(),resultveca.end());
   		sort(resultvecb.begin(),resultvecb.end());

//   		cout<<"HI"<<endl;
//   		fflush(stdout);

//   		cout<<secondset.size()<<endl;

//   		set_symmetric_difference(firstset.begin(),firstset.end(),secondset.begin(),secondset.end(),resultveca.begin(),inserter(result,result.end()));
//   		rb=set_difference(secondset.begin(),secondset.end(),firstset.begin(),firstset.end(),resultvecb.begin());

//   		cout<<"HI"<<endl;
//   		fflush(stdout);


   		if(resultveca.size()!=resultvecb.size()){
   			cout<<"NO"<<endl;
   			return 0;
   		}

   		for(int k=0;k<resultveca.size();k++){
   			if(resultveca[k]!=resultvecb[k]){
   				cout<<"NO"<<endl;
   				return 0;
   			}
   		}

   	}

   	cout<<"YES"<<endl;
}