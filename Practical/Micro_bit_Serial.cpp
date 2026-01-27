#include <windows.h>
#include <iostream>

int main() {
    // COMポートを開く（番号はデバイスマネージャーで確認）
    HANDLE hSerial = CreateFile("\\\\.\\COM7", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    
    // 通信設定（ボーレートをmicro:bit標準の115200に合わせる）
    DCB dcbSerialParams = { 0 };
    dcbSerialParams.BaudRate = CBR_115200;
    SetCommState(hSerial, &dcbSerialParams);

    char szBuff[32];
    DWORD dwBytesRead = 0;
    while(true) {
        if(ReadFile(hSerial, szBuff, sizeof(szBuff)-1, &dwBytesRead, NULL)){
            szBuff[dwBytesRead] = '\0';
            std::cout << "Data: " << szBuff << std::endl;
        }
    }
    CloseHandle(hSerial);
    return 0;
}