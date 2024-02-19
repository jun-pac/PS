#include <bits/stdc++.h>
using namespace std;
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define gnr(i,b,a) for(int i=int(b);i>=int(a);i--)
#define N 101
#define INF 1000000007 

int datas[N][3];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    cin>>t;
    rng(tt,1,t){
        int n, sum=0;
        // sum은 각각의 요원이 가장 큰 능력치만을 고를 때 발생하는 총 비용
        // datas[i][j]는 i번째 요원이 j번째 능력을 공유할 때, sum에서부터 추가로 발생되는 비용
        cin>>n;
        rng(i,0,n-1){
            int mx=0;
            rng(j,0,2){
                cin>>datas[i][j];
                mx=max(mx,datas[i][j]);
                sum+=datas[i][j];
            }
            sum-=mx;
            rng(j,0,2) datas[i][j]=mx-datas[i][j];
        }
        

        if(n<=2){
            cout<<"#"<<tt<<' '<<-1<<'\n';
            continue;
        }
        // 적어도 한 번씩 공유받음을 강제하기 위해서 i,j,k번째 요원은 각각 0,1,2번째 능력을 공유하도록 강요. 그 상태에서 최소값을 구하는 것.
        int mn=INF;
        rng(i,0,n-1){
            rng(j,0,n-1){
                if(i==j) continue;
                rng(k,0,n-1){
                    if(k==i || k==j) continue;
                    mn=min(mn,datas[i][0]+datas[j][1]+datas[k][2]);
                }
            }
        }
        cout<<"#"<<tt<<' '<<mn+sum<<'\n';
    }
    return 0;
}

