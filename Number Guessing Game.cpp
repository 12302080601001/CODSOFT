#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
 {
  srand(static_cast<unsigned int>(time(0)));
    int random_num = rand() % 100 + 1;
    int guess = 0;
    cout << "Welcome to the Number Guessing Game!"<<endl;
    cout << "I have selected a random number between 1 and 100."<<endl;
    cout << "Can you catch me?"<<endl;
    while (guess != random_num) 
    {
        cout << "Enter your guess: ";
        cin >> guess;
        if (guess < random_num)
         {
            cout << "Very close! Please try again."<<endl;
         } 
        else if (guess > random_num)
         {
            cout << " very far! Please Try again.\n";
         }
         else
          {
            cout << " You did it: " << random_num << endl;
          }
    }
    return 0;
}
