#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<pair<ll,ll>, pair<ll,ll> >myPoint;

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	vector<myPoint> myVec;

   	ll n;
   	cin>>n;
   	ll x,y,z;
   	for(int i=0;i<n;i++){
   		cin>>x>>y>>z;
   		myVec.push_back(make_pair(make_pair(x,y),make_pair(z,i)));
   	}

   	sort(myVec.begin(),myVec.end());

   	ll i=0;
   	ll j=0;
   	ll maxx,maxy,maxz;
   	ll minx,miny,minz;
   	ll thex,they,thez;
   	i=0;
   	j=1;
   	while(myVec.size()>0){
   		minx=min(myVec[i].first.first,myVec[j].first.first);
   		miny=min(myVec[i].first.second,myVec[j].first.second);
   		minz=min(myVec[i].second.first,myVec[j].second.first);
   		maxx=max(myVec[i].first.first,myVec[j].first.first);
   		maxy=max(myVec[i].first.second,myVec[j].first.second);
   		maxz=max(myVec[i].second.first,myVec[j].second.first);

   		for(int k=2;k<myVec.size();k++){
	   		thex=myVec[k].first.first;
	   		they=myVec[k].first.second;
	   		thez=myVec[k].second.first;

	   		if(thex>maxx || (thex==maxx && they>maxy) || (thex==maxx&&they==maxy&&thez>maxz))break;
	   		if(thex>=minx && thex<=maxx && they>=miny && they<=maxy && thez>=minz && thez<=maxz){
	   			j=k;
		   		minx=min(myVec[i].first.first,myVec[j].first.first);
		   		miny=min(myVec[i].first.second,myVec[j].first.second);
		   		minz=min(myVec[i].second.first,myVec[j].second.first);
		   		maxx=max(myVec[i].first.first,myVec[j].first.first);
		   		maxy=max(myVec[i].first.second,myVec[j].first.second);
		   		maxz=max(myVec[i].second.first,myVec[j].second.first);
	   		}
	   	}
		cout<<myVec[i].second.second+1<<" "<<myVec[j].second.second+1<<endl;
   		myVec.erase(myVec.begin()+i);
   		myVec.erase(myVec.begin()+j-1);
   		i=(j-2)%myVec.size();
   		if(i<0) i+=2;
   		j=(j-1)%myVec.size();
   	}
}