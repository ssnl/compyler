/* -*- mode: C++; c-file-style: "stroustrup"; -*- */

#ifndef LINALG_H
#define LINALG_H

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include <list>

class Quantity {
public:

    Quantity (double x) : V(1, x) { }

    template <class InputIterator>
    Quantity (InputIterator b, InputIterator e) {
	for (InputIterator p = b; p != e; p ++)
	    V.push_back (**p);
    }

    Quantity (const Quantity& v) : V (v.V) { }

    Quantity* add (Quantity* val) const {
	if (dimen () != val->dimen ())
	    throw std::invalid_argument ("non-conforming quantities");
	Quantity* R = new Quantity (*this);
	for (size_t i = 0; i < V.size (); i += 1)
	    R->V[i] += val->V[i];
	return R;
    }
	
    Quantity* sub (Quantity* val) const {
	if (dimen () != val->dimen ())
	    throw std::invalid_argument ("non-conforming quantities");
	Quantity* R = new Quantity (*this);
	for (size_t i = 0; i < V.size (); i += 1)
	    R->V[i] -= val->V[i];
	return R;
    }

    Quantity* mult (Quantity* val) const {
	if (dimen () != val->dimen () && dimen () != 1 && val->dimen () != 1)
	    throw std::invalid_argument ("non-conforming quantities");
	Quantity* R;
	if (dimen () == 1) {
	    R = new Quantity (*val);
	    for (size_t i = 0; i < val->V.size (); i += 1)
		R->V[i] *= V[0];
	} else if (val->dimen () == 1) {
	    R = new Quantity (*this);
	    for (size_t i = 0; i < V.size (); i += 1)
		R->V[i] *= val->V[0];
	} else {
	    R = new Quantity (*this);
	    for (size_t i = 0; i < V.size (); i += 1)
		R->V[i] *= val->V[i];
	}
	return R;
    }

    Quantity* neg () const {
	Quantity* R = new Quantity (*this);
	for (size_t i = 0; i < V.size (); i += 1)
	    R->V[i] = -R->V[i];
	return R;
    }

    Quantity* inner_prod (Quantity* val) const {
	if (dimen () != val->dimen ())
	    throw std::invalid_argument ("non-conforming quantities");
	double R; 
	R = 0.0;
	for (size_t i = 0; i < V.size (); i += 1)
	    R += V[i] * val->V[i];
	return new Quantity (R);
    }
    int dimen () const { return V.size (); }
  
    operator double () const {
	if (V.size () == 1) 
	    return V[0];
	else
	    throw std::invalid_argument ("quantity not scalar");
    }

    std::ostream& write (std::ostream& out) {
	if (dimen () == 1) 
	    out << V[0];
	else if (dimen () == 0)
	    out << "[]";
	else {
	    out << "[" << V[0];
	    for (size_t i = 1; i < V.size (); i += 1) 
		out << ", " << V[i];
	    out << "]";
	}
	return out;
    }
  
    void dump () {
	write (std::cerr) << std::endl;
    }

private:

    std::vector<double> V;

};

static inline std::ostream&
operator<< (std::ostream& out, Quantity* val)
{
    return val->write (out);
}

    
#endif
