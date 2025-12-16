cmake_minimum_required(VERSION 3.10.0)
project(CMakeTest VERSION 0.1.0 LANGUAGES C)

add_executable(CMakeTest main.c OperationStackImpl.c MiniStackVM.h StorageStackImpl.c
        MiniStackVMImpl.c
        OpCode.c
        String.c
        String.h
        StringReader.h
        ByteCodeParse.c
        ByteCodeParse.h
        StringReader.c
)
