@echo off

set PATH=%~dp0emscripten\cmake\bin;%~dp0emscripten\python;%~dp0emscripten\node;%~dp0emscripten;%PATH%

set CMAKE_GENERATOR=Ninja
set CMAKE_TOOLCHAIN_FILE=%~dp0emscripten\cmake\Modules\Platform\Emscripten.cmake
set CXXFLAGS=-Wno-version-check
set CFLAGS=-Wno-version-check

cmd
