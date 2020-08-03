#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;
ll lp[1000006];
int n;
//Disjoint Set Union
int p[1000006]; //initially p[i] = i;
int Find(int x)
{
    if(p[x] == x) return x;
    return p[x] = Find(p[x]);
}
void Union(int a, int b)
{
    p[Find(b)] = Find(a); // Making the parent of a and b same
}
vector<int>prime,vec,w;

void FindLowestPrimeFactor(){
    for(int64_t i=2;i<=1000001;i++){
        if(lp[i]==0){
            lp[i]=i;
            prime.pb(i);
        }
        for(int64_t j=0;j<prime.size();j++){
            if(lp[i]<prime[j])break;
            if(i*prime[j]>1000000)break;

            lp[i*prime[j]]=prime[j];
        }
    }
}

void input();
unordered_set<int>st;
void solve(){
    int ans = 0;
    for(int i=0;i<n;i++){
        int x=vec[i];

        if(x==1){
            ans++;
            continue;
        }
        while(x>1){
            int LP = lp[x];

            Union(LP,vec[i]);
            w.pb(LP);
            while(x%LP==0){
                x/=LP;
            }
        }
    }

    for(int i=0;i<n;i++){
        int x = vec[i];
        if(x==1)continue;
        st.insert(Find(x));
    }
    ans+=st.size();
    cout<<ans<<"\n";
}

void Clear(){
    vec.clear();
    for(int i=0;i<w.size();i++){
        p[w[i]]=w[i];
    }
    w.clear();
    st.clear();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i=0;i<1000004;i++)p[i]=i;
    FindLowestPrimeFactor();
    int t;
    cin>>t;

    for(int tt=0;tt<t;tt++){
        cout<<"Case "<<tt+1<<": ";
        input();
        solve();
        Clear();
    }
}

void input(){
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        vec.pb(x);
        w.pb(x);
    }
}
