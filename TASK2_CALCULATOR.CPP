#include <iostream>
using namespace std;


// SIMPLE CALCULATOR - TASK2

int main ()
{

int num1 , num2 ;
string operation;

 while ( 1 == 1 ) {
   cout << "----------------------------------------CALCULATOR------------------------------------------ \n"<<endl;
 
 cout << "Enter The First Number : ";
 cin >> num1 ;
 cout << "Enter The Second Number : ";
 cin >> num2 ;
 
 cout << "What Operation Do YOu Want To Do ?  ";
 cin >> operation  ;

 if( operation == "+" ) {
    cout  << num1 + num2  << endl;
 }
 
 else if( operation == "-" ) {
    cout  << num1 - num2  << endl;
 }
  else if( operation == "/" ) {
    cout  << float(num1) / float(num2)  << endl;
 }
  else if( operation == "*" ) {
    cout  << num1 * num2  << endl;
 }

 }


}