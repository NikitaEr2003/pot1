
#include "thread"
#include <iostream>
#include <chrono>
 #include <Windows.h>


using namespace std;
int main() 
{
  int variable = 10;
  std::thread first(
  [&variable](int a = 5) 
   {
    for (int i = 0; i < a; i++) {
      variable++;
      this_thread::sleep_for(1s);
      cout << variable << " ";
    }
  });
  std::thread second([&variable]() {
    while (variable) {
      variable--;
      this_thread::sleep_for(2s);
      cout << variable << " ";
    }
    
  });
  first.join();
  second.join();

}

