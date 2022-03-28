

#include <iostream>

class human
{
private:
	std::string name;
public:
	std::string get_name()
	{
		return name;
	}
	void set_name(std::string name)
	{
		this->name = name;
	}
};
class student : public human
{
public:
	std::string group;
	void learn()
	{
		std::cout << "Я учусь\n";
	}
};
class extramural_student : public student
{
public:
	void learn()
	{
		std::cout << "Я учусь заочно\n";
	}
};
class teacher : public human
{
public:

	std::string subject;
};
int main()
{
	setlocale(LC_ALL, "ru");
	student st;
	
	st.learn();
	extramural_student ex_st;
	ex_st.learn();

}

