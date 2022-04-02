

#include <iostream>

class human
{
public:
	human(std::string name)
	{
		this->name_ = name;
		this->age_ = 0;
		this->weight_ = 0;
	}
	human(std::string name, unsigned int age) :human(name)
	{
		this->age_ = age;
	}
	human(std::string name, unsigned int age, unsigned int weight) :human(name, age)
	{
		this->weight_ = weight;
	}
private:
	std::string name_;
	unsigned int age_;
	unsigned int weight_;
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

	human h("Дезмонд", 27, 60);

}

