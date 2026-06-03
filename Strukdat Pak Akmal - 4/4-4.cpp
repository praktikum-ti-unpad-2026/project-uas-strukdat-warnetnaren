#include <iostream>
using std::cout;
using std::endl;

typedef int larik[100];

void printLarikPointer(larik a, int n){

 cout <<"\nPencetakan alamat variable dan array dengan pointer\n";
 cout <<"------------------------------------------------------------"<<endl;

 cout<<"Alamat parameter n = "<<&n<<endl;
 cout<<"Nilai n = "<<n<<endl;

 cout<<"Alamat array a = "<<a<<endl;
 cout<<"Alamat elemen pertama = "<<&a[0]<<endl;
 cout<<"Isi elemen pertama (*a) = "<<*a<<endl<<endl;

 for (int* p = a; p < a+n; p++) {

     cout<<"Alamat pointer p = "<<&p<<endl;
     cout<<"Isi pointer p (alamat elemen) = "<<p<<endl;
     cout<<"Data yang ditunjuk *p = "<<*p<<endl;
     cout<<"----------------------------------"<<endl;
 }
}

void printLarikPointer1(larik a, int n){

 cout <<"\nPencetakan alamat array dan data dengan dereference"<<endl;
 cout <<"------------------------------------------------------"<<endl;

 cout<<"Alamat parameter n = "<<&n<<endl;
 cout<<"Alamat array a = "<<a<<endl<<endl;

 for(int i=0; i<n; i++) {

 cout<<"Alamat index i = "<<&i<<endl;

 cout<<"Alamat Data ke-"<<(i+1)<<" = "<<&(a[i])<<endl;

 cout<<"Data ke-"<<(i+1)<<" = "<<*(a+i)<<endl;

 cout<<"----------------------------------"<<endl;
 }
}