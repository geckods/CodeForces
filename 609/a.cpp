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

    ll n,k;
    cin>>n>>k;

    string s;
    cin>>s;
    //store first and highest

    char first[k];
    char highest[k];
    char lowest[k];
    for(int i=0;i<k;i++){
    	first[i]=highest[i]=0;
    	lowest[i]=CHAR_MAX;
    }

    int j;
    for(int i=0;i<n;i++){
    	j=i%k;
    	if(i<k)first[i]=s[i];
    	highest[j]=max(highest[j],s[i]);
    	lowest[j]=min(lowest[j],s[i]);
    }

    bool corr=true;
    for(int i=0;i<k;i++){
    	if(highest[i]!=lowest[i]){
    		corr=false;
    		break;
    	}
    }

    if(corr){
    	cout<<n<<endl<<s<<endl;
    	return 0;
    }

    //till here->something must increase in first k

    char assign[k];
    int theans=k;
    for(int i=k-1;i>=0;i--){
    	if(first[i]!='9'){
    		theans=i;
    		break;
    	}
    }

    for(int i=0;i<k;i++){
    	if(i<theans){
    		assign[i]=first[i];
    	}
    	else if (i==theans){
    		// assign[i]=first[i]+1;
    		assign[i]=highest[i];
    	}
    	else{
    		assign[i]=first[i];
    	}
    }

    bool lowered=false;
    for(int i=k;i<n;i++){
    	if(s[i]>assign[i%k]){
    		lowered=true;
    		break;
    	}
    	if(s[i]<assign[i%k]){
    		break;
    	}
    }

    if(lowered){
    	assign[theans]=first[theans]+1;
    	for(int i=theans+1;i<k;i++){
    		assign[i]='0';
    	}
    }

    cout<<n<<endl;
    for(int i=0;i<n;i++){
    	cout<<assign[i%k];

    }
    cout<<endl;

    //the last one for which highest > first

}
