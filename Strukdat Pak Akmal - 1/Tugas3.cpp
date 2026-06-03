#include <iostream>
using namespace std;

void fungsi(int a, int &b, int &c){
 b = ++a ;
 c += --b;
 a--;
 cout << a << " " << b << " " << c << endl;
}

int main()  
            {
 int a=2, c=2, b=2, y=2;
 fungsi (c,a,b);
 cout << a << " " << b << " " << c << endl;
 fungsi (a + b,c,y);
 cout << a << " " << b << " " << c << endl;
 
}