#include <windows.h>
#include <iostream>
#include <string>

// シリアルポート設定
const char* PORT_NAME = "\\\\.\\COM7"; // お使いのポートに合わせて変更 (例: COM3, COM4...)
const int BAUDRATE = 115200;

int main() {
    // 1. シリアルポートを開く
    HANDLE hSerial = CreateFileA(PORT_NAME, GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

    if (hSerial == INVALID_HANDLE_VALUE) {
        std::cerr << "Error: We failed to open the COM" << std::endl;
        return 1;
    }

    // 2. 通信パラメータの設定
    DCB dcbSerialParams = { 0 };
    dcbSerialParams.DCBlength = sizeof(dcbSerialParams);

    if (!GetCommState(hSerial, &dcbSerialParams)) {
        std::cerr << "Error: We couldn't get the condition" << std::endl;
        CloseHandle(hSerial);
        return 1;
    }

    dcbSerialParams.BaudRate = BAUDRATE;
    dcbSerialParams.ByteSize = 8;
    dcbSerialParams.StopBits = ONESTOPBIT;
    dcbSerialParams.Parity = NOPARITY;

    if (!SetCommState(hSerial, &dcbSerialParams)) {
        std::cerr << "Error: We couldn't apply the config" << std::endl;
        CloseHandle(hSerial);
        return 1;
    }

    // タイムアウト設定（即時リターン設定）
    COMMTIMEOUTS timeouts = { 0 };
    timeouts.ReadIntervalTimeout = 50;
    timeouts.ReadTotalTimeoutConstant = 50;
    timeouts.ReadTotalTimeoutMultiplier = 10;
    SetCommTimeouts(hSerial, &timeouts);

    std::cout << "--- Airsoft Shoot Timer (Desktop Edition) ---" << std::endl;
    std::cout << "Waiting for data from Micro:bit..." << std::endl;

    // 3. 受信ループ
    char buffer[1];
    DWORD bytesRead;
    std::string lineBuffer = "";

    while (true) {
        if (ReadFile(hSerial, buffer, 1, &bytesRead, NULL)) {
            if (bytesRead > 0) {
                // 改行が来るまでバッファに溜める
                if (buffer[0] == '\n') {
                    if (!lineBuffer.empty()) {
                        // データ受信時の処理
                        if (lineBuffer == "TIMER_STARTED") {
                            std::cout << "\n[STATUS] Timer Started! Go!" << std::endl;
                        } else if (lineBuffer == "TIMER_STOPPED") {
                            std::cout << "[STATUS] Timer Stopped." << std::endl;
                        } else if (lineBuffer == "RESET") {
                            std::cout << "[STATUS] Reset." << std::endl;
                            system("cls"); // 画面クリア
                            std::cout << "--- Airsoft Shoot Timer (Desktop Edition) ---" << std::endl;
                        } else {
                            // 秒数の表示
                            std::cout << ">> SHOT: " << lineBuffer << " sec" << std::endl;
                        }
                        lineBuffer = "";
                    }
                } else {
                    if (buffer[0] != '\r') { // CRは無視
                        lineBuffer += buffer[0];
                    }
                }
            }
        }
    }

    CloseHandle(hSerial);
    return 0;
}