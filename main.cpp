#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <bits/stdc++.h>
using namespace std;

struct person_info
{
    string id;
    string name;
    string postCode;
    string city;
    string purchases;


};



int main ()
{
  int i = 0;
  ifstream file("4971980_1651485922_Data1.txt");
  string str;

  int arrSize = 0;

  while (getline(file, str)) {
    arrSize++;
  }
  struct person_info pinfo[arrSize];
  file.close();
  file.open("4971980_1651485922_Data1.txt");
  
  while (getline(file, str)) {
    
    
        // id is from position 0, to until first * found
        pinfo[i].id = str.substr(0, str.find(",", 0));
        str = str.substr(str.find(",", 0)+1, str.length());

        // name is from position 0 to until first * found
        pinfo[i].name = str.substr(0, str.find(",", 0));
        str = str.substr(str.find(",", 0)+1, str.length());

       // postCode is from position 0, to until ";" found
        pinfo[i].postCode = str.substr(0, str.find(",", 0));
        str = str.substr(str.find(",", 0)+1, str.length());

        // city is from position 0, to until ";" found
        pinfo[i].city = str.substr(0, str.find(",", 0));
        str = str.substr(str.find(",", 0)+1, str.length());

        // purchases is from position 0, to until ";" found
        pinfo[i].purchases = str.substr(0, str.find(',', 0));
        str = str.substr(str.find('"', 0)+1, str.length());
  

   i++;
  }

  for (int j= 0; j < arrSize; j++)
  {
    cout << pinfo[j].id << ", " << pinfo[j].name << ", " << pinfo[j].postCode
    << "," << pinfo[j].city << "," << pinfo[j].purchases << "\n";
  }
}
