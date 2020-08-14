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

    string s;
    cin>>s;

    string t;
    cin>>t;

    ll soc=0;
    ll toc=0;

    for(int i=0;i<n;i++){
    	soc+=(s[i]=='1');
    	toc+=(t[i]=='1');
    }

    if(soc!=toc){
    	cout<<-1<<endl;
    	return 0;
    }

    // vector<ll> oz;
    // vector<ll> zo;

    vector<ll> temp;

    for(int i=0;i<n;i++){
    	if(s[i]=='1' && t[i]=='0'){
    		// oz.push_back(i);
    		temp.push_back(1);
    	}

    	if(s[i]=='0' && t[i]=='1'){
    		// zo.push_back(i);
    		temp.push_back(2);
    	}
    }

    ll ans=0;

    if(temp.size()==0){
    	cout<<0<<endl;
    	return 0;
    }

    ll i=0;
	while(i<temp.size() && temp[i]==2)i++;
    ll j=i;

    while(i<temp.size()){
    	while(i<temp.size() && temp[i]==2)i++;
    	if(i==temp.size())break;
    	// cerr<<i<<" "<<j<<endl;
    	while(temp[j]==1){
    		j++;
    		if(j==temp.size())j=0;
    	}
    	// cerr<<i<<" "<<j<<" "<<temp.size()<<endl;

    	if(i<j){
    		ans=max(ans,j-i);
    	}
    	else{
    		ans=max(ans,(ll)temp.size()-i+j);
    	}

    	i++;j++;
    }


    // ll curr=1;
    // for(int i=1;i<temp.size();i++){
    // 	if(temp[i]==temp[i-1]){
    // 		curr++;
    // 	}
    // 	else{
    // 		curr=1;
    // 	}
    // 	ans=max(ans,curr);
    // }

    // if(temp[0]==temp[temp.size()-1]){
    // 	ll i=1;
    // 	ll j=temp.size()-2;

    // 	while(temp[i]==temp[i-1])i++;
    // 	while(temp[j]==temp[j+1])j--;
    // 	ans=max(ans,i+(ll)temp.size()-j-1ll);
    // }

    cout<<ans<<endl;

}