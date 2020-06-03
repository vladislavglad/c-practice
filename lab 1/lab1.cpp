#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void sortArr(string a[], int b[], int size);
void swap(string a[], int b[], int i, int j);

int main() {
    try {
        //open file stream.
        ifstream readFile("names.data");
        if (readFile.fail()) throw string("*** Exception *** input file names.data not found"); 

        //configuration
        const int CAPACITY = 50;
        int index = 0;
        int id = 1001;

        //our parallel arrays.
        string stringArr[CAPACITY];
        int integerArr[CAPACITY];
        
        //populate the arrays.
        while(!readFile.eof()) {
            if (index >= CAPACITY) throw string("*** Exception *** array capacity exceeded");

            string data;
            readFile >> data;
            if (data != "") {
                stringArr[index] = data;
                integerArr[index] = id;
                index++;
                id++;
            }
        }
        readFile.close();

        sortArr(stringArr, integerArr, index);
        
        //create an output file
        ofstream writeFile("results.data");
        if (!writeFile) throw string("Cannot open results.data");

        //populate an output file.
        for (int i = 0; i<index; i++) {
            writeFile << stringArr[i] << " ";
            writeFile << integerArr[i] << endl;
        }
        writeFile.close();
        
        cout << index << " records processed";
        return 0;

    } catch(string errorMsg) {
        cout << errorMsg << endl;
        exit(1);
    }
}

//selection sort alg. implementation. 
//O(n^2) but for capacity of 50 should suffice.
void sortArr(string a[], int b[], int size) {
    for (int i = 0; i<size-1; i++) {

        int min = i;
        for (int j = i + 1; j<size; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }

        swap(a, b, i, min);
    }
}

//swap contents at specified indices.
void swap(string a[], int b[], int i, int j) {
    string tempStr = a[i];
    a[i] = a[j];
    a[j] = tempStr;

    int tempInt = b[i];
    b[i] = b[j];
    b[j] = tempInt;
}
