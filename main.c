#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "MiniStackVM.h"
#include "OpCodes.h"

void* emptyArgs[] = {};

DWORD WINAPI MyThreadFunction(LPVOID lpParam) {
    MiniStackVM *vm = createMiniStackVM(5);
    if (!vm) {
        printf("Failed to create MiniStackVM\n");
        return 1;
    }
    executeByteCode(vm, ICONST_2, 0);
    executeByteCode(vm, ISTORE, 1, "0");
    executeByteCode(vm, ICONST_3, 0);
    executeByteCode(vm, ILOAD, 1, "0");
    executeByteCode(vm, IADD, 0);
    executeByteCode(vm, ILOAD, 1, "0");
    executeByteCode(vm, IADD, 0);
    executeByteCode(vm, ICONST_1, 0);
    executeByteCode(vm, IADD, 0);
//    executeBC(vm, "IADD", emptyArgs);
    executeByteCode(vm, PRINT, 0);
    freeMiniStackVM(&vm);
    return 0;
}

int main(void){
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
