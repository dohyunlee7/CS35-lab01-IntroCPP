/*
  Copyright (c) 2019
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2019
  CPSC 035: Data Structures and Algorithms
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//sorts the elements in an array in ascending order
void swap(int i, int j, int *arrayOfNumbers){
  if (arrayOfNumbers[j] < arrayOfNumbers[i]) {
    int temp = arrayOfNumbers[i];
    arrayOfNumbers[i] = arrayOfNumbers[j];
    arrayOfNumbers[j] = temp;
  }
}
//finds last number of array
int lastNum(int *arrayOfNumbers, int length) {
  return arrayOfNumbers[length-1];
}
//finds the largest number
int largestNum(int *arrayOfNumbers, int length) {
  for (int i = 0; i < length; i++) {
    for (int j = i + 1; j < length; j++){
      swap(i, j, arrayOfNumbers);
    }
  }
  return arrayOfNumbers[length-1];
}
//finds the second largest number
int secLargestNum(int *arrayOfNumbers, int length) {
  for (int i = 0; i < length; i++) {
    for (int j = i + 1; j < length; j++){
      swap(i, j, arrayOfNumbers);
    }
  }
  return arrayOfNumbers[length-2];
}

//finds the average of the numbers
float average(int *arrayOfNumbers, float length) {
  int sum = 0;
  for (int i = 0; i < length; i++) {
    sum += arrayOfNumbers[i];
  }
  float total = sum/length;
  return total;
}

int main() {
  string fileName;
  cout << "Please enter the name of your file: ";
  cin >> fileName;

  //open file for reading
  ifstream file(fileName);
  //reads length from file
  int length;
  file >> length;
  //reads data from file
  int *data = new int[length];
  for (int i = 0; i < length; i++) {
    file >> data[i];
  }

  file.close();

  cout << "The last number is " << lastNum(data, length) << "." << endl;
  cout << "The largest number is " << largestNum(data, length) << "." <<endl;
  cout << "The second largest number is " << secLargestNum(data, length)
  << "." << endl;
  cout << "The average is " << average(data, length) << "." << endl;

  delete[] data;

  return 0;
}
