/* Write your test code for the ULListStr in this file */

#include <iostream>
#include <string>
#include <vector>
#include "ulliststr.cpp"
using namespace std;

int main(int argc, char* argv[]) {

  cout << "Creating empty list dat1:\n";
  ULListStr dat1;
  dat1.print();

  cout << "Pushing back digits of PI (314159265358979323):\n";
  
  const string PI [18] = {
    "3","1","4","1",
    "5","9","2","6",
    "5","3","5","8",
    "9","7","9","3"
  };
  for (int i = 0; i < 16; i ++) {
    dat1.push_back(PI[i]);
  }
  dat1.print();
  
  cout << "Value at loc 12: " << dat1.get(12) << "\n";

  cout << "Popping one digit:\n";
  dat1.pop_back();
  dat1.print();

  cout << "Popping 15 digits:\n";
  for (int i = 0; i < 15; i ++) {
    dat1.pop_back();
  }
  dat1.print();

  
  return 0;
}
