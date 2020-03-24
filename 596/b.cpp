#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


#define MAXN 100001 
  
// stores smallest prime factor for every number 
ll spf[MAXN]; 
  
// Calculating SPF (Smallest Prime Factor) for every 
// number till MAXN. 
// Time Complexity : O(nloglogn) 
void sieve() 
{ 
    spf[1] = 1; 
    for (ll i=2; i<MAXN; i++) 
  
        // marking smallest prime factor for every 
        // number to be itself. 
        spf[i] = i; 
  
    // separately marking spf for every even 
    // number as 2 
    for (ll i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
  
    for (ll i=3; i*i<MAXN; i++) 
    { 
        // checking if i is prime 
        if (spf[i] == i) 
        { 
            // marking SPF for all numbers divisible by i 
            for (ll j=i*i; j<MAXN; j+=i) 
  
                // marking spf[j] if it is not  
                // previously marked 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 
  
// A O(log n) function returning primefactorization 
// by dividing by smallest prime factor at every step 
vector<ll> getFactorization(ll x) 
{ 
    vector<ll> ret; 
    while (x != 1) 
    { 
        ret.push_back(spf[x]); 
        x = x / spf[x]; 
    } 
    return ret; 
}

vector<pair<ll,ll> > rle(vector<ll> myVec){
	sort(myVec.begin(),myVec.end());

	vector<pair<ll,ll> > mainVec;
	ll i=0,j=0;
	while(i<myVec.size()){
		while(j<myVec.size() && myVec[j]==myVec[i])j++;
		mainVec.push_back(make_pair(myVec[i],j-i));
		i=j;
	}
	return mainVec;
}

ll primes[MAXN];

vector<ll> possprod(map<ll,ll> myMap, ll k, ll max, ll currind, ll currval){

	// cerr<<currind<<" "<<currval<<endl;
	// for(int i=0;i<myVec.size();i++){

	// }

	if(myMap.size()==0)return vector<ll>();

	ll leftoverthis=(k-myMap[primes[currind]]%k)%k;
	// cerr<<leftoverthis<<endl;
	currval*=pow(primes[currind],leftoverthis);
	vector<ll> ans;
	if(currval>max){
		return vector<ll>();
	}
	if(pow(primes[currind],k) > max){
		vector<ll> tempVec;
		tempVec.push_back(currval);
		return tempVec;
	}
	else{
		while(currval<=max){
			vector<ll> tempVec = possprod(myMap, k, max, currind+1, currval);
			ans.insert(ans.end(), tempVec.begin(),tempVec.end());
			currval*=pow(primes[currind],k);
			myMap[currind]+=k;
		}
		return ans;
	}
}


int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	ll n,k;
   	cin>>n>>k;

   	map<ll,ll> myMap;
   	vector<ll> kpows;

   	sieve();

   	int c=0;
   	for(int i=2;i<MAXN;i++){
   		if(spf[i]==i)primes[c++]=i;
   	}

   	ll arr[n];
   	ll maxof=0;
   	for(int i=0;i<n;i++){
   		cin>>arr[i];
   		myMap[arr[i]]++;
   		maxof=max(maxof,arr[i]);
   	}


   	ll i=1;
   	ll z;
   	while((z=pow(i,k))<=maxof*maxof){
   		kpows.push_back(z);
   		i++;
   	}

   	ll ans=(myMap[1]*(myMap[1]-1));
   	ll theby;
   	// set<ll> exclude;
   	for(int i=0;i<n;i++){

   		vector<pair<ll,ll> > myVec = rle(getFactorization(arr[i]));
   		// for(int i=0;i<myVec.size();i++){
   		// 	cerr<<myVec[i].first<<" "<<myVec[i].second<<endl;
   		// 	// cerr<<myVec[i]<<" ";
   		// 	cerr<<endl;
   		// }
   		map<ll,ll> facMap;
   		for(int z=0;z<myVec.size();z++){
   			facMap[myVec[z].first]=myVec[z].second;
   		}

   		vector<ll> tempVec = possprod(facMap,k,maxof,0,1);

   		// for(int i=0;i<)

   		// cerr<<arr[i]<<endl;
   		for(int j=0;j<tempVec.size();j++){
   			// cerr<<"POSS:";
   			// cerr<<tempVec[i]<<" ";
   			// cerr<<arr[i]<<" "<<tempVec[j]<<" "<<myMap[tempVec[j]]<<endl;
   			ans+=myMap[tempVec[j]];
   			if(tempVec[j]==1){
	   			ans+=myMap[tempVec[j]];
   			}
   			if(tempVec[j]==arr[i])ans--;
   			// cerr<<ans<<endl;
   		}
   		// cerr<<endl;

   		// cerr<<"HI"<<endl;
   		// if(exclude.find(arr[i])!=exclude.end())continue;
   		// cerr<<"HI2"<<endl;

   		// ll lb = lower_bound(kpows.begin(),kpows.end(),arr[i])-kpows.begin();
   		// ll up = upper_bound(kpows.begin(),kpows.end(),arr[i]*maxof)-kpows.begin();
   		// // cerr<<lb<<" "<<up<<endl;
   		// for(int j=lb;j<up;j++){
   		// 	// cerr<<kpows[j]<<" "<<arr[i]<<endl;
   		// 	if(kpows[j]%arr[i]==0){
   		// 		theby=kpows[j]/arr[i];
   		// 		ans+=myMap[theby];
   		// 		// cerr<<arr[i]<<" "<<theby<<" "<<myMap[theby]<<endl;
   		// 		if(theby==arr[i])ans--;
   		// 	}
   		// }
   		// exclude.insert(arr[i]);
   	}

   	cout<<ans/2<<endl;
}