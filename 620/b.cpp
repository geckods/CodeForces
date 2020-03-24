#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isPalin(string s){
	int i=0;
	int j=s.length()-1;
	while(i<j){
		if(s[i]!=s[j])return false;
		i++;
		j--;
	}
	return true;
}

bool arePalin(string a, string b){
	int i=0;
	int j=b.length()-1;
	while(i<a.length()){
		if(a[i]!=b[j])return false;
		i++;
		j--;
	}
	return true;
}


int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;

    vector<string> arr;
    string s;
    for(int i=0;i<n;i++){
    	cin>>s;
    	arr.push_back(s);
    }

    string selfPal;
    bool hasSelfPal=false;

    vector<pair<string,string>> palVec;

    bool seen[n];
    memset(seen,false,sizeof(seen));

    for(int i=0;i<n;i++){

    	if(seen[i])continue;
    	bool thisdone=false;
    	for(int j=i+1;j<n;j++){
    		if(arePalin(arr[i], arr[j])){
    			thisdone=true;
    			palVec.push_back({arr[i],arr[j]});
    			seen[i]=true;
    			seen[j]=true;
    		}
    	}
		if(!thisdone && !hasSelfPal){
			if(isPalin(arr[i])){
				seen[i]=true;
				selfPal=arr[i];
				hasSelfPal=true;
			}
		}
    	// cerr<<i<<endl;
    }

    string ans="";
    for(int i=0;i<palVec.size();i++){
    	ans.append(palVec[i].first);
    }
    if(hasSelfPal){
    	ans.append(selfPal);
    }
    for(int i=palVec.size()-1;i>=0;i--){
    	ans.append(palVec[i].second);
    }

    cout<<ans.size()<<endl;
    cout<<ans<<endl;

}