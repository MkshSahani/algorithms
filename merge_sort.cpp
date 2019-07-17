#include "util.h"


void merge(vector<int> &a, int from, int mid,int to)
{
  int n = to - from + 1;

  vector<int> b(n);

  int i1 = from;
  int i2 = mid + 1;

  int j = 0;

  while(i1 <= mid && i2 <= to)
  {
    if(a[i1] < a[i2])
    {
      b[j] = a[i1];
      i1++;
    }
    else
    {
      b[j] = a[i2];
      i2++;
    }
    j++;
  }


  while(i1 <= mid)
  {
    b[j] = a[i1];
    j++;
    i1++;
  }

  while(i2 <= to){
    b[j] = a[i2];
    i2++;
    j++;
  }

  for(int j = 0; j < n; j++)
    a[from + j] = b[j];

}

void m_sort(vector<int> &a, int from, int to){
  if(from == to)
    return;
  int mid = (from + to) / 2;
  m_sort(a, from, mid);
  m_sort(a, mid+1, to);
  merge(a, from, mid, to);
}


int main(){


  rand_seed();
  vector<int> v(200);
  for(int i = 0; i < 200; i++)
    v[i] = rand_int(1, 100);

  print(v);

  m_sort(v,0,v.size() - 1);
  print(v);

  return 0;
}
