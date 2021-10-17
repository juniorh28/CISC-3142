#include <iostream>

using namespace std;

int main()
{

    char s[] = "stressed";
    char *p = s;
    for (; *p !='\0'; ++p)
    {
    }
    for (--p; p >= s; --p)
    {
        cout << *p;
    }
    cout << " \n\n";
    
     return 0;
}