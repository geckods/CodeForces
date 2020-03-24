#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef pair<ll,ll> intpair;
typedef pair<ll,intpair> triple;


int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<triple> myVec;
    vector<ll> ans;

    bool seen[n];
    int count[n];

    for(int i=0;i<n;i++){
    	seen[i]=false;
    	count[i]=0;
    }

    map<intpair,ll> seenWith;

    for(int i=0;i<n;i++){
    	triple asd;
    	cin>>asd.first>>asd.second.first>>asd.second.second;
    	asd.first--;
    	asd.second.first--;
    	asd.second.second--;
    	myVec.push_back(asd);

    	count[asd.first]++;
    	count[asd.second.first]++;
    	count[asd.second.second]++;

    	seenWith[{asd.first,asd.second.first}]++;
    	seenWith[{asd.first,asd.second.second}]++;
    	seenWith[{asd.second.first,asd.first}]++;
    	seenWith[{asd.second.first,asd.second.second}]++;
    	seenWith[{asd.second.second,asd.second.first}]++;
    	seenWith[{asd.second.second,asd.first}]++;
    }

    int i=0;
    while(count[i]>1)i++;

    int curr=i;
    ans.push_back(curr);

    auto asd = seenWith.lower_bound({curr,INT_MIN});
    if(count[(asd->first).second]!=2)asd++;

    seen[curr]=true;
    curr = (asd->first).second;
    seen[curr]=true;

    ans.push_back(curr);

    for(int i=0;i<n-4;i++){
	    auto asd = seenWith.lower_bound({curr,INT_MIN});
	    while(asd->second != 2 || seen[(asd->first).second])asd++;
	    curr = (asd->first).second;
	    seen[curr]=true;
	    ans.push_back(curr);
    }

    for(int i=0;i<n;i++){
    	if((!seen[i]) && count[i]==2){
    		ans.push_back(i);
    		break;
    	}
    }

    for(int i=0;i<n;i++){
    	if((!seen[i]) && count[i]==1){
    		ans.push_back(i);
    		break;
    	}
    }

    for(int i=0;i<ans.size();i++){
    	cout<<ans[i]+1<<" ";
    }
    cout<<endl;
}