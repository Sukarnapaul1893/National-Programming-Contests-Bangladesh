#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;
int n,m;
int cs;
string s[20004];
vector<int>adj[20004];
int vis[20004];

void dfs(int v){
    vis[v]++;

    for(int i=0;i<adj[v].size();i++){
        int u = adj[v][i];
        if(vis[u]==0){
            dfs(u);
        }
    }
}

void input();
int cur ;
void solve(){
    int N = n-1;
    int M = m-1;

    for(cur=0;cur<m-2;cur++){
        adj[cur].pb(cur+1);
        adj[cur+1].pb(cur);
    }
    cur++;

    for(int i=1;i<=N;i++){
        for(int j=0;j<M;j++){

            int UP = cur-(m-1);
            int LEFT  = cur-1;
            if(s[i-1][j]=='R'){

                adj[cur].pb(LEFT);
                adj[LEFT].pb(cur);
            }
            else if(s[i-1][j]=='D'){
                adj[cur].pb(UP);
                adj[UP].pb(cur);

            }
            else if(s[i-1][j]=='N'){
                adj[cur].pb(UP);
                adj[UP].pb(cur);

                adj[cur].pb(LEFT);
                adj[LEFT].pb(cur);

            }

            cur++;
        }
    }

    dfs(0);

    int ans = 0;

    for(int i=m-1;i<cur;i++){
        if(vis[i]!=0)ans++;
    }
    cout<<"Case "<<cs<<": "<<ans<<"\n";
}

void Clear(){
    cs++;
    for(int i=0;i<n;i++)s[i]="";
    for(int i=0;i<cur+5;i++){
        adj[i].clear();
        vis[i]=0;
    }
    cur=0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    cs=1;
    while(t--){
        input();
        solve();
        Clear();
    }
}

void input(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
}
/*
3
4 5
DDDND
DBNND
BDBRD
RRRRN
5 6
DDNNND
DDNNBD
DBDNDD
BNRBBD
RRRRRN
4 4
BBDD
DDDD
DRND
RRRN
*/
