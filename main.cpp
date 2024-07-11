#include "Strassen.h"

int main()
{
    int n;
    cout << "Enter n:";
    cin >> n;
    int** A = create(n);
    int** B = create(n);
    int** C = create(n);

    el(A, n);
    el(B, n);

    print(A, n);
    print(B, n);

    auto start = high_resolution_clock::now();

    C = strassen(A, B, n);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);

    print(C, n);

    cout << "Strassen method duration is " << duration.count() << " milliseconds" << endl;

    remove(A, n);
    remove(B, n);
    remove(C, n);

    return 0;
}
