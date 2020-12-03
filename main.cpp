#include <iostream>

#include "base.hpp"
#include "op.hpp"
#include "mult.hpp"
#include "add.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "rand.hpp"
#include "sub.hpp"

#include "binary_iterator.cpp"
#include "preorder_iterator.cpp"

using namespace std;


int main() {

  Op* op1 = new Op(1);
  Op* op2 = new Op(2);
  Op* op3 = new Op(3);
  Op* op6 = new Op(4);

  Sub* sub1 = new Sub(op2, op1);
  Add* add1 = new Add(op6, op3);
  Mult* mult1 = new Mult(sub1, add1);
  Sub* sub2 = new Sub(mult1, sub1);
  Sub* first = new Sub(sub1, sub2);
  Pow* pow1 = new Pow(add1, op6);
  Sub* test = new Sub(first, pow1);

PreorderIterator* pre_it = new PreorderIterator(test);
	
  cout << "Number of occurances in the tree:" << endl;

  CountVisitor *cv = new CountVisitor();
  pre_it->first();
	while(pre_it->is_done() == false){
	    pre_it->current()->accept(cv);
	    pre_it->next();
	}
  cout << "Ops:" << cv->op_count() << endl;
  cout << "Rands:" << cv->rand_count() << endl;
  cout << "Adds:" << cv->add_count() << endl;
  cout << "Subs:" << cv->sub_count() << endl;
  cout << "Mults:" << cv->mult_count() << endl;
  cout << "Divs:" << cv->div_count() << endl;
  cout << "Pows:" << cv->pow_count() << endl;

} 

