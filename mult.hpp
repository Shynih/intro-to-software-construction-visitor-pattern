#ifndef MULT_HPP
#define MULT_HPP

#include "base.hpp"
#include "op.hpp"
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;
#include "iterator.hpp"
#include "visitor.hpp"

class Mult : public Base {
    private:
        Base* left;
        Base* right;

        string lstring;
		    string rstring;
		    double ldouble;
		    double rdouble;
    public:
        Mult(Base* val1, Base* val2) : Base() {
            left = val1;
            right = val2;
        }
        virtual double evaluate() {
            ldouble = left -> evaluate();
			      rdouble = right -> evaluate();
            return ldouble * rdouble;
        }
        virtual string stringify() { 
            lstring = left -> stringify();
			      rstring = right -> stringify();
            return lstring + " * " + rstring;
        }

        
        Base* get_left() {
          return left;
        }
		    Base* get_right() {
          return right;
        }
		    Iterator* create_iterator() {
		      Iterator* it = new BinaryIterator(this);
		      return it;
		    }
		    void accept(CountVisitor* vis) {
		      vis->visit_mult();
        }

};

#endif 
