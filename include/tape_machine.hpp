#ifndef TAPE_MACHINE_HPP
#define TAPE_MACHINE_HPP

#include <string>
#include <vector>

namespace bf
{
    class tape_machine
    {
        public:
        const static std::string symbols;
        const static std::vector<unsigned char>::size_type capacity;

        void reset();
        void eval(const char&);

        // reset reverts the machine to an initial state anyways, right?
        tape_machine() { reset(); }

        private:
        // unsigned char stores exactly one byte (0 to 255)
        std::vector<unsigned char> cells;
        std::vector<unsigned char>::size_type data_pointer;
    };
}

#endif