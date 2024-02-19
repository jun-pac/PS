
#include <iostream>
using namespace std;

class node;

class pnode{
public:
	pnode(){
		pnext=NULL;
		pprev=NULL;
		pp=NULL;
	}
	pnode *pp=NULL;
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
	void update_p(){
		if(parent==NULL) return ;
		while(parent->pp!=NULL){
			parent=parent->pp;
		}
	}
	pnode *parent;
	node *next, *prev;
	char val;
};

node *cursor;
pnode* root;
pnode* tail;

void prt(){
	node* psd=root->firstnode->next;
	int cnt=0;
	while(psd!=tail->firstnode && cnt<50){
		cout<<(psd->val);
		psd=psd->next;
		cnt++;
	}
	cout<<' ';
	cout<<(cursor->next==tail->firstnode?'$':cursor->next->val)<<endl;
	psd=root->firstnode->next;
	cnt=0;
	while(psd!=tail->firstnode && cnt<50){
		psd->update_p();
		cout<<(psd->parent->firstnode->val);
		psd=psd->next;
		cnt++;
	}
	cout<<endl;
	psd=root->firstnode->next;
	cnt=0;
	while(psd!=tail->firstnode && cnt<50){
		psd->update_p();
		cout<<(psd->parent->lastnode->val);
		psd=psd->next;
		cnt++;
	}
	cout<<endl;
}


void init(){
	root = new pnode();
	tail = new pnode();
	root->pnext=tail;
	tail->pprev=root;

	root->firstnode= new node('_');
	root->firstnode->update_p();
	root->firstnode->parent = root;
	tail->firstnode= new node('_');
	tail->firstnode->update_p();
	tail->firstnode->parent = tail;
	tail->firstnode->prev=root->firstnode;
	root->firstnode->next=tail->firstnode;
	root->lastnode=root->firstnode;
	tail->lastnode=tail->firstnode;

	cursor=root->firstnode;
}

char putString(char mStr[]){
	int cur=0;
	//prt();
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
				//cout<<cursor->val<<endl;
				if(cursor!=root->firstnode) cursor=cursor->prev;
			}
			//cout<<"her"<<endl;
			cur+=2;
		}
		else if(mStr[cur]=='F'){
			int num=mStr[cur+1]-'0';
			cursor->update_p();
			pnode* curp=cursor->parent; // '_'�� ��쿡�� �տ� �ٴ� �����̴�.
			for(int i=0; i<num; i++){
				if(curp!=tail && curp->pnext!=tail) curp=curp->pnext;
			}
			cursor=curp->lastnode;
			cur+=2;
		}
		else if(mStr[cur]=='B'){
			int num=mStr[cur+1]-'0';
			cursor->update_p();
			pnode* curp=cursor->parent; // '_'�� ��쿡�� �ڿ� �پ�� �Ѵ�.
			if(cursor->val=='_') curp=curp->pnext;
			for(int i=0; i<num; i++){
				if(curp!=root && curp->pprev!=root) curp=curp->pprev;
			}
			cursor=curp->firstnode->prev;
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
			s->update_p();
			e->update_p();
			pnode *sparent=s->parent;
			pnode *eparent=e->parent;
			// ���̸� ��� ����. cursor�� ������ s. deallocate�� �ؾ� �ϱ� �ϴµ�..
			s->next=e;
			e->prev=s;
			if(sparent!=eparent){
				if(s->val!='_' || e->val=='_'){
					// sparent�� ����, �� �ڿ� eparent���� ���� �����ؾ� �Ѵ�.
					pnode *temp=sparent;
					while(temp!=eparent){
						if(temp!=sparent) temp->pp=sparent;
						temp=temp->pnext;
					}
					temp->pp=sparent;
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
					// sparent�� eparent�� ���´�.
					pnode *temp=sparent;
					while(temp!=eparent){
						if(temp!=sparent) temp->pp=sparent;
						temp=temp->pnext;
					}
					eparent->pprev=sparent;
					sparent->pnext=eparent;
					eparent->firstnode=e;
				}
			}
			else{
				if(s->val!='_' && e->val=='_'){
					// �����ϰ� lastnode�� �ٲ�� ���
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
			// [cur, last-1]�� �Է��� �ܾ���
			for(int i=cur; i<last; i++){
				node *temp_next=cursor->next;
				temp_next->update_p();
				node *reallast=temp_next->parent->lastnode;
				cursor->next = new node(mStr[i]);
				cursor->next->next=temp_next;
				cursor->next->prev=cursor;
				temp_next->prev=cursor->next;
				cursor=cursor->next;

				if(mStr[i]=='_'){
					cursor->update_p();
					cursor->prev->update_p();
					cursor->parent=cursor->prev->parent;
				}
				else{
					if(cursor->prev->val=='_' && cursor->next->val=='_'){
						// ���ο� �θ� ������ ��. (�θ��带 �߰�)
						cursor->prev->update_p();
						pnode *prevparent=cursor->prev->parent;
						pnode *nextparent=prevparent->pnext;
						prevparent->pnext=new pnode();
						cursor->update_p();
						cursor->parent = prevparent->pnext;
						cursor->parent->firstnode=cursor;
						cursor->parent->lastnode=cursor;
						cursor->parent->pprev=prevparent;
						cursor->parent->pnext=nextparent;
						nextparent->pprev=cursor->parent;
					}
					else if(cursor->prev->val=='_' && cursor->next->val!='_'){
						cursor->next->update_p();
						cursor->update_p();
						cursor->parent = cursor->next->parent;
						cursor->parent->firstnode = cursor;
					}
					else{
						cursor->update_p();
						cursor->prev->update_p();
						cursor->parent = cursor->prev->parent;
					}
				}
				if((i==last-1 && cursor->val!='_' && cursor->next->val=='_') || (i!=last-1 && mStr[i]!='_' && mStr[i+1]=='_')){
					cursor->update_p();
					reallast=cursor->parent->lastnode;
					cursor->parent->lastnode=cursor;
				}
				if(mStr[last-1]=='_'){
					cursor->next->update_p();
					if(cursor->next->parent->firstnode!=cursor->next){
						// ���ο� parent�� �������� ��.
						node* tcursor=cursor->next;
						tcursor->prev->update_p();
						pnode *prevparent=tcursor->prev->parent;
						pnode *nextparent=prevparent->pnext;
						prevparent->pnext=new pnode();
						tcursor->update_p();
						tcursor->parent = prevparent->pnext;
						tcursor->parent->firstnode=cursor;
						tcursor->parent->pprev=prevparent;
						tcursor->parent->lastnode=reallast;
						tcursor->parent->pnext=nextparent;
						nextparent->pprev=tcursor->parent;
						
					}
				}
			}
			cur=last;
		}
	}
	prt();
	//cout<<"answer : "<<(cursor->next==tail->firstnode?'$':cursor->next->val)<<endl;
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