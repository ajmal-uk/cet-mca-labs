#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> age;
    age["Alice"] = 25;
    age["Bob"] = 30;
    for (const auto &pair : age) {
        std::cout << pair.first << " is " << pair.second << " years old.\n";
    }
    return 0;
}
