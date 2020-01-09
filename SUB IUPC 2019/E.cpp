#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include<ext/pb_ds/detail/standard_policies.hpp>
#define pii pair<int,int>
#define pll pair<long long ,long long>
#define pli pair<long long , int>
#define pil pair<int ,long long>
#define pi acos(-1)
#define pb push_back
#define mkp make_pair
#define all(a) a.begin(), a.end()
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
typedef tree<pair<ll, int>,null_type,less<pair<ll, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;




int main(){
    IOS
    //freopen("output.txt","w",stdout);
    int T;
    cin>>T;

    for(int tt=0;tt<T;tt++){
        int p,n,t;
        cin>>p>>n>>t;
        vector<pair<pair<ll,int>,int > >dat;
        for(int i=0;i<n;i++){
            int type;
            ll time;
            cin>>type>>time;

            dat.pb({{time,type},0});
        }

        for(int i=0;i<t;i++){
            ll time ;
            cin>>time;

            dat.pb({{time,p+1},1});
        }

        sort(dat.begin(),dat.end());
        ordered_multiset st[p+1];

        priority_queue<pair<ll,int> >pq;
        ll ans = -1 ;
        for(int i=0;i<dat.size();i++){
            if(dat[i].second==0){
                int type = dat[i].first.second;
                ll time = dat[i].first.first;
                if(st[type].size()==0){
                    pq.push({time,type});
                    st[type].insert({time,i});
                }
                else{
                    st[type].insert({time,i});
                }
            }
            else{
                ll time = dat[i].first.first;
                priority_queue<pair<ll,int > >temp,temp2;
                unordered_map<int,int>cnt;
                while(!pq.empty()){
                    auto TOP = pq.top();
                    if(cnt[(TOP).second]==0){
                        ans = max(time-(TOP).first,ans);
                        st[(TOP).second].erase(st[(TOP).second].begin());
                        cnt[(TOP).second]++;
                        if(st[(TOP).second].size()!=0){
                            auto it= st[(TOP).second].begin();
                            temp2.push({(*it).first,(TOP).second});
                        }

                    }
                    else{
                        temp.push({(TOP).first,(TOP).second});
                    }
                    pq.pop();
                }
                while(!temp.empty()){
                    auto TOP = temp.top();
                    pq.push({(TOP).first,(TOP).second});
                    temp.pop();
                }
                while(!temp2.empty()){
                    auto TOP = temp2.top();
                    pq.push({(TOP).first,(TOP).second});
                    temp2.pop();
                }
            }
        }
        for(int i=1;i<=p;i++){
            if(st[i].size()>0)ans=-1;
        }
        cout<<"Case "<<tt+1<<": "<<ans<<"\n";
    }
}

