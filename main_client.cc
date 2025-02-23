#include <iostream>
#include <vector>

#include "big_unsigned.h"

int main() {
  // BigUnsigned bu{4294967295};
  // std::cout << bu << std::endl;

  // const unsigned char* cadena = reinterpret_cast<const unsigned char*>("12345678910111213141516171819202122232425");
  // BigUnsigned bu1{cadena};
  // std::cout << bu1 << std::endl;

  // BigUnsigned bu2(bu1);
  // std::cout << bu2 << std::endl;

  // BigUnsigned bu3 = bu1;
  // std::cout << "copia = " <<bu3 << std::endl;

  // BigUnsigned bu4;
  // std::cin >> bu4;
  // std::cout << bu4 << std::endl;

  // if (bu3 == bu4) {
  //   std::cout << "bu3 = " << bu3 << " == " << " bu4 = " << bu4 << std::endl;
  // }
  // else {
  //   std::cout << "bu3 = " << bu3 << " != " << " bu4 = " << bu4 << std::endl;
  // }


  // BigUnsigned bu5{45};
  // BigUnsigned bu6{4567};
  // if (bu5 < bu6) {
  //   std::cout << "bu5 = " << bu5 << " < " << " bu6 = " << bu6 << std::endl;
  // }
  // else {
  //   std::cout << "bu5 = " << bu5 << " > " << " bu6 = " << bu6 << std::endl;
  // }


  BigUnsigned bu5{11181};
  BigUnsigned bu6{11111};
  // // BigUnsigned bu7 = bu5 + bu6;
  // // std::cout << bu7 << std::endl;


  BigUnsigned bu7 = bu5 - bu6;
  std::cout << bu7 << std::endl;

  // BigUnsigned bu8{999};
  // bu8++;
  // std::cout << bu8 << std::endl;
  // ++bu8;
  // std::cout << bu8 << std::endl;

  // bu8 = 1000;
  // --bu8;
  // std::cout << bu8 << std::endl; // 0999
  // bu8--;
  // std::cout << bu8 << std::endl;

  // 1224 * 9 funciona
  // 1224 * 10 se peta
  // BigUnsigned bu9{1224}; 
  // BigUnsigned bu10{10};
  // BigUnsigned bu11 = bu9 * bu10;
  // std::cout << bu11 << std::endl;

  return 0;
}
