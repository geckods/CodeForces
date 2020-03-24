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


	int n,m;
	cin>>n>>m;

	int edgelist[m][4];

	vector<vector<pair<int,int> > > edgeVec;

	int mymin,mymax;
	bool minwasfirst;

	for(int i=0;i<m;i++){
		cin>>edgelist[i][0];
		cin>>edgelist[i][1];

		mymin = min(edgelist[i][0],edgelist[i][1]);
		mymax = max(edgelist[i][0],edgelist[i][1]);

		if(mymin==edgelist[i][0]){
			minwasfirst=true;
		}
		else{
			minwasfirst=false;
		}

		edgelist[i][0]=mymin;
		edgelist[i][1]=mymax;
		edgelist[i][2]=-1;
		if(minwasfirst){
			edgelist[i][3]=0;
		}
		else{
			edgelist[i][3]=1;
		}

		while(edgeVec.size()<max(edgelist[i][0],edgelist[i][1])){
			vector<pair<int,int> > newVec;
			edgeVec.push_back(newVec);
		}

		edgeVec[edgelist[i][0]].push_back(make_pair(edgelist[i][1],-1));
		edgeVec[edgelist[i][1]].push_back(make_pair(edgelist[i][0],-1));
	}

	queue<pair<int,int> > myQueue;

	myQueue.push(make_pair(1, 1));

	int nodeLabel[n+1];

	for(int i=0;i<=n;i++){
		nodeLabel[i]=-1;
	}

	nodeLabel[1]=1;//1 is outgoing, 0 is incoming, -1 is as of yet undefined

	int currNode,nextNode;
	int currDepth;
	while(myQueue.size()>0){
		currNode = myQueue.front().first;
		currDepth = myQueue.front().second;

		nodeLabel[currNode] = currDepth%2;

		myQueue.pop();
		for(int i=0;i<edgeVec[currNode].size();i++){
			nextNode=edgeVec[currNode][i].first;
			if(nodeLabel[nextNode]!=-1){
				continue;
			}
			else{
				edgeVec[currNode][i].second = nodeLabel[currNode];
			}
			myQueue.push(make_pair(nextNode,currDepth+1));
		}
	}

	cout<<"YES"<<endl;
	for(int i=0;i<m;i++){
//		cout<<i<<endl;
		for(int j=0;j<edgeVec[edgelist[i][0]].size();j++){
			if(edgeVec[edgelist[i][0]][j].first==edgelist[i][1]){
				cout<<(edgeVec[edgelist[i][0]][j].second^edgelist[i][3]);
				break;
			}
		}
	}

}