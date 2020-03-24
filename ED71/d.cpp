#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> intpair;
#define MOD 998244353 

ll fact[300001];

void factorial(){
	fact[0]=1;
	fact[1]=1;
	for(int i=2;i<300001;i++){
		fact[i]=i*fact[i-1];
		fact[i]%=MOD;
	}
}

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	int n;
   	cin>>n;

   	vector<intpair> vec1;
   	vector<intpair> vec2;

   	ll x,y;
   	factorial();

   	for(int i=0;i<n;i++){
   		cin>>x>>y;
   		vec1.push_back(make_pair(x,y));
   		vec2.push_back(make_pair(y,x));
   	}

   	sort(vec1.begin(),vec1.end());
   	sort(vec2.begin(),vec2.end());

   	bool same=true;
   	for(int i=0;i<n;i++){
   		if(vec1[i].first!=vec2[i].second || vec1[i].second!=vec2[i].first){
   			same=false;
   		}
   	}
   	// cout<<same<<endl;

   	ll vec1ans=1;
   	ll z=1;
   	for(int i=1;i<n;i++){
   		if(vec1[i].first==vec1[i-1].first){
   			z++;
   		}
   		else{
   			vec1ans*=fact[z];
   			vec1ans%=MOD;
   			z=1;
   		}
   	}

   	vec1ans*=fact[z];
   	vec1ans%=MOD;

	// if(n==1){
 //   		cout<<1<<endl;
 //   		return 0;
 //   	}


   	ll vec2ans=1;
   	z=1;
   	ll jjans=1;
   	ll jj = 1;
   	for(int i=1;i<n;i++){
   		if(vec2[i].first==vec2[i-1].first){
   			z++;
   			if(vec2[i].second==vec2[i-1].second){
   				jj++;
   			}
   			else{
   				jjans*=fact[jj];
   				jjans%=MOD;
   				jj=1;
   			}
   		}
   		else{
   			vec2ans*=fact[z];
   			vec2ans%=MOD;
   			z=1;
   			jjans*=fact[jj];
   			jjans%=MOD;
   			jj=1;
   		}
   	}

   	vec2ans*=fact[z];
   	vec2ans%=MOD;

   	jjans*=fact[jj];
   	jjans%=MOD;

   	ll ans;
   	ans=fact[n];
   	ans-=(vec1ans+vec2ans)%MOD;
   	ans%=MOD;
   	if(same)
	   	ans+=jjans;
   	ans%=MOD;
   	if(ans<0)ans+=MOD;
   	cout<<ans<<endl;
}