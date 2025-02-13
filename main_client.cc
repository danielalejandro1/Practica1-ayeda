// int 0 to 2,147,483,647 
// 4 bytes
// 4*8=32 bits


// big_unsigned 0 to 1*10^30


#include <iostream>
#include <vector>
#include <cstring> // strlen()

#include "big_unsigned.h"

int main(int argc, char* argv[]) {
  // unsigned int number = 7;
  // unsigned int number2 = 82;
  // BigUnsigned bu{number}; // BigUnsigned bu(7) tambien funciona
  // BigUnsigned bu2{number2};
  // // bu = 0? BingUnsigned bu3; da 0 por defecto bien,
  // // por que BigUnsigned bu3{0}; no funciona?
  // unsigned int zero = 0; // se debe especificar porque sino genera ambiguedads
  // BigUnsigned bu3(zero);
  // // std::cout << bu << std::endl;
  // // std::cout << bu2 << std::endl;
  // // std::cout << bu3 << std::endl;
  // // BigUnsigned bu_max{4294967295};
  // // std::cout << bu_max << std::endl;


  // // el reinterpret_cast es para pasar el const unsigned char* a const char*
  // // const unsigned char* cadena = reinterpret_cast<const unsigned char*>("12345678910111213141516171819202122232425");
  // // BigUnsigned bu3{cadena};
  // // std::cout << bu3 << std::endl; 
  // // // int len = strlen(reinterpret_cast<const char*>(cadena)); // tamaño cadena
  // // // std::cout << len << std::endl;


  // BigUnsigned copy_bu = bu;
  // BigUnsigned copy_bu2 = bu2;
  // BigUnsigned copy_bu3 = bu3;
  // std::cout << " copia de bu = 7      " << copy_bu << std::endl;
  // std::cout << " copia de bu2 = 82    " << copy_bu2 << std::endl;
  // std::cout << " copia de b3 = 0      " << copy_bu3 << std::endl;

  // esto no lo he sabido hacer
  BigUnsigned bu4;
  std::cin >> bu4;
  std::cout << bu4 << std::endl;

  // if (bu == bu2) {
  //   std::cout << bu << " es igual a " << bu2 << std::endl;
  // }
  // else {
  //   std::cout << bu << " NO es igual a " << bu2 << std::endl;
  // }

  // if (bu < bu2) {
  //   std::cout << bu << " Es menor que " << bu2 << std::endl;
  // }
  // else {
  //   std::cout << bu << " Es mayor que " << bu2 << std::endl;
  // }

  // BigUnsigned bu7{12345};
  // BigUnsigned bu8{56789};
  // BigUnsigned bu6 = bu7 + bu8;
  // std::cout << bu6 << std::endl;
  // bu7 = 1234, bu8 = 235, bu6 = bu7 + bu8;
  // std::cout << bu6 << std::endl;


  // bu6 = bu6 + 1;
  // std::cout << bu6 << std::endl;


  // ++bu6;
  // std::cout << bu6 << std::endl;
  
  // bu6++;
  // std::cout << bu6 << std::endl;


  // BigUnsigned bu9{22};
  // --bu9;
  // std::cout << bu9 << std::endl; // 21
  // bu9--;
  // std::cout << bu9 << std::endl; // 20



  // std::cout << std::endl;
  // BigUnsigned bu10{5678};
  // BigUnsigned bu11{1234};
  // BigUnsigned bu12 = bu10 - bu11;
  // std::cout << "bu12 = " << bu12 << std::endl;

  // bu10 = 5678, bu11 = 234, bu12 = bu10 - bu11;
  // std::cout << "bu12 = " << bu12 << std::endl;


  // std::cout << std::endl << std::endl;
  // BigUnsigned bu13{5678};
  // BigUnsigned bu14{3};
  // // // BigUnsigned bu15 = bu13 * bu14;
  // // // std::cout << "bu15 = " << bu15 << std::endl;

  // BigUnsigned bu15;
  // // bu13 = 5678, bu14 = 234, 
  // bu15 = bu13 * bu14;
  // std::cout << "bu15 = " << bu15 << std::endl;

  // std::cout << BigUnsigned(11356) + BigUnsigned(5678); funciona
  // std::cout << BigUnsigned(5678) + BigUnsigned(5678) + BigUnsigned(5678); // valor erroneo

  // not working yet
  // BigUnsigned bu16{15};
  // BigUnsigned bu17{4};
  // // BigUnsigned bu18 = bu16 - bu17;
  // BigUnsigned bu18 = bu16 / bu17;
  // // if (bu16 > bu17) {
  // //   std::cout << "funciona";
  // // }
  // // else {
  // //   std::cout << "funciona";
  // // }
  // std::cout << bu18 << std::endl;
  // return 0;
}