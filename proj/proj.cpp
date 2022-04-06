
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


int main()
{

	graph_card("Nvidia", "Samsung");
	return 0;
}

