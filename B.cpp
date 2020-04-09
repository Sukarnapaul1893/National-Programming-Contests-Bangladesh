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
vector <int> prime;
bitset <10000010> bs;

void sieve (int n){
	bs.set ();
    //prime.pb(2);
	for (int i = 2; i <= n; i++){
		if (bs[i])prime.pb(i);

		for (int j = 0; j<prime.size() && i*prime[j]<=n; j++){
		    bs[i*prime[j]] = 0;
		    if(i%prime[j]==0)break;
		}
	}
}
vector<int>pfactors[1000006];
void pre(){
    for(int i=1;i<=1000002;i++){
        int cur = i;
        for(int j=0;j<prime.size() && prime[j]*prime[j]<=cur;j++){
            int cnt=0;
            while(cur%prime[j]==0){
                cur/=prime[j];
                cnt++;
            }
            if(cnt>0)pfactors[i].pb(prime[j]);
        }
        if(cur>1)pfactors[i].pb(cur);
    }
}

ordered_multiset st[1000006];

int main(){
    IOS
    //freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    sieve(1000006);
    pre();
    for(int tt=0;tt<t;tt++){
        int n,k;
        cin>>n>>k;
        int arr[n];
        int dp[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
            dp[i]=INF;
        }
        dp[0]=0;
        vector<int>erasable;
        for(int j=0;j<pfactors[arr[0]].size();j++){
            int u = pfactors[arr[0]][j];
            st[u].insert({dp[0],0});
            erasable.pb(u);
        }

        for(int i=1;i<n;i++){
            int cur = arr[i];
            int Gcd = INF;
            for(int j=0;j<pfactors[cur].size();j++){
                int u = pfactors[cur][j];
                if(st[u].size()==0){
                    continue;
                }
                else{
                    while(st[u].size()>0){
                        auto it=st[u].begin();
                        int f = (*it).first;
                        int s = (*it).second;
                        if(i-s<=k){
                            Gcd = min(Gcd,f);
                            break;
                        }
                        else{
                            st[u].erase(it);
                        }
                    }
                }

            }
            dp[i] = min(dp[i-1]+1,Gcd+1);
            for(int j=0;j<pfactors[cur].size();j++){
                int u = pfactors[cur][j];
                st[u].insert({dp[i],i});
                erasable.pb(u);
            }
        }
        /*for(int i=0;i<n;i++){
            cout<<dp[i]<<" ";
        }*/
        //cout<<"\n";
        cout<<"Case "<<tt+1<<": "<<dp[n-1]<<"\n";
        for(int i=0;i<erasable.size();i++){
            int u = erasable[i];
            st[u].clear();
        }
    }
}
