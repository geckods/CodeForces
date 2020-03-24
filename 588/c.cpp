#include <bits/stdc++.h>
using namespace std;

set<pair<int,int> > globalSet;

int checkPerm(vector<int> currPerm,vector<pair<int,int> > edgelist){
	set<pair<int,int> > currSet=globalSet;
	int a,b;
	pair<int,int> currPair;
	for(int i=0;i<edgelist.size();i++){
		
		a=currPerm[edgelist[i].first];
		b=currPerm[edgelist[i].second];
		currPair.first=min(a,b);
		currPair.second=max(a,b);

		if(currSet.find(currPair)!=currSet.end())
			currSet.erase(currSet.find(currPair));

	}
	return 21-currSet.size();
}

int generatePerm(int n, vector<int> currPerm, vector<pair<int,int> > edgelist){
	if(n==0){
		return checkPerm(currPerm,edgelist);
	}
	else{
		int ans=0;
		for(int i=1;i<=6;i++){
			currPerm.push_back(i);
			ans=max(ans,generatePerm(n-1,currPerm,edgelist));
			currPerm.pop_back();
		}
		return ans;
	}
}


int main(){
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	for(int i=1;i<7;i++){
   		for(int j=1;j<7;j++){
   			globalSet.insert(make_pair(min(i,j), max(i,j)));
   		}
   	}

   	int n,m;
   	cin>>n>>m;

	vector<pair<int,int> > edgelist;
	int a,b;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		a--;
		b--;
		edgelist.push_back(make_pair(a,b));
	}

	cout<<generatePerm(n,vector<int>(), edgelist)<<endl;
}
