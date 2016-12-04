#include <Vnesh_Sort.cpp>
#include <catch.hpp>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

SCENARIO("8mb", "[8mb]")
{
  Vnesh_sort("8mb", "out_8", 1);
  bool x = true;
  ifstream f1("out_8"), f2("out8");
  line s1, s2;
  while(!f2.eof() && !f1.eof())
  {
    if((f1>>s1)&&(f2>>s2))
    {
      if(s1.name!=s2.name)
      {
        x=false;
        break;
      }
    }
    else break;
  }
  f1.close();
  f2.close();
  REQUIRE(x);
}

SCENARIO("15mb", "[15mb]")
{
  Vnesh_sort("15mb", "out_15", 4);
  bool x = true;
  ifstream f1("out_15"), f2("out15");
  line s1, s2;
  while(!f2.eof() && !f1.eof())
  {
    if((f1>>s1)&&(f2>>s2))
    {
      if(s1.name!=s2.name)
      {
        x=false;
        break;
      }
    }
    else break;
  }
  f1.close();
  f2.close();
  REQUIRE(x);
}

SCENARIO("32mb", "[32mb]")
{
  Vnesh_sort("32mb", "out_32", 17);
  bool x = true;
  ifstream f1("out_32"), f2("out32");
  line s1, s2;
  while(!f2.eof() && !f1.eof())
  {
    if((f1>>s1)&&(f2>>s2))
    {
      if(s1.name!=s2.name)
      {
        x=false;
        break;
      }
    }
    else break;
  }
  f1.close();
  f2.close();
  REQUIRE(x);
}
