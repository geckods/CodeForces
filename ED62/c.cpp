#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void pairsort(ll a[], ll b[], int n) //sorts by a
{ 
    pair<ll, ll> pairt[n]; 
  
    // Storing the respective array 
    // elements in pairs. 
    for (int i = 0; i < n; i++)  
    { 
        pairt[i].first = a[i]; 
        pairt[i].second = b[i]; 
    } 
  
    // Sorting the pair array. 
    sort(pairt, pairt + n); 
      
    // Modifying original arrays 
    for (int i = 0; i < n; i++)  
    { 
        a[i] = pairt[i].first; 
        b[i] = pairt[i].second; 
    } 
} 

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin>>n>>k;

    ll l[n];
    ll b[n];
    for(int i=0;i<n;i++){
    	cin>>l[i]>>b[i];
    }

    pairsort(b,l,n);

    ll ans[n];
    ans[n-1]=b[n-1]*l[n-1];

    priority_queue<ll,vector<ll>,greater<ll> > pq;

    pq.push(l[n-1]);

    ll newans;
    ll currb=b[n-1];
    ll currsum=l[n-1];

    for(int i=n-2;i>=0;i--){

        if(pq.size()<k){
            pq.push(l[i]);
            currsum+=l[i];
        }
        else{
            if(l[i]>pq.top()){
                currsum-=pq.top();
                pq.pop();
                pq.push(l[i]);
                currsum+=l[i];
            }
        }

    	newans=(currsum*b[i]);
    	if(newans>=ans[i+1]){
	    	ans[i]=newans;
	    	currb=b[i];
	    }
	    else{
	    	ans[i]=ans[i+1];
	    }
    }

    // for(int i=0;i<n;i++){
    //     cout<<ans[i]<<" ";
    // }
    
    cout<<ans[0]<<endl;
}