
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define N 300030
#define MOD 998244353
#define INF 1000000007 

string datas[3];
ll cnt[3][3];
int mp[200];
char invmp[3];
set<array<int,3>> x_mod, y_mod, z_mod;

ll calc(){
    ll res=0; 
    res+=cnt[0][0]*cnt[1][1]*cnt[2][2];
    res+=cnt[0][0]*cnt[1][2]*cnt[2][1];
    res+=cnt[0][1]*cnt[1][2]*cnt[2][0];
    res+=cnt[0][1]*cnt[1][0]*cnt[2][2];
    res+=cnt[0][2]*cnt[1][0]*cnt[2][1];
    res+=cnt[0][2]*cnt[1][1]*cnt[2][0];
    return res;
}

void Solve(){
    ll nx,ny,nz;
    cin>>nx>>ny>>nz;
    x_mod.clear();
    y_mod.clear();
    z_mod.clear();
    x_mod.insert({0,0,0});
    y_mod.insert({0,0,0});
    z_mod.insert({0,0,0});

    cin>>datas[0];
    cin>>datas[1];
    cin>>datas[2];
    for(int i=0;i<=2;i++) for(int j=0;j<=2;j++) cnt[i][j]=0;
    for(int i=0;i<=nx-1;i++){
        if(datas[0][i]==datas[0][i+1]){
            if(datas[0][i]=='R') cnt[0][0]++;
            if(datas[0][i]=='G') cnt[0][1]++;
            if(datas[0][i]=='B') cnt[0][2]++;
        }
    }
    for(int i=0;i<=ny-1;i++){
        if(datas[1][i]==datas[1][i+1]){
            if(datas[1][i]=='R') cnt[1][0]++;
            if(datas[1][i]=='G') cnt[1][1]++;
            if(datas[1][i]=='B') cnt[1][2]++;
        }
    }
    for(int i=0;i<=nz-1;i++){
        if(datas[2][i]==datas[2][i+1]){
            if(datas[2][i]=='R') cnt[2][0]++;
            if(datas[2][i]=='G') cnt[2][1]++;
            if(datas[2][i]=='B') cnt[2][2]++;
        }
    }

    for(int i=0;i<=nx;i++){
        for(int k=0;k<=2;k++){
            array<int,3> temp={0,0,0};
            if(k==mp[datas[0][i]]) continue;
            temp[mp[datas[0][i]]]-=(i!=0 && datas[0][i-1]==datas[0][i])+(i!=nx && datas[0][i+1]==datas[0][i]);
            temp[k]+=(i!=0 && datas[0][i-1]==invmp[k])+(i!=nx && datas[0][i+1]==invmp[k]);
            if(x_mod.find(temp)==x_mod.end()) x_mod.insert(temp);
        }
    }
    for(int i=0;i<=ny;i++){
        for(int k=0;k<=2;k++){
            array<int,3> temp={0,0,0};
            if(k==mp[datas[1][i]]) continue;
            temp[mp[datas[1][i]]]-=(i!=0 && datas[1][i-1]==datas[1][i])+(i!=ny && datas[1][i+1]==datas[1][i]);
            temp[k]+=(i!=0 && datas[1][i-1]==invmp[k])+(i!=ny && datas[1][i+1]==invmp[k]);
            if(y_mod.find(temp)==y_mod.end()) y_mod.insert(temp);
        }
    }
    for(int i=0;i<=nz;i++){
        for(int k=0;k<=2;k++){
            array<int,3> temp={0,0,0};
            if(k==mp[datas[2][i]]) continue;
            temp[mp[datas[2][i]]]-=(i!=0 && datas[2][i-1]==datas[2][i])+(i!=nz && datas[2][i+1]==datas[2][i]);
            temp[k]+=(i!=0 && datas[2][i-1]==invmp[k])+(i!=nz && datas[2][i+1]==invmp[k]);
            if(z_mod.find(temp)==z_mod.end()) z_mod.insert(temp);
        }
    }

    ll mx=calc();
    for(auto xx : x_mod){
        for(int i=0;i<=2;i++) cnt[0][i]+=xx[i];
        for(auto yy : y_mod){
            for(int i=0;i<=2;i++) cnt[1][i]+=yy[i];
            for(auto zz : z_mod){
                for(int i=0;i<=2;i++) cnt[2][i]+=zz[i];
                mx=max(mx,calc());
                for(int i=0;i<=2;i++) cnt[2][i]-=zz[i];
            }
            for(int i=0;i<=2;i++) cnt[1][i]-=yy[i];
        }
        for(int i=0;i<=2;i++) cnt[0][i]-=xx[i];
    }
    cout<<mx<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    cin>>t;
    mp['R']=0;
    mp['G']=1;
    mp['B']=2;
    invmp[0]='R';
    invmp[1]='G';
    invmp[2]='B';

    while(t--){
        Solve();
    }
    return 0;
}

