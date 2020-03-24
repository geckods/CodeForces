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

    int t;
    cin>>t;

    for(int test=0;test<t;test++){
    	int n;
    	cin>>n;

    	string s,t;
    	cin>>s>>t;

    	//go from left to right, either change t to s or change s to t
    	map<char,int> count;
    	for(int i=0;i<n;i++){
    		count[s[i]]++;
    		count[t[i]]++;
    	}

    	bool works=true;
    	for(char c = 'a';c<='z';c++){
    		if(count[c]%2!=0){
    			works=false;
    			break;
    		}
    	}

    	if(!works){
    		cout<<"No"<<endl;
    		continue;
    	}

    	cout<<"Yes"<<endl;

    	bool done=false;
    	char temp;

    	vector<pair<int,int>> ansVec;

    	for(int i=0;i<n-1;i++){
    		if(s[i]==t[i])continue;
    		done=false;
    		for(int j=i+1;j<n;j++){
    			if(s[j]==s[i]){
    				done=true;
    				ansVec.push_back(make_pair(j+1,i+1));
    				s[j]=t[i];
    				t[i]=s[i];
    				break;
    			}
    		}
    		if(done)continue;

    		for(int j=i+1;j<n;j++){
    			if(t[j]==s[i]){
    				ansVec.push_back(make_pair(i+2,j+1));
    				ansVec.push_back(make_pair(i+2,i+1));
    				t[j]=s[i+1];
    				s[i+1]=t[i];
    				t[i]=s[i];
    				break;
    			}
    		}
    	}

    	cout<<ansVec.size()<<endl;
    	for(int i=0;i<ansVec.size();i++){
    		cout<<ansVec[i].first<<" "<<ansVec[i].second<<endl;
    	}
    }
}