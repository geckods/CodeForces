#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define MAXN 400001
vector<ll int> adj[MAXN];
bool visited[MAXN];
ll int dist[MAXN];

void clear_full(int n)
{
    ll int i;
    for(i=0;i<n;i++)
    {
        adj[i].clear();
        dist[i]=0;
        visited[i]=false;
    }
}

void bfs(ll int v, ll int distance)
{
    queue<pair<ll int, ll int> > dq;
    ll int i;
    dq.push(make_pair(v,dist[v]));

    while(!dq.empty())
    {
        pair<ll int, ll int> temp=dq.front();
        dq.pop();
        dist[temp.first]=temp.second;
        visited[temp.first]=true;

        for(i=0;i<adj[temp.first].size();i++)
        {
            if(!visited[adj[temp.first][i]])
            {
                dq.push(make_pair(adj[temp.first][i],temp.second+1));
            }
        }

    }
}
 
int main()
{
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll int t;
    cin>>t;
    while(t--)
    {
        ll int n,m,i;
        cin>>n>>m;
//        clear_full(n+2);
        ll int x,y;
        while(m--)
        {
            cin>>x>>y;
            x--;
            y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        bfs(0,0);
        // ll int evencount=0;
         // ll int oddcount=n-evencount;
        ll evencount=0;
        ll oddcount=0;


        for(i=0;i<n;i++)
        {
            if(dist[i]%2==0)
            {
                evencount++;
            }
            else
            {
                oddcount++;
            }
            
        }

        if(evencount<oddcount)
        {
            cout<<evencount<<endl;
            for(i=0;i<n;i++)
            {
                if(dist[i]%2==0)
                {
                    cout<<i+1<<" ";
                }
            }
        }
        else
        {
            cout<<oddcount<<endl;
            for(i=0;i<n;i++)
            {
                if(dist[i]%2!=0)
                {
                    cout<<i+1<<" ";
                }
            }
        }
        cout<<endl;
    }
}
