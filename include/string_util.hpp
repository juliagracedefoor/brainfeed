#ifndef STRING_UTIL_HPP
#define STRING_UTIL_HPP

#include <algorithm>
#include <string>

namespace string_util
{
    // compute a string's lowercase form
    std::string uncapitalize(const std::string & str)
    {
        std::string lowered;

        std::transform(
            str.begin(), str.end(), back_inserter(lowered),
            [](unsigned char c) { return tolower(c); });

        return lowered;
    }

    // strip all characters from a string that are not found in exceptions
    void strip_all_except(std::string & str, const std::string & exceptions)
    {
        str.erase(
            std::remove_if(
                str.begin(), str.end(),
                [&](char c) { return exceptions.find(c) == std::string::npos; }),
            str.end());
    }
}

#endif
