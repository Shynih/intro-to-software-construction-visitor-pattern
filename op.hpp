#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include "sstream"
#include <string>
#include <iomanip>

#include "iterator.hpp"
#include "visitor.hpp"

class Op : public Base {
    private:
        double value;
    public:
        Op(double value) : Base() { this -> value = value; }

        virtual double evaluate() { return value; }

        virtual std::string stringify() {
			    std::stringstream stream;
			    std::string sentence;
			    stream << std::fixed << std::setprecision(1) << value;
			    sentence = stream.str();
			    return sentence;
		    }

        Base* get_left() {
          return nullptr;
        }
        Base* get_right() {
          return nullptr;
        }
        Iterator* create_iterator() {
          Iterator* it = new NullIterator(this);
          return it;
        }
        void accept(CountVisitor* vis) {
          vis->visit_op();
        }
};

#endif //__OP_HPP__
