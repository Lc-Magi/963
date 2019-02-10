#include <iostream>
 
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    if(n<=0)
        return 0;
 
    for(int i=n; i; i--) {
        for (int j = 0; j < i; j++)
            cout << "*" << " ";
    cout << endl;
    }
    return 0;
}
