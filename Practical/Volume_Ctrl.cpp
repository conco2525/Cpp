#include <windows.h>
#include <iostream>

// Windowsの仮想キー入力を送信する関数
void PressVolumeKey(WORD vkey) {
    INPUT input;
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = vkey; // VK_VOLUME_UP, VK_VOLUME_DOWN, VK_VOLUME_MUTE
    input.ki.dwFlags = 0; // キーを押す
    SendInput(1, &input, sizeof(INPUT));

    input.ki.dwFlags = KEYEVENTF_KEYUP; // キーを離す
    SendInput(1, &input, sizeof(INPUT));
}

int main() {
    // 1. ポート設定
    const char* portName = "\\\\.\\COM7"; 
    HANDLE hSerial = CreateFile(portName, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

    if (hSerial == INVALID_HANDLE_VALUE) {
        std::cerr << "We cannot open the port!" << std::endl;
        return 1;
    }

    DCB dcb = { 0 };

    dcb.DCBlength = sizeof(dcb);
    GetCommState(hSerial, &dcb);
    dcb.BaudRate = CBR_115200;
    SetCommState(hSerial, &dcb);

    std::cout << "waiting..." << std::endl;

    char buffer[1];
    DWORD bytesRead;

    while (true) {
        if (ReadFile(hSerial, buffer, 1, &bytesRead, NULL) && bytesRead > 0) {
            char cmd = buffer[0];
            
            if (cmd == 'U') {
                std::cout << "UP Volume" << std::endl;
                PressVolumeKey(VK_VOLUME_UP);
                Sleep(300);
                PurgeComm(hSerial, PURGE_RXCLEAR);
            } 
            else if (cmd == 'D') {
                std::cout << "DOWN Volume" << std::endl;
                PressVolumeKey(VK_VOLUME_DOWN);
                Sleep(300);
                PurgeComm(hSerial, PURGE_RXCLEAR);
            }
            else if (cmd == 'M') {
                std::cout << "Mute" << std::endl;
                PressVolumeKey(VK_VOLUME_MUTE);
                Sleep(100);
                PurgeComm(hSerial, PURGE_RXCLEAR);
            }
        }
        Sleep(10); // CPU負荷軽減
    }

    CloseHandle(hSerial);
    return 0;
}