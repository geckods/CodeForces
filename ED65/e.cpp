#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> intpair;

int main() 
{ 
    #ifndef ONLINE_JUDGE
        freopen("input", "r", stdin);
        freopen("output", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,x;
    cin>>n>>x;

    vector<intpair> myVec;

    ll z;

    for(int i=0;i<n;i++){
        cin>>z;
        myVec.push_back(make_pair(z,i));
    }

    sort(myVec.begin(),myVec.end());

    int minind=INT_MAX;
    int minnow[n];
    int isgood[n];
    isgood[n-1]=1;

    for(int i=n-1;i>=0;i--){
        minind=min(minind,myVec[i].second);
        minnow[i]=minind;
        if(i<n-1){
            if(myVec[i].second<myVec[i+1].second){
                isgood[i]=isgood[i+1];
            }
            else{
                isgood[i]=0;
            }
        }
    }

    int isgood2[n];
    isgood2[0]=1;

    for(int i=1;i<n;i++){
        if(myVec[i].second>myVec[i-1].second){
            isgood2[i]=isgood2[i-1];
        }
        else{
            isgood2[i]=0;
        }
    }


    ll ans=0;
    ll prevlow=0;

    int maxindtillnow=-1;
    int i=1;
    int arraypointer=0;
    int prevx=0;

    while(i<=x){
        //find the right bound for which you can delete i..j safely

        int prlow=i;
        int prhigh=x;
        int prmid;
        while(prlow<prhigh){
            prmid=(prlow+prhigh)/2;
            int theind=upper_bound(myVec.begin(),myVec.end(),make_pair(prmid,INT_MAX))-myVec.begin();
            // cout<<i<<" "<<prlow<<" "<<prhigh<<" "<<prmid<<" "<<theind<<endl;
            if(theind==n || (isgood[theind]&&minnow[theind]>maxindtillnow)){
                prhigh=prmid;
            }
            else{
                prlow=prmid+1;
            }

        }

        ans+=(x+1-prhigh);

        // cout<<i<<" "<<prhigh<<endl;

        while(arraypointer<n && myVec[arraypointer].first==i){
            maxindtillnow=max(maxindtillnow,myVec[arraypointer].second);
            arraypointer++;
        }

        int asd=upper_bound(myVec.begin(),myVec.end(),make_pair(i,INT_MAX))-myVec.begin()-1;

        if(asd>0&&!isgood2[asd]){
            break;
        }



        i++;
    }

    cout<<ans<<endl;

    return 0; 
} 