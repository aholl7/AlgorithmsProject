//
//  main.cpp
//  FinalTeamProject
//
//  Created by Alfred Holland on 4/21/21.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include "Student.h"

using namespace std;
 

void swap(Student* a, Student* b)
{
    Student t = *a;
    *a = *b;
    *b = t;
}
 

double partition (vector<Student> &s, int low, int high)
{
    double pivot = s[high].getGrade();    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (s[j].getGrade() <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&s[i], &s[j]);
        }
    }
    swap(&s[i + 1], &s[high]);
    return (i + 1);
}
 

void quickSort(vector<Student> &s, int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place*/
        int pi = partition(s, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(s, low, pi - 1);
        quickSort(s, pi + 1, high);
    }
}

/*Knapsack Problem*/

double max(double a, double b) {
    return (a > b) ? a : b;
    
}


double knapSack(double maxGPA, vector<Student> s, int n){
   if(n == 0 || maxGPA == 0)
       return 0;
    
    
    if(s[n-1].getGPA() > maxGPA){
       return knapSack(maxGPA, s, n-1);
    }
    
   else{
       double parameter1 = s[n-1].getGrade() + knapSack(maxGPA - s[n-1].getGPA(), s, n-1);
       double parameter2 = knapSack(maxGPA, s, n-1);
       
       return max(parameter1, parameter2);
   }


}

void printKnapsackSubset(vector<Student> s, double maxGPA, double knapsackValue, int i, string acc){
    if ((maxGPA <= 12.0 && knapsackValue == 0) && !(acc == "")) {
        cout << "The most feasible set among students is: " << endl;
        cout << endl;
        cout << acc << endl;
        
        acc = "";
    }
    
    if(i == s.size()){
        return;
    }
    
    string stringGPA = s[i].getFirstName() + " " + s[i].getLastName() + " " + to_string(s[i].getGrade()) + " " + to_string((s[i].getGPA()));
    string variable = acc + " " + stringGPA + "\n";
    
    printKnapsackSubset(s, maxGPA, knapsackValue, i+1, acc);
    printKnapsackSubset(s, maxGPA+s[i].getGPA(), knapsackValue - s[i].getGrade(), i + 1, variable);
}

void printKnapsackSubset(vector<Student> s, double maxGPA, double knapsackValue){
    printKnapsackSubset(s, maxGPA, knapsackValue, 0, "");
}

double computeAverage(vector<Student> s, int n){
    double sum = 0;
    
    for(int i = 0; i < n; i++){
        sum += s[i].getGrade();
    }
    
    return sum/n;
}

void printArray(vector<Student> s, int n){
    ofstream outFile;
    outFile.open("output.txt");
    
    if(!outFile){
        cout << "Unable to open file output.txt" << endl;
        exit(1);
    }
    
    outFile << setw(15) << "First Name";
    outFile << setw(30) << "Last Name";
    outFile<< setw(10) << "Grade";
    outFile<< setw(10) << "GPA";
    outFile << endl;
    
    if(outFile.is_open()){
        for(int i = n-1; i >= 0; i--){
            outFile << setw(15) << s[i].getFirstName();
            outFile << setw(30) << s[i].getLastName();
            outFile<< setw(10) << s[i].getGrade();
            outFile<< setw(10) << s[i].getGPA();
            outFile << endl;
        }
        
        outFile << endl;
        
        outFile << "The lowest grade is a " << s[0].getGrade() <<endl;
        outFile << "The highest grade is a " << s[n-1].getGrade() <<endl;
        outFile << "The average grade is a " << computeAverage(s, n) <<endl;
    }
}


  
int main() {
    ifstream inFile ("input.txt");
    ofstream outFile;
    
    int n = 0;
    double maxGPA = 12.0;
    vector<Student> s;
    string line;
    string firstName;
    string lastName;
    double grade;
    float GPA;

    
    
    if (!inFile) {
        cout << "Unable to open file input.txt" << endl;
        exit(1);   // call system to stop
    }
    if(inFile.is_open()){
        while(inFile >> firstName >> lastName >> grade >> GPA){
            s.push_back(Student(firstName, lastName, grade, GPA));
            n+=1;
        }
        
        inFile.close();
    }
    

    quickSort(s, 0, n-1);
    printArray(s, n);
    
    double knapsackValue =  knapSack(maxGPA, s, n);
    
    cout << "The value of the most feasible subset has a value of " << knapsackValue << endl;
    cout << endl;

    printKnapsackSubset(s, 0, knapsackValue, 0, "");
    
    return 0;
}

