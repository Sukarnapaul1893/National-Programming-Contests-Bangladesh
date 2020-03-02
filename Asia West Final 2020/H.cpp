
#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long long ,long long>
#define pli pair<long long , int>
#define pil pair<int ,long long>
#define pi acos(-1)
#define pb push_back
#define mkp make_pair
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define all(v)              ((v).begin()), ((v).end())
using namespace std;
int n;
int pp[100005];
ll dist[100005];
vector<pii > adj[100005];
void dijkstra(int src, int N){


	for (int i = 2; i <= N; ++i) {
		dist[i] =(1LL<<62);
	}

	set<pair<int, int> > q;
	q.insert(make_pair(0, 1));
	while(!q.empty()){
		int u = (*q.begin()).second;
		q.erase(q.begin());
		for (int j = 0; j < adj[u].size(); ++j) {
			if (dist[u]+adj[u][j].second < dist[adj[u][j].first]){
				dist[adj[u][j].first] = dist[u]+adj[u][j].second;
				pp[adj[u][j].first] = u;
				q.insert(make_pair(dist[adj[u][j].first], adj[u][j].first));
			}

		}
	}

}
int aa[100005];
ll sum ;
void solve(int node)
{
	if (node!=1)
		solve(pp[node]);
	//cout<<node<<" ";
	sum+=aa[node];
}
int main(){
    int t;
    cin>>t;

    for(int tt=0;tt<t;tt++){
        sum=0;
        int n,m;
        cin>>n>>m;
        int cur = 1;
        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){

                cin>>aa[cur];
                int a = aa[cur];
                if(cur%m>1){
                    adj[cur-1].pb({cur,a});
                }
                if(cur%m==0){
                    if(m!=1){
                        adj[cur-1].pb({cur,a});
                    }
                }

                if(cur%m>0){
                    adj[cur+1].pb({cur,a});
                }

                if(cur-m>=1 && cur-m<=n*m){
                    adj[cur-m].pb({cur,a});
                }
                if(cur+m>=1 && cur+m<=n*m){
                    adj[cur+m].pb({cur,a});
                }
                cur++;
            }
        }

        /*for(int i=1;i<=n*m;i++){

            cout<<i<<" ";
            for(int j=0;j<adj[i].size();j++){
                cout<<adj[i][j].first<<" ";
            }
            cout<<"\n";
        }*/

        dijkstra(1,n*m);

        solve(n*m);
        cout<<"Case "<<tt+1<<": Penalty = "<<sum<<"\n";


        for(int i=1;i<=n*m;i++){
            adj[i].clear();
            aa[i]=0;
            pp[i]=0;
            dist[i]=0;
        }
    }

}
