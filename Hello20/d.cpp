#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef pair<ll,ll> intpair;

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;

    vector<pair<intpair,intpair> > myVec;

    ll a,b,c,d;
    for(int i=0;i<n;i++){
    	cin>>a>>b>>c>>d;
    	myVec.push_back({{a,b},{c,d}});
    }
    sort(myVec.begin(),myVec.end());
    
    int i=0;

    multiset<intpair> firstends;

    multiset<ll> starts;
    multiset<ll> ends;

    while(i<n || firstends.size()>0){
    	if(i==n || (firstends.size()>0 && firstends.begin()->first<myVec[i].first.first)){
    		//do stuff
    		int j = firstends.begin()->second;
    		starts.erase(starts.find(myVec[j].second.first));
    		ends.erase(ends.find(myVec[j].second.second));
    		firstends.erase(firstends.begin());
    		j++;
    	}
    	else{
    		//max of this start, all open starts must be <= min of this end, all open ends
    		//all open starts = largest open start
    		//all open ends = lowest open end

    		starts.insert(myVec[i].second.first);
			ends.insert(myVec[i].second.second);
    		if(*starts.rbegin()<=*ends.begin()){
    			firstends.insert({myVec[i].first.second,i});
	    		i++;
    		}
    		else{
    			cout<<"NO"<<endl;
    			return 0;
    		}
    	}
    }

    starts.clear();
    ends.clear();
    firstends.clear();
    i=0;

    vector<pair<intpair,intpair> > newmyVec;
    for(int i=0;i<n;i++){
    	newmyVec.push_back({myVec[i].second,myVec[i].first});
    }
    sort(newmyVec.begin(),newmyVec.end());

    while(i<n || firstends.size()>0){
    	if(i==n || (firstends.size()>0 && firstends.begin()->first<newmyVec[i].first.first)){
    		//do stuff
    		int j = firstends.begin()->second;
    		starts.erase(starts.find(newmyVec[j].second.first));
    		ends.erase(ends.find(newmyVec[j].second.second));
    		firstends.erase(firstends.begin());

    		j++;
    	}
    	else{
    		//max of this start, all open starts must be <= min of this end, all open ends
    		//all open starts = largest open start
    		//all open ends = lowest open end

    		starts.insert(newmyVec[i].second.first);
			ends.insert(newmyVec[i].second.second);
    		if(*starts.rbegin()<=*ends.begin()){
    			firstends.insert({newmyVec[i].first.second,i});
	    		i++;
    		}
    		else{
    			cout<<"NO"<<endl;
    			return 0;
    		}
    	}
    }


    cout<<"YES"<<endl;
}