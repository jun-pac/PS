
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

#define N 100030
#define MOD 998244353
#define INF 1000000007 

class node{
public:
    map<int,int> mp;
    int offset=0;
    int mn; // offset�� �������� ���� mp�� value�� mn.
};

int datas[N];
vc<int> edges[N];
node DP[N];


void DFS2(int idx, int p, int cur){
    int mxidx=-1, mxsz=-1, mn=0;
    cur=cur^datas[idx];
    datas[idx]=0;
    for(auto next : edges[idx]){
        if(next!=p){
            DFS2(next,idx,cur);
            if((int)DP[next].mp.size()>mxsz) mxsz=DP[next].mp.size(), mxidx=next;
            mn+=DP[next].mn+1;
        }
    }
    if(edges[idx].size()==1 && idx!=0){
        datas[idx]=cur;
        DP[idx].mp[datas[idx]]=0;
        DP[idx].offset=0;
        DP[idx].mn=0;
        return;
    }
    swap(DP[idx],DP[mxidx]); // ���� DP[idx]�� Large��
    mn--; // mxidx�� ���ҵ��� �����Ѵٰ� �����غ�����. DP[idx].mn���ٰ��� 1�� ���� �ʿ䰡 ����.
    int newmn=mn;
    DP[idx].offset+=mn-DP[idx].mn; // �ٸ� subtree���� (mn+1)���� ��. // offset�� DP[idx].mp�� value�� �Ȱǵ�� ���� �����ۿ� ����.
    int ioff=DP[idx].offset;
    for(auto next : edges[idx]){
        if(next!=p && next!=mxidx){
            for(auto [k,v] : DP[next].mp){
                if(v+DP[next].offset!=DP[next].mn) continue;
                if(DP[idx].mp.find(k)!=DP[idx].mp.end()){ // large�� �ִ� �����̴�
                    // �� ���⿡�� ���� �߰ߵ� �����ε� DP[idx].mp���� ��Ű��� v���� ������ �������� �ֱ���
                    // �װ� ����� DP[idx].mn+1-value�� ���� ������ �Ǵ°ǵ� ������.
                    int temp=DP[idx].mp[k];
                    if(temp+ioff>mn){
                        // �̹� �湮�� �ߴٸ� ���� �� ���� ����,, ���� ���⸸ �� �Ŵϱ�
                        DP[idx].mp[k]=mn-ioff;
                    }
                    else{
                        DP[idx].mp[k]--;
                        newmn=min(newmn,temp-1+ioff);
                    }
                }               
                else{ // ���ο� ���Ҵ�
                    DP[idx].mp[k]=mn-ioff; // �ƴѰ�? mn���� ���� ������ ���� �� �����ʳ�? // ó�� �߰�, ��ġ�� �� ���ٴ� ����
                }
            }
        }
    }
    DP[idx].mn=newmn; // �� ���������� ���� ������ mn���� ����Ѵ�.
    // cout<<"REPORT "<<idx+1<<' '<<mxidx+1<<endl;
    // for(auto kv : DP[idx].mp){
    //     cout<<"( "<<kv.fi<<' '<<kv.se+DP[idx].offset<<" ) ";
    // }
    // cout<<endl;
    // cout<<"mn, offset "<<DP[idx].mn<<' '<<DP[idx].offset<<endl;
}

void Solve(){
    int n,a,b;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    rng(i,0,n-2){
        cin>>a>>b;
        a--, b--;
        edges[a].pb(b);
        edges[b].pb(a);
    }
    DFS2(0,-1,0);

    int res=INF;
    for(auto [k,v] : DP[0].mp){
        res=min(res,v+DP[0].offset+(k==0?0:1));
    }
    cout<<res<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    while(t--){
        Solve();    
    }
    return 0;
}

