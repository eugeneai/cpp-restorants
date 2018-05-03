#include "iostream"
#include "stdio.h"
#include <stdlib.h>
#include <vector>
#include <map>
#include <csignal>

#define NL "\n"


// https://gihub.com/eugeneai/cpp-restorants

using namespace std;

// Depth-first constraint satisfation.


enum state_t{
  MIN=0,
  none=MIN,
  empty,
  MD,
  BB,
  MAX
};


class Rest {
  multimap<int,int> * m = NULL;
  vector<state_t> * s = NULL;
  int size = 0;

public:
  bool csp (int index, state_t con);
  void add(int a, int b);
  void clear();
  void printSolution();
  Rest();
  ~Rest();

}; // struct a_s {...};    struct a_s a; typedef struct a_s a_t; a_t a;


state_t operator ++(state_t &s, int) {
  state_t prev_s = s;
  if ( MAX == s)
    s = MIN;
  else
    s = static_cast<state_t>( s + 1 );

  return ( prev_s );
}

Rest::Rest() {
  m = new multimap<int, int>();
}

Rest::~Rest() {
  if (m!=NULL) {
    delete m;
  }

  if (s!=NULL) {
    delete s;
  }
}

void Rest::add(int a, int b) {
  m->insert(pair<int,int>(a, b));
  m->insert(pair<int,int>(b, a));
  size++;
}

/*
  Поиском в глубину найти решение.
  Параметры:
  i - номер текущей вершины ?
  p - указатель на предыдущую вершину.

 */

typedef multimap<int,int>::iterator int_i_t;

bool Rest::csp(int n, state_t p) {
  state_t c=none;

  for (c=none; c<MAX; c++) {
    if (n==c) continue; //

    pair<int_i_t,int_i_t> it = m->equal_range(n);
    s->at(n)=c;  //

    // raise(SIGINT);

    for (int_i_t mit = it.first; mit!=it.second; mit++) {
      int m = mit->second;

      if (s->at(m) == none) csp(m, c);
    }

    s->at(n)=none;
  }
}

void Rest::clear() {
  if (s==NULL) {
    s = new vector<state_t>(size);
  }
  for (state_t &i: *s) {
    i=none;
  }
}

void Rest::printSolution(){
  cout << "Printing a solution" << NL;
}

// ------------------------------------------


int main(int argc, char ** argv) {
  Rest rest;

  cout << "\n-------------------------------\n";

  // rest.setLen(3);
  rest.add(1,2);
  rest.add(2,3);

  rest.clear();

  if (rest.csp(0, none)) {
    cout << "Solution found" << NL;
    rest.printSolution();
  }

  return 0;
}
