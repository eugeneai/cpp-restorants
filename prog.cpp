#include "iostream"
#include "stdio.h"
#include <stdlib.h>
#include <vector>

#define NL "\n"


// https://gihub.com/eugeneai/cpp-restorants

using namespace std;

// Depth-first constraint satisfation.


struct Arc {
  int a,b;   // int m_a, m_b
  Arc(int a, int b);
};

enum state_t{
  MIN=0,
  none=MIN,
  empty,
  MD,
  BB,
  MAX
};


class Rest {
  vector<Arc *> * v = NULL;
  vector<state_t> * s = NULL;

public:
  bool csp (int index, state_t con);
  Arc * add(int a, int b);
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

Arc::Arc(int a, int b) {
  (*this).a=a;
  this->b=b; //
}

Rest::Rest() {
  v = new vector<Arc *>();
}

Rest::~Rest() {
  if (v!=NULL) {
    for (Arc * arc: *v) {
      delete arc;
    }
    delete v;
  }

  if (s!=NULL) {
    delete s;
  }
}

Arc * Rest::add(int a, int b) {
  Arc * arc = new Arc(a,b);
  v->push_back(arc);
  return arc;
}


bool Rest::csp(int i, state_t p) {
  state_t c=none;

  for (c=none; c<=BB; c++) {
    cout << "Value:" << c << NL;
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

  if (rest.csp(0, none)) {
    cout << "Solution found" << NL;
    rest.printSolution();
  }

  return 0;
}
