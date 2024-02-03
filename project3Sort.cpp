/*
Chris Comito
11/25/2023
Im just tryna sort an array
*/


#include <iostream>
using namespace std;


void Sort(int numArr[]);
const int MAX = 20; 

int main(){
    //variables
    int valueOut;
    int valueIn;
    int numArr[MAX] = {10,12,2332,101,102,67,90,50,120,53,20,45,30,69,39,59,9,1,5,32};

        Sort(numArr);



    return 0;
}


void Sort(int numArr[]){
    int numSortedArr[MAX];
    int numArrCopy[MAX];

    for(int n = 0; n < MAX; n++){
        numArrCopy[n] = numArr[n];
    }

    for(int x = 0; x < MAX; x++){
        int num = 10000;
        int pointerArrNum;
        for(int i = 0; i < MAX; i++){
            
            if(num >  numArrCopy[i]){
                num =  numArrCopy[i];
                pointerArrNum = i;
            }
        }
        numSortedArr[x] = num;
        numArrCopy[pointerArrNum] = 10000000;
    }

    for(int n = 0; n < MAX; n++){
        cout << " " << numArr[n];
    }

    cout << endl;
    
    for(int n = 0; n < MAX; n++){
        cout << " " << numSortedArr[n];
    }
}