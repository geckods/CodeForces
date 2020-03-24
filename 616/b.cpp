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

    string s;
    cin>>s;

    int n=s.length();

    int q;
    cin>>q;

    int quer[q][2];
    for(int i=0;i<q;i++){
    	cin>>quer[i][0]>>quer[i][1];
    	quer[i][0]--;
    	quer[i][1]--;
    }

    // int rclose[n][26];//closest NOT i on right
    // for(int i=0;i<26;i++){
    // 	rclose[n-1][i]=n-1;
    // }
    // rclose[n-1][s[n-1]-'a']=INT_MAX;

    // for(int i=n-2;i>=0;i--){
    // 	for(int j=0;j<26;j++){
    // 		rclose[i][j]=i;
    // 	}
    // 	rclose[i][s[i]-'a']=rclose[i+1][s[i]-'a'];
    // }

    // int lclose[n][26];//closest NOT i on left
    // for(int i=0;i<26;i++){
    // 	lclose[0][i]=0;
    // }
    // lclose[0][s[0]-'a']=INT_MIN;

    // for(int i=1;i<n;i++){
    // 	for(int j=0;j<26;j++){
    // 		lclose[i][j]=i;
    // 	}
    // 	lclose[i][s[i]-'a']=lclose[i-1][s[i]-'a'];
    // }

    int cum[n][26];
    for(int i=0;i<n;i++){
    	for(int j=0;j<26;j++){
    		if(i==0){
    			cum[i][j]=0;
    		}
    		else{
    			cum[i][j]=cum[i-1][j];
    		}
    		cum[i][s[i]-'a']++;
    	}
    }

    for(int i=0;i<q;i++){
    	if(quer[i][0]==quer[i][1]){
    		cout<<"Yes"<<endl;
    		continue;
    	}

    	//if last (not same as first) exists and is preceeded by any (not same as last) -> Yes
    	int fc=s[quer[i][0]]-'a';
    	int lc=s[quer[i][1]]-'a';

    	if(fc!=lc){
    		cout<<"Yes"<<endl;
    	}
    	else{
    		int works=0;
    		for(int z=0;z<26;z++){
    			if(z==fc)continue;
    			if(cum[quer[i][1]][z]!=cum[quer[i][0]][z]){
    				works++;
    			}
    		}

    		if(works>1){
    			cout<<"Yes"<<endl;
    		}
    		else{
    			cout<<"No"<<endl;
    		}
    	}
    }
}