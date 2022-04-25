#include <iostream>
#include <string>

template <class T>
class my_list
{
private:
	class node
	{
	public:
		node* ptr_next; // adress of next node
		T data;
		node(T data = T(), node* ptr_next = nullptr) 
		{
			this->data = data;
			this->ptr_next = ptr_next;
		}

	};
	node* head; // head(main) node
	int size;
public:
	my_list();
	~my_list();
	void push_back(T data);
	int get_size() { return size; }
};

template <class T>
my_list<T>::my_list()
{
	size = 0;
	head = nullptr;
}

template <class T>
my_list<T>::~my_list()
{
		
}

template <class T>
void my_list<T>::push_back(T data)
{

	//Сначала проверяем есть ли хоть какой-то элеменет в листе
	//Если их нет, создаем и сразу же присваиваем его адрес голове
	//В ином случае, создаем указатель типа Node,который изначально равен голове
	//Если он равен нулю, присваиваем ему новую Nod'у
	//Иначе просто перебираем все Nod'ы, пока не найдем последнюю
	if(head == nullptr)
	{
		head = new node(data);
	}
	else
	{
		node* current = this->head ;
		while(current->ptr_next != nullptr)
		{
			current = current->ptr_next;
		}
		current->ptr_next = new node(data);
	}

	size++; // Увеличиваем size после добавления элемента
}

int main()
{
	my_list<int> lst;
	lst.push_back(1);
	lst.push_back(11);
	lst.push_back(72);
	return 0;
}