#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main ()
{   
    srand(time(0));
    int randomNumber = (rand() %100) +1 ; // random number from 1 to 100
    int guessNumber = 0;
    int chances = 5;

    

    cout << "\n Welcome To Number Guessing Game \n" << endl;
    cout << "\n Guess A Number Between 1 to 100 \n";
    cout << "\n Lets Startl, Good Luck! \n" <<endl;
    
    cout << "\n !!You Have 5 Chances To Guess, Can You? \n" <<endl;
    
    for (int i = 1 ; i <= 5 ; i++) 
    { 
      cout << "Enter Your Number Between 1 And 100 : ";
      cin >> guessNumber;

      if(guessNumber == randomNumber) 
        {
        cout << "Congrats!!. You Did It "<< endl;
        break;
        }


      else
       {
        if(guessNumber < randomNumber) 
        {
           cout << "Guess Higher!" << endl;
        }
        else
        {
           cout << "Guess Lower!" << endl;

        }
       } chances --;
       cout << "\n Chances Left : " << chances << endl; 

       if (chances ==0) 
       {
           cout << "Sorry You Dont Have more Chances" << endl;
           cout << "The Number Was : " << randomNumber  << endl;

       }
    }
    return 0 ;
}