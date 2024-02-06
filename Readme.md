# To build a C++ project with a CMake file, follow these steps:

1. **Create a build directory**: This is where all the build files will go. It's common practice to do out-of-source builds with CMake to keep build files separate from source files. From your terminal, navigate to your project directory and create a new directory called `build`:

    ```bash
    mkdir build
    ```

2. **Navigate into the build directory**:

    ```bash
    cd build
    ```

3. **Run CMake**: This will generate the build files. You need to tell CMake where the `CMakeLists.txt` file is. Since you're in the `build` directory and the `CMakeLists.txt` file is in the parent directory, you can use `..` to refer to the parent directory:

    ```bash
    cmake ..
    ```

4. **Build the project**: After running CMake, you can build the project using the generated build files. If you're on Unix-based system like Linux or macOS, CMake generates Makefiles by default, so you can use `make` to build the project:

    ```bash
    make
    ```

    If you're on Windows and you're using a different build system, you'll need to use the appropriate command for that build system.

After building the project, the executable (or library, depending on your project) will be in the `build` directory.