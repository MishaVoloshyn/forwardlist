#include <iostream>
using namespace std;


struct Element
{
	// Данные
	char data;
	// Адрес следующего элемента списка
	Element* Next;
};

// Односвязный список
class List
{
	// Адрес головного элемента списка
	Element* Head;
	// Адрес головного элемента списка
	Element* Tail;
	// Количество элементов списка
	int Count;

public:
	// Конструктор
	List();
	// Деструктор
	~List();

	// Добавление элемента в список
	// (Новый элемент становится последним)
	void Add(char data);

	// Удаление элемента списка
	// (Удаляется головной элемент)
	void Del();
	// Удаление всего списка
	void DelAll();
	void InsertAt(int adress, char data);// вставка узла в определнное место
	void RemoveAt(int adress);//удаление узла из списка
	int Find(char data);
	// Распечатка содержимого списка
	// (Распечатка начинается с головного элемента)
	void Print();

	// Получение количества элементов, находящихся в списке
	int GetCount();
};

List::List()
{
	// Изначально список пуст
	Head = Tail = NULL;
	Count = 0;
}

List::~List()
{
	// Вызов функции удаления
	DelAll();
}



void List::Add(char data)
{
	// создание нового элемента
	Element* temp = new Element;

	// заполнение данными
	temp->data = data;
	// следующий элемент отсутствует
	temp->Next = NULL;
	// новый элемент становится последним элементом списка
	// если он не первый добавленный
	if (Head != NULL) {
		Tail->Next = temp;
		Tail = temp;
	}
	// новый элемент становится единственным
	// если он первый добавленный
	else {
		Head = Tail = temp;
	}
	Count++;
}

void List::Del()
{
	// запоминаем адрес головного элемента
	Element* temp = Head;
	// перебрасываем голову на следующий элемент
	Head = Head->Next;
	// удаляем бывший головной элемент
	delete temp;
}











void List::DelAll()
{
	// Пока еще есть элементы
	while (Head != 0)
		// Удаляем элементы по одному
		Del();
}

void List::Print()
{
	// запоминаем адрес головного элемента
	Element* temp = Head;
	// Пока еще есть элементы
	while (temp != 0)
	{
		// Выводим данные
		cout << temp->data << " ";
		// Переходим на следующий элемент
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
		// создание нового элемента
		Element* temp = new Element;

		// заполнение данными
		temp->data = data;
		// следующий элемент отсутствует
		temp->Next = Head;
		Head = temp;
		//Если счетчик равен 0 то мы и голове и хвосту присваиваем адресс на 1 обьект типо первый
		if (Count == 0)
		{
			Head = Tail;
		}
	}
	else {
		// создание нового элемента
		Element* temp = new Element;

		// заполнение данными
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
	// Возвращаем количество элементов
	return Count;
}

// Тестовый пример
void main()
{
	// Создаем объект класса List
	List lst;

	// Тестовая строка
	char s[] = "Hello, World !!!\n";
	// Выводим строку
	cout << s << "\n\n";
	// Определяем длину строки
	int len = strlen(s);
	// Загоняем строку в список
	for (int i = 0; i < len; i++)
		lst.Add(s[i]);

	lst.Print();
	cout << len <<"Dlina" << endl;
	lst.InsertAt(3, 'w');
	
	cout << endl;
	cout << endl;

	//Распечатываем содержимое списка
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
	// Распечатываем содержимое списка
//	lst.Print();
	// Удаляем три элемента списка
//	lst.Del();
//	lst.Del();
//	lst.Del();
	//Распечатываем содержимое списка
//	lst.Print();
}

