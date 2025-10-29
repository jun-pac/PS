
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define rep(i,b) rng(i,0,b-1)  
#define gnr(i,b,a) for(int i=int(b);i>=int(a);i--)
#define per(i,b) gnr(i,b-1,0)
#define pb push_back
#define eb emplace_back
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#define si(x) int(x.size())
template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;
typedef long long ll;
using pii=pair<int,int>;
using vi=vc<int>;
using uint=unsigned;
using ull=unsigned long long;
using pil=pair<int,ll>;
using pli=pair<ll,int>;
using pll=pair<ll,ll>;
using t3=tuple<int,int,int>;

#define N 3030
#define MOD 998244353
#define INF 100000000007 

array<ll,3> datas[N];
array<double,3> totsum;
array<double,3> avg;
ll sqsum;


double calc3(array<ll,3> a, array<ll,3> b, array<ll,3> c, int n){
    array<ll,3> x,y;
    rng(i,0,2) x[i]=b[i]-a[i];
    rng(i,0,2) y[i]=c[i]-a[i];
    array<ll,3> perp={x[1]*y[2]-x[2]*y[1],x[2]*y[0]-x[0]*y[2],x[0]*y[1]-x[1]*y[0]};
    // rng(j,0,2) cout<<perp[j]<<' ';
    // cout<<'\n';
    array<double,3> sumup={0,0,0};
    ll upcnt=0;
    rng(i,0,n-1){
        ll temp=0;
        rng(j,0,2) temp+=perp[j]*(datas[i][j]-a[j]);
        // cout<<"temp "<<temp<<'\n';
        if(temp>0){
            rng(j,0,2) sumup[j]+=datas[i][j];
            upcnt++;
        }
    }

    // two cases
    array<double,3> sumcur={0,0,0};
    rng(j,0,2) sumcur[j]=a[j]+b[j]+c[j];
    array<double,3> sumtemp;
    array<double,3> sumtemp2;
    double avgsum;
    double mn=INF;

    if(3+upcnt!=n){
        // cur included in upside
        rng(j,0,2) sumtemp[j]=sumup[j]+sumcur[j];
        rng(j,0,2) sumtemp2[j]=totsum[j]-sumtemp[j];
        avgsum=0;
        rng(j,0,2) avgsum+=(3+upcnt)*(sumtemp[j]/(3+upcnt))*(sumtemp[j]/(3+upcnt));
        rng(j,0,2) avgsum+=(n-3-upcnt)*(sumtemp2[j]/(n-3-upcnt))*(sumtemp2[j]/(n-3-upcnt));
        mn=min(mn,sqsum-avgsum);
    }
    if(upcnt!=0){
        // cur included in downside
        rng(j,0,2) sumtemp[j]=sumup[j];
        rng(j,0,2) sumtemp2[j]=totsum[j]-sumtemp[j];
        avgsum=0;
        rng(j,0,2) avgsum+=(upcnt)*(sumtemp[j]/(upcnt))*(sumtemp[j]/(upcnt));
        rng(j,0,2) avgsum+=(n-upcnt)*(sumtemp2[j]/(n-upcnt))*(sumtemp2[j]/(n-upcnt));
        mn=min(mn,sqsum-avgsum);
    }
    array<ll,3> sums[3];
    sums[0]=a;
    sums[1]=b;
    sums[2]=c;
    rng(i,0,2){
        // a in the upside
        rng(j,0,2) sumtemp[j]=sumup[j]+sums[i][j];
        rng(j,0,2) sumtemp2[j]=totsum[j]-sumtemp[j];
        avgsum=0;
        rng(j,0,2) avgsum+=(1+upcnt)*(sumtemp[j]/(1+upcnt))*(sumtemp[j]/(1+upcnt));
        rng(j,0,2) avgsum+=(n-1-upcnt)*(sumtemp2[j]/(n-1-upcnt))*(sumtemp2[j]/(n-1-upcnt));
        mn=min(mn,sqsum-avgsum);
    }

    rng(j,0,2) sums[0][j]=a[j]+b[j];
    rng(j,0,2) sums[1][j]=b[j]+c[j];
    rng(j,0,2) sums[2][j]=c[j]+a[j];
    rng(i,0,2){
        // a in the upside
        rng(j,0,2) sumtemp[j]=sumup[j]+sums[i][j];
        rng(j,0,2) sumtemp2[j]=totsum[j]-sumtemp[j];
        avgsum=0;
        rng(j,0,2) avgsum+=(2+upcnt)*(sumtemp[j]/(2+upcnt))*(sumtemp[j]/(2+upcnt));
        rng(j,0,2) avgsum+=(n-2-upcnt)*(sumtemp2[j]/(n-2-upcnt))*(sumtemp2[j]/(n-2-upcnt));
        mn=min(mn,sqsum-avgsum);
    }


    return mn;
}

void Solve(){
    int n,k;
    cin>>n>>k;
    sqsum=0;
    totsum={0,0,0};
    avg={0,0,0};

    rng(i,0,n-1){
        rng(j,0,2) cin>>datas[i][j];
        rng(j,0,2) sqsum+=datas[i][j]*datas[i][j];
        rng(j,0,2) totsum[j]+=datas[i][j]; 
    }

    // cout<<"sqsum: "<<sqsum<<", totsum: "<<totsum[0]<<' '<<totsum[1]<<' '<<totsum[2]<<'\n';
    

    double avgsq=0;
    rng(j,0,2){
        avgsq+=n*(totsum[j]/n)*(totsum[j]/n);
    }

    double mn=sqsum-avgsq;

    // cout<<"initmn: "<<mn<<'\n';
    if(k==2){
        
        // 1 and n-1
        rng(i,0,n-1){
            array<double,3> sumtemp={0,0,0};
            rng(j,0,2) sumtemp[j]=totsum[j]-datas[i][j];
            avgsq=0;
            rng(j,0,2) avgsq+=datas[i][j]*datas[i][j]+(n-1)*(sumtemp[j]/(n-1))*(sumtemp[j]/(n-1));
            mn=min(mn,sqsum-avgsq);
            // cout<<"1min: "<<sqsum-avgsq<<'\n';
        }

        // 2 and n-2
        if(n>=2){
            rng(i,0,n-1){
                rng(j,i+1,n-1){
                    array<double,3> sumtemp={0,0,0}, sumtemp2;
                    // cout<<"2ee "<<i<<' '<<j<<'\n';
                    rng(k,0,2) sumtemp[k]=datas[i][k]+datas[j][k];
                    // rng(k,0,2) cout<<sumtemp[k]<<' ';
                    // cout<<'\n';

                    rng(k,0,2) sumtemp2[k]=totsum[k]-sumtemp[k];
                    // rng(k,0,2) cout<<sumtemp2[k]<<' ';
                    // cout<<'\n';
                    avgsq=0;
                    rng(k,0,2) avgsq+=(n-2)*(sumtemp2[k]/(n-2))*(sumtemp2[k]/(n-2))+2*(sumtemp[k]/(2))*(sumtemp[k]/(2));
                    // cout<<"2min: "<<sqsum-avgsq<<'\n';
                    mn=min(mn,sqsum-avgsq);
                }
            }
        }

        if(n>=3){
            rng(i,0,n-1){
                rng(j,i+1,n-1){
                    rng(k,j+1,n-1){
                        // cout<<"ijk "<<mn<<' '<<calc3(datas[i],datas[j],datas[k],n)<<'\n';
                        mn=min(mn,calc3(datas[i],datas[j],datas[k],n));
                    }
                }
            }
        }
    }

    cout<<fixed;
    cout.precision(6);
    // mn=1.9999999;
    cout<<mn<<'\n';

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

