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

  	ll n;
  	cin>>n;

  	ll a[n][3];
  	for(int i=0;i<n;i++){
  		cin>>a[i][0];
  	}

  	for(int i=0;i<n;i++){
  		cin>>a[i][1];
  	}

  	for(int i=0;i<n;i++){
  		cin>>a[i][2];
  	}

  	ll arr[n][2];
  	for(int i=0;i<n;i++){
  		arr[i][0]=arr[i][1]=-1;
  	}

  	ll u,v;
  	for(int i=0;i<n-1;i++){
  		cin>>u>>v;
  		u--;
  		v--;

  		if(arr[u][0]==-1){
  			arr[u][0]=v;
  		}
  		else if (arr[u][1]==-1){
  			arr[u][1]=v;
  		}
  		else{
  			cout<<-1<<endl;
  			return 0;
  		}

  		if(arr[v][0]==-1){
  			arr[v][0]=u;
  		}
  		else if (arr[v][1]==-1){
  			arr[v][1]=u;
  		}
  		else{
  			cout<<-1<<endl;
  			return 0;
  		}
  	}

  	int first=-1;
  	for(int i=0;i<n;i++){
  		if(arr[i][1]==-1){
  			first=i;
  			break;
  		}
  	}

  	ll next[n];
  	next[first]=arr[first][0];
  	ll prev=first;
  	ll curr=next[first];
  	for(int i=1;i<n;i++){
  		if(arr[curr][0]==prev){
  			next[curr]=arr[curr][1];
  		}
  		else{
  			next[curr]=arr[curr][0];  			
  		}
  		prev=curr;
  		curr=next[curr];
  	}

  	ll ans=LLONG_MAX;

  	// cout<<first<<endl;
  	ll color[n];
  	ll minicolor[n];

  	for(int i=0;i<3;i++){
  		for(int j=0;j<3;j++){
  			if(i==j)continue;
  			ll minians=0;
  			ll prev1,prev2;
  			prev1=i;
  			prev2=j;
  			minians+=a[first][i];
  			minians+=a[next[first]][j];
  			ll curr=next[next[first]];
  			ll newone;

  			minicolor[first]=i;
  			minicolor[next[first]]=j;

  			for(int z=2;z<n;z++){
  				newone=3-(prev1+prev2);
  				minians+=a[curr][newone];
  				// cout<<z<<" "<<newone<<endl;
  				prev1=prev2;
  				prev2=newone;
  				minicolor[curr]=newone;
  				curr=next[curr];
  			}

  			// cout<<i<<" "<<j<<" "<<minians<<endl;

  			if(minians<ans){
  				ans=minians;
  				for(int z=0;z<n;z++){
  					color[z]=minicolor[z];
  				}
  			}

  			// ans=min(ans,minians);
  		}
  	}
  	cout<<ans<<endl;
  	for(int i=0;i<n;i++){
  		cout<<color[i]+1<<" ";
  	}
  	cout<<endl;
}