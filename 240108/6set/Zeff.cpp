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
        // sum�� ������ ����� ���� ū �ɷ�ġ���� �� �� �߻��ϴ� �� ���
        // datas[i][j]�� i��° ����� j��° �ɷ��� ������ ��, sum�������� �߰��� �߻��Ǵ� ���
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
        // ��� �� ���� ���������� �����ϱ� ���ؼ� i,j,k��° ����� ���� 0,1,2��° �ɷ��� �����ϵ��� ����. �� ���¿��� �ּҰ��� ���ϴ� ��.
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

