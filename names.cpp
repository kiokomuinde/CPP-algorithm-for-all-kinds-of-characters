#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

const int MAX_PERSON_INFO = 3;

struct person_info
{
  string name;
  string gender;
  string age;
} pinfo[MAX_PERSON_INFO];

int main () 
{
  string s ("Olivia Montgomery*female*47;John Newton*male*34;Carla Walton*female*43;");
  istringstream iss (s);
  string buffer;
  int i = 0;
  while (getline (iss, buffer, ';') && i < MAX_PERSON_INFO)
  {
    istringstream ls (buffer);
    getline (ls, pinfo[i].name, '*');
    getline (ls, pinfo[i].gender, '*');
    ls >> pinfo[i].age;
    i++;
  }

  for (auto p : pinfo)
  {
    cout << "\nName = " << p.name;
    cout << "\nGender = " << p.gender;
    cout << "\nAge = " << p.age << '\n';
  }

  system ("pause");
  return 0;
}