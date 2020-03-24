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
        string s,t;
        cin>>s;
        int ns=s.length();
        cin>>t;
        int nt=t.length();
        set<set<int>> dp[ns][nt];

        for(int i=0;i<ns;i++){
            for(int j=0;j<nt;j++){
                dp[i][j].clear();
            }
        }        


        for(int ti=0;ti<nt;ti++){
            for(int si=ti;si<ns;si++){
                if(s[si]==t[ti]){
                    if(ti>0){
                        for(int j=ti-1;j<si;j++){
                            // cerr<<ti<<" "<<si<<endl;
                            if(dp[j][ti-1].size()>0){
                                for(auto k=dp[j][ti-1].begin();k!=dp[j][ti-1].end();k++){
                                    auto temp=*k;
                                    temp.insert(si);
                                    dp[si][ti].insert(temp);
                                }
                            }
                        }
                    }
                    else{
                        set<int> temp;
                        temp.insert(si);
                        dp[si][ti].insert(temp);
                    }
                }
            }

            // if(ti>0){
            //     for(int si=0;si<ns;si++){
            //         dp[si][ti-1].clear();
            //     }
            // }            

        }

        bool works=false;

        for(int ti=0;ti<nt;ti++){
            for(int si=ti;si<ns;si++){
                for(auto k=dp[si][ti].begin();k!=dp[si][ti].end();k++){
                    int j=ti+1;
                    int i=0;
                    while(j<nt){
                        while(i<ns && (*k).find(i)!=(*k).end())i++;
                        if(i==ns)break;
                        if(s[i]==t[j]){
                            i++;
                            j++;
                        }
                        else{
                            i++;
                        }
                        if(i==ns)break;
                    }

                    if(j==nt)works=true;
                }
            }
        }

        if(works){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

    }
}    