
#include <bits/stdc++.h>
using namespace std;

class node;

class pnode{
public:
	pnode(){
		pnext=NULL;
		pprev=NULL;
		pp=this;
	}
	pnode *pp;
	pnode *pnext, *pprev;
	node *firstnode;
	node *lastnode;
};

class node{
public:
	node(char val){
		parent=NULL;
		next=NULL;
		prev=NULL;
		this->val=val;
	}
	pnode *find_p(){
		while(parent!=parent->pp){
			parent=parent->pp;
		}
		return parent;
	}
	pnode *parent;
	node *next, *prev;
	char val;
};

node *cursor;
pnode* root;
pnode* tail;

void init(){
	root = new pnode();
	tail = new pnode();
	root->pnext=tail;
	tail->pprev=root;

	root->firstnode= new node('_');
	root->firstnode->parent=root;
	tail->firstnode= new node('_');
	tail->firstnode->parent=tail;
	tail->firstnode->prev=root->firstnode;
	root->firstnode->next=tail->firstnode;
	root->lastnode=root->firstnode;
	tail->lastnode=tail->firstnode;

	cursor=root->firstnode;
}

char putString(char mStr[]){
	int cur=0;

	while(cur<21 && mStr[cur]!='\0'){
		//cout<<"for debug "<<mStr[cur]<<endl;
		if(mStr[cur]=='R'){
			int num=mStr[cur+1]-'0';
			for(int i=0; i<num; i++){
				if(cursor->next!=tail->firstnode) cursor=cursor->next;
			}
			cur+=2;
		}
		else if(mStr[cur]=='L'){
			int num=mStr[cur+1]-'0';
			for(int i=0; i<num; i++){
				if(cursor!=root->firstnode) cursor=cursor->prev;
			}
			cur+=2;
		}
		else if(mStr[cur]=='F'){
			int num=mStr[cur+1]-'0';
			pnode* curp=cursor->parent; // '_'인 경우에는 앞에 붙는 구조이다.
			for(int i=0; i<num; i++){
				if(curp!=tail && curp->pnext!=tail) curp=curp->pnext;
			}
			cursor=curp->lastnode;
			cur+=2;
		}
		else if(mStr[cur]=='B'){
			int num=mStr[cur+1]-'0';
			pnode* curp=cursor->parent; // '_'인 경우에는 뒤에 붙어야 한다.
			if(cursor->val=='_') curp=curp->pnext;
			for(int i=0; i<num; i++){
				if(curp!=root && curp->pprev!=root) curp=curp->pprev;
			}
			cursor=curp->firstnode;
			cur+=2;
		}
		else if(mStr[cur]=='D'){
			int num=mStr[cur+1]-'0';
			node* s=cursor;
			node* e=s->next;
			for(int i=0; i<num; i++){
				if(e!=tail->firstnode) e=e->next;
			}
			node *snext=s->next;
			node *eprev=e->prev;
			pnode *sparent=s->parent;
			pnode *eparent=e->parent;
			// 사이를 모두 제거. cursor는 여전히 s. deallocate을 해야 하긴 하는데..
			s->next=e;
			e->prev=s;
			if(sparent!=eparent){
				if(s->val!='_' || e->val=='_'){
					// sparent는 남고, 그 뒤에 eparent까지 전부 제거해야 한다.
					sparent->pnext=eparent->pnext;
					eparent->pnext->pprev=sparent;
					if(s->val!='_' && e->val=='_'){
						sparent->lastnode=s;
					}
					else if(s->val!='_' && e->val!='_'){
						sparent->lastnode=eparent->lastnode;
					}
				}
				else{
					// sparent와 eparent는 남는다.
					eparent->pprev=sparent;
					sparent->pnext=eparent;
					eparent->firstnode=e;
				}
			}
			else{
				if(s->val!='_' && e->val=='_'){
					// 유일하게 lastnode가 바뀌는 경우
					sparent->lastnode = s;
				}
			}
			cur+=2;
		}
		else{
			int last=cur+1;
			while(last<21 && mStr[last]!='\0' && (('a'<=mStr[last] && mStr[last]<='z') || mStr[last]=='_')){
				last++;
			}
			cout<<"end "<<endl;
			// [cur, last-1]이 입력할 단어임
			for(int i=cur; i<last; i++){
				node *temp_next=cursor->next;
				cursor->next = new node(mStr[i]);
				cursor->next->next=temp_next;
				cursor->next->prev=cursor;
				temp_next->prev=cursor->next;
				cursor=cursor->next;

				if(mStr[i]=='_'){
					cursor->parent=cursor->prev->parent;
				}
				else{
					if(cursor->val=='_'){
						// 새로운 부모를 가져야 함. (부모노드를 추가)
						pnode *prevparent=cursor->prev->parent;
						pnode *nextparent=prevparent->pnext;
						prevparent->pnext=new pnode();
						cursor->parent=prevparent->pnext;
						prevparent->pnext->firstnode=cursor;
						cursor->parent->pprev=prevparent;
						cursor->parent->pnext=nextparent;
						nextparent->pprev=cursor->parent;
					}
					else{
						cursor->parent=cursor->prev->parent;
					}
				}
				if(cursor->val!='_' && cursor->next->val=='_'){
					cursor->parent->lastnode=cursor;
				}
			}
			cur=last;
		}
	}
	if(cursor->next==tail->firstnode) return '$';
	else return cursor->next->val;
	return '0';
}

char getWord(int mX){
	pnode *cur_pnode=root;
	for(int i=0; i<mX; i++){
		if(cur_pnode != tail) cur_pnode=cur_pnode->pnext;
	}
	if(cur_pnode != tail) return cur_pnode->firstnode->val;
	else return '$'; 
}




#define INIT	0
#define PUT		1
#define GET		2

static bool run()
{
	int cmd, mx;
	char ansc[5], retc;
	char str[21];

	int Q = 0;
	bool okay = false;

	scanf("%d", &Q);
	for (int q = 0; q < Q; ++q)
	{
		
		scanf("%d", &cmd);
		cout<<"deffwa "<<q<<' '<<cmd<<endl;
		switch (cmd)
		{
		case INIT:
			init();
			okay = true;
			break;

		case PUT:
			scanf("%s", str);
			cout<<"put "<<str<<endl;
			retc = putString(str);
			scanf("%s", ansc);
			if (ansc[0] != retc) {
				okay = false;
			}
			break;

		case GET:
			scanf("%d", &mx);
			retc = getWord(mx);
			scanf("%s", ansc);
			if (retc != ansc[0]) {
				okay = false;
			}
			break;

		default:
			okay = false;
		}
	}

	return okay;
}

int main()
{
	setbuf(stdout, NULL);
	freopen("sample_input.txt", "r", stdin);

	int T, MARK;
	scanf("%d %d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++)
	{
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}

	return 0;
}