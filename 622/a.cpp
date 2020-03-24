#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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
    	int a,b,c;
    	cin>>a>>b>>c;

    	int ans=0;
    	if(a>0){
    		a--;
    		ans++;
    	}
    	if(b>0){
    		b--;
    		ans++;
    	}
    	if(c>0){
    		c--;
    		ans++;
    	}

    	int arr[3];
    	arr[0]=a;
    	arr[1]=b;
    	arr[2]=c;

    	sort(arr,arr+3);
    	a=arr[0];
    	b=arr[1];
    	c=arr[2];

    	if(b>0 && c>0){
    		b--;
    		c--;
    		ans++;
    	}
    	if(c>0 && a>0){
    		c--;
    		a--;
    		ans++;
    	}
    	if(a>0 && b>0){
    		a--;
    		b--;
    		ans++;
    	}
    	if(a>0 && b>0 && c>0){
    		c--;
    		a--;
    		b--;
    		ans++;
    	}
    	cout<<ans<<endl;

    }
}
