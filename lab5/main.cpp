#include "allocator.hpp"
#include "stack.hpp"

int main(int argc, char **argv)
{

//---------------------------custom allocator for map--------------------------
    std::map<int, int, std::less<int>,Allocator<std::pair<int,int>, 3>> my_map;

    my_map[1]=10;
    my_map[2]=20;
    my_map[3]=30;


    for(const auto& pair: my_map)
        std::cout << pair.first << "->" << pair.second << std::endl;
//-----------------------------------------------------------------------------

    Stack<int, Allocator<int, 10>> stack;
    stack.pushBack(1);
    stack.pushBack(2);
    stack.pushBack(3);
    stack.pushBack(34);
    stack.popBack();

    for (const auto &i : stack) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    //std::cout << stack;

    return 0;
}