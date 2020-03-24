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
        string s;
        cin>>s;
        set<int> adj[26];

        for(int i=0;i<s.length()-1;i++){
            adj[s[i]-'a'].insert(s[i+1]-'a');
            adj[s[i+1]-'a'].insert(s[i]-'a');
        }

        bool works=true;
        int hasone=-1;

        int maxadj=0;
        for(int i=0;i<26;i++){
            maxadj=max(maxadj,(int)adj[i].size());
            if(adj[i].size()==1)hasone=i;
            if(adj[i].size()>2){
                works=false;
                break;
            }
        }

        if(hasone==-1 && maxadj>0)works=false;

        bool printed[26];
        memset(printed,false,sizeof(printed));

        if(!works){
            cout<<"NO"<<endl;
            continue;
        }
        else{
            cout<<"YES"<<endl;
        }

        int i=hasone;
        int j=-1;

        while(i!=-1){
            // cerr<<i<<" "<<j<<endl;
            cout<<(char)(i+'a');
            // cout<<"HI"<<endl;
            printed[i]=true;

            if(adj[i].find(j)!=adj[i].end()){
                adj[i].erase(adj[i].find(j));
            }

            j=i;
            if(adj[i].size()==0)break;
            i=(*adj[i].begin());
        }

        for(int i=0;i<26;i++){
            if(!printed[i]){
                cout<<(char)(i+'a');
            }
        }
        cout<<endl;

    }
}