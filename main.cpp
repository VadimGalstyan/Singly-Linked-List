#include "list.h"

int main()
{
    List<int> list;

    list.push_back(5);
    list.push_back(6);
    list.push_back(7);
    list.push_back(8);

    list.printList();
    std::cout<<std::endl;

    list.insert(4,3);
    list.deleteNode(4);
    list.push_front(300);
    list.push_front(3000);

    list.printList();
    std::cout<<std::endl;
    
    list.search(40);

    list.pop_back();
    list.pop_front();

    list.printList();
   

    list.reverse();

    std::cout<<std::endl;

    list.printList();

    return 0;
}