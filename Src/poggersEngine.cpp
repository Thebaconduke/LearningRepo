#include <iostream>
#include "DataStructures\pgLinkList.h"
using namespace std;

int main()
{
    pgLinkList<int> newlinklist;
    newlinklist.add(1234);
    newlinklist.add(1323234);
    newlinklist.add(1234534554); 
    newlinklist.add(1333334);
    newlinklist.add(98463);

    newlinklist.remove(2);

    newlinklist.addToStart(12345);

    newlinklist.sort();
    int poggers = newlinklist.find(1);
    cout << poggers << endl;

    pgLinkList<const char*> charLinkList;

    charLinkList.add("w");
    charLinkList.add("nigg");
    charLinkList.add("l");

    const char* wow = charLinkList[1];
    cout << wow << endl;
}