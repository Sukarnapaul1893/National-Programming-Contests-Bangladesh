#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;
int cs;
ll n;

vector<int>adj[20004];
int vis[20004];
int parent[20004];
ll subTree[20004];
vector<pair<pair<int,int>,ll> >edge;
ll sum;
ll ans;

void dfs(int v, int par){
    vis[v]++;
    subTree[v]++;
    parent[v] = par;
    for(int i=0;i<adj[v].size();i++){
        int u = adj[v][i];
        if(vis[u]==0){
            dfs(u,v);
            subTree[v] +=subTree[u];
        }

    }
}

ll Check (ll weight, ll nvis, ll need){
    ll div = need/nvis;
    if(need%nvis>0)div++;
    ans += min(div,weight);
    return min(need, weight*nvis);
}

void input();

void solve(){
    dfs(1,-1);
    vector<pair< ll,ll> >vec;

    for(int i=0;i<edge.size();i++){
        int u = edge[i].first.first;
        int v = edge[i].first.second;
        ll w = edge[i].second;
        if(parent[u]!=v)continue;
        ll nvis = subTree[u]*(n-subTree[u]);
        sum += nvis*w;
        if(w<0)vec.pb({w,nvis});
    }


    if(sum>=0){
        cout<<ans<<"\n";
        return;
    }
    sort(vec.begin(),vec.end(),[&](auto a, auto b){return a.second>b.second;});
    for(int i=0;i<vec.size();i++){
        ll weight = vec[i].first;
        ll nvis   = vec[i].second;
        ll need   = sum;

        ll Cover = Check(abs(weight),nvis, abs(need));
        sum += Cover;

        if(sum>=0){
            cout<<ans<<"\n";
            return;
        }
    }
}

void Clear(){
    cs++;
    for(int i=1;i<=n;i++){
        vis[i] = 0;
        parent[i] = 0;
        subTree[i] = 0;
        adj[i].clear();
    }
    edge.clear();
    sum = 0;
    ans = 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cs = 1;
    int t;
    cin>>t;

    while(t--){
        cout<<"Case "<<cs<<": ";
        input();
        solve();
        Clear();
    }
}

void input(){
    cin>>n;

    for(int i=0;i<n-1;i++){
        int u,v;
        ll w;
        cin>>u>>v>>w;
        adj[u].pb(v);
        adj[v].pb(u);
        edge.pb({{u,v},w});
        edge.pb({{v,u},w});
    }
}
