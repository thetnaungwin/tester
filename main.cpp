#include <windows.h>
#include <iostream>

void hideConsole() {
    FreeConsole(); // Detach console
}

void showConsole() {
    AllocConsole(); // Create and attach a new console
    FILE* fp;
    freopen("CONOUT$", "w", stdout); // Redirect stdout to new console
    freopen("CONOUT$", "w", stderr); // Redirect stderr
    freopen("CONIN$", "r", stdin);   // Redirect stdin
}

int main() {
    std::cout << "Console is visible.\n";
    Sleep(2000);

    std::cout << "Hiding console in 2 seconds...\n";
    Sleep(2000);
    hideConsole();

    MessageBox(NULL, "Console is hidden now!", "Info", MB_OK);

    showConsole(); // Bring it back
    std::cout << "Console is shown again!\n";

    return 0;
}
