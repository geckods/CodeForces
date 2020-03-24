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

    	int a,b,c;
    	cin>>a>>b>>c;

    	string s;
    	cin>>s;

    	vector<char> ans;

    	int losscount=0;

    	for(int i=0;i<n;i++){
    		if(s[i]=='R'){
    			if(b>0){
    				ans.push_back('P');
    				b--;
    			}
    			else{
    				ans.push_back('X');
    				losscount++;
    			}
    		}
    		else if(s[i]=='P'){
    			if(c>0){
    				ans.push_back('S');
    				c--;
    			}
    			else{
    				ans.push_back('X');
    				losscount++;
    			}
    		}
    		else
    			if(a>0){
    				ans.push_back('R');
    				a--;
    			}
    			else{
    				ans.push_back('X');
    				losscount++;
    			}
    		}

    		if(losscount>n/2){
    			cout<<"NO"<<endl;
    		}
    		else{
    			cout<<"YES"<<endl;
    			for(int i=0;i<n;i++){
    				if(ans[i]!='X'){
    					cout<<ans[i];
    				}
    				else{
    					if(a>0){
    						cout<<"R";
    						a--;
    					}
    					else if (b>0){
    						cout<<"P";
    						b--;
    					}
    					else{
    						cout<<"S";
    						c--;
    					}
    				}
    			}
    			cout<<endl;
    		}

    	}

    }