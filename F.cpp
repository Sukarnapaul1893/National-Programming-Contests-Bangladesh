//Author : Sukarna Paul

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include<ext/pb_ds/detail/standard_policies.hpp>
#define pi acos(-1)
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define MAX 300005
#define INF 0x3f3f3f3f
template <class T> inline T bigmod(T p,T e,T M){ll ret = 1LL;for(; e > 0LL; e >>= 1LL){if(e & 1LL) ret = (ret * p) % M;p = (p * p) % M;}return (T)ret;}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}   // M is prime}

using namespace std;
using namespace __gnu_pbds;

typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update>pref_trie;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;


unordered_map<ll , ll >P;

const int MAXN = 2e5+5;
const int LG = log2(MAXN) + 1;

int par[MAXN][LG];



vector<int>adj[200005];

bool vis[200005];
int level[200005];
int lca(int u, int v){
	if(level[u] < level[v])	swap(u, v);
	int log = log2(level[u]);
	for(int i = log; i >= 0; i--)
		if(level[u]-level[v] >= (1 << i))
			u = par[u][i];
	if(u == v)
		return u;
	for(int i = log; i >= 0; i--){
		if(par[u][i] != -1 && par[u][i] != par[v][i]){
			u = par[u][i];
			v = par[v][i];
		}
	}
	return par[u][0];
}


void dfs(int u, int parent){
	level[u] = level[parent] + 1;
	par[u][0] = parent;
	for(auto v : adj[u]){
		if(v == parent)	continue;
		dfs(v, u);
	}
}


int main(){
    IOS
    //freopen("output.txt","w",stdout);
    int t;
    cin>>t;

    for(int tt=0;tt<t;tt++){
        cout<<"Case "<<tt+1<<":\n";
        int q;
        cin>>q;
        ll U[q],V[q];
        int type[q] ;
        P[1]=1;
        int cur=1;
        for(int i=0;i<q;i++){

            cin>>type[i];

            ll u ,v;
            cin>>u>>v;

            U[i]=u;
            V[i]=v;

            if(type[i] == 1){
                cur++;
                P[v]=cur;
                adj[P[u]].pb(cur);
                adj[cur].pb(P[u]);
            }
            if(type[i]==2){
                P[v]=P[u];
            }
        }
        memset(par, -1, sizeof par);
        level[0] = -1;
        dfs(1, 0);
        for(int j = 1; j < LG; j++){
            for(int i = 1; i <= cur-1; i++){
                if(par[i][j-1] != -1)
                    par[i][j] = par[par[i][j-1]][j-1];
            }
        }

        for(int i=0;i<q;i++){
            if(type[i]==3){
                int x=lca(P[U[i]],P[V[i]]);
                int ans = level[P[U[i]]]+level[P[V[i]]]-2*level[x];
                cout<<ans<<"\n";
            }
        }
        for(int i=0;i<=cur;i++)adj[i].clear();
        for(int i=0;i<=cur;i++)vis[i]=false;
        for(int i=0;i<=cur;i++)level[i]=0;

    }
}
/*
1
8
1 1 5
1 1 2
1 5 6
3 2 6
1 2 7
3 7 6
2 7 9
3 9 6
*/
