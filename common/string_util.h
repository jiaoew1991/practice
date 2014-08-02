#include <string>
#include <sstream>
#include <vector>

template<class T>
std::string toString(T elem) 
{
    std::stringstream sstream;
    sstream << elem;
    return sstream.str();
}

template<class T>
std::string toStringList(std::vector<T>& tList)
{
    std::stringstream sstream;
    sstream << "[";
    int index = 0;
    for (typename std::vector<T>::iterator it = tList.begin(); it != tList.end(); it++) {
        sstream << *it;
        if (index < tList.size() - 1) {
            sstream << ", ";
        }
        index++;
    }
    sstream << "]";
    return sstream.str();
}
