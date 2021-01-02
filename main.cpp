#include <iostream>
#include "carton.h"
#include <array>

using namespace std;

int main() {
  // Create a constant int that will specify the size of the arrays
  // in this program. Set it to 20.
    int const kMaxSize = 20;

  // Write the value of the constant to cout.
  cout << "\nConstant to specify size of array: \n" << kMaxSize << endl;


  // Create a Carton object using the default constructor.
    Carton first_carton;

  // Use the getters to write the length, width, and height of
  // the Carton to cout.
  cout << "\nFirst Carton information:\n";
  cout << first_carton.GetLength() << " "
        << first_carton.GetWidth() << " "
        << first_carton.GetHeight();

  // Create a Carton object using the non-default constructor.
    Carton second_carton(2, 3, 4);

  // Use the getters to write the length, width, and height of
  // the Carton to cout.
  cout << "\nSecond Carton information:\n";
  cout << second_carton.GetLength() << " "
        << second_carton.GetWidth() << " "
        << second_carton.GetHeight();

  // Create an array of Cartons. Use the constant defined earlier for the
  // size of the array.

  array<Carton, kMaxSize> third_carton;

  // Update the first three elements of the array by adding Carton objects
  // created with the non-default constructor.

  third_carton[0] = Carton(2,6,3);
  third_carton[1] = Carton(8,3,5);
  third_carton[2] = Carton(4,7,3);

  // Loop through the first three elements in the array, use the getters
  // to write the length, width, and height of the Cartons.
  cout << "\nDetails of three Cartons in an array:\n";

  for (int i = 0; i < 3; ++i){
      cout << "Dimensions of carton " << i + 1 << ": "
            << third_carton[i].GetLength() << " "
            << third_carton[i].GetWidth() << " "
            << third_carton[i].GetHeight()
            << endl;
  }

  // Use the WriteData method to print the data of the two Cartons you
  // have created to cout.
  cout << "\nData of two Cartons:\n";
  first_carton.WriteData(cout);
  second_carton.WriteData(cout);

  // Use the WriteCarton method to print sentences about the two Cartons you
  // have created to cout.
  cout << "\nReport of two Cartons:\n";
  first_carton.WriteCarton(cout);
  cout << endl;
  second_carton.WriteCarton(cout);

  // Loop through the first three elements in the array and write carton data
  // and information using the WriteData and WriteCarton methods.
  // Notice the WriteData method adds an endl and the WriteCarton does not.
  // Add an endl after calling the WriteCarton method.
  cout << "\nReport and data of three Cartons in an array:\n";
  for (int j = 0; j < 3; ++j){
      third_carton[j].WriteData(cout);
      third_carton[j].WriteCarton(cout);
      cout << endl;
  }

  // Print out the volume of two Cartons you have created to cout.
  cout << "\nVolumes of two Cartons:\n";
  cout << first_carton.Volume() << endl;
  cout << second_carton.Volume() << endl;

  // Loop through the first three elements in the array and print out
  // the volume of the Cartons in the array.
  cout << "\nVolumes of the first three Cartons in the array:\n";
    for (int k = 0; k < 3; ++k){
        cout << third_carton[k].Volume() << endl;
    }

  // Create another array of Cartons. Use the constant defined earlier for the
  // size of the array.
    array<Carton, kMaxSize> fourth_carton;

  // Define and open an ifstream object. Test that the ifstream opens.
  // Then read the data from file named
  // cartons.txt and store them in this array.

    ifstream in("../../cartons.txt");
    if(in.fail()){
        cout << "Unable to open file cartons.txt. Shutting down.";
    }

    int index = 0;
    float length, width, height;
    while (index < kMaxSize && in >> length){
        in >> width;
        in >> height;
        fourth_carton[index].SetLength(length);
        fourth_carton[index].SetWidth(width);
        fourth_carton[index].SetHeight(height);
        index++;
    }

  // Write the Carton data to file named carton_data.txt. First, define and
  // open an ofstream object using that filename. Then loop through the
  // array from Part 7 and use WriteData to write the data for
  // each Carton. Put each Carton on a single line. Do not include blank lines.
  // Include all the valid Cartons in the array and none of the default Cartons.

    ofstream out("../../carton_data.txt");

    for (int k = 0; k < index; ++k){
        fourth_carton[k].WriteData(out);
    }
  // Write a Carton report to file named carton_report.txt. First, define and
  // open an ofstream object using that filename. Then loop through the
  // array from Part 7 and use WriteCarton to write a sentence for
  // each Carton. Put each Carton on a single line. Include all the valid
  // Cartons in the array and none of the default Cartons.

    ofstream outfile("../../carton_report.txt");

    for (int a = 0; a < index; ++a){
        fourth_carton[a].WriteCarton(outfile);
        outfile << endl;
    }

    return 0;
}