#include <iostream>
#include <conio.h>
#include <vector>
#include <windows.h>
#include <fstream>
#include <chrono> // high resolution timing
#include "SortAlgorithm.h"


// Lấy dữ liệu các loại input (Ngẫu nhiên, tăng dần, giảm dần)
void getInput();

// Hàm gọi đến thuật toán sắp xếp, căn cứ vào chỉ số index
void SortType(long long index, vector<long long>& elements);

// Lấy thời gian xử lí của thuật toán sắp xếp
long long getTimeHandle(long long index, vector<long long>& elements, vector<long long>& timeHandle);

// Biểu diễn các giá trị thời gian xử lí trên màn hình console
void showTimeHandleAll();

// Định màu chữ trên màn hình console
void setTextColor(long long color);

// Di chuyển vị trí của con trỏ trên màn hình console
void gotoXY(long long X, long long Y);

// Thể hiện bảng kết quả so sánh thời gian xử lí các loại thuật sắp xếp trên màn hình console
void showCompareResult();

// In kết quả mảng đã được sắp xếp ra file outputResult.txt
void printOutput();
