// 
//./E<test

#include <bits/stdc++.h>
#define endl '\n'
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

template<typename T>
inline T umax(T &u, T v){return u = max(u, v);}
template<typename T>
inline T umin(T &u, T v){return u = min(u, v);}

int parent[200000];
int root(int idx){return parent[idx]=(parent[idx]==idx?idx:root(parent[idx]));}
void c_union(int a, int b){parent[root(a)]=parent[root(b)];}
pair<int,int> ap[200000], bp[200000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        for(int i=0; i<n; i++) parent[i]=i;
        for(int i=0; i<n-k; i++) c_union(i,i+k);
        for(int i=0; i<n-k-1; i++) c_union(i,i+k+1);
        string a,b;
        cin>>a>>b;
        for(int i=0; i<n; i++) ap[i]={root(i),a[i]};
        for(int i=0; i<n; i++) bp[i]={root(i),b[i]};
        sort(ap,ap+n);
        sort(bp,bp+n);
        bool flag=true;
        for(int i=0; i<n; i++) if(ap[i]!=bp[i]){
            flag=false;
            break;
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}