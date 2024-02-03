/*
Chris Comito
11/25/2023
Edited 11/30/2023
This project shows an array of int's and displays them then asks for an input
After you enter and input that corresponds with one of the ones listed it displys
The number you entered and also the location where it is in the array. IT also Displays a
sorted array
*/


#include <iostream>
using namespace std;
#include <climits>
#include <chrono>
using namespace chrono;


int Calc(int numArr[], int value);
int Input(int numArr[]);
void Output(int valueIn, int valueOut);
void Sort(int numArr[]);
const int MAX = 20; 

int main(){
    //variables
    int valueOut;
    int valueIn;
    int numArr[MAX] = { 4, 2, 7, 32, 55, 21, 90, 200, 35, 1, 67, 57, 23, 76, 44, 6, 919, 102, 31, 38};

        valueIn = Input(numArr);
        valueOut = Calc(numArr, valueIn);
        Output(valueIn,valueOut);


    return 0;
}

int Calc(int numArr[], int valueIn){                                    
    int valueOut;

        for(int x = 0; x < MAX; x++){                //O(MAX)
                if(numArr[x] == valueIn){
                    valueOut = x;
                    return valueOut;
        }
    }
}

int Input(int numArr[]){
    int valueIn;
    int x = 0;

        cout << "Original List of Numbers: ";
        for(int num = 0; num < MAX; num++){                                     //O(MAX)
        cout << numArr[num] << " ";
    }

    cout << endl;


    double timerCount = 0;
    auto start = high_resolution_clock::now();

    Sort(numArr);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    timerCount = duration.count();
    timerCount /= 1000000;
    cout << endl << "Time for Sort: "<< timerCount << endl;



        cout << endl << "What number do you want to find? ";
        cin >> valueIn;
            while(valueIn != numArr[x]){                                        //O(MAX)
                x++;
                    if(x > MAX){
                        cout << "Please Enter a number in the Array ";
                        cin >> valueIn;
                        x = 0;
                    }
            }

    return valueIn;
}                                                                               //O2(MAX)

void Output(int valueIn, int valueOut){
            cout << "Your number is: " << valueIn << endl;
        cout << "The index of your number is: " << valueOut << endl;
}

void Sort(int numArr[]){
    int numSortedArr[MAX];
    int numArrCopy[MAX];

    for(int n = 0; n < MAX; n++){                           //O(MAX )
        numArrCopy[n] = numArr[n];
    }

    for(int x = 0; x < MAX; x++){                           
        int num = INT_MAX - 1;
        int pointerArrNum;      
        for(int i = 0; i < MAX; i++){                       //O(MAX^2)
            
            if(num >  numArrCopy[i]){
                num =  numArrCopy[i];
                pointerArrNum = i;
            }
        }
        numSortedArr[x] = num;
        numArrCopy[pointerArrNum] = INT_MAX;
    }


    cout << "Sorted List of Numbers:  ";
    for(int n = 0; n < MAX; n++){                               //O(MAX)
        cout << " " << numSortedArr[n];
    }
}
