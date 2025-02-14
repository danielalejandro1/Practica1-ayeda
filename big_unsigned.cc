#include <iostream>
#include <vector>
#include <cassert>

#include "big_unsigned.h"

  BigUnsigned::BigUnsigned(unsigned int n) {
    if (n == 0) {
      bu_value_.push_back(0);
    }
    unsigned int digit;
    while (n != 0) {
      digit = n % 10 + '0';
      n = n / 10;
      bu_value_.push_back(digit);
    }

  }

  BigUnsigned::BigUnsigned(const unsigned char* chain_ptr) { 
    while (*chain_ptr != '\0') { // while (*chain_ptr)
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
  BigUnsigned& BigUnsigned::operator=(const BigUnsigned& other) { 
    if (this != &other) { // evitar la autoasignacion
      bu_digit_ = other.bu_digit_;
      bu_value_ = other.bu_value_;
    }
    return *this;
  }

  // ● Inserción y extracción en flujo: (friends)
  std::ostream& operator<<(std::ostream& os, const BigUnsigned& other) {
    for (int i = other.GetBuValue().size() - 1; i >= 0; --i) { 
      os << other.GetBuValue()[i];
    }
    return os;
  }


  // std::istream& operator>>(std::istream& is, BigUnsigned& other) { // leer datos std::cin >> bu5;
  
  // }

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
    bool is_lower = false;
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
  BigUnsigned BigUnsigned::operator++(int n) {  
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

   // ● Operadores aritméticos:
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
          sum = bu1_digit + bu2_digit + carry; 
          carry = sum / 10;
          sum = sum % 10;
          result.bu_value_.push_back(sum + '0');
        }
        if (carry == 1) { // caso en el que no queden mas operaciones de digitos y haya carry
          result.bu_value_.push_back(carry + '0'); 
        }
      return result;
    }
      
  BigUnsigned BigUnsigned::operator-(const BigUnsigned& other) const {
      unsigned int sub{0};
      BigUnsigned result;
      bool borrow = false; // flag para ver si el siguiente numero se le resta 1
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
           if (borrow) {
            bu1_digit = bu1_digit - 1;
            borrow = false;
          }
          if (bu1_digit < bu2_digit) {
            bu1_digit = bu1_digit + 10;
            borrow = true;
          }
          sub = bu1_digit - bu2_digit; 
          sub = sub % 10;
          result.bu_value_.push_back(sub + '0');
        }
      return result;
  }

  bool operator!=(const BigUnsigned& bu1, const BigUnsigned& bu2) {
    return !(bu1 == bu2);
  }


  // necesario para mi operator*
  unsigned int VectorToUnsignedInt(const std::vector<unsigned char>& vec) {
    unsigned int number{0};
    unsigned int multiplier{1};
    
    for (unsigned char digit : vec) {
        number += (digit - '0') * multiplier;
        multiplier *= 10;
    }
    
    return number;
}

  BigUnsigned BigUnsigned::operator*(const BigUnsigned& other) const {
    BigUnsigned multiplication;
    unsigned int this_value = VectorToUnsignedInt(bu_value_);
    unsigned int other_value = VectorToUnsignedInt(other.bu_value_);
    unsigned int iterations = std::min(this_value, other_value);

    while (iterations != 0) {  
        multiplication = multiplication + *this;
        --iterations;
    }
    return multiplication;
}

  // dividend(bu1) - divider(bu2)
  // bucle infinito error 
  BigUnsigned operator/(const BigUnsigned& bu1, const BigUnsigned& bu2) {
    BigUnsigned operation = bu1 - bu2; // 20 menos 4 = 16
    unsigned int quotient{0};

    while (!(operation < bu2)) { // while (operation >= bu2) 16 > 4? si 
      operation = operation - bu2; // 16 menos 4 = 12
      ++quotient; // c = 1
      std::cout << quotient << " ";
    }
    return quotient;
  }

  // BigUnsigned::BigUnsigned operator%(const BigUnsigned& other) const {

  // }
