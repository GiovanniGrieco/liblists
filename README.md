# LibLists

This is a simple library that offers basic functionalities on managing lists in
memory. This library is entirely written in C.

To know how to work with the library, just read *header* files. You'll find the
relative documentation for each function.

The source code is licensed under GPLv3. You are free to contribute or fork this
project.

## Compile

### Pre-requisites
Make sure you have installed the following software on your system:

#### Linux
- _gcc_ or _clang_ (Personally I prefer the latter)
- _make_

#### OS X
- _Xcode Command Line Tools_

#### Windows
- _MinGW_ (make sure the environment variable *PATH* is set correctly!)
- _gcc_ (_mingw32-base_ package if you are unsure)

### Compile the source
Just type on _Linux_ or _OS X_

```Shell
make
```

Remember, if you are using _Linux_, to do ```make install``` or programs won't
run.

On _Windows_ the Makefile is broken, I made, hopefully temporally, a batch
script. Just type
```Shell
compile_windows.bat
```

This automated process also compile example programs, just as a proof of concept on what can be done. Binaries will be saved in ```build``` folder.

### Clean source folder from binaries
```Shell
make clean
```