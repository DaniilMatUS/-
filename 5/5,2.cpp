#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

void generateInputFile(const  string& filename) {
     ofstream outFile(filename);
    if (!outFile) {
         cerr << "Ошибка открытия файла для записи: " << filename <<  endl;
        return;
    }

     srand( time(nullptr)); 
    for (int i = 0; i < 100; ++i) {
        int randomNumber =  rand() % 101 - 50; 
        outFile << randomNumber <<  endl;
    }

    outFile.close();
}


 vector<int> readInputFile(const  string& filename) {
     ifstream inFile(filename);
    if (!inFile) {
         cerr << "Ошибка открытия файла для чтения: " << filename <<  endl;
        return {};
    }

     vector<int> numbers;
    int number;
    while (inFile >> number) {
        numbers.push_back(number);
    }

    inFile.close();
    return numbers;
}


void writeOutputFile(const  string& filename, const  vector<int>& numbers) {
     ofstream outFile(filename);
    if (!outFile) {
         cerr << "Ошибка открытия файла для записи: " << filename <<  endl;
        return;
    }

    for (int number : numbers) {
        outFile << number <<  endl;
    }

    outFile.close();
}

int main() {
    setlocale(LC_ALL, "ru");
    const  string inputFilename = "input.txt";
    const  string outputFilename = "output.txt";

    
    generateInputFile(inputFilename);

    
     vector<int> numbers = readInputFile(inputFilename);

    if (numbers.empty()) {
         cerr << "Ошибка: входной файл пуст или не удалось прочитать данные." <<  endl;
        return 1;
    }

    
    int maxNumber = * max_element(numbers.begin(), numbers.end());

    
    for (int& number : numbers) {
        number -= maxNumber;
    }

    
    writeOutputFile(outputFilename, numbers);

     cout << "Преобразование завершено. Результаты записаны в файл: " << outputFilename <<  endl;

    return 0;
}
