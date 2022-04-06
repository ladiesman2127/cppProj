

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
class msg
{
private:
	std::string ms;
public:
	msg(std::string ms)
	{
		this->ms = ms;
	}
	virtual std::string get_msg()
	{
		return ms;
	}
};
class bracket_msg : public msg
{
public:
	bracket_msg(std::string ms) :msg(ms)
	{

	}
	std::string get_msg() override
	{
		return "[" + msg::get_msg() + "]";
	}

};
class printer
{
public:
	void print(msg* msg)
	{
		std::cout << msg->get_msg() << '\n';
	}
};
class car
{
public:
	car()
	{
		std::cout << "car ctor\n";
	}
	std::string str = "GG";
	void use()
	{
		std::cout << "Drive!\n";
	}
};
class plane
{
public:
	plane()
	{
		std::cout << "plane ctor\n";
	}
	std::string str = "ff";
	void use()
	{
		std::cout << "Fly!\n";
	}
};
class fly_car :public car, public plane
{
};


class i_bicycle
{
public:
	void virtual twist_wheel() = 0;
	void virtual ride() = 0;
};

class hum
{
public:
	void ride_on(i_bicycle &bicycle)
	{
		std::cout << "Крутим руль\n";
		bicycle.twist_wheel();
		std::cout << "Поехали\n";
		bicycle.ride();
	}
};

class simple_bicycle : public i_bicycle
{
public:
	void ride() override
	{
		std::cout << "sb ride\n";
	}
	void twist_wheel() override
	{
		std::cout << "sb twist\n";
	}
};
int main()
{
	setlocale(LC_ALL, "ru");
	simple_bicycle sb;
	hum human;
	human.ride_on(sb);

}

