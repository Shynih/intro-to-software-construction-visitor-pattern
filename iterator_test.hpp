#ifndef ITERATOR_TEST_HPP
#define ITERATOR_TEST_HPP
#include "gtest/gtest.h"

#include <iostream>

#include "base.hpp"
#include "op.hpp"
#include "mult.hpp"
#include "add.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "rand.hpp"
#include "sub.hpp"

using namespace std;

TEST(IteratorTest, OpTest) {
    Base* one = new Op(1);
    Iterator* test = one -> create_iterator();
    EXPECT_EQ(test -> current(), nullptr);
    EXPECT_EQ(test -> is_done(), true);
}

TEST(IteratorTest, RandTest) {
    Base* one = new Rand();
    Iterator* test = one -> create_iterator();
    EXPECT_EQ(test -> current(), nullptr);
    EXPECT_EQ(test -> is_done(), true);
}

TEST(IteratorTest, PowTest) {
    Base* one = new Op(1);
    Base* two = new Op(2);
    Base* total = new Pow(one, two);
    Iterator* test = total -> create_iterator();
    while (test -> is_done() == false) {
        test -> next();
    }
    EXPECT_EQ(test -> is_done(), true);
}

TEST(IteratorTest, AddTest) {
    Base* one = new Op(1);
    Base* two = new Op(2);
    Base* total = new Add(one, two);
    Iterator* test = total -> create_iterator();
    while (test -> is_done() == false) {
        test -> next();
    }
    EXPECT_EQ(test -> is_done(), true);
}

TEST(IteratorTest, SubTest) {
    Base* one = new Op(1);
    Base* two = new Op(2);
    Base* total = new Sub(one, two);
    Iterator* test = total -> create_iterator();
    while (test -> is_done() == false) {
        test -> next();
    }
    EXPECT_EQ(test -> is_done(), true);
}

TEST(IteratorTest, MultTest) {
    Base* one = new Op(1);
    Base* two = new Op(2);
    Base* total = new Mult(one, two);
    Iterator* test = total -> create_iterator();
    while (test -> is_done() == false) {
        test -> next();
    }
    EXPECT_EQ(test -> is_done(), true);
}

TEST(IteratorTest, DivTest) {
    Base* one = new Op(1);
    Base* two = new Op(2);
    Base* total = new Div(one, two);
    Iterator* test = total -> create_iterator();
    while (test -> is_done() == false) {
        test -> next();
    }
    EXPECT_EQ(test -> is_done(), true);
}

#endif
