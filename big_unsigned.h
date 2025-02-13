#ifndef BIG_UNSIGNED_H
#define BIG_UNSIGNED_H

// 0 to MAX_VALUE 
// 0 to quetta (10^(30))
// 0 to 100.000.000.000.000.000.000.000.000.000.000


#include <vector>

// constexpr double QUETTA = 1e30;

class BigUnsigned {
 public:
  // ● Constructores:
  BigUnsigned(unsigned n = 0); // unsigned por defecto es unsigned int
  BigUnsigned(const unsigned char*); // puntero a un unsigned se le puede pasar una cadena de caracteres lo tan largo que quieras
  BigUnsigned(const BigUnsigned&); // Constructor de copia

  const std::vector<unsigned char> GetBuValue() const { return bu_value_; }
  // ● Asignación:
  // BigUnsigned& operator=(const BigUnsigned&);
  // ● Inserción y extracción en flujo:
  friend std::ostream& operator<<(std::ostream&, const BigUnsigned&);
  friend std::istream& operator>>(std::istream&, BigUnsigned&);
  // ● Comparación:
  bool operator==(const BigUnsigned&) const;
  friend bool operator<(const BigUnsigned&, const BigUnsigned&);
  friend bool operator!=(const BigUnsigned&, const BigUnsigned&);

  //   ● Incremento/decremento:
  BigUnsigned& operator++(); // Pre-incremento
  BigUnsigned operator++(int); // Post-incremento
  BigUnsigned& operator--(); // Pre-decremento
  BigUnsigned operator--(int); // Post-decremento
  // ● Operadores aritméticos:
  friend BigUnsigned operator+(const BigUnsigned&, const BigUnsigned&);
  BigUnsigned operator-(const BigUnsigned&) const;
  BigUnsigned operator*(const BigUnsigned&) const;
  friend BigUnsigned operator/(const BigUnsigned&, const BigUnsigned&);
  BigUnsigned operator%(const BigUnsigned&) const;
 private: 
  unsigned char bu_digit_; 
  std::vector<unsigned char> bu_value_; // se debe limitar de 0 a quetta
  bool sign_;
  //int size_; // creo que deberia ser vector pq si el vector puede ser tan grande como quieras su tamaño tambien
};

#endif // BIG_UNSIGNED_H








// //   BigUnsigned min_value_{0};
// //   BigUnsigned max_value_{pow(10, 30)};
//   // unsigned char quetta_bytes_[13]; //   2^(N) - 1 >= N     //    LOGBASE2(N + 1) / 8
//   // std::vector<quetta_bytes_> quetta_vector_;  
//   unsigned char bu_digit_;
//   // unsigned char max_size_{QUETTA};
//   std::vector<unsigned char> bu_value_; // se debe limitar de 0 a quetta

// std::vector[1|2|3|4|5|||||] 1 2 3 4 5 = unsigned chars
// bigint > atributo bigunsigned y signo