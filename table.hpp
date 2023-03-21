#include <vector>
#include <string>
#include <map>

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
            { "middlei", "\u253c" },
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
    std::vector<int> calcSize(
      std::vector<std::vector<std::string>> data
    ){
         std::vector<int> out;
         for (auto & line : data){
             for (int i = 0 ; i < line.size() ; i++){
                 if(out[i] < line[i].length())
                     out[i] = line[i].length();
             }
         }
         return out;
    };
    std::string renderLine(
      std::vector<std::string> columns,
      std::vector<int> size
    ){
        std::string out = element_separator;
        for(int i = 0 ; i < size.size(); i++){
            out += columns[i];
            out.append(size[i]-columns[i].length(), ' ');
            out += element_separator;
        }
        return out;
    };
    std::string renderBorder ( 
      std::vector<int> size,
      std::string elem_name
    ){
        std::string out = this->elements[elem_name]["start"];
        int line = 0;
        for(int & i : size){
            if (line > 0)
                out += this->elements[elem_name]["middle"];
            out.append(i, ' ');
        }
        out += this->elements[elem_name]["end"];
        return out;

    };
  public:
    std::vector<std::string> render (
      std::vector<std::vector<std::string>> data
    ){
        std::vector<std::string> out;
        int line = 0;
        std::vector<int> size = calcSize(data);
        out.push_back(
            this->renderBorder(size, "top")
        );
        for(int i = 0 ; i < data.size(); i++){
            if(line > 0)
                out.push_back(
                    this->renderBorder(size, "center")
                );
            out.push_back(
                this->renderLine(data[i],size)
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
