# CIE 302 - Virtual Memory


This program will read a file containing several 32-bit integer numbers that represent logical addresses. However, it will need only be concerned with 16-bit addresses.

These 16 bits are divided into (1) an 8-bit page number and (2) 8-bit page offset. Hence, the addresses are structured as shown:
```
***********************************************************
31********************16******************7***************0
|                      |    page number   |    offset     |
31********************16******************7***************0
***********************************************************
```
Other specifics include the following: <br />
• 28 entries in the page table <br />
• Page size of 28 bytes <br />
• 16 entries in the TLB <br />
• Frame size of 28 bytes <br />
• 256 frames <br />
• Physical memory of 65,536 bytes (256 frames × 256-byte frame size) <br />


This code is fully developed by Ahmed Wael and Mohamed Elsayed for the operating system class in spring 2018.

## Error handling:
Code is capable of handling the input error cases.

```
$ ./a.out addresse.txt
Error opening addresses.txt addresse.txt

$ ./a.out addresses.txt
Error opening BACKING_STORE.bin BACKING_STORE.bin
```

## How to use
Change the virtual addresses in addresses.txt and the output of the code will be printed on the terminal representing the physical addresses generated and the process of getting frames from page table and the use of TLB.
```
$ ./a.out addresses.txt

mohamed@mohamed-laptop:~/Desktop/OS Project$ ./a.out addresses.txt
Page Fault! Obtaining page from disk and assigning to frame 0
Page number = 66 Frame Number = 0 offset: 20 
Virtual address: 16916 Physical address: 20 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 1
Page number = 244 Frame Number = 1 offset: 29 
Virtual address: 62493 Physical address: 285 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 2
Page number = 117 Frame Number = 2 offset: 246 
Virtual address: 30198 Physical address: 758 Value: 29

Page Fault! Obtaining page from disk and assigning to frame 3
Page number = 209 Frame Number = 3 offset: 179 
Virtual address: 53683 Physical address: 947 Value: 108

Page Fault! Obtaining page from disk and assigning to frame 4
Page number = 156 Frame Number = 4 offset: 249 
Virtual address: 40185 Physical address: 1273 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 5
Page number = 112 Frame Number = 5 offset: 109 
Virtual address: 28781 Physical address: 1389 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 6
Page number = 95 Frame Number = 6 offset: 142 
Virtual address: 24462 Physical address: 1678 Value: 23

Page Fault! Obtaining page from disk and assigning to frame 7
Page number = 189 Frame Number = 7 offset: 15 
Virtual address: 48399 Physical address: 1807 Value: 67

Page Fault! Obtaining page from disk and assigning to frame 8
Page number = 253 Frame Number = 8 offset: 47 
Virtual address: 64815 Physical address: 2095 Value: 75

Page Fault! Obtaining page from disk and assigning to frame 9
Page number = 71 Frame Number = 9 offset: 119 
Virtual address: 18295 Physical address: 2423 Value: -35

Page Fault! Obtaining page from disk and assigning to frame 10
Page number = 47 Frame Number = 10 offset: 186 
Virtual address: 12218 Physical address: 2746 Value: 11

Page Fault! Obtaining page from disk and assigning to frame 11
Page number = 88 Frame Number = 11 offset: 232 
Virtual address: 22760 Physical address: 3048 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 12
Page number = 226 Frame Number = 12 offset: 126 
Virtual address: 57982 Physical address: 3198 Value: 56

Page Fault! Obtaining page from disk and assigning to frame 13
Page number = 109 Frame Number = 13 offset: 62 
Virtual address: 27966 Physical address: 3390 Value: 27

Page Fault! Obtaining page from disk and assigning to frame 14
Page number = 214 Frame Number = 14 offset: 110 
Virtual address: 54894 Physical address: 3694 Value: 53

Page Fault! Obtaining page from disk and assigning to frame 15
Page number = 152 Frame Number = 15 offset: 17 
Virtual address: 38929 Physical address: 3857 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 16
Page number = 128 Frame Number = 16 offset: 97 
Virtual address: 32865 Physical address: 4193 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 17
Page number = 250 Frame Number = 17 offset: 243 
Virtual address: 64243 Physical address: 4595 Value: -68

Page Fault! Obtaining page from disk and assigning to frame 18
Page number = 9 Frame Number = 18 offset: 11 
Virtual address: 2315 Physical address: 4619 Value: 66

Page Fault! Obtaining page from disk and assigning to frame 19
Page number = 251 Frame Number = 19 offset: 198 
Virtual address: 64454 Physical address: 5062 Value: 62

Page Fault! Obtaining page from disk and assigning to frame 20
Page number = 215 Frame Number = 20 offset: 1 
Virtual address: 55041 Physical address: 5121 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 21
Page number = 72 Frame Number = 21 offset: 201 
Virtual address: 18633 Physical address: 5577 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 22
Page number = 56 Frame Number = 22 offset: 221 
Virtual address: 14557 Physical address: 5853 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 23
Page number = 238 Frame Number = 23 offset: 78 
Virtual address: 61006 Physical address: 5966 Value: 59

...

Number of references = 1000
Number of page faults = 244
Number of TLB Hits = 60
Page-fault rate = 0.244000
TLB hit rate = 0.060000
```

## Built With

* [GCC](https://gcc.gnu.org/) - The GNU Compiler Collection
* [Ubuntu 16.04 LTS](releases.ubuntu.com/16.04/) - Xenial Xerus

## Authors

* **Mohamed Elsayed** - [Github](https://github.com/mohamedelsayed95)
* **Ahmed Wael** - [Github](https://github.com/ahmedwael19)

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.
