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

unordered_map<int,int>ok;

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

void pre(){

    for(int i=0;i<prime.size();i++){
        int cur= prime[i];
        ok[cur]=1;
        int temp=cur;
        int p=1;
        while(temp>0){
            int d=temp%10;
            for(int ii=0;ii<=9;ii++){
                ok[(cur-d*p)+ii*p]=1;
            }
            temp/=10;
            p*=10;
        }
    }
}

int main(){
    IOS
    //freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    sieve (1000010);
    pre();

    for(int tt=0;tt<t;tt++){
        int n;
        cin>>n;

        if(ok[n]==1){
            cout<<"yes\n";
        }
        else{
            cout<<"no\n";
        }
    }
}
