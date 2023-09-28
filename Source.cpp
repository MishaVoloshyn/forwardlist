#include <iostream>
using namespace std;


struct Element
{
	// ������
	char data;
	// ����� ���������� �������� ������
	Element* Next;
};

// ����������� ������
class List
{
	// ����� ��������� �������� ������
	Element* Head;
	// ����� ��������� �������� ������
	Element* Tail;
	// ���������� ��������� ������
	int Count;

public:
	// �����������
	List();
	// ����������
	~List();

	// ���������� �������� � ������
	// (����� ������� ���������� ���������)
	void Add(char data);

	// �������� �������� ������
	// (��������� �������� �������)
	void Del();
	// �������� ����� ������
	void DelAll();
	void InsertAt(int adress, char data);// ������� ���� � ����������� �����
	void RemoveAt(int adress);//�������� ���� �� ������
	int Find(char data);
	// ���������� ����������� ������
	// (���������� ���������� � ��������� ��������)
	void Print();

	// ��������� ���������� ���������, ����������� � ������
	int GetCount();
};

List::List()
{
	// ���������� ������ ����
	Head = Tail = NULL;
	Count = 0;
}

List::~List()
{
	// ����� ������� ��������
	DelAll();
}



void List::Add(char data)
{
	// �������� ������ ��������
	Element* temp = new Element;

	// ���������� �������
	temp->data = data;
	// ��������� ������� �����������
	temp->Next = NULL;
	// ����� ������� ���������� ��������� ��������� ������
	// ���� �� �� ������ �����������
	if (Head != NULL) {
		Tail->Next = temp;
		Tail = temp;
	}
	// ����� ������� ���������� ������������
	// ���� �� ������ �����������
	else {
		Head = Tail = temp;
	}
	Count++;
}

void List::Del()
{
	// ���������� ����� ��������� ��������
	Element* temp = Head;
	// ������������� ������ �� ��������� �������
	Head = Head->Next;
	// ������� ������ �������� �������
	delete temp;
}











void List::DelAll()
{
	// ���� ��� ���� ��������
	while (Head != 0)
		// ������� �������� �� ������
		Del();
}

void List::Print()
{
	// ���������� ����� ��������� ��������
	Element* temp = Head;
	// ���� ��� ���� ��������
	while (temp != 0)
	{
		// ������� ������
		cout << temp->data << " ";
		// ��������� �� ��������� �������
		temp = temp->Next;
	}

	cout << "\n\n";
}

void List::InsertAt(int adress, char data)
{
	if (adress > Count || adress < 0)
	{
		cout << "Error adress" << endl;
	}
	else if (adress == Count)
	{
		Add(data);
	}
	else if (adress == 0)
	{
		// �������� ������ ��������
		Element* temp = new Element;

		// ���������� �������
		temp->data = data;
		// ��������� ������� �����������
		temp->Next = Head;
		Head = temp;
		//���� ������� ����� 0 �� �� � ������ � ������ ����������� ������ �� 1 ������ ���� ������
		if (Count == 0)
		{
			Head = Tail;
		}
	}
	else {
		// �������� ������ ��������
		Element* temp = new Element;

		// ���������� �������
		temp->data = data;

		Element* temp2 = Head;
		
		for (int i = 0; i < adress-1; i++)
		{
			temp2 = temp2->Next;
		}
		temp->Next = temp2->Next;
		temp2->Next = temp;
	}
	Count++;
}

void List::RemoveAt(int adress)
{
	Element* temp = Head;
	while (adress > 2)
	{
		temp = temp->Next;
		adress--;
	}
	Element* del = temp->Next;
	temp->Next = del->Next;
	delete del;
}

int List::Find(char data)
{
	Element* temp = Head;
	int adress = 0;
	while (temp!=NULL)
	{
		if (temp->data == data)
		{
			return adress;
		}
		temp = temp->Next;
		adress++;
	}
	return -2;
}
int List::GetCount()
{
	// ���������� ���������� ���������
	return Count;
}

// �������� ������
void main()
{
	// ������� ������ ������ List
	List lst;

	// �������� ������
	char s[] = "Hello, World !!!\n";
	// ������� ������
	cout << s << "\n\n";
	// ���������� ����� ������
	int len = strlen(s);
	// �������� ������ � ������
	for (int i = 0; i < len; i++)
		lst.Add(s[i]);

	lst.Print();
	cout << len <<"Dlina" << endl;
	lst.InsertAt(3, 'w');
	
	cout << endl;
	cout << endl;

	//������������� ���������� ������
	lst.Print();
	//cout << len << "Dlina" << endl;

	int nomer;

	nomer = lst.Find('t');

	if (nomer == -2)
	{
		cout << "Error";
	}
	else {
		cout << "nomer" << nomer;
	}
	// ������������� ���������� ������
//	lst.Print();
	// ������� ��� �������� ������
//	lst.Del();
//	lst.Del();
//	lst.Del();
	//������������� ���������� ������
//	lst.Print();
}

