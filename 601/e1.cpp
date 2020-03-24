#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> primeFactors(int n)  
{  
	vector<ll> ans;
    
    if(n%2==0)
	    ans.push_back(2);
    
    while (n % 2 == 0)  
    {  
        n = n/2;  
    }  
  
    for (int i = 3; i <= sqrt(n); i = i + 2)  
    {  

    	if(n%i==0){
    		ans.push_back(i);
    	}

        while (n % i == 0)  
        {  
            n = n/i;  
        }  
    }  
  
    if (n > 2)  
    	ans.push_back(n);

    return ans;
}  


int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;

    vector<ll> vec;
    ll x;

    ll choccount=0;

    for(int i=0;i<n;i++){
    	cin>>x;
    	if(x==1){
    		vec.push_back(i);
    		choccount++;
    	}
    }

    vector<ll> primeFac = primeFactors(choccount);

    ll ans=LLONG_MAX;

    if(choccount==1){
    	cout<<-1<<endl;
    	return 0;
    }

    for(int i=0;i<primeFac.size();i++){
    	ll minians=0; 
    	for(int j=0;j<choccount/primeFac[i];j++){
    		ll miniminians=LLONG_MAX;

    		// ll sum=0;
    		// for(int k=0;k<primeFac[i];k++){
    		// 	//chocolates are vec[j*primeFac[i]+k]
    		// 	sum+=vec[j*primeFac[i]+k];
    		// }
    		// sum/=primeFac[i];

    		ll ans1=0;
    		// ll ans2=0;
    		// ll ans3=0;
    		// ll ans4=0;
    		// ll ans5=0;

    		// ll theind1 = lower_bound(vec.begin(),vec.end(), sum)-1-vec.begin();
    		// ll theind2 = theind1+1;
    		// ll theind3 = lower_bound(vec.begin(),vec.end(), sum+1)-vec.begin();

    		for(int k=0;k<primeFac[i];k++){
    			ans1+=abs(vec[j*primeFac[i]+k]-vec[j*primeFac[i]+primeFac[i]/2]);
    			// if(theind1>=0 && theind1<vec.size())ans1+=abs(vec[j*primeFac[i]+k] - vec[theind1]);
    			// if(theind2>=0 && theind2<vec.size())ans2+=abs(vec[j*primeFac[i]+k] - vec[theind2]);
    			// if(theind3>=0 && theind3<vec.size())ans3+=abs(vec[j*primeFac[i]+k] - vec[theind3]);

    			// if(sum>=0 && sum < n)
	    		// 	ans4+=abs(vec[j*primeFac[i]+k] - sum);
	    		// if(sum+1>=0 && sum+1 < n)
	    		// 	ans5+=abs(vec[j*primeFac[i]+k] - (sum+1));

    		}

    		if(ans1>0)miniminians=min(miniminians,ans1);
    		// if(ans2>0)miniminians=min(miniminians,ans2);
    		// if(ans3>0)miniminians=min(miniminians,ans3);
    		// if(ans4>0)miniminians=min(miniminians,ans4);
    		// if(ans5>0)miniminians=min(miniminians,ans5);

	    	minians+=miniminians;
    	}

    	ans=min(ans,minians);
    }
    cout<<ans<<endl;


}
