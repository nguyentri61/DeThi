#include <bits/stdc++.h>
using namespace std;
struct CauHoi
{
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

void DisplayQ(CauHoi q)
{
	cout<<q.question<<"\n"<<q.answer[0]<<"\n"<<q.answer[1]<<"\n"<<q.answer[2]<<"\n"<<q.answer[3]<<"\n";
}
class DeThi
{	
private:
	LinkedList l;
public:
	DeThi()
	{
		l.head=NULL;
		l.tail=NULL;
	}
	void Display()
	{
		Node* q=l.head;
		while(q!=NULL)
		{
			DisplayQ(q->data);
//			char chon;
//			cout<<"Nhap dap an: ";
//			cin>>chon;
//			if(chon==q->data.dapan[0])
//				cout<<"Dung";
//			else 
//				cout<<"Sai";
			q=q->next;
		}
	}		
	void AddTail(Node* node)
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
//			cout << x1 << "\n";
			Node* node=CreateNode(InitQ(x1, x2, x3, x4, x5, x6));
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
			if(ip.eof())
				break;	
		}
		ip.close();
	}
	
};

int main()
{
	
	DeThi* dethi= new DeThi;
	LinkedList list;
	dethi->docFile();
//	dethi->AddTail(node);
	dethi->Display();

			
}