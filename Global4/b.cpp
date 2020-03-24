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

   	string s;
   	cin>>s;
   	ll n = s.length();

   	vector<ll> vlist;


   	ll i=0;
   	while(i<n && s[i]=='o')i++;

   	ll curr=0;
   	while(i<n){
   		if(i>0 && s[i]!=s[i-1] && curr>0){
   			vlist.push_back(curr);
   			curr=1;
   		}
   		else{
   			curr++;
   		}
   		i++;
   	}

   	if(s[n-1]=='v')
	   	vlist.push_back(curr);


	ll m=vlist.size();

   	ll rightcum[m];
   	memset(rightcum,0,sizeof(rightcum));

   	ll tot=0;
   	for(ll i=m-1;i>=0;i--){
   		if(i%2==0){
   			tot+=vlist[i]-1;
   		}
   		else{
   			rightcum[i]=tot;
   		}
   	}


   	// cout<<vlist.size()<<endl;
 //   	for(int i=0;i<m;i++){
 //   		cout<<i<<endl;
 //   		cout<<vlist[i]<<" "<<rightcum[i]<<endl;
 //   	}
	// cout<<"HI"<<endl;

   	ll ans=0;

   	ll leftcum=0;
   	for(ll i=0;i<m;i++){
   		if(i%2==0){
   			leftcum+=vlist[i]-1;
   		}
   		else{
   			ans+=leftcum*vlist[i]*rightcum[i];
   		}
   	}

   	cout<<ans<<endl;
}