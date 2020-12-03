#ifndef VISITOR_TEST_HPP
#define VISITOR_TEST_HPP

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


TEST(CountVisitorTest, Tree1) {
  Op* op1 = new Op(1);
  Op* op2 = new Op(2);
  Op* op3 = new Op(3);
  Op* op4 = new Op(4);

    Sub* first = new Sub( op1, op2);
	  Div* second = new Div( op3, op4);
    Add* dummy = new Add(first,second);
    //cout << dummy->stringify() << " = " << dummy->evaluate() << endl;
  CountVisitor *test1 = new CountVisitor();
	PreorderIterator *test2 = new PreorderIterator(dummy);
  
  //cout << first->stringify() << " = " << first->evaluate() << endl;

  test2->first();
	while(test2->is_done() == false){
	    test2->current()->accept(test1);
	    test2->next();
	}
  EXPECT_EQ(test1->sub_count(), 1);
	EXPECT_EQ(test1->div_count(), 1);
	EXPECT_EQ(test1->op_count(), 4);
}

TEST(CountVisitorTest, Tree2) {
  Op* op1 = new Op(1);
  Op* op2 = new Op(2);
  Op* op3 = new Op(3);
  Op* op4 = new Op(4);

    Add* first = new Add( op1, op2);
	  Mult* second = new Mult( op3, op4);
    Sub* dummy = new Sub(first,second);
    //cout << dummy->stringify() << " = " << dummy->evaluate() << endl;
  CountVisitor *test1 = new CountVisitor();
	PreorderIterator *test2 = new PreorderIterator(dummy);
  
  //cout << first->stringify() << " = " << first->evaluate() << endl;

  test2->first();
	while(test2->is_done() == false){
	    test2->current()->accept(test1);
	    test2->next();
	}
  EXPECT_EQ(test1->add_count(), 1);
	EXPECT_EQ(test1->mult_count(), 1);
	EXPECT_EQ(test1->op_count(), 4);
}

TEST(CountVisitorTest, Tree3) {
  Op* op1 = new Op(1);
  Op* op2 = new Op(2);
  Op* op3 = new Op(3);
  Op* op4 = new Op(4);

    Sub* sub1 = new Sub(op2, op1);
	  Add* add1 = new Add(op4, op3);
    Mult* mult1 = new Mult(sub1, add1);
    Sub* sub2 = new Sub(mult1, sub1);
    Sub* first = new Sub(sub1, sub2);
    Pow* second = new Pow(add1, op4);

    Sub* dummy = new Sub(first, second);

    //cout << dummy->stringify() << " = " << dummy->evaluate() << endl;

  CountVisitor *test1 = new CountVisitor();
	PreorderIterator *test2 = new PreorderIterator(dummy);
  
  //cout << first->stringify() << " = " << first->evaluate() << endl;

  test2->first();
	while(test2->is_done() == false){
	    test2->current()->accept(test1);
	    test2->next();
	}


  EXPECT_EQ(test1->add_count(), 2);
	EXPECT_EQ(test1->sub_count(), 5);
	EXPECT_EQ(test1->mult_count(), 1);
	EXPECT_EQ(test1->div_count(), 0);
	EXPECT_EQ(test1->pow_count(), 1);

	EXPECT_EQ(test1->op_count(), 11);
} 

#endif
