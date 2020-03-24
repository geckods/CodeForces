#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// #define d 256

bool search(vector<ll> pat, vector<ll> txt, ll q, ll d)  
{  
    ll M = pat.size();  
    ll N = txt.size();
    ll i, j;  
    ll p = 0; // hash value for pattern  
    ll t = 0; // hash value for txt  
    ll h = 1;  
  
    // The value of h would be "pow(d, M-1)%q"  
    for (i = 0; i < M - 1; i++)  
        h = (h * d) % q;  
  
    // Calculate the hash value of pattern and first  
    // window of text  
    for (i = 0; i < M; i++)  
    {  
        p = (d * p + pat[i]) % q;  
        t = (d * t + txt[i]) % q;  
    }  
  
    // Slide the pattern over text one by one  
    for (i = 0; i <= N - M; i++)  
    {  
  
        // Check the hash values of current window of text  
        // and pattern. If the hash values match then only  
        // check for characters on by one  
        if ( p == t )  
        {  
            /* Check for characters one by one */
            for (j = 0; j < M; j++)  
            {  
                if (txt[i+j] != pat[j])  
                    break;  
            }  
  
            // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]  
            if (j == M)
            	return true;  
                // cout<<"Pattern found at index "<< i<<endl;  
        }  
  
        // Calculate hash value for next window of text: Remove  
        // leading digit, add trailing digit  
        if ( i < N-M )  
        {  
            t = (d*(t - txt[i]*h) + txt[i+M])%q;  
  
            // We might get negative value of t, converting it  
            // to positive  
            if (t < 0)  
            t = (t + q);  
        }  
    } 
    return false;
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

   	ll m;
   	cin>>m;

   	ll arr[n];
   	memset(arr,0,sizeof(arr));

   	ll x,y;
   	for(ll i=0;i<m;i++){
   		cin>>x>>y;
   		x--;
   		y--;
   		arr[x]++;
   		arr[y]++;
   	}

   	vector<ll> seq;
   	vector<ll> newseq;

   	for(ll i=1;i<n;i++){
   		seq.push_back(arr[i]);
   	}

   	for(ll i=0;i<n;i++){
   		newseq.push_back(arr[i]);
   		if(i<n-1)
	   		seq.push_back(arr[i]);
   	}

   	// for(ll i=0;i<n;i++){
   	// 	cout<<i+1<<" "<<newseq[i]<<endl;
   	// }

   	// for(ll i=0;i<seq.size();i++){
   	// 	cout<<seq[i]<<" ";
   	// }

   	// vector<ll> a;
   	// a.push_back(1);
   	// a.push_back(2);
   	// a.push_back(3);

   	// vector<ll> b;
   	// b.push_back(2);

   	if(search(newseq,seq,(1e9)-7,2*m)){
   		cout<<"Yes"<<endl;
   	}
   	else{
   		cout<<"No"<<endl;
   	}
}