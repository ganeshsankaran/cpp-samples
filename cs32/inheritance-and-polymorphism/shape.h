#ifndef _SHAPE_H_
#define _SHAPE_H_

// abstract class with a pure virtual function
// cannot instantiate object of this class
// ensures that derived classes share properties of this class
class Shape {
public:
    virtual double area(); // Pure virtual function    
};

#endif