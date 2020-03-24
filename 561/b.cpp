#include <bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin>>k;

    int n=-1;
    int m=-1;

    for(int i=5;i*i<=k;i++){
    	if(k%i==0){
    		if(k/i>=5){
    			n=i;
    			m=k/i;
    			break;
    		}
    	}
    }

    if(n==-1){
    	cout<<-1<<endl;
    	return 0;
    }

    int offset=0;

    char vowels[] = {'a','e','i','o','u'};
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		cout<<vowels[j+offset];
    	}
    	offset++;
    }
    cout<<endl;
}