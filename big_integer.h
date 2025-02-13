#ifndef BIG_INTEGER_H
#define BIG_INTEGER_H

class BigInteger() {
 public:
  // ● Constructores:
  BigInteger(int n = 0);
  BigInteger(const BigUnsigned&); // Constructor de cambio de tipo

  BigInteger(const unsigned char*);
  BigInteger(const BigInteger&); // Constructor de copia
  // ● Asignación:
  BigInteger& operator=(const BigInteger&);
  // ● Inserción y extracción en flujo:
  friend std::ostream& operator<<(std::ostream&, const BigInteger&);
  friend std::istream& operator>>(std::istream&, BigInteger&);
  // ● Comparación:
  bool operator==(const BigInteger&) const;
  friend bool operator<(const BigInteger&, const BigInteger&);

  //   ● Incremento/decremento:
  BigInteger& operator++(); // Pre-incremento
  BigInteger operator++(int); // Post-incremento
  BigInteger& operator--(); // Pre-decremento
  BigInteger operator--(int); // Post-decremento
  // ● Operadores aritméticos:
  friend BigInteger operator+(const BigInteger&, const BigInteger&);
  BigInteger operator-(const BigInteger&) const;
  BigInteger operator*(const BigInteger&) const;
  friend BigInteger operator/(const BigInteger&, const BigInteger&);
  BigInteger operator%(const BigInteger&) const;
 
 private:
//   BigInteger min_value_{};
//   BigInteger mid_value_{0};
//   BigInteger max_value_{};
};

#endif // BIG_INTEGER_H