#include <iostream>
#include <string>

#include "Event/Event.hpp"

int main(int argc, char const *argv[]) {
    PredictFail i{1, 2};

    json j = i.toJson();

    std::string a = j.dump();

    json b = json::parse(a);

    std::cout << i << std::endl;
    std::cout << j << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;

    return 0;
}
