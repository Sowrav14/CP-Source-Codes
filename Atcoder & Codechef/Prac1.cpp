#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<double> expected_values(const string& S) {
    int N = S.length();
    vector<double> expected(N, 0.0);
    int remaining_blanks = 1;

    for (int i = 0; i < N; ++i) {
        if (S[i] != '?') {
            expected[i] = S[i] - '0';
        } else {
            double sum = 0;
            for (int j = 9; j >= 9 - remaining_blanks + 1; j--) {
                sum += j / 10.0;
            }
            expected[i] = sum;
            remaining_blanks--;
        }
    }

    return expected;
}

int main() {
    string S = "1?";
    vector<double> result = expected_values(S);

    for (double value : result) {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}