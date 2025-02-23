#include <iostream>
#include <vector>
#include <string>

#include "big_unsigned.h"

// funcionando
// si pones 0numero no se imprime correctamente en este constructor
BigUnsigned::BigUnsigned(unsigned int n) {
  if (n == 0) {
    bu_value_.push_back(n + '0');
  }
  unsigned int digit;
  while (n != 0) {
    digit = n % 10 + '0';
    n = n / 10;
    bu_value_.push_back(digit);
  }
}
// funcionando
BigUnsigned::BigUnsigned(const unsigned char* chain_ptr) {
  while (*chain_ptr) {
    bu_value_.insert(bu_value_.begin(), *chain_ptr);
    ++chain_ptr;
  }
}
// funcionando
BigUnsigned::BigUnsigned(const BigUnsigned& other) {
  bu_value_ = other.bu_value_;
}
// funcionando
BigUnsigned& BigUnsigned::operator=(const BigUnsigned& other) {
  bu_value_ = other.bu_value_;
  return *this;
}

// funcionando
std::istream& operator>>(std::istream& is, BigUnsigned& other) {
  std::string big_unsigned; // 1234
  is >> big_unsigned;
  other.bu_value_.clear(); // para eliminar el 0 del principio residual
  for(char character : big_unsigned) {
    other.bu_value_.insert(other.bu_value_.begin(), character); // lo meto al reves para que al imprimirlo lo imprima bien
  }
  return is;
}

// funcionando
bool BigUnsigned::operator==(const BigUnsigned& other) const {
  if (bu_value_.size() != other.bu_value_.size()) { // si los tamaños son distintos no son el mismo numero
    return false;
  }
  bool equal;
  for(size_t i{0}; i < other.bu_value_.size(); ++i) {
    if (bu_value_[i] == other.bu_value_[i]) { // si cada elemento es igual
      equal = true;
    }
    else {
      return false;
    }
  }
  return equal; 
}

bool BigUnsigned::operator!=(const BigUnsigned& other) const {
  return !(*this == other);
}

// funcionando
bool operator<(const BigUnsigned& bu1, const BigUnsigned& bu2) { // 1234 1233
  if (bu1.bu_value_.size() > bu2.bu_value_.size()) {
    return false;
  }
  if (bu1.bu_value_.size() < bu2.bu_value_.size()) {
    return true;
  }
  if (bu1.bu_value_.size() == bu2.bu_value_.size()) {
    for (size_t i{0}; i < bu1.bu_value_.size(); ++i) {
      if (bu1.bu_value_[i] > bu2.bu_value_[i]) {
        return false;
      }
    }
  }
  return true;
}

BigUnsigned operator+(const BigUnsigned& bu1, const BigUnsigned& bu2) {
  BigUnsigned result;
    result.bu_value_.clear();
    unsigned int carry = 0;
    // mismo tamaños de vectores
    if (bu1.bu_value_.size() == bu2.bu_value_.size()) {
      for (size_t i = 0; i < bu1.bu_value_.size(); ++i) {
        unsigned int sum = ((bu1.bu_value_[i] - '0') + (bu2.bu_value_[i] - '0')) + carry;
        carry = sum / 10;  
        result.bu_value_.push_back((sum % 10) + '0'); 
      }
    }
    // primer vector mayor que el segundo
    if (bu1.bu_value_.size() > bu2.bu_value_.size()) {
      for (size_t i = 0; i < bu2.bu_value_.size(); ++i) {
        unsigned int sum = ((bu1.bu_value_[i] - '0') + (bu2.bu_value_[i] - '0')) + carry;
        carry = sum / 10;
        result.bu_value_.push_back((sum % 10) + '0');
      }
        for (size_t j = bu2.bu_value_.size(); j < bu1.bu_value_.size(); ++j) {
          unsigned sum = (bu1.bu_value_[j] - '0') + carry;
          carry = sum /10;
          result.bu_value_.push_back((sum % 10) + '0');
        }
    }
    // segundo vector mayor que el primero
    if (bu1.bu_value_.size() < bu2.bu_value_.size()) {
      for (size_t i = 0; i < bu1.bu_value_.size(); ++i) {
        unsigned int sum = ((bu1.bu_value_[i] - '0') + (bu2.bu_value_[i] - '0')) + carry;
        carry = sum / 10;
        result.bu_value_.push_back((sum % 10) + '0');
      }
        for (size_t j = bu1.bu_value_.size(); j < bu2.bu_value_.size(); ++j) {
          unsigned sum = (bu2.bu_value_[j] - '0') + carry;
          carry = sum /10;
          result.bu_value_.push_back((sum % 10) + '0');
        }
    }
    // si queda carry añado un 1 al principio
    if (carry > 0) {
        result.bu_value_.push_back(carry + '0');
    }
    return result;
}
// funcionando
BigUnsigned BigUnsigned::operator-(const BigUnsigned& other) const {
   BigUnsigned result;
    result.bu_value_.clear();
    unsigned int borrow = 0;
    // caso this < other
    if (bu_value_.size() < other.bu_value_.size()) { // bien
      result.bu_value_.push_back('0');
      return result;
    }
  
    // caso this == other
    if (bu_value_.size() == other.bu_value_.size()) { // bien
      for (size_t i = 0; i < bu_value_.size(); ++i) {
        if ((bu_value_[i] - '0') < (other.bu_value_[i] - '0')) { // cocinada directa del cheff
          result.bu_value_.clear(); // se carga un 5 random que aparece
          result.bu_value_.push_back('0');
          return result;
        }
         int sub = (bu_value_[i] - '0') - (other.bu_value_[i] - '0') - borrow;
        if (sub < 0) {
          sub = sub + 10;
          borrow = 1;
        }
        else {
          borrow = 0;
        }
        result.bu_value_.push_back(sub + '0'); 
      }
    }
    // // primer vector mayor que el segundo
    if (bu_value_.size() > other.bu_value_.size()) {
      for (size_t i = 0; i < other.bu_value_.size(); ++i) {
        int sub = ((bu_value_[i] - '0') - (other.bu_value_[i] - '0')) - borrow;
        if (sub < 0) {
          sub = sub + 10;
          borrow = 1;
        }
        else {
          borrow = 0;
        }
        result.bu_value_.push_back(sub + '0');
      }
        for (size_t j = other.bu_value_.size(); j < bu_value_.size(); ++j) {
          int sub = (bu_value_[j] - '0') - borrow;
          if (sub < 0) {
            sub = sub + 10;
            borrow = 1;
          }
          else {
            borrow = 0;
          }
          result.bu_value_.push_back(sub + '0');
        }
    }
    return result;
}

 // funcionando
 BigUnsigned& BigUnsigned::operator++() {
  BigUnsigned one{1};
  *this = *this + one;
  return *this;
 }

 // funcionando
 BigUnsigned BigUnsigned::operator++(int) {
  BigUnsigned temp = *this;
  BigUnsigned one{1};
  *this = *this + one;
  return temp;
 }
 // funcionando
 BigUnsigned& BigUnsigned::operator--() {
  BigUnsigned one{1};
  *this = *this - one;
  return *this;
 }
 // funcionando
 BigUnsigned BigUnsigned::operator--(int) { 
  BigUnsigned temp = *this;
  BigUnsigned one{1};
  *this = *this - one;
  return temp;
 }

 // la idea es que si es 1234 * 3 haga 
 // repeat > this + this (other times)
 // funciona x * 1..9 pero a partir de 10 da bucle infinito
 // tengo el prescentimiento de que es porque lo comparo con 0 y a partir de 2 cifras al usar -- pondria 00, tres cifras 000 y asi que son != 0
 // de hecho el problema es que compara 00 con 0 no sale del while y pasa de 00 a 99
 BigUnsigned BigUnsigned::operator*(const BigUnsigned& other) const {
   BigUnsigned result;
   BigUnsigned zero;
   BigUnsigned other_copy = other;
   while (other_copy != zero) {
     result = result + *this; // sumar el mismo numero hasta que other sea = 0 
     --other_copy;
     std::cout << other_copy << std::endl;
     char a; // debugeo
     std::cin >> a;
   }
   return result;
 }

// funcionando
std::ostream& operator<<(std::ostream& os, const BigUnsigned& other) {
  for (int i = other.bu_value_.size() - 1; i >= 0; --i) {
    os << other.bu_value_[i];
  }
  return os;
}
