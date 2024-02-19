// 
//./C<test

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

#define MOD 998244353

int cons[100][100];
int parent[100];
pair<int,int> dcon[10000];
pair<ll,ll> DP[101];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin>>n;
    for(int i=0; i<n; i++) parent[i]=i;
    bool flag=true;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            cin>>cons[i][j];
            if(i==j && cons[i][j]==2) flag=false;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(cons[i][j]==1){
                for(int k=i+1; k<=j; k++) parent[k]=parent[i];
            }
        }
    }
    int cnt=0, dcnt=0;
    int last=parent[0];
    for(int i=0; i<n; i++){
        if(parent[i]==last) parent[i]=cnt;
        else{
            last=parent[i];
            cnt++;
            parent[i]=cnt;
        }
    }
    cnt++;

    //cout<<"parent ";
    //for(int i=0; i<n; i++) cout<<parent[i]<<' ';
    //cout<<endl;

    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if(cons[i][j]==2){
                dcon[dcnt++]={parent[i],parent[j]};
                if(parent[i]==parent[j]) flag=false;
            }
        }
    }
    /*cout<<"cnt "<<cnt<<endl;
    cout<<"dcnt : "<<dcnt<<endl;
    for(int i=0; i<dcnt; i++){
        cout<<dcon[i].fi<<' '<<dcon[i].se<<endl;
    }*/

    sort(dcon,dcon+dcnt);
    if(!flag) cout<<0<<endl;
    else{
        n=cnt;
        DP[0]={2,0}; // second는 몇 개의 cons를 지울 수 있는지.
        for(int i=1; i<n; i++){
            ll temp=0;
            int j=i-1;
            int last_l=-1;
            for(int j=0; j<dcnt; j++){
                if(dcon[j].se<i) last_l=max(last_l,dcon[j].fi);
            }
            int lcnt=0;
            while(lcnt<dcnt && dcon[lcnt].fi<i) lcnt++;
            for(int j=last_l+1; j<i; j++){
                temp=(temp+DP[j].fi)%MOD;
            }
            DP[i]={temp,lcnt};
        }
        /*cout<<"DP "<<endl;
        for(int i=0; i<n; i++) cout<<DP[i].fi<<' '<<DP[i].se<<endl;
        cout<<endl;*/

        ll ans=0;
        for(int i=0; i<n; i++){
            if(DP[i].se==dcnt){
                ans=(ans+DP[i].fi)%MOD;
            } 
        }
        cout<<ans<<endl;
    }
    return 0;
}