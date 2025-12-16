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
    executeByteCode(vm, ICONST_2, emptyArgs);
    void* t[1] = {"0"};
    executeByteCode(vm, ISTORE, t);
    executeByteCode(vm, ICONST_3, emptyArgs);
    executeByteCode(vm, ILOAD, t);
    executeByteCode(vm, IADD, emptyArgs);
    executeByteCode(vm, ILOAD, t);
    executeByteCode(vm, IADD, emptyArgs);
    executeByteCode(vm, ICONST_1, emptyArgs);
    executeBC(vm, "IADD", emptyArgs);
    executeByteCode(vm, PRINT, emptyArgs);
    freeMiniStackVM(vm);
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
