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
	void push_front(T data);
	void pop_back(T data);
	void pop_front();
	void remove_at(int index);
	void insert(T data, int index);
	int get_size() const { return size; }

	void clear();
	T& operator[](const int index);
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
	clear();
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
		node* cur_node = this->head;
		while(cur_node->ptr_next != nullptr)
		{
			cur_node = cur_node->ptr_next;
		}
		cur_node->ptr_next = new node(data);
	}

	size++; // Увеличиваем size после добавления элемента
}

template <class T>
void my_list<T>::push_front(T data)
{
	head = new node(data, head);
	size++;
}

template <class T>
void my_list<T>::pop_back(T data)
{
	node* cur_node = this->head;

	for(int i = 0; i < size - 1; i++)
	{
		cur_node = cur_node->ptr_next;
	}
	delete cur_node->ptr_next;
	cur_node->ptr_next = nullptr;
}

template <class T>
void my_list<T>::insert(T data, int index)
{
	if(index == 0)
	{
		push_front(data);
	}
	else
	{
		node* previous = this->head;
		for(int i = 0; i < index - 1; i++)
		{
			previous = previous->ptr_next;
		}

		node* new_node = new node(data, previous->ptr_next);
		previous->ptr_next = new_node;
		size++;
	}
}


template <class T>
void my_list<T>::pop_front()
{
	//Запоминаем адресс головы
	node* temp = head;
	//голову задаем за вторую ноду
	head = head->ptr_next;
	//удаляем данные с прежней головы
	delete temp;
	size--;
}

template <class T>
void my_list<T>::remove_at(int index)
{
	if(index == 0)
	{
		pop_front();
	}
	else if(index == size - 1)
	{
		pop_back();
	}
	else
	{
		node* cur_node = this->head;
		for(int i = 0;i < index - 1;i++)
		{
			cur_node = cur_node->ptr_next;
		}
		node* temp = cur_node->ptr_next;
		cur_node->ptr_next = cur_node->ptr_next->ptr_next;
		delete temp;
		size--;
	}
}

template <class T>
void my_list<T>::clear()
{
	while(size)
	{
		pop_front();
	}
}

template <class T>
T& my_list<T>::operator[](const int index)
{
	int cur_index = 0;
	node* cur_node = this->head;
	while(cur_node != nullptr)
	{
		if(cur_index == index)
			return cur_node->data;
		cur_index++;
		cur_node = cur_node->ptr_next;
	}
}

int main()
{
	my_list<int> lst;
	lst.push_back(1);
	lst.push_back(11);
	lst.push_back(72);
	lst.insert(2, 2);
	for(int i = 0; i < lst.get_size(); i++)
	{
		std::cout << lst[i] << " ";
	}
	return 0;
}
