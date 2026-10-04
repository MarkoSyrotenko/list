#include <iostream>
using namespace std;


/*
Добавить в класс "Односвязный список" следующие функции:
 вставка элемента в заданную позицию,
+ удаление элемента по заданной позиции,
поиск заданного элемента (функция возвращает позицию найденного элемента в случае успеха или NULL в случае неудачи).
*/
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

	// Распечатка содержимого списка
	// (Распечатка начинается с головного элемента)
	void Print();

	// Получение количества элементов, находящихся в списке
	int GetCount();

	void AddPos(char data, int pos);
	void DelPos(int pos);
	int Search(char data);
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

int List::GetCount()
{
	// Возвращаем количество элементов
	return Count;
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
	Count--;
}

void List::DelAll()
{
	// Пока еще есть элементы
	while (Head != 0)
		// Удаляем элементы по одному
		Del();
	Count = 0;
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

void List::AddPos(char data, int pos)
{
	
	if (pos == Count) 
	{
		Add(data);
		return;
	}
	if (pos <0 || pos >= Count) 
	{
		return;
	}
	// создание нового элемента
	Element* temp = new Element;
	// заполнение данными
	temp->data = data;

	if (pos>0)
	{
		Element* tempprev = Head;
		for (int i = 0; i < pos - 1; i++)
		{
			// Переходим на следующий элемент
			tempprev = tempprev->Next;
		}
		temp->Next = tempprev->Next;
		tempprev->Next = temp;
	}
	else
	{
		temp->Next = Head;
		Head = temp;
	}
	Count++;
}

void List::DelPos(int pos)
{
	if (pos == 0)
	{
		Del();
		return;
	}
	if (pos <= 0 || pos >= Count)
	{
		return;
	}
	
	Element* temp = NULL;

	Element* tempprev = Head;
	for (int i = 0; i < pos - 1; i++)
	{
		// Переходим на следующий элемент
		tempprev = tempprev->Next;
	}
	temp = tempprev->Next;

	if (temp == Tail)
	{
		
		tempprev->Next = NULL;
		Tail = tempprev;
	}
	else
	{
		tempprev->Next = temp->Next;
	}
	delete temp;
	Count++;
}

int List::Search(char data)
{
	Element* temp = Head;
	for (int i = 0; i < Count; i++)
	{
		if (temp->data == data)
		{
			return i;
		}
		temp = temp->Next;
	}
	return NULL;
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
	// Распечатываем содержимое списка
	lst.Print();
	// Удаляем три элемента списка
	lst.Del();
	lst.Del();
	lst.Del();
	//Распечатываем содержимое списка
	lst.Print();
	lst.AddPos('H', 0);
	lst.AddPos('e', 1);
	lst.AddPos('l', 2);



	lst.Print();
	cout << "W is at " << lst.Search('W') << "\n\n";
	lst.DelPos(7);
	lst.DelPos(8);
	lst.Print();
}
