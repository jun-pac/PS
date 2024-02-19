// 
//./F<test

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

bool valid[1<<7];
int DP[200000][1<<7];

void prt(int idx){
    vector<int> temp;
    for(int i=0; i<7; i++){
        temp.pb(idx%2);
        idx/=2;
    }
    for(int i=6; i>=0; i--) cout<<temp[i];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    for(int i=0; i<(1<<7); i++){
        bool flag=true;
        int temp=i;
        int cnt=0;
        while(temp!=0){
            if(temp%8==7) flag=false;
            if(temp%2==1) cnt++;
            temp=temp/2;
        }
        if(cnt>3) flag=false;
        valid[i]=flag;
        /*if(valid[i]){
            //prt(i);
            //cout<<endl;
        }*/
    }

    while(t--){
        string s;
        cin>>s;
        int n=s.size();
        for(int i=0; i<n; i++) fill(DP[i],DP[i]+128,0);
        DP[0][1]=s[0]-'a'+1;
        DP[0][0]=0;
        for(int i=1; i<n; i++){
            for(int j=0; j<128; j++){
                if(valid[j]){
                    if(valid[(j*2)%128+1]) DP[i][(j*2)%128+1]=max(DP[i][(j*2)%128+1],DP[i-1][j]+(s[i]-'a'+1));
                    if(valid[(j*2)%128]) DP[i][(j*2)%128]=max(DP[i][(j*2)%128],DP[i-1][j]);
                    /*
                    if(valid[(j*2)%128+1] &&  DP[i][(j*2)%128+1]!=0){
                        cout<<"idx DP val : "<<i<<' ';
                        prt((j*2)%128+1);
                        cout<<' '<<DP[i][(j*2)%128+1]<<endl;
                    }
                    if(valid[(j*2)%128] && DP[i][(j*2)%128]!=0){
                        cout<<"idx DP val : "<<i<<' ';
                        prt((j*2)%128);
                        cout<<' '<<DP[i][(j*2)%128]<<endl;
                    }
                    */
                }
            }
        }
        int mx=0;
        for(int i=0; i<(1<<7); i++) mx=max(mx,DP[n-1][i]);
        cout<<mx<<endl;
    }
    return 0;
}