
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

int datas[N];
// ���� ���� XOR�̶� �ڰ��, �տ��� ���� ���� ��ġ�� ���¿��� �ϰ�, ù 1�� �����ϴ� ������ �ִ��� �ڿ�.
// ��� �տ������� ���� ����� �� ã��.
// �� �̰� ���� trie�ƴѰ�?

// K=001001101
// A�� ��*ü�ؼ� K�� �Ǵ� ���� B=A^K
// �ٵ� ���� K'=000******, 001000***, 00100010**, 001001100 �� �� �۾����� �ĺ���
// �ִ� 31������ Ȯ���ϸ� �ȴ�.
// �̷� �͵��� �ִ����� trie�� ������ Ȯ�ΰ���.
// �̷� �͵��� ��� �ִ���? ���� ����� �� �������?
// ���̿� �ִ���? �� �˾ƾ� �ϴµ� ������...
// Mo's�� trie���ٰ� �ְ� ���� ����̸� �ȵǳ�?
// mx, mn�� �� �� ������ ���� � ������ ���� ����� �� ������� �𸣴� �� �翬�ϴϱ�
// �̰� small to large��? array�� �ǵ� upperbound, lowerbound�� ���� �ʳ�

// �̰� ������ ������ ������ �ƴ϶�, �� ���̿� �ٸ� ���ҵ��� ������ ����ų���� ����.
// �׳� ������ ���ҿ� ���ؼ� XOR�� K'�� �ϳ��� �Ǵ� ���� ����� ���̸� ã���� �� ��

// �̰� ��� trie�� �Ⱦ��� �����ؼ� lower upper bound�� ã���� �Ǵ°ű���
// �׸��� seg�� �¿� idx���ϰ�. �ƴѰ� 
// �ٵ� A^B in K' �̰� B^C in K'�̸� A^C in K'��
// 
// �״ϱ� trie�� ������ ������ �۰ų� ū ���� �ִ��� log n)^2���� �� �� ����.
// �ٵ� �����غ��ϱ� ������ �������� �̺�Ž���ؼ� �� �� ���� �ʳ�
// set���� �����ϸ� ���

int merge_seg[4*10000];
int l_bound[N], r_bound[N];

void Solve(){
    int n,k;
    cin>>n>>k;
    rng(i,0,n-1) cin>>datas[i];
    rng(i,0,n-1){
        rng(j,0,n-1){
            int temp=datas[i]^datas[j];
            if(temp==k){

            }
            else if(temp<k){
                
            }
        }
    }
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

