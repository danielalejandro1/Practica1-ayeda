#ifndef BIG_UNSIGNED_H 
#define BIG_UNSIGNED_H

#include <vector>

class BigUnsigned {
  public:
   // constructores
   BigUnsigned(unsigned n = 0);
   BigUnsigned(const unsigned char*);
   BigUnsigned(const BigUnsigned&);

   // asignacion
   BigUnsigned& operator=(const BigUnsigned&);

   // inserccion y extraccion
   friend std::ostream& operator<<(std::ostream&, const BigUnsigned&);
   friend std::istream& operator>>(std::istream&, BigUnsigned&);

   // comparación:
   bool operator==(const BigUnsigned&) const;
   bool operator!=(const BigUnsigned& other) const;
   friend bool operator<(const BigUnsigned&, const BigUnsigned&);

   // incremento/decremento:
   BigUnsigned& operator++(); // Pre-incremento
   BigUnsigned operator++(int); // Post-incremento
   BigUnsigned& operator--(); // Pre-decremento
   BigUnsigned operator--(int); // Post-decremento

   // operadores aritméticos:
  friend BigUnsigned operator+(const BigUnsigned&, const BigUnsigned&);
  BigUnsigned operator-(const BigUnsigned&) const;
  BigUnsigned operator*(const BigUnsigned&) const;
  friend BigUnsigned operator/(const BigUnsigned&, const BigUnsigned&);
  BigUnsigned operator%(const BigUnsigned&) const;

  private:
   std::vector<unsigned char> bu_value_;
};

#endif // BIG_UNSIGNED_H
