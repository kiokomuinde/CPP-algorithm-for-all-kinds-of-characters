#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

//sttruct of the account info
struct person_info
{
    string id;
    string name;
    int postCode;
    string city;
    string purchases;
    string returns;
    string relAccounts;

};

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
   
// partition the array using last element as pivot
int partition (struct person_info pinfo[], int low, int high) 
{ 
    int pivot = pinfo[high].postCode;    // pivot 
    int i = (low - 1);   
   
    for (int j = low; j <= high- 1; j++) 
    { 
        //if current element is smaller than pivot, increment the low element
        //swap elements at i and j
        if (pinfo[j].postCode <= pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(&pinfo[i].postCode, &pinfo[j].postCode); 
        } 
    } 
    swap(&pinfo[i + 1].postCode, &pinfo[high].postCode); 
    return (i + 1); 
} 
   
//quicksort algorithm
void quickSort(struct person_info pinfo[], int low, int high) 
{ 
    if (low < high) 
    { 
        //partition the array 
        int pivot = partition(pinfo, low, high); 
   
        //sort the sub arrays independently 
        quickSort(pinfo, low, pivot - 1); 
        quickSort(pinfo, pivot + 1, high); 
    } 
} 

//Function definition for reading printing the array of structs. 
void displayArray(struct person_info pinfo[], int size) 
{  
    for (int i=0; i < size; i++){
        
      cout<< right << setw(7) << pinfo[i].id;
      cout<< right << setw(17)<< pinfo[i].name;
      cout<< right << setw(7) << pinfo[i].postCode;
      cout<< right << setw(20)<< pinfo[i].city; 
      cout<< right << setw(12) << pinfo[i].purchases; 
      cout<< right << setw(12) << pinfo[i].returns;
      cout<< right << setw(15)  << pinfo[i].relAccounts << "\n"; 
    }

      cout<<"End List\n\n"<<endl;
      
} 

//Function definition for searching related accounts.
void search(struct person_info pinfo[], int size) 
{  
    cout<<"Related entity checking report"<<endl;
    for (int i=0; i < size; i++){
      string temp;
        for (int j = 0; j < size; ++j)
        {

          istringstream searched (pinfo[j].relAccounts);

          while(getline (searched, temp , ',')){ 

            if (pinfo[i].id == temp)
            {
              cout<< right << setw(7) << pinfo[i].id;
              cout<< right << setw(17)<< pinfo[i].name;
              cout<< right << setw(7) << pinfo[i].postCode;
              cout<< right << setw(20)<< pinfo[i].city; 
              cout<< right << setw(12) << pinfo[i].purchases; 
              cout<< right << setw(12) << pinfo[i].returns;
              cout<< right << setw(15)  << pinfo[i].relAccounts << "\n";
              cout<<"       "<< pinfo[j].id<< "  " << pinfo[j].name<< "\n" << endl;
            }
             
           
          } 
        }
    }

      cout<<"End List\n\n"<<endl;
      
}

//Function definition for searching those with alrming returns.
void valueSearch(struct person_info pinfo[], int size){

  cout<<"List of  those whose returns are greater than 25% of purchases\n"<<endl;

  for (int i=0; i < size; i++){

    if ((stoi(pinfo[i].returns) > stoi(pinfo[i].purchases)/4))
    {
      cout<< right << setw(7) << pinfo[i].id;
      cout<< right << setw(17)<< pinfo[i].name;
      cout<< right << setw(7) << pinfo[i].postCode;
      cout<< right << setw(20)<< pinfo[i].city; 
      cout<< right << setw(12) << pinfo[i].purchases; 
      cout<< right << setw(12) << pinfo[i].returns;
      cout<< right << setw(15)  << pinfo[i].relAccounts << "\n";

      if (stoi(pinfo[i].purchases  ) > 1000000)
      {
        cout <<  "    ****** warning : total account is: "<< pinfo[i].purchases <<endl;
      }
    }
  }

  cout<<"End List\n\n"<<endl;

}

//Reading the file and printing the accounts report.
void read(struct person_info pinfo[], int size){
  int totalPurchases = 0 , totalReturns = 0;
  for (int i = 0; i < size; ++i)
  {
    cout<< right << setw(7) << pinfo[i].id;
    cout<< right << setw(17)<< pinfo[i].name;
    cout<< right << setw(7) << pinfo[i].postCode;
    cout<< right << setw(20)<< pinfo[i].city; 
    cout<< right << setw(12) << pinfo[i].purchases; 
    cout<< right << setw(12) << pinfo[i].returns;
    cout<< right << setw(15)  << pinfo[i].relAccounts << "\n";


    totalPurchases = totalPurchases + stoi(pinfo[i].purchases);
    totalReturns = totalReturns + stoi(pinfo[i].returns);
  }

  cout<<"\nCount of records is:  "<<size<<endl;
  cout<<"Total purchases is:  "<<totalPurchases<<endl;
  cout<<"Total returns is:  "<<totalReturns<<endl;

  cout<<"End checking report\n\n"<<endl;

}



int main ()
{
  int i = 0;
  string fileName;
  fileName = "4971980_1651485922_Data1.txt";
  //Open our file to check number of fileds to be used to 
  //allocate the size of the array of structs.
  ifstream file(fileName);
  string str;

  cout<<"Assign1 2021"<<endl;

  if (!file.is_open()) {
        cerr << "Could not open the file - '"
             << fileName << "'" << endl;
        return EXIT_FAILURE;
    }else{

      cout<<"File: " <<fileName<<" loaded"<<endl;
    }

  int arrSize = 0;

  while (getline(file, str)) {
    arrSize++;
  }

  struct person_info pinfo[arrSize];

  file.close();
  //Reopen file to read in data
  file.open(fileName);
  string buffer;
  
  //Looping throough file line by line.
  while (getline (file, str)) {
  
    istringstream ls (str);
    getline (ls, pinfo[i].id, ',');
    getline (ls, pinfo[i].name, ',');

    getline (ls, buffer, ',');
    pinfo[i].postCode = stoi(buffer);

    getline (ls, pinfo[i].city, ',');
    getline (ls, pinfo[i].purchases, ',');
    getline (ls, pinfo[i].returns, ',');
    ls >> pinfo[i].relAccounts;

   i++;
  }

  // search(pinfo, arrSize);
   // valueSearch(pinfo, arrSize);

  //Infinite loop to be exited when the user wants to exit or incase of invalid input.
  for(; ;){

  string menu;
  cout<<left << "Assign1 2021 menu\n";
  cout<<left << setw(10) <<"E  -  "; cout<<right <<"EXit\n";
  cout<<left << setw(10) <<"R  -  "; cout<<right <<"Read file\n";
  cout<<left << setw(10) <<"Se  -  "; cout<<right <<"Search\n";
  cout<<left << setw(10) <<"V  -  "; cout<<right <<"Value search(Checks Related\n";
  cout<<left << setw(10) <<"So  -  "; cout<<right <<"Sort Postcode\n";
  cout<<left << setw(10) <<"Sob  -  "; cout<<right <<"Sort both(post code then name)\n";
  cout<<left << setw(10) <<"R  -  "; cout<<right <<"read file\n";
  cout<<left << setw(10) <<"P  -  "; cout<<right <<"Path Find\n";
  cout<<left << setw(10) <<"F  -  "; cout<<right <<"set filename\n";
  cout<<"Enter your choice  ";

  cin >> menu; // get user input from the keyboard

  cout<<"Option selected is: "<< menu<<"\n"<<endl;
  
  //Menu logic
  if (menu == "so" || menu == "SO" || menu == "So")
  {
    quickSort(pinfo, 0, arrSize-1);
    displayArray(pinfo,arrSize);

  }else if (menu == "sob" || menu == "Sob"  || menu == "SOB" )
  {
    quickSort(pinfo, 0, arrSize-1);
    displayArray(pinfo,arrSize);

  }else if (menu == "v" || menu == "V")
  {
    valueSearch(pinfo, arrSize);

  }else if (menu == "se" || menu == "Se"  || menu == "SE" )
  {
    search(pinfo, arrSize);

  }else if (menu == "r" || menu == "R")
  {
    read(pinfo, arrSize);

  }else if (menu == "E" || menu == "e" ){

    return 0;

  }else if (menu == "P" || menu == "p" ){

    cout<<"Enter File path "<<endl;
    cin >> fileName;
    cout<<"The file path is"<<fileName;

  }else if (menu == "F" || menu == "f" ){
    cout<<"Enter Filename ";
    cin >> fileName;
    cout<<"The file name is: "<<fileName<<endl;

  }else{

    cout << "The menu choice entered does not exist \n" << menu;

    menu = "";

  }
}

  
}
