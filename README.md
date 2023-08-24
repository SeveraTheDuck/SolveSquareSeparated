# Solve Quadratic Equation
### From [SeveraTheDuck](https://github.com/SeveraTheDuck)

I'm MIPT student of phystech school of applied mathematic and informatic.
This is my first huge progect. *Criticism is welcome.*

This program solves **your own quadratic equation** form ax<sup>2</sup> + bx + c for real numbers.

It includes different cases like linear equation (a = 0).

For developers, the program also runs several tests (if you want to change something,

it is highly recommend to run them). You can read how to enable test mode down below.

### Guide for solving your own equation

1. Download the *repository.rar* file, unzip it wherever you like.
2. Open your terminal in runtask folder(it is *terminal.app* on MacOS
    and Linux and *PowerShell* on Windows).
3. In terminal, run file "run" by typing ./run.
4. You will be asked to type 3 coefficients of your equation. Press enter after that.
5. You will get answer depending on your coefficients. There can be zero, one, two or infinite number of roots.

If you type coefficients in wrong format (like letters), the program will end. Run it once again.

### Guide for developers to run unit tests

1. Download the *repository.rar* file, unzip it wherever you like.
2. Open your terminal in runtask folder(it is *terminal.app* on MacOS
    and Linux and *PowerShell* on Windows).
3. Open *makefile* in any text editor and add "-D _DEBUG" after "=" in 2<sup>nd</sup> and 3<sup>rd</sup> lines.
4. In terminal, run file "run" by typing ./run.
5. You will be asked whether you want to run tests or not. Press y if yes and n if no.
6. The program will display number of succeed tests.
7. You will be asked to type 3 coefficients of your equation. Press enter after that.
8. You will get answer depending on your coefficients. There can be zero, one, two or infinite number of roots.
