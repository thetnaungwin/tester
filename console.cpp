#include <windows.h>
#include <cstdio>
#include <iostream>

void hideConsole() {
    FreeConsole(); // Detach the current console
}

void showConsole() {
    AllocConsole(); // Allocate a new console

    // Redirect standard input/output/error streams to the new console.
#ifdef _MSC_VER
    FILE* fp;
    freopen_s(&fp, "CONOUT$", "w", stdout); // Redirect stdout
    freopen_s(&fp, "CONOUT$", "w", stderr); // Redirect stderr
    freopen_s(&fp, "CONIN$", "r", stdin);   // Redirect stdin
#else
    // For non-MSVC compilers like g++, use freopen
    freopen("CONOUT$", "w", stdout); // Redirect stdout
    freopen("CONOUT$", "w", stderr); // Redirect stderr
    freopen("CONIN$", "r", stdin);   // Redirect stdin
#endif
}

int main() {
    std::cout << "Console is visible.\n";
    Sleep(2000);

    std::cout << "Hiding console in 2 seconds...\n";
    Sleep(2000);
    hideConsole();  //add

    MessageBox(NULL, "Console is hidden now!", "Info", MB_OK);

    showConsole(); // Reattach a new console
    std::cout << "Console is shown again!\n";

    return 0;
}
