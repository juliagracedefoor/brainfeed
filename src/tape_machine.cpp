// tape_machine.cpp defines a class for evaluating brainfuck commands by manipulating state

#include "tape_machine.hpp"
#include <cstdio>
#include <stdexcept>

const std::string bf::tape_machine::symbols = "><+-.,";
const std::vector<unsigned char>::size_type bf::tape_machine::capacity = 30000;

void bf::tape_machine::reset()
{
	cells.assign(capacity, 0);
	data_pointer = 0;
}

void bf::tape_machine::eval(const char& symbol)
{
	switch (symbol) {

	case '>':
		if (data_pointer + 1 == capacity)
		{
			throw std::range_error("the data pointer cannot exceed the capacity of the tape machine (30000)");
		}
		data_pointer += 1;
		break;

	case '<':
		if (data_pointer == 0)
		{
			throw std::range_error("the data pointer cannot point to a negative cell");
		}
		data_pointer -= 1;
		break;

	case '+':
		cells.at(data_pointer) += 1;
		break;

	case '-':
		cells.at(data_pointer) -= 1;
		break;

	case '.':
		std::putchar(cells.at(data_pointer));
		break;

	case ',':
		cells.at(data_pointer) = std::getchar();
		break;
	}
}
