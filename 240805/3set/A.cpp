
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define gnr(i,b,a) for(int i=int(b);i>=int(a);i--)
#define pb push_back
#define eb emplace_back
typedef long long ll;
using pii=pair<int,int>;

#define N 300030
#define MOD 998244353
#define INF 1000000007 



void solution(){
    int n;
    string s;
    cin>>s;
    n=s.size();
    int cnt[4];
    fill(cnt,cnt+4,0);
    for(int i=0; i<=n-1; i++){
        if(s[i]=='<') cnt[0]++;
        if(s[i]=='^') cnt[1]++;
        if(s[i]=='>') cnt[2]++;
        if(s[i]=='v') cnt[3]++;
    }
    int sum=0;
    for(int i=0; i<=3; i++) sum+=cnt[i];
    int mn=sum;
    for(int i=0; i<=3; i++) mn=min(mn,sum-cnt[i]);
    cout<<mn<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        solution();
    }
    return 0;
}

