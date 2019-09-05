
#include <iostream>
#include <string>
#include <new>
#include <map>

using namespace std;

#include "Map.cpp"

int main() {

    Map<int, string> map;
    
    map.put(3, "Sue");
    map.put(1, "Paul");
    map.put(2, "Mary");
    
    cout << "Map of Name Values: ";
    cout << map << endl;
    
    map.clear();
    
    
    cout << "Map cleared: " << map << endl;
    
    return 0;
}




