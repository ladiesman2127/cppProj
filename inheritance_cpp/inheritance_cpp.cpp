

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
class weapon
{
public:
	virtual void use() = 0;
};
class gun : public weapon
{
public:
	void use() override
	{
		std::cout << "Bang!\n";
	}
};
class sub_machine_gun : public gun
{
public:
	void use() override
	{
		std::cout << "Bang! Bang! Bang!\n";
	}
};
class bazzoka : public weapon
{
public:
	void use() override
	{
		std::cout << "BadaBum!\n";
	}
};
class knife : public weapon
{
public:
	void use() override
	{
		std::cout << "Pshick!\n";
	}
};

class player
{
public:
	void use(weapon* weapon)
	{
		weapon->use();
	}
};

class a
{
public:
	a()
	{
		
	}
	virtual ~a() = 0;
};

a::~a() {};
class b : public a
{
public:
	b()
	{
		
	}
	~b() override
	{
		
	}
};
int main()
{
	b b;


}

