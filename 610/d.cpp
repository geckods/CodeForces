#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
solved in contest, but could only iron out the bugs after the contest
*/

typedef pair<ll,ll> intpair;

char opp(char a){
    if(a=='a')return 'b';
    return 'a';
}

int main(){
	
	// #ifndef ONLINE_JUDGE
    	// freopen("input", "r", stdin);
    	// freopen("output", "w", stdout);
    	// freopen("error", "w", stderr);
	// #endif
	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);


    //first ask 300 as -> get number of as in answer
    //then ask 300 bs -> get number of bs in answer
    //then then ask numa as and numb bs
    //store edit distance
    //take cases for moving stuff around

    int acount;
    int bcount;

    string as;
    string bs;
    for(int i=0;i<300;i++){
        as.push_back('a');
    }
    cout<<as<<endl;
    fflush(stdout);
    cin>>acount;

    if(acount==0){
        return 0;
    }

    acount=300-acount;

    for(int i=0;i<300;i++){
        bs.push_back('b');
    }
    cout<<bs<<endl;
    fflush(stdout);
    cin>>bcount;

    if(bcount==0){
        return 0;
    }

    bcount=300-bcount;

    int n=acount+bcount;

    char ans[n+1];
    char curr[n+1];
    ans[n]=curr[n]=0;

    for(int i=0;i<acount;i++){
        ans[i]=curr[i]='a';
    }
    for(int i=acount;i<n;i++){
        ans[i]=curr[i]='b';
    }

    int lefta=acount;
    int leftb=bcount;

    int i=0;
    int resp=0;
    int currdist;

    cout<<curr<<endl;
    fflush(stdout);
    cin>>resp;
    if(resp==0){
        return 0;
    }

    currdist=resp;

    int apointer=0;
    int bpointer=acount;

    bool curra=true;
    int done=0;

    int asd = resp/2;

    while(1){
        //if you have only a single a left then it must be the wrong one

        // cout<<apointer<<" "<<bpointer<<" "<<acount<<" "<<n<<endl;

        // if((currdist/2)--)curra=true;
        if(currdist==0)break;

        if(curra){
            if(apointer<acount-1){
                curr[apointer]='b';
                cout<<curr<<endl;
                fflush(stdout);
                cin>>resp;
                if(resp==0){
                    return 0;
                }
                if(resp<currdist){
                    curra=false;
                    currdist=resp;
                }
                else{
                    curr[apointer]='a';
                }
                apointer++;
            }
            else{
                curra=false;
                curr[apointer]='b';
                currdist--;
            }
        }
        else{
            if(bpointer<n-1){
                curr[bpointer]='a';
                cout<<curr<<endl;
                fflush(stdout);
                cin>>resp;
                if(resp==0){
                    return 0;
                }
                if(resp<currdist){
                    curra=true;
                    currdist=resp;
                }
                else{
                    curr[bpointer]='b';
                }
                bpointer++;
            }
            else{
                curra=true;
                curr[bpointer]='a';
                currdist--;
            }
        }

        if(apointer>=acount-1&&bpointer>=n-1){
            if(done<2){
                done++;
                continue;
            }
            break;
        }

    }

    if(lefta==0||leftb==0){
        for(;i<n;i++){
            if(lefta>0)curr[i]='a';
            else curr[i]='b';
        }
    }

    cout<<curr<<endl;
    fflush(stdout);
    cin>>resp;
    if(resp==0){
        return 0;
    }
    cerr<<"ERROR"<<endl;

}