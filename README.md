# Multimethod

In this project, we have implemented a template class called Multimethod. 
This class allows for the creation of a multimethod with two arguments, 
which can dynamically add new implementations for various pairs of classes.

The `Multimethod` class interface consists of three methods: `addImpl`, `hasImpl`, and `call`. 
- The `addImpl` method adds an implementation of the multimethod for two types, which are specified through std::type_info. 
- The `hasImpl` method takes two pointers and checks whether an implementation of the multimethod exists for the corresponding types. 
- The `call` method takes two pointers and invokes the corresponding implementation for them. 

Notably, the implementation of these methods correctly handles situations where the multimethod is commutative.

### Example usage:
```c++
// base class for shapes (polymorphic)
struct Shape {};

// rectangle shape
struct Rectangle : Shape {};

// triangle shape
struct Triangle : Shape {};

// function to check intersection of two rectangles
bool is_intersect_r_r(Shape * a, Shape * b);

// function to check intersection of a rectangle and a triangle
bool is_intersect_r_t(Shape* a, Shape* b);"
```

```c++
// Add implementation of multimethod for two rectangles
// and for rectangle and triangle
#include<functions.h>

int main() {
  // Multimethod for Shape subclasses
  // returns a bool and is commutative
  Multimethod2<Shape, bool, true> is_intersect;

  // Create two shapes
  Shape *s1 = new Triangle();
  Shape *s2 = new Rectangle();

  // Check that implementation for s1 and s2 exists
  if (is_intersect.hasImpl(s1, s2)) {
      // Call is_intersect_r_t(s2, s1) function
      bool res = is_intersect.call(s1, s2);
  }
}
```
Note: `is_intersect_r_t` expects the first argument to be a rectangle
and the second argument to be a triangle, but the arguments are passed in reverse order here.
Our implementation allows you to do this.

To store functions inside the class, we use `std::map`, which takes a `std::pair<std::type_index, std::type_index>` as the key.

