#include <iostream>
#include <fstream>
#include <string>
#include "Vector.h"
#include "Timer.h"
#include "SortingAlgorythms/InsertionSort.h"
#include "SortingAlgorythms/QuickSort.h"

void Error() {
    std::cout<<"Arguments are wrong"<<std::endl;
}

void Helper() {
    std::cout<<"If you want to do single test using file, type:"<<std::endl;
    std::cout<<"./YourProject --file <algorithm> <type> <inputFile> [outputFile]"<<std::endl<<std::endl;
    std::cout<<"<algorithm> Sorting algorithm to use (...)."<<std::endl;
    std::cout<<"<type> Data type to load (...)."<<std::endl;
    std::cout<<"<inputFile> File containing the data to be sorted."<<std::endl;
    std::cout<<"[outputFile] File where sorted file should be saved."<<std::endl<<std::endl;
    std::cout<<"If you want to do multiply tests using random types of data, type:"<<std::endl;
    std::cout<<"./YourProject --test <algorithm> <type> <size> <outputFile>"<<std::endl<<std::endl;
    std::cout<<"<algorithm> Sorting algorithm to use (...)."<<std::endl;
    std::cout<<"<type> Data type to load (...)."<<std::endl;
    std::cout<<"<size> Number of elements to generate (instance size)."<<std::endl;
    std::cout<<"<outputFile> File where the benchmark results should be saved."<<std::endl<<std::endl;
    std::cout<<"If you want to exit, type:"<<std::endl;
    std::cout<<"--quit"<<std::endl;
}

template<class T>
Vector<T> *ValuesSaver(std::fstream file) {
    auto *notSorted = new Vector<T>();
    std::string line;
    while (!file.eof()) {
        getline(file,line);
        notSorted->Add(std::stoi(line));
    }
    return notSorted;
}

template<class T>
Vector<T> FileReader(const std::string& path) {  //Reading values from file
    std::fstream file;
    file.open(path, std::ios::in);
    if (!file.is_open()) {
        std::cout<<"File does not exist."<<std::endl;
        exit(1);
    }
    std::cout<<"File opened."<<std::endl;
    std::string numberOfElementsString;
    getline(file,numberOfElementsString);
    int numberOfElements = std::stoi(numberOfElementsString);
    Vector<T> notSorted = *ValuesSaver<T>(std::move(file)); //Saving
    file.close();
    return notSorted;
}
template<class T>
void DrunkStudent(Vector<T> *border, float drinkParameter) {
    int pos = 0;
    if (drinkParameter != 0) {
        drinkParameter *= 10;
    }
    else
        drinkParameter = 1;
    for (int i = 13*drinkParameter; i < border->size(); i+=13*drinkParameter) {
        T temp = border->getValue(i);
        border->ChangeValue(i, border->getValue(pos));
        border->ChangeValue(pos, temp);
        pos++;
    }
}
template <typename T>
InsertionSort<T> insertionSort;
template <typename T>
QuickSort<T> quickSort;
int main(const int argc, char* argv[0]) {
    const std::string firstArg = argv[1];
    const int algorithmType = std::stoi(argv[2]);
    const int dataType = std::stoi(argv[3]);
    const std::string inputFileOrSize = argv[4];
    const std::string outputFile = argv[5];

    while (true) {
        if (firstArg == "--file") {
            switch (dataType) {
                case 0: {
                    const Vector<int> noSorted = FileReader<int>(inputFileOrSize);
                    break;
                }
                case 1: {
                    const Vector<float> noSorted = FileReader<float>(inputFileOrSize);
                }
                case 2: {
                    const Vector<double> noSorted = FileReader<double>(inputFileOrSize);
                }
                case 3: {
                    const Vector<char> noSorted = FileReader<char>(inputFileOrSize);
                }
                default: {
                    Error();
                    continue;
                }
            }
            break;
        }
        else if (firstArg == "--test") {
            switch (dataType) {
                case 0: {
                    Vector<int> noSorted;
                    noSorted.FillRandom(stoi(inputFileOrSize));
                    //insertionSort<int>.InsertionSorting(&noSorted);
                    for (int i = 0; i<5; i++) {
                        std::cout<<noSorted.GetValue(i)<<" ";
                    }
                    std::cout<<std::endl;
                    quickSort<int>.QuickSorting(&noSorted);
                    for (int i = 0; i<5; i++) {
                        std::cout<<noSorted.GetValue(i)<<" ";
                    }
                    break;
                }
                case 1: {
                    Vector<float> noSorted;
                    noSorted.FillRandom(stoi(inputFileOrSize));
                    insertionSort<float>.InsertionSorting(&noSorted);
                    break;
                }
                case 2: {
                    Vector<double> noSorted;
                    noSorted.FillRandom(stoi(inputFileOrSize));

                    insertionSort<double>.InsertionSorting(&noSorted);
                    break;
                }
                case 3: {
                    Vector<char> noSorted;
                    noSorted.FillRandom(stoi(inputFileOrSize));
                    for (int i = 0; i<5; i++) {
                        std::cout<<noSorted.GetValue(i)<<" ";
                    }
                    insertionSort<char>.InsertionSorting(&noSorted);
                    break;
                }
                default: {
                    Error();
                    break;
                }
            }
            break;
        }
        else if (firstArg == "--help") {
            Helper();
        }
        else if (firstArg == "--quit") {
            std::cout<<"Exiting..."<<std::endl;
            break;
        }
    }

    return 0;
}

