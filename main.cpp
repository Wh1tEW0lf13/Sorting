#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>

#include "Vector.h"
#include "Timer.h"
#include "GraphsAlgorythms/MST.h"
#include "GraphsAlgorythms/ShortestPath.h"
#include "GraphsAlgorythms/Vertex.h"
#include "SortingAlgorythms/HeapifySort.h"
#include "SortingAlgorythms/InsertionSort.h"
#include "SortingAlgorythms/QuickSort.h"
#include "SortingAlgorythms/ShellSort.h"

void Error() {
    std::cout<<"Arguments are wrong"<<std::endl;
    exit(-2138);
}
template<class T>
void IfSorted(Vector<T> *border) {  //Checking is a border sorted
    bool isSorted = true;
    for (int i = 0; i < border->GetSize()-1; i++) {
        if (border->GetValue(i) > border->GetValue(i+1)) {
            isSorted = false;
            std::cout << "No sorted" << std::endl;
            break;
        }
    }
    if (isSorted) {
        std::cout<<"Sorted"<<std::endl;
    }
}
void SortingHelper()
    {     //Explain how to start a program
        std::cout<<"If you want to do single test using file, type:"<<std::endl;
        std::cout<<"./YourProject 0 --file <algorithm> <type> <inputFile> [outputFile]"<<std::endl<<std::endl;
        std::cout<<"<algorithm> Sorting algorithm to use (0: InsertionSort, 1: QuickSort, 2: HeapifySort, 3: ShellSort)."<<std::endl;
        std::cout<<"<type> Data type to load (0: int, 1: float, 2: double, 3: char)."<<std::endl;
        std::cout<<"<inputFile> File containing the data to be sorted."<<std::endl;
        std::cout<<"[outputFile] File where sorted file should be saved."<<std::endl<<std::endl;
        std::cout<<"If you want to do multiply tests using random types of data, type:"<<std::endl;
        std::cout<<"./YourProject --test <algorithm> <type> <size> <outputFile>"<<std::endl<<std::endl;
        std::cout<<"<algorithm> Sorting algorithm to use (0: InsertionSort, 1: QuickSort, 2: HeapifySort, 3: ShellSort, 4:DrunkStudentSort)."<<std::endl;
        std::cout<<"<type> Data type to load (0: int, 1: float, 2: double, 3: char)."<<std::endl;
        std::cout<<"<size> Number of elements to generate (instance size)."<<std::endl;
        std::cout<<"<outputFile> File where the benchmark results should be saved."<<std::endl<<std::endl;
    }
void GraphHelper() {     //Explain how to start a program
    std::cout<<"If you want to do single test using file, type:"<<std::endl;
    std::cout<<"./YourProject 1 --file <problem> <algorithm> <inputFile> [outputFile]"<<std::endl<<std::endl;
    std::cout<<"<problem> Problem to solve ( 0 - MST, 1 - shortest path )."<<std::endl;
    std::cout<<"Algorithm for the problem:"<<std::endl;
    std::cout<<"For MST (e.g. 0 - all, 1 - Prim's, 2 - Kruskal's)"<<std::endl;
    std::cout<<"For shortest (e.g. 0 - all, 1 - Dijkstra's, 2 - Ford-Bellman's, 3 - Ford-Fulkerson's)"<<std::endl;
    std::cout<<"<inputFile> File containing the data to be sorted."<<std::endl;
    std::cout<<"[outputFile] File where sorted file should be saved."<<std::endl<<std::endl;
    std::cout<<"If you want to do multiply tests using random types of data, type:"<<std::endl;
    std::cout<<"<problem> Problem to solve ( 0 - MST, 1 - shortest path )."<<std::endl;
    std::cout<<"Algorithm for the problem:"<<std::endl;
    std::cout<<"For MST (e.g. 0 - all, 1 - Prim's, 2 - Kruskal's)"<<std::endl;
    std::cout<<"For shortest (e.g. 0 - all, 1 - Dijkstra's, 2 - Ford-Bellman's, 3 - Ford-Fulkerson's)"<<std::endl;
    std::cout<<"<size> Number of elements to generate (instance size)."<<std::endl;
    std::cout<<"<outputFile> File where the benchmark results should be saved."<<std::endl<<std::endl;
}
template<class T>
Vector<T> FileReaderBorder(std::string path) {  //Reading values from file
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
    Vector<T> notSorted;
    for (int i = 0; i < numberOfElements; i++) {
        getline(file,numberOfElementsString);
        notSorted.Add(std::stoi(numberOfElementsString));
    }
    file.close();
    return notSorted;
}

void SaveGraphToFile(Vertex* graph, std::string path, int size) {
    std::ofstream file(path);
    file<<size<<"\t"<<graph[0].GetEdgeSizes()<<std::endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < graph[i].GetEdgeSizes(); j++) {
            file<<graph[i].GetEdge(j)<<" ";
        }
        file<<std::endl;
    }
    file.close();
}

template<class T>
void SaveBorderToFile(Vector<T> *border, std::string path) {  //Here I save sorted elements to a txt
    std::ofstream file(path);
    file<<border->GetSize()<<std::endl;
    for (int i = 0; i < border->GetSize(); i++) {
        file<<border->GetValue(i)<<std::endl;
    }
    file.close();
}
void SaveTimeToFile(int time, std::string path) { //Here I save time (ms) to a txt
    std::fstream file;
    file.open(path, std::ios::out | std::ios::app);
    file<<time<<std::endl;
    file.close();
}
template<class T>
void DrunkStudent(Vector<T> *border, float drinkParameter) {
    int pos = 0;
    if (drinkParameter != 0) {
        if (drinkParameter > 4.0) {
            std::cout<<"Student is DEAD [*]";
            exit(13);
        }
        drinkParameter *= 10;
    }
    else
        drinkParameter = 1;
    for (int i = 13*drinkParameter; i < border->GetSize(); i+=13*drinkParameter) {
        T temp = border->GetValue(i);
        border->ChangeValue(i, border->GetValue(pos));
        border->ChangeValue(pos, temp);
        pos++;
    }
}

template<class T>
void SortType(Vector<T> *border, int algorithmType) {   //Here I check which type of algorythm is used
    Timer *timer = new Timer();
    float drinkParameter = 1.0;
    switch (algorithmType) {
        case 0: {
            InsertionSort<T> insertionSort;
            timer->start();
            insertionSort.InsertionSorting(border);
            timer->stop();
            SaveTimeToFile(timer->result(),"time.txt");
            break;
        }
        case 1: {
            QuickSort<T> quickSort;
            timer->start();
            quickSort.QuickSorting(border);
            timer->stop();
            SaveTimeToFile(timer->result(),"time.txt");
            break;
        }
        case 2: {
            HeapifySort<T> heapifySort;
            timer->start();
            heapifySort.HeapifySorting(border);
            timer->stop();
            SaveTimeToFile(timer->result(),"time.txt");
            break;
        }
        case 3: {
            ShellSort<T> shellSort;
            timer->start();
            shellSort.ShellSorting(border);
            timer->stop();
            SaveTimeToFile(timer->result(),"time.txt");
            break;
        }
        case 4: {
            InsertionSort<T> insertionSort;
            DrunkStudent(border, drinkParameter);
            timer->start();
            insertionSort.InsertionSorting(border);
            timer->stop();
            SaveTimeToFile(timer->result(),"time.txt");
            break;
        }
        default:
            Error();
    }
}

static bool CheckIfCycle(int a, int b, Vertex *graph) {
    for (int i = 0; i < graph[0].GetEdgeSizes(); i++) {
        if (graph[a].GetEdge(i) != 0 && graph[b].GetEdge(i) != 0) {
            return false;
        }
    }
    return true;
}

int FillGraph(Vertex *graph ,int size, int firstVertex, int secondVertex, int maxWeight, int problem, bool isTest, int value) {
    if (isTest)
        value = std::rand() % (maxWeight-1) + 1;
    for (int j = 0; j < size; j++) {
            if (j == firstVertex) {
                graph[j].AddEdge(value);
                graph[j].AddNext(secondVertex,value);
            }
            else if (j == secondVertex) {
                if (problem==0) {
                    graph[j].AddEdge(value);
                }
                else{
                    graph[j].AddEdge(-value);
                    graph[j].AddPrev(firstVertex);
                }
            }
            else {
                graph[j].AddEdge(0);
            }
        }
    return 1;
    }

void GraphCreator(Vertex *graph ,int size, int density, int maxWeight, int problem) {
    int graphDensity = 0;
    srand(time(NULL));
    for (int i = 0; i < size-1; i++) {  //Creating simple consistent graph
        int randomVertex = rand() % (size-1-i) + i+1;
        FillGraph(graph,size,i,randomVertex,maxWeight, problem, true, 0); //Creating incident matrix
        graphDensity++;
    }
    if (density <= 100 && density > 0) {
        while((size*(size-1)/2)*(density/100.0)>graphDensity) {
            int firstRandomVertex = rand() % size;
            int secondRandomVertex = rand() % size;
            if (firstRandomVertex != secondRandomVertex&&CheckIfCycle(firstRandomVertex,secondRandomVertex, graph)) {
                FillGraph(graph,size,firstRandomVertex,secondRandomVertex,maxWeight, problem, true, 0);
                graphDensity++;
            }
        }
    }
    else{
        std::cout<<"Density is wrong!!!"<<std::endl;
        exit(-2136);
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < graph[i].GetEdgeSizes(); j++) {
            std::cout<<graph[i].GetEdge(j)<<" ";
        }
        std::cout<<std::endl;
    }
}
void FileReaderGraph(std::string filePath, int maxWeight, int problem, std::string output) {
    std::fstream file;
    file.open(filePath, std::ios::in);
    std::cout<<"File opened."<<std::endl;
    std::string numberOfElementsString;
    getline(file,numberOfElementsString);
    if (!file.is_open()) {
        std::cout<<"File does not exist."<<std::endl;
        exit(1);
    }
    int tab = numberOfElementsString.find('\t');
    int numberOfEdges = stoi(numberOfElementsString.substr(0, tab));
    int numberOfVertex = stoi(numberOfElementsString.substr(tab+1, numberOfElementsString.length()-1));
    Vertex graph[numberOfVertex];
    for (int i = 0; i < numberOfEdges; i++) {
        getline(file,numberOfElementsString);
        tab = numberOfElementsString.find('\t');
        int firstVertex = stoi(numberOfElementsString.substr(0, tab));
        numberOfElementsString.erase(0, tab+1);
        tab = numberOfElementsString.find('\t');
        int secondVertex = stoi(numberOfElementsString.substr(0, tab));
        numberOfElementsString.erase(0, tab+1);
        int weight = stoi(numberOfElementsString);
        FillGraph(graph,numberOfVertex,firstVertex,secondVertex,maxWeight,problem, false, weight);
    }
    for (int i = 0; i < numberOfVertex; i++) {
        for (int j = 0; j < graph[i].GetEdgeSizes(); j++) {
            std::cout<<graph[i].GetEdge(j)<<" ";
        }
        std::cout<<std::endl;
    }
    ShortestPath::Dijkstra(numberOfVertex,graph, 1,3);
    //SaveGraphToFile(mst_solution,output,numberOfVertex);

}
int main(int argc, char* argv[]) {
    std::string whichProgram;
    if (argc > 1)
        whichProgram = argv[1];
    if (whichProgram == "0") {
        const std::string firstArg = argv[2];
        if (firstArg == "--file") {
            const int algorithmType = std::stoi(argv[3]);
            const int dataType = std::stoi(argv[4]);
            const std::string inputFileOrSize = argv[5];
            const std::string outputFile = argv[6];
                switch (dataType) {
                    case 0: {
                        Vector<int> noSorted = FileReaderBorder<int>(inputFileOrSize);
                        SortType(&noSorted, algorithmType);
                        IfSorted(&noSorted);
                        SaveBorderToFile(&noSorted, outputFile);
                        break;
                    }
                    case 1: {
                        Vector<float> noSorted = FileReaderBorder<float>(inputFileOrSize);
                        SortType(&noSorted, algorithmType);
                        IfSorted(&noSorted);
                        SaveBorderToFile(&noSorted, outputFile);
                        break;
                    }
                    case 2: {
                        Vector<double> noSorted = FileReaderBorder<double>(inputFileOrSize);
                        SortType(&noSorted, algorithmType);
                        IfSorted(&noSorted);
                        SaveBorderToFile(&noSorted, outputFile);
                        break;
                    }
                    case 3: {
                        Vector<char> noSorted = FileReaderBorder<char>(inputFileOrSize);
                        SortType(&noSorted, algorithmType);
                        IfSorted(&noSorted);
                        SaveBorderToFile(&noSorted, outputFile);
                        break;
                    }
                    default: {
                        Error();
                    }
                }
        }
        else if (firstArg == "--test") {
            const int algorithmType = std::stoi(argv[3]);
            const int dataType = std::stoi(argv[4]);
            const std::string inputFileOrSize = argv[5];
            const std::string outputFile = argv[6];
            switch (dataType) {
                case 0: {
                    Vector<int> noSorted;
                    noSorted.FillRandom(stoi(inputFileOrSize)); //Fill a border with random values
                    //DrunkStudent(&noSorted, 2.0); //When needed it is out of comment
                    SortType(&noSorted, algorithmType);
                    IfSorted(&noSorted);
                    SaveBorderToFile(&noSorted, outputFile);
                    break;
                }
                case 1: {
                    Vector<float> noSorted;
                    noSorted.FillRandom(stoi(inputFileOrSize));
                    SortType(&noSorted, algorithmType);
                    IfSorted(&noSorted);
                    SaveBorderToFile(&noSorted, outputFile);
                    break;
                }
                case 2: {
                    Vector<double> noSorted;
                    noSorted.FillRandom(stoi(inputFileOrSize));
                    SortType(&noSorted, algorithmType);
                    IfSorted(&noSorted);
                    SaveBorderToFile(&noSorted, outputFile);
                    break;
                }
                case 3: {
                    Vector<char> noSorted;
                    noSorted.FillRandom(stoi(inputFileOrSize));
                    SortType(&noSorted, algorithmType);
                    IfSorted(&noSorted);
                    SaveBorderToFile(&noSorted, outputFile);
                    break;
                }
                default: {
                    Error();
                    break;
                }
            }
        }
    }
    else if (whichProgram == "1") {
        const int maxWeight = 100;
        const std::string firstArg = argv[2];
        const int problem = std::stoi(argv[3]);
        const std::string algorythmType = argv[4];
        if (firstArg == "--file") {
            const std::string inputFile = argv[5];
            const std::string outputFile = argv[6];
            FileReaderGraph(inputFile, maxWeight,problem,outputFile);
        }
        else if (firstArg == "--test") {
            const int size = std::stoi(argv[5]);
            const int density = std::stoi(argv[6]);
            const int count = std::stoi(argv[7]);
            const std::string outputFile = argv[8];
            Vertex graph[size];
            GraphCreator(graph,size, density, maxWeight, problem);
            Vertex* mst = MST::Kruskal(size, graph, maxWeight);
            SaveGraphToFile(mst, outputFile, size);
        }
    }
    else if (whichProgram == "--help1") {
        SortingHelper();
    }
    else if (whichProgram == "--help2") {
        GraphHelper();
    }
    else {
        std::cout<<"Type --help1 if you want sorting helper, or --help2 if you want graph helper.";
    }
    return 0;
}

