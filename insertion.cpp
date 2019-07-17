/******
  program for insertion_sort
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

/***
insertion sort that sort the vector using the insertion sort algorithm
@param the vector which needed to be sorted..
*/

void insert_sort(vector<int> &a)
{
  for(int j = 1; j < a.size(); j++)
  {
    int i = j - 1;
    int key = a[j];
    while(i >= 0 && a[i] > key)
    {
      a[i+1]  = a[i];
      i--;
    }
    a[i+1] = key;
  }
}

int main(int argc, char* argv[])
{
  int result = static_cast<int>(time(0)); // syntax -- static_cast<typename>(expression)
  srand(result);
  vector<int> b(20);
  for(int i = 0; i < 20; i++)
    b[i] = rand() % 100;

  cout << "data" << endl;
  for(int i = 0; i < 20; i++)
    cout << b[i] << endl;

  insert_sort(b);

  cout << "data" << endl;
  for(int i = 0; i < 20; i++)
    cout << b[i] << endl;

  return 0;
}
