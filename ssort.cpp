#include "util.h"

int min_position(vector<int> &a, int from, int to)
{
  int min = from;
  for(int i = from + 1; i <= to; i++)
    if(a[min] > a[i]) min = i;
  return min;
}

void s_sort(vector<int> &a){
  for(int i = 0; i < a.size() - 1; i++){
    int min_pos = min_position(a, i, a.size() - 1);
    if(min_pos != i)
      swap(a[min_pos], a[i]);
  }
}


int main(int argc, char* argv[]){

  rand_seed();
  vector<int> v(20000);
  for(int i = 0; i < 20000; i++)
    v[i] = rand_int(1, 100);

  print(v);

  s_sort(v);
  print(v);

  return 0;
}
