#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define TEMPCHECK 8

ll countSetBits(ll n) 
{ 
    ll count = 0; 
    while (n) { 
        n &= (n - 1); 
        count++; 
    } 
    return count; 
} 

ll ask(ll a, ll b){
    cout<<"?"<<" "<<a+1<<" "<<b+1<<endl;
    fflush(stdout);
    ll x;
    cin>>x;
    if(x==-1){
        cerr<<"ERROR ERROR"<<endl;
        exit(0);
    }
    return x;
}

#define rng rand


// THINGS TO REMEMBER
// ENDL is slow, '\n' is fast
// Clear everything (including graphs) between test cases
// use anti-anti-hash: https://codeforces.com/blog/entry/62393
// pb-ds: https://codeforces.com/blog/entry/11080
// check when to use LLONG_MAX/LLONG_MIN vs INT_MAX or INT_MIN
// You frequently suffer from confirmation bias - you trust your initial solution and miss simple things. 
// When you hit a roadblock, remember to rethink the solution ground up, not just try hacky fixes
int main(){
	
    // mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    // rng();

    // cerr<<rng()<<endl;
    // return 0;

    bool firstTime=false;

    ll n;
    cin>>n;

    vector<ll> cbz;
    for(int i=0;i<n;i++)cbz.push_back(i);

    ll theZ=-1;

    ll minInd=-1;

    // while(1){
    //     ask(1,2);
    // }

    if(n>100){
        vector<ll> temp;

        for(int i=0;i<TEMPCHECK;i++){
            ll tempval = rng()%cbz.size();
            while(find(temp.begin(),temp.end(),tempval)!=temp.end()){
                tempval = rng()%cbz.size();
            }
            temp.push_back(tempval);
        }

        ll sum[TEMPCHECK] = {0};
        for(int i=0;i<TEMPCHECK;i++){
            sum[i]=0;
        }
        ll abc;

        for(int i=0;i<TEMPCHECK;i++){
            for(int j=i+1;j<TEMPCHECK;j++){
                abc=countSetBits(ask(temp[i],temp[j]));
                sum[i]+=abc;
                sum[j]+=abc;
            }
        }

        ll minSum=INT_MAX;
        minInd=-1;

        for(int i=0;i<TEMPCHECK;i++){
            if(sum[i]<minSum){
                minSum=sum[i];
                minInd=temp[i];
            }
        }
        firstTime=true;
    }


    ll ans[n];
    memset(ans,-1,sizeof(ans));

    while(cbz.size()>1){
        ll currInd;
        if(firstTime){
            currInd=minInd;
            firstTime=false;
        }
        else{
            currInd = rng()%cbz.size();
        }
        currInd%=cbz.size();

        vector<ll> ncbz;

        ll currMinBits = 20;

        bool hasNotSeen[12];
        memset(hasNotSeen,false,sizeof(hasNotSeen));

        bool hasSeen[12];
        memset(hasSeen,false,sizeof(hasSeen));
// 

        // cerr<<"CBZ:"<<endl;
        // cerr<<cbz.size()<<endl;
        // for(int i=0;i<cbz.size();i++){
        //     cerr<<cbz[i]<<" ";
        // }
        // cerr<<endl;

        map<ll,ll> miniTemp;

        for(int i=0;i<cbz.size();i++){
            if(i==currInd)continue;
            ll temp = ask(cbz[currInd],cbz[i]);

            miniTemp[cbz[i]]=temp;

            for(int z=0;z<12;z++){
                if(((temp>>z)&1)==0){
                    hasNotSeen[z]=true;
                }
                else{
                    hasSeen[z]=true;
                }
            }

            ll csb = countSetBits(temp);

            if(csb<currMinBits){
                currMinBits=csb;
                ncbz.clear();
                ncbz.push_back(cbz[i]);
            }
            else if (csb==currMinBits){
                ncbz.push_back(cbz[i]);               
            }
            // cerr<<"CSB"<<" "<<csb<<" "<<currMinBits<<endl;
        }
        // if(currMinBits>1){
            // cbz.erase(cbz.begin()+cbz[currInd]);
        // }

        bool works=true;

        ll rb=0;

        for(int i=0;i<12;i++){
            // there should be no bit which is always seen
            if((hasSeen[i] && (!hasNotSeen[i]))){
                rb|=(1<<i);
                works=false;
            }
        }

        // ans[cbz[currInd]]=rb;
        // cerr<<"WROSK "<<works<<endl;

        if(works){
            for(auto j:miniTemp){
                ans[j.first]=j.second;
            }
            theZ=cbz[currInd];
            break;
        }


        cbz=ncbz;
    }

    if(theZ==-1){
        if(cbz.empty()){
            ask(-1,-1);
        }
        else{
            theZ=cbz[0];            
        }
    }

    // cerr<<"FOUNDZ"<<" "<<theZ<<endl;

    ans[theZ]=0;

    for(int i=0;i<n;i++){
        if(ans[i]!=-1)continue;
        ans[i]=ask(theZ,i);
    }

    cout<<"! ";
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

}