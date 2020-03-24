#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<ll,ll> primeFactors(ll n)  
{  
    map<ll,ll> ansmap;
    while (n % 2 == 0)  
    {  
        ansmap[2]++;
        n = n/2;  
    }  
  
    for (ll i = 3; i <= sqrt(n); i = i + 2)  
    {  
        while (n % i == 0)  
        {  
            ansmap[i]++;
            n = n/i;  
        }  
    }  
  
    if (n > 2){
        ansmap[n]++;
    }  
    return ansmap;
}  

ll gcd(ll a, ll b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 

unsigned int countSetBits(int n) 
{ 
    unsigned int count = 0; 
    while (n) { 
        n &= (n - 1); 
        count++; 
    } 
    return count; 
} 


int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        ll a,m;
        cin>>a>>m;

        map<ll,ll>amap = primeFactors(a);
        map<ll,ll>mmap = primeFactors(m);

        set<ll> forbidden;
        // for(auto i = amap.begin();i!=amap.end();i++){
        //     if(i->second != mmap[i->first])
        //         forbidden.insert(i->first);
        // }

        for(auto i = mmap.begin();i!=mmap.end();i++){
            if(i->second > amap[i->first])
                forbidden.insert(i->first);
        }

        ll ans=0;

        ll thegcd = gcd(a,m);

        ll ts=a/thegcd;
        ll tf=(a+m-1)/thegcd;

        vector<ll> fvec;

        // cout<<thegcd<<endl;

        for(auto i=forbidden.begin();i!=forbidden.end();i++){
            fvec.push_back(*i);
            // cout<<*i<<endl;
        }

        for(int i=0;i<pow(2,fvec.size());i++){
            ll it=1;
            for(int j=0;j<fvec.size();j++){
                if(i&(1<<j)){
                    it*=fvec[j];
                }
            }

            ll inrange=0;

            //number of multiples <= tf
            inrange=tf/it-((ts-1)/it);
            // cout<<it<<" "<<inrange<<endl;
            if(countSetBits(i)%2==0){
                ans+=inrange;
            }
            else{
                ans-=inrange;
            }
        }
        cout<<ans<<endl;
    }
}