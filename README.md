# The N*-ecosystem's core library.

<!-- ========================================================================================================================================================== -->

## Description

### Basic
This library provides basic things for other N*-ecosystem libaries, like error codes, fundamental types and basic data containers.

### Thread-safe
This library is completely **thread-safe**, because it doesn't uses any multithreading-dangerous things.

<!-- ========================================================================================================================================================== -->

## Building the library

### Windows

#### MSVC
Requirements: `Visual Studio`, `CMake`

1. Clone this repo and open it **folder** in Visual Studio.
2. Visual Studio must generate MSBuild script through CMake automaticly. Just wait for it.
3. Build library and tests through Viusal Studio GUI, using hotkey (Ctrl + Shift + B by default) or terminal.

#### MinGW UCRT64
Requirements: `MSYS2 UCRT64`, `MinGW UCRT64`, `make` (`mingw32-make`), `CMake`.

1. Run **MSYS2 UCRT64 environment** (<ins>**recommended**</ins>). Install all requirements if you haven't it.
2. Clone this repo and go to repository root folder.
3. Create folder `build`. Go to this catalog.
4. Run `cmake -S .. -G "MinGW Makefiles" -DCMAKE_INSTALL_PREFIX=$MSYSTEM_PREFIX`. Wait for generating Makefile.
5. Run `mingw32-make` and wait for building library.

### Linux (UNIX)
Requirements: `GCC`, `make`, `CMake`

1. Install all requirements if you haven't it.
2. Clone this repo and go to repository root folder.
3. Create folder `build`. Go to this catalog.
4. Run `cmake -S ..`. Wait for generating Makefile.
5. Run `make` and wait for building library.

<!-- ========================================================================================================================================================== -->

## Installation

### Windows

#### MinGW UCRT64
Just run `mingw32-make install`. Library will be installed to your MSYS2 system path (specified in -DCMAKE_INSTALL_PATH CMake option; `/ucrt64` in this example).

### Linux (UNIX)
Also just run `sudo make install`. Library will be installed to your system.

<!-- ========================================================================================================================================================== -->

## Usage in project

### Manual linking (GCC/MinGW options style)
> [!WARNING]
> Manual linking is not recommended library usage way. Please use CMake for correct linking with library.

Include `<libncore.h>` header where you need to use this library. That link your executable with library by adding flag to command line `-lncore`. If you use static version of this library, please specify definition `LIBNCORE_STATIC` when you compile file, where included <ins>libncore</ins> header. Also you need to link with required dependencies.

### CMake
If you using CMake in your project, add `libncore` by using `find_package`:

```cmake
find_package(libncore REQUIRED)
target_link_libraries(<target> PRIVATE libncore::ncore)
```

This will fully automatily setup <ins>libncore</ins> for your project. By default CMake will use static version of <ins>libncore</ins>, so if you want to use dynamic version of this library, set `BUILD_SHARED_LIBS` flag in your CMake config command prompt to `ON`.

<!-- ========================================================================================================================================================== -->