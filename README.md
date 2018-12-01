# Matrix

## When should I use this program?
Well, if you are tring to calculate the determinant of a square matrix, this program are made for you!!

---

## Building!


### Local
Well, if you want to get the binary file in the same folder of the project, use

    make local

and enjoy it!

<br>

### Builds + Local
So, if you want to keep the object files, and get the binary, use

    make build

and if you want to clean them later, use

    make clan

**But this one will keep the executable.*

<br>

### Build and Install on linux.

> Unfortunately, I can not create a makefile that can install it on MS Windows ... If you know how to do it, feel free to improve my project!

To just install it on linux, use

    sudo make install-linux

and then, you can use it every where!

To uninstall use

    sudo make uninstall-linux

<br>

---

## How to use it?
Easy! You just have to call and say the size of the matrix. I'll assume you're trying to use a square matrix, so you just need to pass one value, intead of the two dimentions (Wrong: 2x2 / Right: 2):

    Matrix 2

to call a 2x2 matrix

***(yes, you can't calculate a assimetrical matrix... for now)***

---

Now, the progam will guide you to enter the correct value in the correct position, like this:

    Line 1:
    Enter the element 1: 4   <-- value that you have passed
    Enter the element 2: 10  <-- value that you have passed

    Line 2:
    Enter the element 1: 50  <-- value that you have passed
    Enter the element 2: 100 <-- value that you have passed

So, when you finished to enter the values to the program, it will show the matrix...

    [  4][ 10]
    [ 50][100]

...and print the determinant:

    The determinant of the matrix is: -100

So that's it, enjoy!

*~Grechuk*
