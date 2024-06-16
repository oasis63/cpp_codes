#include "helper.h"

void copyVector(const vector<int> &source, vector<int> &destination) {
    destination = source;
}

void clearVector(vector<int> &vec) { vec.clear(); }

void printVector(vector<int> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

void print2DVector(vector<vector<int>> &vect) {
    for (int i = 0; i < vect.size(); i++) {
        for (int j = 0; j < vect[i].size(); j++) {
            cout << vect[i][j] << " ";
        }
        cout << endl;
    }
}