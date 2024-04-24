# Factorial Example using C and PHP

## Why Use Shared Libraries in High-Level Programming Languages

High-level programming languages, like PHP, Python, and Ruby, offer convenience and ease of use for developers. However, they sometimes lack performance or certain low-level functionalities compared to languages like C or C++. This is where shared libraries come into play.

Shared libraries, also known as dynamic link libraries (DLLs) in Windows or shared objects (SO) in Unix-like systems, are compiled code files that can be linked and loaded into a program at runtime. They contain precompiled functions and routines that can be accessed and utilized by programs written in various languages.

### Advantages of Using Shared Libraries:

**Performance Optimization**: Shared libraries are typically written in lower-level languages like C or C++, which offer better performance compared to high-level languages. By using shared libraries for performance-critical operations, developers can leverage the optimized code and algorithms implemented in these languages.

**Reuse of Code**: Shared libraries promote code reuse across different projects and programming languages. Instead of reinventing the wheel for common functionalities like math operations, file I/O, or database access, developers can utilize existing shared libraries that provide these functionalities, saving time and effort.

**Platform Independence**: Shared libraries abstract away platform-specific details and provide a consistent interface for accessing their functionalities. This allows developers to write code that can run on multiple platforms without modification, as long as the necessary shared libraries are available.

**Easier Maintenance**: By separating common functionalities into shared libraries, developers can maintain and update them independently of the main application code. This modular approach simplifies maintenance tasks and reduces the risk of introducing bugs or breaking changes in the main application.

**Security and Stability**: Shared libraries undergo rigorous testing and scrutiny, making them more reliable and secure than custom-built solutions. Additionally, security patches and updates can be applied to shared libraries centrally, ensuring that all applications using them benefit from the improvements.

**Examples of Shared Libraries**:
- libc: The C standard library provides essential functions and routines for C programs, such as memory management, string manipulation, and input/output operations.
- SQLite: A self-contained, serverless, zero-configuration SQL database engine implemented in C. SQLite is widely used in embedded systems, mobile applications, and desktop software due to its small footprint and simplicity.
- GMP (GNU Multiple Precision Arithmetic Library): A library for arbitrary-precision arithmetic, offering high-performance implementations of mathematical functions for integers, rationals, and floating-point numbers.

### Integration with High-Level Languages like PHP:
In the provided example project, we demonstrate how shared libraries written in C can be seamlessly integrated with PHP, a high-level scripting language commonly used for web development. By leveraging PHP's Foreign Function Interface (FFI), developers can load and call functions from shared libraries directly within PHP scripts, extending the language's capabilities to include low-level optimizations and functionalities.

This integration allows PHP developers to harness the power of C libraries like GMP for complex mathematical computations while maintaining the flexibility and productivity benefits of working in a high-level language environment. It showcases the versatility and interoperability of modern programming ecosystems, enabling developers to leverage the strengths of multiple languages within a single project.

## Directory Structure

```
.
├── compile
│   ├── factorial (after compiling)
│   ├── factorial.c
│   └── factorial.php
├── library
│   ├── factorial.so (after compiling)
│   ├── factorial.php
│   └── factorial.c
└── README.md
```

## Contents

- **compile**: Contains C source code and PHP script to calculate factorial.
- **library**: Contains C source code and PHP script with shared library to calculate factorial.
- **README.md**: Instructions on how to compile and use the example.

## Instructions

### Compile Directory

#### C Implementation
- `factorial.c`: C source code to calculate factorial using GMP library.
- To compile the C program, run the following command in the terminal:

```bash
gcc -o compile/factorial compile/factorial.c -lgmp
```

- This will generate an executable named `factorial` in the `compile` directory.

#### PHP Implementation
- `factorial.php`: PHP script to call the compiled C program and calculate factorial.
- Usage:

```bash
php compile/factorial.php <number>
```

Replace `<number>` with the desired integer to calculate its factorial.

### Library Directory

#### C Implementation with Shared Library
- `factorial.c`: C source code to calculate factorial using GMP library and generate a shared library.
- To compile the C program and generate the shared library, run the following command in the terminal:

```bash
gcc -shared -o library/factorial.so library/factorial.c -lgmp
```

- This will generate a shared library named `factorial.so` in the `library` directory.

#### PHP Implementation with Shared Library
- `factorial.php`: PHP script to call the shared library and calculate factorial.
- Usage:

```bash
php library/factorial.php <number>
```

Replace `<number>` with the desired integer to calculate its factorial.

### Example Usage
- Run the following command to calculate the factorial of `50` using the compiled C program:

```bash
./compile/factorial 50
```

- Run the following command to calculate the factorial of `50` using php and the C shared library:

```bash
php library/factorial.php 50
```

## Requirements

Before using the provided examples, ensure that the following requirements are met and the necessary dependencies are installed:

### Compiler

- **GCC (GNU Compiler Collection)**: Required for compiling C programs. Install GCC using your package manager. For example, on Debian-based systems (e.g., Ubuntu), you can install it with the following command:

    ```bash
    sudo apt-get install build-essential
    ```

- **GMP (GNU Multiple Precision Arithmetic Library)**: Required for handling arbitrary-precision arithmetic in C programs. Install GMP using your package manager. For example, on Debian-based systems, you can install it with the following command:

    ```bash
    sudo apt-get install libgmp-dev
    ```

### PHP

- **PHP**: Ensure that PHP is installed on your system. You can download PHP from the official PHP website ([php.net](https://www.php.net/downloads)).

1. **Locate PHP Configuration File**: Run the following command to locate the PHP configuration file (`php.ini`):

    ```bash
    php --ini
    ```

    Note down the path to the configuration file displayed in the output.

2. **Enable FFI Extension**:
    - Open the PHP configuration file (`php.ini`) in a text editor.
    - Add the following line to enable the FFI extension:
    
    ```ini
    extension=ffi.so
    ```
    
3. **Enable GMP Extension**:
    - Similarly, add the following line to enable the GMP extension:
    
    ```ini
    extension=gmp.so
    ```

4. **Enable FFI Support**:
    - Ensure that FFI support is enabled by adding or modifying the following line:
    
    ```ini
    ffi.enable=true
    ```

5. **Verify Extensions**:
    - Save the changes to the PHP configuration file.
    - Restart the PHP service if necessary.
    - To check if the extensions are enabled, run the following command:
    
    ```bash
    php -m
    ```

    Verify that both `gmp` and `ffi` appear in the list of loaded modules.

Once you've installed the necessary dependencies and configured PHP accordingly, you're ready to use the provided examples.

