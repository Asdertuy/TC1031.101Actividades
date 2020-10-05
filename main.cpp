#include "linkedList.h"

using namespace std;

int main()
{    
    try
    {
        LinkedList<int> list;
        list.push(6);
        list.push(7);
        list.push(2);
        list.push(8);
        list.push(1);
        list.push(7);
        list.push(6);
        list.push(7);
        list.push(7);
        list.push(9);
        list.print();
        cout << "\ncount number of times 7 repeats\n";
        cout << list.count(7);
        cout << "\ndelete list\n";
        list.deleteList();
        list.push(10);
        list.push(9);
        list.push(9);
        list.push(9);
        list.push(8);
        list.push(7);
        list.push(7);
        list.push(6);
        list.push(5);
        list.push(5);
        list.push(4);
        list.push(3);
        list.push(2);
        list.push(1);
        cout << "\nnew sorted list\n";
        list.print();
        list.sortedInsert(list.newNode(8));
        cout << "\nsorted insert 8\n";
        list.print();
        list.removeDuplicates();
        cout << "\nremoved duplicates\n";
        list.print();
        list.reverse();
        cout << "\nreversed the list\n";
        list.print();
        cout << endl;        
    }
    catch(const char* e)
    {
        std::cerr << "ERROR caught: " << e << std::endl;
    } 

    return 0;
}