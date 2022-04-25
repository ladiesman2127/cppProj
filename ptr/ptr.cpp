
#include <memory>
#include <iostream>

//
//class point
//{
//public:
//	point()
//	{
//		x = y = z = 0;
//	}
//	point(int x, int y, int z)
//	{
//		this->x = x;
//		this->y = y;
//		this->z = z;
//	}
//private:
//	int x, y, z;
//};
//
//template <class T>
//class type_size
//{
//public:
//	type_size(T value)
//	{
//		data = value;
//	}
//	void data_size()
//	{
//		std::cout << sizeof(data);
//	}
//	T get_data()
//	{
//		return data;
//	}
//	const char* type_name()
//	{
//		return typeid(data).name();
//	}
//	void print(T value)
//	{
//		std::cout << value << '\n';
//	}
//protected:
//	T data;
//};
//
//
//template<>
//class type_size<std::string>
//{
//public:
//	type_size(std::string val)
//	{
//
//	}
//
//	static void print(const std::string& value)
//	{
//		std::cout << "________" << value << "________\n";
//	}
//};
//
//template <class T>
//class type_inf : public type_size<T>
//{
//public:
//
//	type_inf(T value) :type_size<T>(value)
//	{
//
//	}
//};

template <class T>
class smart_pointer
{
private:
	T* pointer_ = nullptr;
public:
	smart_pointer(T* pointer)
	{
		pointer_ = pointer;
	}

	~smart_pointer()
	{
		delete pointer_;
	}

	T& operator*()
	{
		return *pointer_;
	}
	T* operator+(const int value)
	{
		return (pointer_ + value);
	}
};

int main()
{
	//int* p = new int(22);
	//std::shared_ptr<int> s_ptr1(p);
	//std::shared_ptr<int> u_ptr2(s_ptr1);
	/*std::unique_ptr<int> u_ptr2 = std::move(u_ptr1);
	u_ptr2.swap(u_ptr1);
	std::cout << u_ptr1 << " " << u_ptr2 << '\n';
	int* raw_ptr = u_ptr1.get();
	delete raw_ptr;*/

	// reset: deleted all values and ptrs = 0
	// release: all data is not deleted ptrs = 0
	srand(time(nullptr));
	int size;
	std::cin >> size;
	std::shared_ptr<int[]> arr(new int[size]);
	for(int i = 0; i < size; i++)
	{
		arr[i] = rand() % 10;
	}
	for(int i = 0; i < size; i++)
	{
		std::cout << arr[i] << '\n';
	}
	return 0;
}