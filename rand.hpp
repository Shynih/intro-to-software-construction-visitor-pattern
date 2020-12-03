#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"
#include "stdlib.h"
#include <ctime>

#include <iostream>
#include "iterator.hpp"
#include "visitor.hpp"

class Rand : public Base {
    private:
        double value;
    public:
        Rand() : Base() { 
            srand(time(0));
            this -> value = rand() % 100; 
        }
        virtual double evaluate() { return value; }
        virtual std::string stringify() { return std::to_string(value); }

        Base* get_left() {return nullptr;}
        
        Base* get_right() {return nullptr;}

        Iterator* create_iterator() {
          Iterator* it = new NullIterator(this);
          return it;
        }
        void accept(CountVisitor* vis) {
          vis->visit_rand();
        }
};

#endif
