#include "Function.h"

using namespace std;
using namespace std::chrono;

#define Clock               high_resolution_clock
#define nanoTimeConverter   duration_cast<nanoseconds>(timeFinish - timeStart).count() // chuyển đổi sang nano giây

//----------------------------
vector<long long> getRandomInput;      // vector lưu các phần tử trong file arrayRandom.txt
vector<long long> getAscendingInput;   // vector lưu các phần tử trong file arrayAscending.txt
vector<long long> getDescendingInput;  // vector lưu các phần tử trong file arrayDescending.txt
//-----------------------------
vector<long long> timeHandleWithRandomInput;     // vector lưu giá trị thời gian xử lí test Random của các loại thuật sắp xếp
vector<long long> timeHandleWithAscendingInput;  // vector lưu giá trị thời gian xử lí test Tăng dần của các loại thuật sắp xếp
vector<long long> timeHandleWithDescendingInput; // vector lưu giá trị thời gian xử lí test Giảm dần của các loại thuật sắp xếp
//-----------------------------
// Lấy dữ liệu các loại cho các loại input (Ngẫu nhiên, tăng dần, giảm dần)
void getInput() {
    long long length;  // độ dài vector
    fstream f;

    f.open("arrayRandom.txt", ios::in);
    f >> length; // lấy độ dài vector (vì độ dài vector là như nhau ở cả 3 test cases nên ta chỉ cần lấy một lần)

    // khởi tạo độ dài cho các vector
    getRandomInput = vector<long long>(length);
    getAscendingInput = vector<long long>(length);
    getDescendingInput = vector<long long>(length);

    // --------------------------
    // lấy dữ liệu cho vector getRandomInput
    for(long long i = 0; i < length; i++) {
        f >> getRandomInput[i];
    }
    f.close();
    // --------------------------
    // lấy dữ liệu cho vector getAscendingInput
    f.open("arrayAscending.txt", ios::in);
    for(long long i = 0; i < length; i++) {
        f >> getAscendingInput[i];
    }
    f.close();
    // --------------------------
    // lấy dữ liệu cho vector getDescendingInput
    f.open("arrayDescending.txt", ios::in);
    for(long long i = 0; i < length; i++) {
        f >> getDescendingInput[i];
    }
    f.close();
}

//----------------------------
// Hàm gọi đến thuật toán sắp xếp, căn cứ vào chỉ số index
void SortType(long long index, vector<long long>& elements) {
    switch(index) {
        case 0: BubbleSort(elements); break;
        case 1: SelectionSort(elements); break;
        case 2: InsertionSort(elements); break;
        case 3: QuickSort(elements, 0, elements.size() - 1); break;
        case 4: HeapSort(elements); break;
        case 5: MergeSort(elements, 0, elements.size() - 1); break;
    }
}

//----------------------------
// Hàm lấy thời gian xử lí của thuật toán sắp xếp
// index : chỉ số của loại giải thuật
// elements : vector cần xử lí sắp xếp
// timeHandle : vector lưu giá trị xử lí
long long getTimeHandle(long long index, vector<long long>& elements, vector<long long>& timeHandle) {

    Clock::time_point timeStart, timeFinish;

    timeStart = Clock::now();  // bắt đầu tính thời gian
    SortType(index, elements); // gọi hàm xử lí
    timeFinish = Clock::now(); // kết thúc tính thời gian

    long long res = nanoTimeConverter; // chuyển đổi sang nano giây
    timeHandle.push_back(res);  // lưu giá trị vào vector timeHandle

    return res;
}

//----------------------------
// Hàm biểu diễn các giá trị thời gian xử lí trên màn hình console
// i : 0 - 5 tương ứng với 6 loại thuật sắp xếp
void showTimeHandleAll() {
    setTextColor(15);

    for(long long i = 0; i < 6; i++) {
        getInput();
        gotoXY(37, 8 + 2*i); cout<< getTimeHandle(i, getRandomInput, timeHandleWithRandomInput);
        gotoXY(57, 8 + 2*i); cout<< getTimeHandle(i, getAscendingInput, timeHandleWithAscendingInput);
        gotoXY(77, 8 + 2*i); cout<< getTimeHandle(i, getDescendingInput, timeHandleWithDescendingInput);
    }
}

//----------------------------
// Định màu chữ trên màn hình console
void setTextColor(long long color) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, color);
}

//----------------------------
// Di chuyển vị trí của con trỏ trên màn hình console
void gotoXY(long long X, long long Y) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(h, {X, Y});
}

//----------------------------
// Thể hiện kết quả so sánh thời gian xử lí các loại thuật sắp xếp trên màn hình console
void showCompareResult() {
    getInput(); // lấy dữ liệu vào

    // Vẽ bảng kết quả
    system("cls");
    setTextColor(15);
    cout<< "Test case: " << getRandomInput.size() << " elements\n";
    cout<< "Time unit: nanosecond = 10^(-9) second\n\n";

    setTextColor(12); cout << "Processing...";

    setTextColor(15);
    for(long long i = 5; i < 95; i++) { gotoXY(i, 5); putchar(205); }
    for(long long i = 5; i < 95; i++) { gotoXY(i, 7); putchar(205); }
    for(long long i = 5; i < 95; i++) { gotoXY(i, 9); putchar(205); }
    for(long long i = 5; i < 95; i++) { gotoXY(i, 11); putchar(205); }
    for(long long i = 5; i < 95; i++) { gotoXY(i, 13); putchar(205); }
    for(long long i = 5; i < 95; i++) { gotoXY(i, 15); putchar(205); }
    for(long long i = 5; i < 95; i++) { gotoXY(i, 17); putchar(205); }
    for(long long i = 5; i < 95; i++) { gotoXY(i, 19); putchar(205); }
    for(long long i = 5; i <= 19; i++) { gotoXY(4, i); putchar(186); }
    for(long long i = 5; i <= 19; i++) { gotoXY(35, i); putchar(186); }
    for(long long i = 5; i <= 19; i++) { gotoXY(55, i); putchar(186); }
    for(long long i = 5; i <= 19; i++) { gotoXY(75, i); putchar(186); }
    for(long long i = 5; i <= 19; i++) { gotoXY(95, i); putchar(186); }

    gotoXY(4, 5); putchar(201); gotoXY(95, 5); putchar(187);
    gotoXY(4, 19); putchar(200); gotoXY(95, 19); putchar(188);
    gotoXY(4, 7); putchar(204); gotoXY(95, 7); putchar(185);
    gotoXY(4, 9); putchar(204); gotoXY(95, 9); putchar(185);
    gotoXY(4, 11); putchar(204); gotoXY(95, 11); putchar(185);
    gotoXY(4, 13); putchar(204); gotoXY(95, 13); putchar(185);
    gotoXY(4, 15); putchar(204); gotoXY(95, 15); putchar(185);
    gotoXY(4, 17); putchar(204); gotoXY(95, 17); putchar(185);

    gotoXY(35, 5); putchar(203); gotoXY(55, 5); putchar(203); gotoXY(75, 5); putchar(203);
    gotoXY(35, 19); putchar(202); gotoXY(55, 19); putchar(202); gotoXY(75, 19); putchar(202);

    gotoXY(35, 7); putchar(206); gotoXY(55, 7); putchar(206); gotoXY(75, 7); putchar(206);
    gotoXY(35, 9); putchar(206); gotoXY(55, 9); putchar(206); gotoXY(75, 9); putchar(206);
    gotoXY(35, 11); putchar(206); gotoXY(55, 11); putchar(206); gotoXY(75, 11); putchar(206);
    gotoXY(35, 13); putchar(206); gotoXY(55, 13); putchar(206); gotoXY(75, 13); putchar(206);
    gotoXY(35, 15); putchar(206); gotoXY(55, 15); putchar(206); gotoXY(75, 15); putchar(206);
    gotoXY(35, 17); putchar(206); gotoXY(55, 17); putchar(206); gotoXY(75, 17); putchar(206);


    setTextColor(14);
    gotoXY(7, 8); cout<< "Bubble Sort";
    gotoXY(7, 10); cout<< "Selection Sort";
    gotoXY(7, 12); cout<< "Insertion Sort";
    gotoXY(7, 14); cout<< "Quick Sort";
    gotoXY(7, 16); cout<< "Heap Sort";
    gotoXY(7, 18); cout<< "Merge Sort";

    setTextColor(13);
    gotoXY(37, 6); cout<< "Random Input";
    gotoXY(57, 6); cout<< "Ascending Input";
    gotoXY(77, 6); cout<< "Descending Input";

    //------------------------------------
    showTimeHandleAll();  // thể hiện kết quả ra màn hình
    Sleep(1000);

    // tính toán giá trị max, min về thời gian xử lí ở mỗi loại test case
    long long min1 = 0, max1 = 0, min2 = 0, max2 = 0, min3 = 0, max3 = 0;
    for(long long i = 0; i < 3; i++) {
        for(long long j = 0; j < 6; j++) {
            if(timeHandleWithRandomInput[min1] > timeHandleWithRandomInput[j]) { min1 = j; }
            if(timeHandleWithRandomInput[max1] < timeHandleWithRandomInput[j]) { max1 = j; }
            if(timeHandleWithAscendingInput[min2] > timeHandleWithAscendingInput[j]) { min2 = j; }
            if(timeHandleWithAscendingInput[max2] < timeHandleWithAscendingInput[j]) { max2 = j; }
            if(timeHandleWithDescendingInput[min3] > timeHandleWithDescendingInput[j]) {min3 = j; }
            if(timeHandleWithDescendingInput[max3] < timeHandleWithDescendingInput[j]) {max3 = j; }
        }
    }

    setTextColor(10);
    gotoXY(37, 8 + 2*min1); cout<< timeHandleWithRandomInput[min1];
    gotoXY(57, 8 + 2*min2); cout<< timeHandleWithAscendingInput[min2];
    gotoXY(77, 8 + 2*min3); cout<< timeHandleWithDescendingInput[min3];
    setTextColor(12);
    gotoXY(37, 8 + 2*max1); cout<< timeHandleWithRandomInput[max1];
    gotoXY(57, 8 + 2*max2); cout<< timeHandleWithAscendingInput[max2];
    gotoXY(77, 8 + 2*max3); cout<< timeHandleWithDescendingInput[max3];



    gotoXY(0, 3); setTextColor(0); cout<< "Processing...";
    gotoXY(0, 3); setTextColor(12); cout<< "DONE !!!";
    gotoXY(4, 20); cout<< "RED - Worst Result";
    gotoXY(4, 21); setTextColor(10); cout<< "GREEN - Best Result";

    _getch();
}

//----------------------------
// In kết quả mảng đã được sắp xếp ra file outputResult.txt
void printOutput() {
    system("cls");

    long long choose;
    cout<< "Choose one Sort-Algo that you want to get the output result:\n\n";
    cout<< "1. Bubble Sort\n" << "2. Selection Sort\n" << "3. Insertion Sort\n" << "4. Quick Sort\n" <<
            "5. Heap Sort\n" << "6. Merge Sort\n\n";
    cout<< "--> "; cin>> choose; // lấy lựa chọn của người dùng

    getInput(); // lấy input các loại mảng, tuy nhiên chỉ xét việc sắp xếp mảng ngẫu nhiên (Randomly)
                // và xuất kết quả ra file outputResult.txt

    SortType(choose - 1, getRandomInput);

    ofstream f;  // xuất kết quả ra file
    f.open("outputResult.txt");
    for(long long i = 0; i < getRandomInput.size(); i++) {
        f << getRandomInput[i] << " ";
    }

    cout<< "\n\nDONE !!!";
    _getch();
}
