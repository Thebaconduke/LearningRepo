#include <iostream>
#include "DataStructures\pgLinkList.h"
using namespace std;

int main()
{
    pgLinkList<int> newlinklist;
    newlinklist.add(1);
    newlinklist.add(2);
    newlinklist.add(11); 
    newlinklist.add(9); 
    newlinklist.add(8); 
    newlinklist.add(5);
    newlinklist.add(4);

    newlinklist.remove(2);

    newlinklist.addToStart(12345);

    newlinklist.sort();
    newlinklist.__toString();

    pgLinkList<const char*> charLinkList;
    
    charLinkList.add("w");
    charLinkList.add("l");
    charLinkList.add("sadjhnasd");
    charLinkList.add("ldddd");
    charLinkList.add("aaaad");
    charLinkList.add("some Random Word");
    charLinkList.add("aaafd");
    
    auto x = [](const char* a, const char* b)
    {
        return strcmp(a,b) > 0;
    };

    charLinkList.sort(x);
    
    charLinkList.__toString();
    //const char* wow = charLinkList[0];
    //cout << wow << endl;
}