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

   	ll t;
   	cin>>t;

   	for(int test=0;test<t;test++){
   		ll n,a,b;
   		cin>>n>>a>>b;

   		string s;
   		cin>>s;

   		ll ans=0;

   		vector<int> twoup;
   		vector<int> twodown;

   		for(int i=0;i<s.length();i++){
   			// cerr<<i<<endl;
   			if(s[i]=='1'){
   				ans+=2*b;
   				ans+=a;
   			}
   			else{
   				if(i>0 && s[i-1]=='1' && s[i+1]=='1'){
	   				ans+=2*b;
   					ans+=a;   					
   				}
   				else{
   					if(i>0 && s[i-1]=='1'){
		   				ans+=2*b;
   						ans+=2*a;
   						twodown.push_back(i);
   					}
   					else if (i<s.length() && s[i+1]=='1'){
		   				ans+=b;
   						ans+=2*a;
   						twoup.push_back(i);
   					}
   					else{
   						ans+=b;
   						ans+=a;
   					}
   				}
   			}
   			// cout<<i<<" "<<ans<<endl;
   		}
   		ans+=b;
   		// cerr<<ans<<endl;

   		// cerr<<ans<<" "<<twodown.size()<<endl;
   		if(twodown.size()==0){
   			cout<<ans<<endl;
   			continue;
   		}

   		for(int i=0;i<twodown.size()-1;i++){
   			// cerr<<test<<endl;
	   		ll currcost = 4*a+(twoup[i+1]-twodown[i])*(a+b)-a;
	   		ll newcost = (twoup[i+1]-twodown[i]+1)*(a+2*b)-2*b;
	   		// cout<<twodown[i]<<" "<<twoup[i+1]<<" "<<currcost<<" "<<newcost<<endl;
	   		if(currcost>newcost){
	   			ans-=currcost;
	   			ans+=newcost;
	   		}
   		}
   		cout<<ans<<endl;
   	}

}