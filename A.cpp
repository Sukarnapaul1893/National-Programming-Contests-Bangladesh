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


vector<int>pos[27];
set<char>st[27];


void Clear(){
    for(int i=0;i<27;i++)st[i].clear();
    for(int i=0;i<26;i++){
        st[i].insert('A'+i);
    }
    st[26].insert('_');

    for(int i=0;i<27;i++)pos[i].clear();

}

int main(){
    IOS
    //freopen("output.txt","w",stdout);
    int t;
    cin>>t;

    for(int tt=0;tt<t;tt++){
        Clear();
        string s;
        cin>>s;
        int len = s.size();
        for(int i=0;i<len;i++){
            if(s[i]=='_')pos[26].pb(i);
            else pos[s[i]-'A'].pb(i);
        }

        int R;
        cin>>R;

        for(int i=0;i<R;i++){
            char x,y;
            cin>>x>>y;
            int F,L;
            if(x=='_'){
                F = 26;
            }
            else {
                F = x-'A';
            }
            if(y=='_'){
                L = 26;
            }
            else {
                L = y-'A';
            }

            for(auto it=st[L].begin();it!=st[L].end();it++){
                st[F].insert((*it));
            }
            if(x!=y)st[L].clear();

        }
        unordered_map<char,char>mp;
        for(int i=0;i<27;i++){
            if(i==26){
                for(auto it=st[i].begin();it!=st[i].end();it++){
                    mp[(*it)]='_';
                }
                continue;
            }
            for(auto it=st[i].begin();it!=st[i].end();it++){
                mp[(*it)]='A'+i;
            }
        }
        for(int i=0;i<len;i++){

            cout<<mp[s[i]];
        }
        cout<<"\n";
    }
}
