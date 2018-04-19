#include "iostream"
#include "stdio.h"
#include <stdlib.h>
#include <vector>

// https://gihub.com/eugeneai/cpp-restorants

using namespace std;


struct Arc {
  int a,b;   // int m_a, m_b
  Arc(int a, int b);
};

class Rest {
  vector<Arc *> * v = NULL;

public:
  Rest();
  ~Rest();

}; // struct a_s {...};    struct a_s a; typedef struct a_s a_t; a_t a;


Arc::Arc(int a, int b) {
  (*this).a=a;
  this->b=b; //
}


Rest::Rest() {
  v = new vector<Arc *>();
}

Rest::~Rest() {
  delete v;
}


extern "C" {
  extern void hello() {
    printf("Void hello\n");
  }
}

Rest rest();
Rest * prest = NULL;

int main(int argc, char ** argv) {

  prest = new Rest();

  cout << "\n-------------------------------\n";
  (cout << "Hello world!\n") << 100.0;  // IOStream <<(IOStream, char *)
  printf("Hello from C %020.5f\n", 100.0);
  hello();

  delete prest;

  return 0;
}
