#include <iostream>
#include <cstdlib>
#include <ctime>

#include "util.h"

void swap(int &x, int &y){
  int temp = x;
  x = y;
  y = temp;
}

void print(vector<int> &a){
  cout << "vector data " << endl;
  for(int i = 0; i < a.size(); i++)
    cout << a[i] << endl;
}

void rand_seed(){
  int seed = static_cast<int>(time(0));
  srand(seed);
}

int rand_int(int a, int b){
  return a + rand() % (a + b - 1);
}
