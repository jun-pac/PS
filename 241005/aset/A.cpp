
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

#define N 300030
#define MOD 998244353
#define INF 1000000007 
random_device rd; 
mt19937 gen(rd());
uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)


int state[1001]; // �ϴ� counter�ΰ� 1�� ������
vc<int> ans; // counter
vc<vc<int>> DP, nDP; // currently managing sets

void Solve(){
    int n,m,q;
    cin>>n>>m>>q;
    // n=1000, m=10, q=950
    // m=10 output(idx of counter)
    int res, cnt=0;
    state[0]=0;
    rng(i,1,20){
        cout<<"? "<<1<<' '<<i+1<<endl;
        cin>>res;
        assert(res!=-1);
        if(res==0) state[i]=0;
        if(res==1){
            state[i]=1;
            cnt++;
        }
    }
    if(cnt>10){ // 1�� �����δ� ����
        rng(i,0,20) state[i]=1-state[i];    
    } 
    rng(i,0,20) if(state[i]==1) ans.pb(i);

    if((int)ans.size()==m){
        cout<<"! ";
        rng(i,0,m-1) cout<<ans[i]+1<<' ';
        cout<<endl;
        return;   
    }
    
    // ���� 0~20������ �ùٸ� state
    rng(i,21,n-1){
        vc<int> temp;
        temp.pb(i);
        DP.pb(temp);
    }
    
    while(true){
        if(DP.empty()) break;
        nDP.clear();
        int DPsz=DP.size();
        for(int k=0; k<=DPsz-2; k+=2){
            cout<<"? "<<DP[k][0]+1<<' '<<DP[k+1][0]+1<<endl;
            cin>>res;
            assert(res!=-1);
            if(res==0){
                // �̵��� ���ļ� �ִ´�.
                if((int)DP[k].size()+(int)DP[k+1].size()+(int)ans.size()<=m){ // �̰ź��� ū �༮�� ���ʿ� �ĺ��� �ƴ� 
                    vc<int> temp;
                    rng(i,0,(int)DP[k].size()-1) temp.pb(DP[k][i]);
                    rng(i,0,(int)DP[k+1].size()-1) temp.pb(DP[k+1][i]);
                    nDP.pb(temp);
                }
            }
            else{
                // �� �� �ϳ��� �ٸ�.
                cout<<"? "<<1<<' '<<DP[k][0]+1<<endl;
                cin>>res;
                assert(res!=-1);
                if(res!=state[0]){
                    // DP[k]�� �ϴ� ������
                    rng(i,0,(int)DP[k].size()-1) ans.pb(DP[k][i]);
                }
                else{
                    // DP[k+1]�� �� ������
                    rng(i,0,(int)DP[k+1].size()-1) ans.pb(DP[k+1][i]);
                }
                if((int)ans.size()>=m) break;
            }
        } 
        if(DPsz%2==1){
            // ���� �ϳ��� ���´�.
            cout<<"? "<<1<<' '<<DP[DPsz-1][0]+1<<endl;
            cin>>res;
            assert(res!=-1);
            if(res!=state[0]) rng(i,0,(int)DP[DPsz-1].size()-1) ans.pb(DP[DPsz-1][i]);
        }
        if((int)ans.size()>=m) break;
        if((int)nDP.size()==0) break;
        DP=nDP;
        // 10���� ū �༮�� ����� ������� �ʴ´�.
        // ������ ans.size()>=10 �̸� break;
    }
    assert((int)ans.size()==m);
    cout<<"! ";
    rng(i,0,m-1) cout<<ans[i]+1<<' ';
    cout<<endl;

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

