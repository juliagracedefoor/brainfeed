#include <vector>

#ifndef TAPE_MACHINE_HPP
#define TAPE_MACHINE_HPP

namespace bf
{
    class tape_machine
    {
        public:
        void eval(const char& command);
        void reset();

        private:
        std::vector<unsigned char> cells;
        std::vector<unsigned char>::size_type data_pointer;
    };
}


#endif