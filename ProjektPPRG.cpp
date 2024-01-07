#include <iostream>
#include <vector>

using namespace std;

//deklaracje

void displayMatrix(const vector<vector<int>>& matrix, const string& name); //funkcja wyswietlajaca macierz
vector<vector<int>> inicjalizacja(int row, int col, const string& name); //funkcja uzupelniajaca macierz
vector<vector<int>> dodawanie(const vector<vector<int>>& matrixA, const vector<vector<int>>& matrixB); //dodawanie macierzy
vector<vector<int>> odejmowanie(const vector<vector<int>>& matrixA, const vector<vector<int>>& matrixB); //odejmowanie macierzy
vector<vector<int>> mnozenie(const vector<vector<int>>& matrixA, const vector<vector<int>>& matrixB); //mnozenie macierzy
vector<vector<int>> transpozycja(const vector<vector<int>>& matrix); //transpozycja macierzy

int main() {

    //okreslenie wymiarow
    int row = 3;
    int col = 3;

    cout << "Witaj w kalkulatorze macierzy!\n";

    vector<vector<int>> matrixA = inicjalizacja(row, col, "macierz A");

    vector<vector<int>> matrixB = inicjalizacja(row, col, "macierz B");

    displayMatrix(matrixA, "Macierz A");
    displayMatrix(matrixB, "Macierz B");

    cout << "Wybierz operacje:\n";
    cout << "1. Dodawanie macierzy\n";
    cout << "2. Odejmowanie macierzy\n";
    cout << "3. Mnozenie macierzy\n";
    cout << "4. Transpozycja macierzy\n";

    int operation;
    cin >> operation;

    vector<vector<int>> resultMatrix;

    //wykonywanie operacji
    switch (operation) {
    case 1:
        resultMatrix = dodawanie(matrixA, matrixB);
        break;
    case 2:
        resultMatrix = odejmowanie(matrixA, matrixB);
        break;
    case 3:
        resultMatrix = mnozenie(matrixA, matrixB);
        break;
    case 4:
        resultMatrix = transpozycja(matrixA);
        break;
    default:
        cout << "Nieprawidlowy wybor operacji.\n";
        return 1;
    }

    //wyswietlenie macierzy
    displayMatrix(resultMatrix, "Macierz Wynikowa");

    return 0;
}


//funkcja wyswietlajaca macierze
void displayMatrix(const vector<vector<int>>& matrix, const string& name) {
    cout << name << ":\n";
    for (const auto& row : matrix) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }
}


//uzupelnianie macierzy
vector<vector<int>> inicjalizacja(int row, int col, const string& name) {
    cout << "Uzupelnij " << name << ":\n";
    vector<vector<int>> matrix(row, vector<int>(col, 0));

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << "Wprowadz wartosc dla [" << i << "][" << j << "]: ";

            //sprawdzanie czy wprowadzona wartosc jest liczba calkowita
            while (!(cin >> matrix[i][j])) {
                cout << "Blad! Wprowadz liczbe calkowita: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignorowanie blednego wejscia
            }
        }   
    }

    return matrix;
}


//dodawanie
vector<vector<int>> dodawanie(const vector<vector<int>>& matrixA, const vector<vector<int>>& matrixB) {
    vector<vector<int>> result(matrixA);

    for (int i = 0; i < matrixA.size(); ++i) {
        for (int j = 0; j < matrixA[0].size(); ++j) {
            result[i][j] += matrixB[i][j];
        }
    }

    return result;
}


//odejmowanie
vector<vector<int>> odejmowanie(const vector<vector<int>>& matrixA, const vector<vector<int>>& matrixB) {
    vector<vector<int>> result(matrixA);

    for (int i = 0; i < matrixA.size(); ++i) {
        for (int j = 0; j < matrixA[0].size(); ++j) {
            result[i][j] -= matrixB[i][j];
        }
    }

    return result;
}


//mnożenie
vector<vector<int>> mnozenie(const vector<vector<int>>& matrixA, const vector<vector<int>>& matrixB) {
    int rowA = matrixA.size();
    int colA = matrixA[0].size();
    int colB = matrixB[0].size();

    vector<vector<int>> result(rowA, vector<int>(colB, 0));

    for (int i = 0; i < rowA; ++i) {
        for (int j = 0; j < colB; ++j) {
            for (int k = 0; k < colA; ++k) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    return result;
}


//transpozycja
vector<vector<int>> transpozycja(const vector<vector<int>>& matrix) {
    int row = matrix.size();
    int col = matrix[0].size();

    vector<vector<int>> result(col, vector<int>(row, 0));

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            result[j][i] = matrix[i][j];
        }
    }

    return result;
}
