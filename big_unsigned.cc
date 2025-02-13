#include <iostream>
#include <vector>
#include <cassert>

#include "big_unsigned.h"


  // ● Constructores:
  // YO GUARDO EL NUMERO AL REVES Y LO IMPRIMO EN EL SENTIDO CORRECTO
  // le pasas un numero debo pasarlo a char con ascii

  BigUnsigned::BigUnsigned(unsigned int n) { // es un numero 0 al 4,294,967,295
    unsigned int digit;
    if (n == 0) {
      bu_value_.push_back(n + '0');
    }
    while (n != 0) {
      digit = n % 10;
      n = n / 10;
      bu_value_.push_back(digit + '0'); // + '0' para visualizar el valor
    }

  }


  // 1234567... irlo separando
  BigUnsigned::BigUnsigned(const unsigned char* chain_ptr) { // coger cada uno de los caracteres del char* y irlo poniendo en el vector
    while (*chain_ptr != '\0') { // while (*chain_ptr)
      // bu_value_.push_back(*chain_ptr); no sirve porque me da el valor al reves por como funciona mi operator<<
      bu_value_.insert(bu_value_.begin(), *chain_ptr);
      ++chain_ptr;
    }
  }

 // Constructor de copia
  BigUnsigned::BigUnsigned(const BigUnsigned& other) {
    bu_digit_ = other.bu_digit_;
    bu_value_ = other.bu_value_;
  }
  
  
  // ● Asignación:
  // BigUnsigned& BigUnsigned::operator=(const BigUnsigned& other) { // no es BigUnsigned::BigUnsigned&, sino solo BigUnsigned&
  //   if (*this = other) { // evitar la autoasignacion
  //     bu_digit_ = other.bu_digit_;
  //     bu_value_ = other.bu_value_;
  //   }
  //   return *this;
  // }

  // ● Inserción y extracción en flujo: (friends)
  std::ostream& operator<<(std::ostream& os, const BigUnsigned& other) {
    for (int i = other.GetBuValue().size() - 1; i >= 0; --i) { // hay que hacerlo al reves
      if (other.bu_value_[0] == '0') { // si el primer caracter es 0 eliminalo
        other.bu_value_.erase(other.bu_value_.begin());
      }
      os << other.GetBuValue()[i];
    }
    return os;
  }

  std::istream& operator>>(std::istream& is, BigUnsigned& other) { // leer datos std::cin >> bu5;
    std::string input;
    is >> input;
    for (char character : input) {
      other.bu_value_.insert(other.bu_value_.begin(), character);
    }
    return is;
  }

  // ● Comparación: (friends)
  bool BigUnsigned::operator==(const BigUnsigned& other) const { // mismo tamaño y mismos elementos en misma posicion
    if (bu_value_.size() != other.bu_value_.size()) {
      return false;
    }
    for (unsigned int i = 0; i < other.bu_value_.size(); ++i) {
      if (bu_value_[i] != other.bu_value_[i]) {
        return false;
      }
    }
    return true;
  }

  bool operator<(const BigUnsigned& bu1, const BigUnsigned& bu2) {
    bool is_lower = false;// bu1 < bu2 sera true
    if (bu1.bu_value_.size() < bu2.bu_value_.size()) {
      is_lower = true;
    }
    else if (bu1.bu_value_.size() > bu2.bu_value_.size()) {
      is_lower = false;
    }
    else { // ==
      for (int i = bu1.GetBuValue().size() - 1; i >= 0; --i) {
        if (bu1.bu_value_[i] < bu2.bu_value_[i]) {
          is_lower= true;
        }
        else {
          is_lower = false;
        }
      }
    }
    return is_lower;
  }

  // //   ● Incremento/decremento:

  // // Pre-incremento
  BigUnsigned& BigUnsigned::operator++() {
    BigUnsigned pre_increment;
    pre_increment.bu_value_.push_back('1');
    *this = *this + pre_increment;
    return *this;
  }

  // Post-incremento
  BigUnsigned BigUnsigned::operator++(int n) {  // el int n es una marca para distinguir el pre inc del post inc
    BigUnsigned post_increment = *this;  
    ++(*this);                 
    return post_increment;
  }

  // Pre-decremento
  BigUnsigned& BigUnsigned::operator--() {
    BigUnsigned pre_decrement;
    pre_decrement.bu_value_.push_back('1');
    *this = *this - pre_decrement;
    return *this;
  }

  // Post-decremento
  BigUnsigned BigUnsigned::operator--(int n) { 
    BigUnsigned post_decrement = *this;  
    --(*this);                 
    return post_decrement;
  } 

  // // ● Operadores aritméticos:

  

   BigUnsigned operator+(const BigUnsigned& bu1, const BigUnsigned& bu2) {
      unsigned int carry{0};
      unsigned int sum{0};
      BigUnsigned result;
      unsigned int max_bu_size = std::max(bu1.bu_value_.size(), bu2.bu_value_.size());
        
        for (unsigned int i = 0; i < max_bu_size; ++i) {
          unsigned int bu1_digit{0};
          if (i < bu1.bu_value_.size()) {
            bu1_digit = bu1.bu_value_[i] - '0';
          }
          unsigned int bu2_digit{0};
          if (i < bu2.bu_value_.size()) {
            bu2_digit = bu2.bu_value_[i] - '0';
          }
          sum = bu1_digit + bu2_digit + carry; // hay que poner menos '0' o sino no suma bien
          carry = sum / 10;
          sum = sum % 10;
           // el carry se le suma al numero siguiente
          result.bu_value_.push_back(sum + '0');
        }
        if (carry == 1) { // caso en el que no queden mas operaciones de digitos y haya carry
          result.bu_value_.push_back(carry + '0'); // puede que haga falta usar insert
        }
      return result;
    }
      // unsigned int a unsgined char + '0'
      // unsigned char a unsigned int - '0'
  // si la resta da negativo devolver 0 si la resta da positivo devolver el valor
  BigUnsigned BigUnsigned::operator-(const BigUnsigned& other) const {
      unsigned int sub{0};
      BigUnsigned result;
      unsigned int max_bu_size = std::max(bu_value_.size(), other.bu_value_.size());
        
        for (unsigned int i = 0; i < max_bu_size; ++i) {
          unsigned int bu1_digit{0};
          if (i < bu_value_.size()) {
            bu1_digit = bu_value_[i] - '0';
          }
          unsigned int bu2_digit{0};
          if (i < other.bu_value_.size()) {
            bu2_digit = other.bu_value_[i] - '0';
          }
          if (bu1_digit == 0) {
            
          }
          sub = bu1_digit - bu2_digit; // hay que poner menos '0' o sino no suma bien
          sub = sub % 10;
           // el carry se le suma al numero siguiente
          result.bu_value_.push_back(sub + '0');
        }
      return result;
  }

  // mod
  bool operator!=(const BigUnsigned& bu1, const BigUnsigned& bu2) {
    return !(bu1 == bu2);
  }

  // BigUnsigned BigUnsigned::operator*(const BigUnsigned& other) const { // uso la sobrecarga de operador+
   
  // }

  // necesario para operator*
  unsigned int VectorToUnsignedIntReverse(const std::vector<unsigned char>& vec) {
    unsigned int number = 0;
    unsigned int multiplier = 1;
    
    for (unsigned char digit : vec) {
        number += (digit - '0') * multiplier;
        multiplier *= 10;
    }
    
    return number;
}

  BigUnsigned BigUnsigned::operator*(const BigUnsigned& other) const {
    BigUnsigned multiplication;
    unsigned int this_value = VectorToUnsignedIntReverse(bu_value_);
    unsigned int other_value = VectorToUnsignedIntReverse(other.bu_value_);
    unsigned int iterations = std::min(this_value, other_value);

    while (iterations != 0) {  
        multiplication = multiplication + *this;
        --iterations;
    }
    return multiplication;
}

  // friend
  // dividend(bu1) - divider(bu2)
  // bucle infinito error
  // la idea es restar bu1 con bu2 hasta que la resta sea mayor que bu2 
  BigUnsigned operator/(const BigUnsigned& bu1, const BigUnsigned& bu2) {
    BigUnsigned operation = bu1 - bu2; // 15 menos 4 = 11
    unsigned int quotient{0};

    while (!(operation < bu2)) { // while (operation > bu2) 16 > 4? si 
      ++quotient; // c = 1
      std::cout << "cociente= " << quotient <<  " op= " << operation  << " bu2= " << bu2 << std::endl;
      char a;
      std::cin >> a;
      operation = operation - bu2; // 16 menos 4 = 12

    }
    return quotient;
  }

  // BigUnsigned::BigUnsigned operator%(const BigUnsigned& other) const {

  // }