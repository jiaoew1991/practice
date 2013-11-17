#include "arraylist.h"

void test_null()
{
	ArrayList<int> al(20);
    int tmp;
    std::cout << "begin test null" << std::endl;
    std::cout << al << std::endl;
    std::cout << al.remove(tmp) << std::endl;
    std::cout << al.getValue(tmp) << std::endl;
    std::cout << "end test null" << std::endl;
}
void test_int_list()
{
    ArrayList<int> slist(20);
    int tmp;
    std::cout << "begin test int list" << std::endl;
    for (int i = 0; i < 20; i++) {
        slist.append(i);
    }
    std::cout << slist << std::endl;
    slist.setPos(7);
    std::cout << slist.getValue(tmp) << "," << tmp << ","  << slist.leftLength() << ","  << slist.rightLength() << std::endl;
    std::cout << slist.setPos(3);
    std::cout << "," << slist.getValue(tmp) << "," << tmp << "," << slist.leftLength() << std::endl;
    slist.prev();
    std::cout << tmp << ", "<< slist.leftLength() << std::endl;
    std::cout << "end test int list" << std::endl;
}
void test_index_out_range()
{
    
}
void test_remove_out_range()
{
}
int main()
{
	std::cout << "test arraylist begin";
    test_null();
    test_int_list();
    std::cout << "test arraylist end";
}
