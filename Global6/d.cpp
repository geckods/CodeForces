#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m;
    cin>>n>>m;

    ll debt[n];
    ll credit[n];

    for(int i=0;i<n;i++){
    	debt[i]=0;
    	credit[i]=0;
    }

    for(int i=0;i<m;i++){
    	ll u,v,d;
    	cin>>u>>v>>d;

    	u--;
    	v--;
    	debt[u]+=d;
    	credit[v]+=d;
    }

    // for(int i=0;i<n;i++){
    // 	cout<<debt[i]<<" "<<credit[i]<<endl;
    // }

   	ll mymin=0;
    for(int i=0;i<n;i++){
    	mymin=min(credit[i],debt[i]);
    	credit[i]-=mymin;
    	debt[i]-=mymin;
    }

    // for(int i=0;i<n;i++){
    // 	cout<<debt[i]<<" "<<credit[i]<<endl;
    // }



    int i=0,j=0;

    vector<pair<pair<int,int>,ll> >ansVec;

    while(i<n && j<n){
    	while(i<n && debt[i]==0)i++;
    	while(j<n && credit[j]==0)j++;
    	// cout<<i<<" "<<j<<endl;

    	if(i==n||j==n)break;

    	mymin=min(debt[i],credit[j]);
    	debt[i]-=mymin;
    	credit[j]-=mymin;
    	ansVec.push_back({{i+1,j+1},mymin});
    }

    cout<<ansVec.size()<<endl;
    for(int i=0;i<ansVec.size();i++){
    	cout<<ansVec[i].first.first<<" "<<ansVec[i].first.second<<" "<<ansVec[i].second<<endl;
    }
}
