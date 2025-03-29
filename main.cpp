#include <iostream>
#include <fstream>
#include <string>
#include "Vector.h"
#include "Timer.h"
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
        notSorted->add(std::stoi(line));
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
void DrunkStudent(Vector<T> *border) {
    //Koncjepcja moja jest taka, że pijany student wymyślił sobie, że przełoży każdą liczbę na początek, która jest opisana ciągiem a(n)=13n gdzie n>0
}

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
                    noSorted.fillRandom(stoi(inputFileOrSize));
                    break;
                }
                case 1: {
                    Vector<float> noSorted;
                    noSorted.fillRandom(stoi(inputFileOrSize));
                    break;
                }
                case 2: {
                    Vector<double> noSorted;
                    noSorted.fillRandom(stoi(inputFileOrSize));
                    break;
                }
                case 3: {
                    Vector<char> noSorted;
                    noSorted.fillRandom(stoi(inputFileOrSize));
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

