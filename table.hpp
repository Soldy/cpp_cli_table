#include <vector>
#include <string>
#include <map>
#include <iostream>

namespace ctcpp{
class Table{
  private:
    std::map<std::string, std::map<std::string, std::string>> elements {
        { "top", {
            { "start", "\u250C" },
            { "middle", "\u252c" },
            { "line", "\u2500" },
            { "end", "\u2510" }
          }
        },
        { "center", {
            { "start", "\u251c" },
            { "middle", "\u253c" },
            { "line", "\u2500" },
            { "end", "\u2524" }
          }
        },
        { "button", {
            { "start", "\u2514" },
            { "middle", "\u2534" },
            { "line", "\u2500" },
            { "end", "\u2518" }
          }
        }
    };
    std::string element_separator = "\u2502";
    std::vector<unsigned int> calcSize(
      std::vector<std::vector<std::string>> data
    ){
         std::vector<unsigned int> out;
         unsigned int max_columns = data[0].size();
         for (auto & line : data)
             if(max_columns < line.size())
                 max_columns = line.size();
         for (unsigned int i = 0 ; i < max_columns ; i++)
              out.push_back(0);
         for (auto & line : data){
             for (unsigned int i = 0 ; i < line.size() ; i++){
                 if(out[i] < line[i].length())
                     out[i] = line[i].length();
             }
         }
         return out;
    };
    std::string renderLine(
      std::vector<std::string> columns,
      std::vector<unsigned int> size
    ){
        std::string out = this->element_separator;
        for(unsigned int i = 0 ; i < size.size(); i++){
            out += columns[i];
            out.append(size[i]-columns[i].length(), ' ');
            out += this->element_separator;
        }
        return out;
    };
    std::string renderBorder ( 
      std::vector<unsigned int> size,
      std::string elem_name
    ){
        std::string out = this->elements[elem_name]["start"];
        int col = 0;
        for(unsigned int & i : size){
            if (col > 0)
                out += this->elements[elem_name]["middle"];
            out += this->pad(i , this->elements[elem_name]["line"]);
            col++;
        }
        out += this->elements[elem_name]["end"];
        return out;

    };
    std::string pad(
        unsigned int size,
        std::string character
    ){
        std::string out;
        for(unsigned int i = 0 ; size > i ; i++)
            out += character;
        return out;

    };
  public:
    std::vector<std::string> render (
      std::vector<std::vector<std::string>> data
    ){
        std::vector<std::string> out;
        int line = 0;
        std::vector<unsigned int> size = calcSize(data);
        out.push_back(
            this->renderBorder(size, "top")
        );
        for(std::vector<std::string>& i : data){
            if(line > 0)
                out.push_back(
                    this->renderBorder(size, "center")
                );
            out.push_back(
                this->renderLine(i, size)
            );
            line++;
        }
        out.push_back(
            this->renderBorder(size, "button")
        );
        return out;
    };
};
}
