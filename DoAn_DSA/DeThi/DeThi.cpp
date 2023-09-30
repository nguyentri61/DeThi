#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#define MAX 100000
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
void AddTail(LinkedList& l, Node* node)
{
	if (l.head == NULL)
	{
		l.head = node;
		l.tail = node;
	}
	else
	{
		l.tail->next = node;
		l.tail = node;
	}
}
void RemoveHead(LinkedList& l,bool b)
{
	if (l.head != NULL)
	{
		Node* p = l.head;
		if (l.head == l.tail)
		{
			l.head = NULL;
			l.tail = NULL;
		}
		else
			l.head = l.head->next;
		if(b)
			delete p;
	}
	return;
}
void RemoveAfterQ(LinkedList& l, Node* q) {
	Node* p = q->next;
	if (l.head != NULL && p != NULL)
	{
		q->next = p->next;
		if (p == l.tail)
			l.tail = q;
		delete p;
	}
}
void Remove(LinkedList& l, int x)
{
	if (l.head != NULL)
	{
		if (l.head->data.stt == x) {
			RemoveHead(l,1);
			Node* q = l.head;
			while (q != NULL)
			{
				q->data.stt--;
				q = q->next;
			}
			return;
		}
		Node* q = l.head;
		while (q->next != NULL && q->next->data.stt != x)
			q = q->next;
		RemoveAfterQ(l, q);
		q = q->next;
		while (q != NULL)
		{
			q->data.stt--;
			q = q->next;
		}
	}
}
void DisplayQ(CauHoi q)
{
	cout << q.stt << ". " << q.question << "\n" << q.answer[0] << "\n" << q.answer[1] << "\n" << q.answer[2] << "\n" << q.answer[3] << "\n";
}
void DestroyList(LinkedList& l)
{
	Node* node = l.head;
	while (node != NULL)
	{
		RemoveHead(l,1);
		node = l.head;
	}
	l.tail = NULL;
}
class DeThi
{
private:
	LinkedList De;
	LinkedList Bo;
	int socau;
	int soCau[MAX] = { 0 };
	int soDeThi;
public:
	DeThi()
	{
		Bo.head = NULL;
		Bo.tail = NULL;
		De.head = NULL;
		De.tail = NULL;
		soDeThi = 0;
		socau = 0;
	}

	void Display(LinkedList l)
	{
		system("cls");
		Node* q = l.head;
		while (q != NULL)
		{
			DisplayQ(q->data);
			q = q->next;
		}
	}

	void Test()
	{
		int socauH=0;
		LayDe(socauH);
		system("cls");
		float diem = (float)10 / socauH, total = 0;
		if (socauH == 0)
		{
			cout << "Chua co de thi\n";
			return;
		}
		Node* q = De.head;
		while (q != NULL)
		{
			DisplayQ(q->data);
			string chon;
			while (chon != "A" && chon != "B" && chon != "C" && chon != "D") {
				cout << "Nhap dap an: ";
				cin >> chon;
			}
			if (chon == q->data.dapan)
				total += diem;
			system("cls");
			q = q->next;
		}
		DestroyList(De);
		cout << "Score: " << total << endl;
	}
	void TestLai() {
		int dethi;
		if (soDeThi == 0)
		{
			cout << "Chua lam de thi nao\n";
			return;
		}
		do {
			cout << "Nhap de thi muon lam lai: ";
			cin >> dethi;

		} while (dethi > soDeThi);
		string d = "De" + to_string(soDeThi) + ".txt";
		int socauH=0;
		docFile(d,socauH);
		system("cls");
		float diem = (float)10 / socauH, total = 0;
		if (socauH == 0)
		{
			cout << "Chua co de thi\n";
			return;
		}
		Node* q = De.head;
		while (q != NULL)
		{
			DisplayQ(q->data);
			string chon;
			while (chon != "A" && chon != "B" && chon != "C" && chon != "D") {
				cout << "Nhap dap an: ";
				cin >> chon;
			}
			if (chon == q->data.dapan)
				total += diem;
			system("cls");
			q = q->next;
		}
		DestroyList(De);
		cout << "Score: " << total << endl;
	}
	void docBo(int x)
	{
		int dem = 0;
		Node* p = new Node;
		while (dem < x)
		{
			p = Bo.head;
			RemoveHead(Bo,0);
			p->next = NULL;		
			AddTail(De, p);
			++dem;
			De.tail->data.stt = dem;
		}
		string namefile = "De" + to_string(soDeThi) + ".txt";
		fstream op(namefile, ios::out);
		Node* q = De.head;
		while (q != NULL)
		{
			op << q->data.question << "\n" << q->data.answer[0] << "\n" << q->data.answer[1] << "\n" << q->data.answer[2] << "\n" << q->data.answer[3] << "\n" << q->data.dapan;
			q = q->next;
			if (q != NULL)
				op << "\n";
		}
		op.close();
	}

	void LayDe(int& socauH)
	{
		soDeThi++;
		int x;
		cout << "1. Bo de 5 cau\n";
		cout << "2. Bo de 10 cau\n";
		cout << "3. Bo de 15 cau\n";
		cout << "4. Bo de 20 cau\n";
		cout << "Chon Bo De:\n";
		do
		{
			cin >> x;
		} while (x <= 0 || x >= 5);
		switch (x)
		{
			case 1: 
				docBo(5);
				socauH = 5;
				break;
			case 2: 
				docBo(10);
				socauH = 10;
				break;
			case 3:
				docBo(15);
				socauH = 15;
				break;
			case 4:
				docBo(20);
				socauH = 20;
				break;
		}
	}

	void docFullFile()
	{
		fstream ip("Bo.txt", ios::in);
		if (ip.fail())
		{
			cout << "Khong the mo file";
			exit(0);
		}

		while (true)
		{
			string x1, x2, x3, x4, x5, x6;
			getline(ip, x1);
			getline(ip, x2);
			getline(ip, x3);
			getline(ip, x4);
			getline(ip, x5);
			getline(ip, x6);
			Node* node = CreateNode(InitQ(x1, x2, x3, x4, x5, x6));
			socau++;
			node->data.stt = socau;
			AddTail(Bo, node);
			if (ip.eof())
				break;
		}
		ip.close();
	}
	void docFile(string s,int& socauH)
	{
		fstream ip(s, ios::in);
		if (ip.fail())
		{
			cout << "Khong the mo file";
			exit(0);
		}

		while (true)
		{
			string x1, x2, x3, x4, x5, x6;
			getline(ip, x1);
			getline(ip, x2);
			getline(ip, x3);
			getline(ip, x4);
			getline(ip, x5);
			getline(ip, x6);
			Node* node = CreateNode(InitQ(x1, x2, x3, x4, x5, x6));
			socauH++;
			node->data.stt = socauH;
			AddTail(De, node);
			if (ip.eof())
				break;
		}
		ip.close();
	}
	void xuatfile()
	{
		fstream op("DeThi.txt", ios::out);
		Node* q = De.head;
		while (q != NULL)
		{
			op << q->data.stt << ". " << q->data.question << "\n" << q->data.answer[0] << "\n" << q->data.answer[1] << "\n" << q->data.answer[2] << "\n" << q->data.answer[3] << "\n" << q->data.dapan << "\n";
			q = q->next;
		}
		op.close();
	}

	void XoaCauHoi() {
		//Display();
		if (socau == 0)
		{
			cout << "Chua co de thi\n";
			return;
		}
		cout << "Nhap cau hoi can xoa: ";
		int x;
		cin >> x;
		Remove(De, x);
		socau--;
		system("cls");
	}
	void ThemCauHoi()
	{
		cout << "Nhap cau hoi muon them: \n";
		string x1, x2, x3, x4, x5, x6;
		cout << "Nhap cau hoi: ";
		fflush(stdin);
		getline(cin, x1);
		cout << "Nhap cau tra loi: ";
		getline(cin, x2);
		getline(cin, x3);
		getline(cin, x4);
		getline(cin, x5);
		cout << "Nhap dap an: ";
		cin >> x6;
		Node* node = CreateNode(InitQ(x1, x2, x3, x4, x5, x6));
		socau++;
		node->data.stt = socau;
		AddTail(De, node);
	}

	void StartMenu()
	{
		docFullFile();
		while (true)
		{
			cout << "--------Mo Hinh Quan Ly De Thi--------\n";
			int Case;
			cout << "1. Xuat bo de\n";
			cout << "2. Thuc hien de thi \n";
			cout << "3. Thuc hien lai de thi da lam \n";
			cout << "4. Xoa cau hoi\n";
			cout << "5. Them cau hoi\n";
			cout << "6. Xuat de thi ra file\n";
			cout << "0. Thoat chuong trinh\n";
			cout << "--------------------------------------\n";
			cout << "Nhap lua chon: ";
			cin >> Case;
			switch (Case)
			{
				case 1:
				{
					Display(Bo);
					system("pause");
					system("cls");
					break;
				}
				case 2:
				{
					Test();
					system("pause");
					system("cls");
					break;
				}
				case 3:
				{
					TestLai();
					system("pause");
					system("cls");
					break;

				}
				case 4:
				{
					Display(De);
					XoaCauHoi();
					Display(De);
					system("pause");
					system("cls");
					break;
				}
				case 5:
				{
					Display(De);
					ThemCauHoi();
					Display(De);
					system("pause");
					system("cls");
					break;
				}
				case 6:
				{
					xuatfile();
					system("pause");
					system("cls");
					break;
				}
				case 0:
				{
					for (int i = 1; i <= soDeThi; i++)
					{
						string namefile = "De" + to_string(soDeThi) + ".txt";
						fstream op(namefile, ios::out,ios::trunc);
						op.close();
					}		
					exit(0);
				}
			}
		}
	}
};

int main()
{
	DeThi* dethi = new DeThi;
	//	dethi->docFile();
	//	dethi->Display();
	//	dethi->XoaCauHoi();
	//	dethi->ThemCauHoi();
	//	dethi->Display();	
	//	dethi->xuatfile();	
	//	dethi->Test();
	dethi->StartMenu();
}
