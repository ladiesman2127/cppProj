
#include <cmath>
#include <iostream>

class component
{
private:
	std::string company_name;
public:
	component(std::string company_name)
	{
		this->company_name = company_name;
		std::cout << "ctor component\n";
	}
};

class gpu : public component
{
public:
	gpu(std::string company_name) : component(company_name)
	{
		std::cout << "ctor cpu\n";
	}
};

class memory : public component
{
public:
	memory(std::string company_name) : component(company_name)
	{
		std::cout << "ctor memory\n";
	}
};

class graph_card : public gpu, public memory
{
public:
	graph_card(std::string gpu_company_name, std::string memory_company_name) : gpu(gpu_company_name), memory(memory_company_name)
	{
		std::cout << "ctor graph_card\n";
	}
};



class pc
{
public:
	enum pc_state
	{
		ON,
		OFF,
		SLEEP
	};
	pc_state get_state() const
	{
		return state_;
	}
	void set_state(const pc_state state)
	{
		this->state_ = state;
	}
private:
	pc_state state_;
};
int main()
{
	pc pc1;
	pc1.set_state(pc::ON);
	pc1.set_state(pc::ON);
	pc1.set_state(pc::OFF);
	std::cout << pc1.get_state();

		return 0;
}

