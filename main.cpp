#include <iostream>
#include <fstream>

using namespace std;
static const int maxsize = 100;

void printMatrix(int* m, int size);
void addMatrix(int* m1, int* m2, int size);
void productMatrix(int* m1, int* m2, int size);
void subMatrix(int* m1, int* m2, int size);

int main() {
    int size;
    std::ifstream input("matrix_input.txt");
    input >> size;
    int m1[size][size], m2[size][size];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            input >> m1[i][j];
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            input >> m2[i][j];
        }
    }

    input.close();

    cout << "Vincent Dick\nLab #6: Matrix manipulation\n";
    cout << "\nMatrix A:\n";
    printMatrix(reinterpret_cast<int*>(m1), size);
    cout << "\nMatrix B:\n";
    printMatrix(reinterpret_cast<int*>(m2), size);
    cout << "\nMatrix Sum (A + B):\n";
    addMatrix(reinterpret_cast<int*>(m1), reinterpret_cast<int*>(m2), size);
    cout << "\nMatrix Product (A * B)\n";
    productMatrix(reinterpret_cast<int*>(m1), reinterpret_cast<int*>(m2), size);
    cout << "\nMatrix Difference (A - B)\n";
    subMatrix(reinterpret_cast<int*>(m1), reinterpret_cast<int*>(m2), size);

    return 0;
}

void printMatrix(int* m, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << m[(i*size + j)] << " ";
        }
        cout << endl;
    }
}

void addMatrix(int* m1, int* m2, int size) {
    int m3[size][size];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            m3[i][j] = m1[i*size + j] + m2[i*size + j];
        }
    }
    printMatrix(reinterpret_cast<int*>(m3), size);
}

void productMatrix(int* m1, int* m2, int size) {
    int m3[size][size];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            m3[i][j] = 0;
            for (int k = 0; k < size; k++) {
                m3[i][j] += m1[i*size + k] * m2[k*size + j];
            }
        }
    }
    printMatrix(reinterpret_cast<int*>(m3), size);
}

void subMatrix(int* m1, int* m2, int size) {
    int m3[size][size];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            m3[i][j] = m1[i*size + j] - m2[i*size + j];
        }
    }
    printMatrix(reinterpret_cast<int*>(m3), size);
}