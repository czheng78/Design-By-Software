//Copyright 2017 Chuan Xing Zheng czheng78@bu.edu
//U32336445
//HWK3

#include <vector>

using namespace std;

// Define the vector type Poly
// Make an empty vector with type Poly
typedef vector<double> Poly;
Poly c, d, vec, vec2;

// Add two polynomials, returning the result
Poly add_poly(const Poly &a, const Poly &b) {
  // Define size variable
  int vsize;
  // Save the size of the larger vector to vsize
  if (a.size() > b.size()) {
    vsize = a.size();
  } else if (a.size() < b.size()) {
    vsize = b.size();
  } else {
    vsize = a.size();
  }
  // After adding each coefficient, put it in the c vector
  for (int i = 0; i < vsize; i++) {
    c.push_back(a[i] + b[i]);
  }
  // When result vector is all 0
  vec2.resize(c.size(), 0);
  if (c == vec2) {
    c.resize(1, 0);
  }

  // When result vector is smaller
  if (c.back() == 0 & c.size() > 1)
    c.erase(c.end() - 1);

  return c;
}

// Multiply two polynomials, returning the result.
Poly multiply_poly(const Poly &a, const Poly &b) {
  // Resize vector d
  d.resize(a.size() + b.size() - 1, 0);
  // Multiply term by term
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < b.size(); j++) {
      d[i + j] += a[i] * b[j];
    }
  }
  // When result is all 0
  vec.resize(d.size(), 0);
  if (d == vec) {
    d.resize(1, 0);
  }
  return d;
}