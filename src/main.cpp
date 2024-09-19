#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main() {

    std::string input = R"({"name":"Jane","age":25,"is_student":true})";
    json parsed = json::parse(input);

    std::cout << "Name: " << parsed["name"] << std::endl;
    std::cout << "Age: " << parsed["age"] << std::endl;
    std::cout << "Is Student: " << parsed["is_student"] << std::endl;

    return 0;
}
