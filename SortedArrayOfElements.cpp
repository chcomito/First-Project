/*
Chris Comito
11/25/2023
Edited 11/30/2023
Edited 12/10/2023

This project shows an array of int's and displays them then asks for an input
After you enter and input that corresponds with one of the ones listed it displys
The number you entered and also the location where it is in the array. IT also Displays a
sorted array

I changed all Arrays to Vectors
Vectors are better becuase now the list can be changed to any size
Also Vectors come with a sort Library
*/


#include <iostream>
using namespace std;
#include <climits>
#include <chrono>
using namespace chrono;
#include <vector>
#include <algorithm>



int Calc(vector<int> Vector, int value);
void SortedOutput(vector<int> Vector, int value);
void Output(vector<int> Vector,int value, int otherValue);
void Sort(vector<int> Vector, int Value);
const int MAX = 200; 

int main(){
    //variables
    vector<int> variVec;
    int variVecSize;
    int seed;
    int lowestRand;
    int highestRand;

        cout << "How big an array do you want? ";
        cin >> variVecSize;

        cout << "What is the seed number? ";
        cin >> seed;

        cout << "What is lowest number in the range? ";
        cin >> lowestRand;

        cout << "What is the highest number in the range? ";
        cin >> highestRand;

        
        srand(seed);
        for(int num = 0; num < variVecSize; num++){  
        int random = rand();
        random %= highestRand + 1;
        if(random <= 100){
            random += lowestRand;
        }                               
        variVec.push_back(random);
    }
        
        Output(variVec,seed,variVecSize);
        SortedOutput(variVec,variVecSize);



    return 0;
}

int Calc(vector<int> variVec, int valueIn){                                    
    int valueOut;

        for(int x = 0; x < MAX; x++){                //O(MAX)
                if(variVec[x] == valueIn){
                    valueOut = x;
                    return valueOut;
        }
    }
}

void SortedOutput(vector<int> variVec,int variVecSize){
    int valueIn;
    int x = 0;


    cout << endl;

    //Timer for how long the algorithm runs
    double timerCount = 0;
    auto start = high_resolution_clock::now();

    Sort(variVec,variVecSize);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    timerCount = duration.count();
    timerCount /= 1000000;

    cout << endl << "Time to Sort "<< variVecSize << " numbers = " <<timerCount << endl;


}                                                                               //O2(MAX)

void Output( vector<int> variVec, int seed, int variVecSize){
            
    cout << "Seed number entered = " << seed << endl;

    cout << "Random Set of Numbers: ";

    for(int i = 0; i < variVecSize; i++){
        cout << variVec[i] << " ";
        if(i >= MAX){
            break;
        }
    }
}

void Sort(vector<int> variVec, int variVecSize){

    vector <int> vec;

    for(int n = 0; n < variVecSize; n++){                           //O(MAX )
        vec.push_back(variVec[n]);
    }


    sort(vec.begin(),vec.end());


    cout << "Sorted List of Numbers:  ";
    for(int n = 0; n < variVecSize; n++){                               //O(MAX)
        cout << vec[n] << " ";
        if(n >= MAX){
            break;
        }
    }
}
