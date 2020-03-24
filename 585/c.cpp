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

    int n;
    cin>>n;

    string s,t;
    cin>>s>>t;

    int acount=0,bcount=0;
    for(int i=0;i<n;i++){
    	acount+=(s[i]=='a');
    	acount+=(t[i]=='a');    	
    	bcount+=(s[i]=='b');
    	bcount+=(t[i]=='b');
    }

    if(acount%2!=0){
    	cout<<-1<<endl;
    	return 0;
    }

    vector<int> bas;
    vector<int> abs;

    for(int i=0;i<n;i++){
    	if(s[i]=='b' && t[i]=='a'){
    		bas.push_back(i);
    	}
    	else if (s[i]=='a'&&t[i]=='b'){
    		abs.push_back(i);
    	}
    }

    vector<pair<int,int> > sol;
    while(bas.size()>1){
    	int sz=bas.size();
    	sol.push_back({bas[sz-1],bas[sz-2]});
    	bas.pop_back();
    	bas.pop_back();    	
    }

    while(abs.size()>1){
    	int sz=abs.size();
    	sol.push_back({abs[sz-1],abs[sz-2]});
    	abs.pop_back();
    	abs.pop_back();    	
    }

    if(bas.size()==1){
    	sol.push_back({bas[0],bas[0]});
    	sol.push_back({bas[0],abs[0]});
    }

    cout<<sol.size()<<endl;
    for(int i=0;i<sol.size();i++){
    	cout<<sol[i].first+1<<" "<<sol[i].second+1<<endl;
    }

}