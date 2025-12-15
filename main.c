#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "MiniStackVM.h"

DWORD WINAPI MyThreadFunction(LPVOID lpParam) {
    MiniStackVM *vm = createMiniStackVM(sizeof(int));
    if (!vm) {
        printf("Failed to create MiniStackVM\n");
        return 1;
    }
    executebyteCode(vm, ICONST_2);
    executebyteCode(vm, ICONST_3);
    executebyteCode(vm, IADD);
    executebyteCode(vm, PRINT);
    freeMiniStackVM(vm);
    return 0;
}

int main(int, char** args){
    const HANDLE handle = CreateThread(NULL, 0, MyThreadFunction, NULL, 0, NULL);

    if (handle == NULL)
    {
        printf("Error creating thread: %d\n", GetLastError());
        return 1;
    }

    Sleep(10000); // Wait for thread to finish
    
    CloseHandle(handle);
    return 0;
}
