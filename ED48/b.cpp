#include <bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif

    int n,m,q;
    cin>>n>>m>>q;

    string s;
    string t;

    cin>>s;
    cin>>t;

    int ocurarr[n];
    for(int i=0;i<n;i++){
    	ocurarr[i]=0;
    }

    for(int i=0;i<=n-m;i++){
    	if(s.substr(i,m).compare(t)==0){
    		ocurarr[i]=1;
    	}
    }

//    for(int i=0;i<n;i++){
//    	cout<<ocurarr[i]<<endl;
//    }

    int cumarr[n];

    int temp=0;
    for(int i=0;i<n;i++){
    	temp+=ocurarr[i];
    	cumarr[i]=temp;
    }

//    for(int i=0;i<n;i++){
//    	cout<<cumarr[i]<<endl;
//    }

    int l,r;
    for(int i=0;i<q;i++){
    	cin>>l>>r;
    	l--;
    	r--;

    	if(r-m+1<l){
    		cout<<0<<endl;
    		continue;
    	}

	    if(l==0){
	    	cout<<cumarr[r-m+1]<<endl;
	    }
	    else{
	    	cout<<cumarr[r-m+1]-cumarr[l-1]<<endl;
	    }
    }
}