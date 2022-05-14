#include <iostream>
#include <string>

#pragma once region single_linked_list  // NOLINT(clang-diagnostic-pragma-once-outside-header, clang-diagnostic-extra-tokens)
template <class T>
class single_linked_list
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
	single_linked_list();
	~single_linked_list();
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
single_linked_list<T>::single_linked_list()
{
	size = 0;
	head = nullptr;
}

template <class T>
single_linked_list<T>::~single_linked_list()
{
	clear();
}

template <class T>
void single_linked_list<T>::push_back(T data)
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
void single_linked_list<T>::push_front(T data)
{
	head = new node(data, head);
	size++;
}

template <class T>
void single_linked_list<T>::pop_back(T data)
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
void single_linked_list<T>::insert(T data, int index)
{
	if(index == 0)
	{
		push_front(data);
	}
	else if(index == size - 1)
	{
		push_back(data);
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
void single_linked_list<T>::pop_front()
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
void single_linked_list<T>::remove_at(int index)
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
		for(int i = 0; i < index - 1; i++)
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
void single_linked_list<T>::clear()
{
	while(size)
	{
		pop_front();
	}
}

template <class T>
T& single_linked_list<T>::operator[](const int index)
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
	return {};
}

#pragma endregion

#pragma region double_linked_list

template <class T> // done!
class double_linked_list
{
private:
	class node
	{
	public:
		node(T data = T(), node* ptr_next = nullptr, node* ptr_prev = nullptr)
		{
			this->data = data;
			this->ptr_next = ptr_next;
			this->ptr_prev = ptr_prev;
		}
		node* ptr_next;
		node* ptr_prev;
		T data;
	};
	node* head_;
	node* tail_;
	int size;
public:
	double_linked_list();
	~double_linked_list();
	T& operator[](int index);
	int get_size() const { return size; }
	void push_back(T data);
	void push_front(T data);
	void pop_back();
	void pop_front();
	void insert(int index, T data);
	void remove_at(int index);
	void clear();
};

template <class T> //done
double_linked_list<T>::double_linked_list()
{
	size = 0;
	head_ = nullptr;
	tail_ = nullptr;
}

template <class T> //done
double_linked_list<T>::~double_linked_list()
{
	clear();
}

template <class T> //done
void double_linked_list<T>::push_back(T data)
{
	if(head_ == nullptr)
	{
		head_ = new node(data);
		tail_ = head_;
	}
	else
	{
		node* cur_node = head_;
		while(cur_node->ptr_next != nullptr)
		{
			cur_node = cur_node->ptr_next;
		}
		cur_node->ptr_next = new node(data);
		tail_ = cur_node->ptr_next;
		tail_->ptr_prev = cur_node;
	}
	size++;
}

template <class T> //done
void double_linked_list<T>::push_front(T data)
{
	if(head_ == nullptr)
	{
		head_ = new node(data);
		tail_ = head_;
	}
	else
	{
		if(size == 1)
		{
			tail_ = head_;
		}
		head_ = new node(data, head_);
		head_->ptr_next->ptr_prev = head_;
	}
	size++;
}

template <class T>	// done
void double_linked_list<T>::pop_back()
{
	if(size == 1)
	{
		delete tail_;
	}
	else
	{
		tail_ = tail_->ptr_prev;
		delete  tail_->ptr_next;
	}
	size--;
}

template <class T> //done
void double_linked_list<T>::pop_front()
{
	if(size == 1)
	{
		delete head_;
	}
	else
	{
		head_ = head_->ptr_next;
		delete head_->ptr_prev;
	}
	size--;
}

template <class T> //done
void double_linked_list<T>::insert(int index, T data)
{
	if(index == 0)
	{
		push_front(data);
	}
	else
	{
		node* prev_node;
		int cur_index;
		if(index >= size / 2)
		{
			cur_index = size - 1;
			prev_node = tail_;
			while(cur_index != index - 1)
			{
				prev_node = prev_node->ptr_prev;
				cur_index--;
			}
		}
		else
		{
			cur_index = 0;
			prev_node = head_;
			while(cur_index != index - 1)
			{
				prev_node = prev_node->ptr_next;
				cur_index++;
			}
		}
		node* new_node = new node(data, prev_node->ptr_next, prev_node);
		prev_node->ptr_next = new_node;
		new_node->ptr_next->ptr_prev = new_node;
		size++;
	}
}

template <class T> // done
void double_linked_list<T>::remove_at(int index)
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
		node* prev_node;
		int cur_index;
		if(index >= size / 2)
		{
			cur_index = size - 1;
			prev_node = tail_;
			while(cur_index != index - 1)
			{
				prev_node = prev_node->ptr_prev;
				cur_index--;
			}
		}
		else
		{
			cur_index = 0;
			prev_node = head_;
			while(cur_index != index - 1)
			{
				prev_node = prev_node->ptr_next;
				cur_index++;
			}
		}
		node* remove_node = prev_node->ptr_next;
		prev_node->ptr_next = remove_node->ptr_next;
		remove_node->ptr_next->ptr_prev = prev_node;
		delete remove_node;
		size--;
	}
}

template <class T> //done
void double_linked_list<T>::clear()
{
	while(size != 0)
		pop_back();
}

template <class T> //done
T& double_linked_list<T>::operator[](const int index)
{
	node* cur_node;
	int cur_index;
	if(index >= size / 2)
	{
		cur_node = tail_;
		cur_index = size - 1;
		while(cur_index != index)
		{
			cur_node = cur_node->ptr_prev;
			cur_index--;
		}
	}
	else
	{
		cur_node = head_;
		cur_index = 0;
		while(cur_index != index)
		{
			cur_node = cur_node->ptr_next;
			cur_index++;
		}
	}
	return cur_node->data;
}

#pragma endregion

#pragma once region binary_tree 
template <class T> //done
class tree
{
private:
	int size_;
	class node
	{
	public:
		T data;
		node* left;
		node* right;
		node(T data = T(), node* left = nullptr, node* right = nullptr)
		{
			this->data = data;
			this->left = left;
			this->right = right;
		}
	};
	node* root_;
public:
	tree();
	~tree();
	void add(T data);
	bool is_contain(T check_data);
};

template <class T> //done
tree<T>::tree()
{
	size_ = 0;
	root_ = nullptr;
}

template <class T>
tree<T>::~tree()
= default;

template <class T> //done
void tree<T>::add(T data)
{
	if(root_ == nullptr)
	{
		root_ = new node(data);
	}
	else
	{
		node* cur_node = root_;
		while(cur_node->left != nullptr && data < cur_node->data ||
			  cur_node->right != nullptr && data > cur_node->data)
		{
			if(data < cur_node->data)
			{
				cur_node = cur_node->left;
			}
			else if(data > cur_node->data)
			{
				cur_node = cur_node->right;
			}
		}
		if(data < cur_node->data)
			cur_node->left = new node(data);
		else
			cur_node->right = new node(data);
	}
	size_++;
}


template <class T> //done
bool tree<T>::is_contain(T check_data)
{
	node* cur_node = root_;
	while(cur_node->data != check_data)
	{
		if(check_data < cur_node->data && cur_node->left == nullptr ||
		   check_data > cur_node->data && cur_node->right == nullptr)
			return false;
		if(check_data > cur_node->data)
		{
			cur_node = cur_node->right;
		}
		else
		{
			cur_node = cur_node->left;
		}
	}
	return true;
}

#pragma endregion
int main()
{
#pragma once region ...
	/*single_linked_list<int> lst;
	lst.push_back(1);
	lst.push_back(11);
	lst.push_back(72);
	lst.insert(2, 2);
	for(int i = 0; i < lst.get_size(); i++)
	{
		std::cout << lst[i] << " ";
	}*/

	/*double_linked_list<int> dbl_list;
	dbl_list.push_front(1);
	dbl_list.push_front(2);
	dbl_list.push_front(-9);
	dbl_list.push_front(44);
	dbl_list.push_front(24);
	dbl_list.push_back(4);
	std::cout << dbl_list.get_size() << '\n';
	dbl_list.insert(dbl_list.get_size() -1 , 0);
	dbl_list.remove_at(3);
	dbl_list.remove_at(0);
	dbl_list.remove_at(0);
	dbl_list.remove_at(0);
	dbl_list.remove_at(0);
	dbl_list.remove_at(0);
	dbl_list.remove_at(0);
	for(auto i = 0; i < dbl_list.get_size(); i++)
	{
		std::cout << dbl_list[i] << " ";
	}*/
	//std::cout << dbl_list.get_size() << '\n';

	/*tree<int> my_tree;
	my_tree.add(72);
	my_tree.add(9);
	my_tree.add(0);
	my_tree.add(-1);
	my_tree.add(122);
	my_tree.add(143);
	std::cout << my_tree.is_contain(-2);*/
#pragma endregion

	return 0;
}
