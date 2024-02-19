#include <bits/stdc++.h>
using namespace std;
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define gnr(i,b,a) for(int i=int(b);i>=int(a);i--)
typedef long long ll;

#define N 100010
#define MOD 1000000007

ll datas[N];
ll sum[N];
ll backval[N][19]; // backval[i][j] is number of indicies that idx>=i and datas[idx]==val 
ll DP[N][19][19]; 
ll cnt[N][19];
// DP[i][j][k] is number of (idx1,idx2) pairs, S.T. i<=idx1<idx2 and sum[idx1]==tar+j-k, datas[idx2]==k
// Here, tar is half of total sum of datas.

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1){
        cin>>datas[i];
        sum[i]=(i==0?0:sum[i-1])+datas[i];
    }
    if(sum[n-1]%2==1){
        cout<<0<<'\n';
        return;
    }
    ll tar=sum[n-1]/2;
    rng(j,0,18) backval[n][j]=0;
    gnr(i,n-1,0){
        rng(j,0,18){
            backval[i][j]=(i==n-1?0:backval[i+1][j])+(datas[i]==j-9);
        }
    }
    gnr(i,n-1,0){
        rng(j,0,18){
            rng(k,0,18){
                DP[i][j][k]=(i==n-1?0:DP[i+1][j][k])+(sum[i]==tar+j-k?backval[i+1][k]:0);
            }
        }
    }
    
    ll res=0;
    // Case 1 : Array divided outside idx of swaped elements
    rng(i,0,n-1){
        rng(j,0,18) cnt[i][j]=(i==0?0:cnt[i-1][j])+(datas[i]==j-9);
    }
    rng(i,0,n-2){
        if(sum[i]==tar){
            res++;
            res+=(i+1)*(i)/2+(n-i-1)*(n-i-2)/2;
            rng(j,0,18){
                res-=cnt[i][j]*(cnt[i][j]-1)/2;
                res-=(cnt[n-1][j]-cnt[i][j])*(cnt[n-1][j]-cnt[i][j]-1)/2;
            }
        }
    }

    // Case 2 : Array divided between swaped elements
    rng(i,0,n-2){
        rng(val,-9,+9){ // Consider swap datas[i], datas[j](=val) S.T. i<j
            if(datas[i]==val) continue;
            // For all k(k>=i) that satisfy sum[0:k]=tar+datas[i]-val, add the number of j that j>k and val==datas[j]
            res+=DP[i][datas[i]+9][val+9];
        }
    }
    cout<<(res%MOD+MOD)%MOD<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

