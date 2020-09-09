#include <iostream>
#include <algorithm>
#include <windows.h>
using namespace std;

// PHÁT SINH MẢNG NGẪU NHIÊN
// Giới hạn: [minValue, maxValue]
// Hình thức: 3 loại (Ngẫu nhiên, Tăng dần, Giảm dần)

void ArrayGenerator() {
    long long numberOfElements;
    long long minValue;
    long long maxValue;

    system("cls");
    cout << "\n--- ARRAY GENERATOR ---\n";
    cout << "\nUSAGE: <number_of_elements> <minimum_value> <maximum_value>\n";
    cout << "\n\n--> ";

// lấy input người dùng nhập vào
    cin >> numberOfElements >> minValue >> maxValue;

    cout << "\n\nProcessing ...\n";

// xử lí phát sinh mảng ngẫu nhiên
    // xuất ra file arrayRandom.txt mảng theo thứ tự ngẫu nhiên
    fstream f;
    f.open("arrayRandom.txt", ios::out);
    f << numberOfElements << endl;
    for(long long i = 0; i < numberOfElements; i++) {
        f << minValue + rand()% (maxValue - minValue + 1) << " ";
    }

    f.close();

    // xuất ra file arrayAscending.txt mảng theo thứ tự ngẫu nhiên tăng dần
    fstream g;
    g.open("arrayAscending.txt", ios::out);
    g << numberOfElements << endl;

    vector<long long> elements(numberOfElements); // tạo mảng ngẫu nhiên
    for(long long i = 0; i < numberOfElements; i++) {
        elements[i] = minValue + rand()% (maxValue - minValue + 1);
    }
    sort(elements.begin(), elements.end()); // sắp xếp để được mảng tăng đần, sử dụng std::sort

    for(int i = 0; i < numberOfElements; i++) {  // xuất ra file
        g << elements[i] << " ";
    }

    g.close();

    // xuất ra file arrayDescending.txt mảng ngẫu nhiên theo thứ tự giảm dần
    fstream t;
    t.open("arrayDescending.txt", ios::out);
    t << numberOfElements << endl;

    for(long long i = 0; i < numberOfElements; i++) { // tương tự, tạo mảng ngẫu nhiên
        elements[i] = minValue + rand()% (maxValue - minValue + 1);
    }
    sort(elements.begin(), elements.end()); // sắp xếp để được mảng tăng dần, sử dụng std::sort
    reverse(elements.begin(), elements.end()); // đảo ngược toàn bộ mảng để được mảng giảm đần, sử dụng std::reverse

    for(long long i = 0; i < numberOfElements; i++) {  // xuất ra file
        t << elements[i] << " ";
    }

    t.close();

    cout << "\nOUTPUT SUCCESSFULLY :)\n"; // quá trình phát sinh 3 loại mảng hoàn tất

    _getch();
}
