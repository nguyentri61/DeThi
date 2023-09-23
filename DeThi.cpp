#include <bits/stdc++.h>
using namespace std;
struct CauHoi
{
	int stt;
	string question;
	string answer[4];
	string dapan; 
};
CauHoi InitQ(string q, string a1, string a2, string a3, string a4, string d)
{
	CauHoi qs;
	qs.question = q;
	qs.answer[0] = a1;
	qs.answer[1] = a2;
	qs.answer[2] = a3;
	qs.answer[3] = a4;
	qs.dapan = d;
	return qs;
}
struct Node
{
	CauHoi data;
	Node* next;
};
Node* CreateNode(CauHoi init_data)
{
	Node* node = new Node;
	node->data = init_data;
	node->next = NULL;
	return node;
}	

struct LinkedList
{
	Node* head;
	Node* tail;
};
void AddTail(LinkedList& l,Node* node)
{	
	if(l.head==NULL)
	{
		l.head=node;
		l.tail=node;
	}
	else
	{
		l.tail->next=node;
		l.tail = node;
	}	
}
void RemoveHead(LinkedList& l)
{
	if(l.head != NULL)
	{
		Node *p =l.head;
		if(l.head==l.tail)
		{
			l.head=NULL;
			l.tail=NULL;
		}
		else
			l.head=l.head->next;
		delete p;
	}
	return;
}
void RemoveAfterQ(LinkedList& l,Node* q){
	Node* p=q->next;
	if(l.head!=NULL && p!=NULL)
	{
		q->next =p->next;
		if(p==l.tail)
			l.tail=q;
		delete p;
	}	
}
void Remove(LinkedList& l,int x)
{
	if(l.head!=NULL)
	{
		if(l.head->data.stt==x){
			RemoveHead(l);
			Node* q=l.head;
			while(q!=NULL)
			{
				q->data.stt--;
				q=q->next;
			}
			return;
		}
		Node* q =l.head;
		while(q->next!=NULL && q->next->data.stt != x)
			q=q->next;
			RemoveAfterQ(l,q);
		q=q->next;
		while(q!=NULL)
		{
			q->data.stt--;
			q=q->next;
		}	
	}	
}
void DisplayQ(CauHoi q)
{
	cout<<q.stt<<". "<<q.question<<"\n"<<q.answer[0]<<"\n"<<q.answer[1]<<"\n"<<q.answer[2]<<"\n"<<q.answer[3]<<"\n";
}
class DeThi
{	
private:
	LinkedList l;
	int socau;
public:
	DeThi()
	{
		l.head=NULL;
		l.tail=NULL;
		socau=0;
	}
	void Display()
	{
		system("cls");
		Node* q=l.head;
		while(q!=NULL)
		{			
			DisplayQ(q->data);
			q=q->next;
		}
		
	}	
	void Test()
	{
		system("cls");
		float diem=10/socau,total=0;
		Node* q=l.head;
		while(q!=NULL)
		{
			
			DisplayQ(q->data);
//			string chon;
//			while(chon !="A" && chon !="B"&& chon !="C"&& chon !="D"){
//				cout<<"Nhap dap an: ";
//				cin>>chon;
//			}
//			if(chon==q->data.dapan)
//				total+=diem;
//			system("cls"); 
			q=q->next;
		}
		cout<<"Score: "<<total;
	}	
	void docFile()
	{
		fstream ip("DeThi.txt", ios::in);
		if(ip.fail())
		{
			cout << "Khong the mo file";
			exit(0);
		}
		
		while(true)
		{
			string x1, x2, x3, x4, x5, x6;
			getline(ip, x1);
			getline(ip, x2);				
			getline(ip, x3);
			getline(ip, x4);
			getline(ip, x5);
			getline(ip, x6);
			Node* node=CreateNode(InitQ(x1, x2, x3, x4, x5, x6));
			socau++;
			node->data.stt=socau;
			AddTail(l,node);
			if(ip.eof())
				break;	
		}
		ip.close();
	}
	void xuatfile()
	{
		fstream op("DeThi.txt", ios::out);
		Node* q = l.head; 
		while(q != NULL)
		{
			op << q->data.stt << ". " << q->data.question << "\n" << q->data.answer[0] << "\n" << q->data.answer[1] << "\n" << q->data.answer[2] << "\n" << q->data.answer[3] << "\n" << q->data.dapan << "\n";
			q = q->next;
		}
		op.close();
	}
	void XoaCauHoi(){
		//Display();
		cout<<"Nhap cau hoi can xoa: ";
		int x;
		cin>>x;
		Remove(l,x);
		socau--;
		system("cls");
	}
	void ThemCauHoi()
	{
		cout << "Nhap cau hoi muon them: \n";
		string x1, x2, x3, x4, x5, x6;
		cout << "Nhap cau hoi: "; 
		getline(cin, x1);
		cout << "Nhap cau tra loi: "; 
		getline(cin, x2);
		getline(cin, x3);
		getline(cin, x4);
		getline(cin, x5);
		cout << "Nhap dap an: ";
		cin>>x6;
		Node* node=CreateNode(InitQ(x1, x2, x3, x4, x5, x6));
		socau++;
		node->data.stt=socau;
		AddTail(l,node);
	}	 
};
int main()
{
	DeThi* dethi= new DeThi;
	dethi->docFile();
//	dethi->Display();
//	dethi->XoaCauHoi();
//	dethi->ThemCauHoi();
//	dethi->Display();	
//	dethi->xuatfile();	
	dethi->Test();
}