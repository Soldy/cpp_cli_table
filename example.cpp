#include "table.hpp"
#include <iostream>


int main(){
    ctcpp::Table *tool = new ctcpp::Table();
    std::vector<std::string> output = tool->render(
      {
        {"testcolumA", "testcolumB", "testcolumC"},
        {"A0", "B0", "C0"},
        {"A1", "B1", "C1"},
        {"A2", "B2", "C2"}
      }
    );
    for(std::string i : output)
        std::cout << i << std::endl;
    return 0;
}
