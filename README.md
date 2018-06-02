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

Page number = 244 Frame Number = 1 offset: 151 
Virtual address: 62615 Physical address: 407 Value: 37

Page Fault! Obtaining page from disk and assigning to frame 24
Page number = 29 Frame Number = 24 offset: 167 
Virtual address: 7591 Physical address: 6311 Value: 105

Page Fault! Obtaining page from disk and assigning to frame 25
Page number = 252 Frame Number = 25 offset: 235 
Virtual address: 64747 Physical address: 6635 Value: 58

Page Fault! Obtaining page from disk and assigning to frame 26
Page number = 26 Frame Number = 26 offset: 71 
Virtual address: 6727 Physical address: 6727 Value: -111

Page Fault! Obtaining page from disk and assigning to frame 27
Page number = 126 Frame Number = 27 offset: 59 
Virtual address: 32315 Physical address: 6971 Value: -114

Page Fault! Obtaining page from disk and assigning to frame 28
Page number = 236 Frame Number = 28 offset: 229 
Virtual address: 60645 Physical address: 7397 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 29
Page number = 24 Frame Number = 29 offset: 164 
Virtual address: 6308 Physical address: 7588 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 30
Page number = 178 Frame Number = 30 offset: 120 
Virtual address: 45688 Physical address: 7800 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 31
Page number = 3 Frame Number = 31 offset: 201 
Virtual address: 969 Physical address: 8137 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 32
Page number = 159 Frame Number = 32 offset: 187 
Virtual address: 40891 Physical address: 8379 Value: -18

Page Fault! Obtaining page from disk and assigning to frame 33
Page number = 192 Frame Number = 33 offset: 142 
Virtual address: 49294 Physical address: 8590 Value: 48

Page Fault! Obtaining page from disk and assigning to frame 34
Page number = 160 Frame Number = 34 offset: 158 
Virtual address: 41118 Physical address: 8862 Value: 40

Page Fault! Obtaining page from disk and assigning to frame 35
Page number = 83 Frame Number = 35 offset: 147 
Virtual address: 21395 Physical address: 9107 Value: -28

Page Fault! Obtaining page from disk and assigning to frame 36
Page number = 23 Frame Number = 36 offset: 203 
Virtual address: 6091 Physical address: 9419 Value: -14

Page Fault! Obtaining page from disk and assigning to frame 37
Page number = 127 Frame Number = 37 offset: 29 
Virtual address: 32541 Physical address: 9501 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 38
Page number = 69 Frame Number = 38 offset: 1 
Virtual address: 17665 Physical address: 9729 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 39
Page number = 14 Frame Number = 39 offset: 200 
Virtual address: 3784 Physical address: 10184 Value: 0

Page number = 112 Frame Number = 5 offset: 46 
Virtual address: 28718 Physical address: 1326 Value: 28

Page Fault! Obtaining page from disk and assigning to frame 40
Page number = 231 Frame Number = 40 offset: 104 
Virtual address: 59240 Physical address: 10344 Value: 0

Page number = 156 Frame Number = 4 offset: 242 
Virtual address: 40178 Physical address: 1266 Value: 39

Page Fault! Obtaining page from disk and assigning to frame 41
Page number = 234 Frame Number = 41 offset: 182 
Virtual address: 60086 Physical address: 10678 Value: 58

Page Fault! Obtaining page from disk and assigning to frame 42
Page number = 165 Frame Number = 42 offset: 12 
Virtual address: 42252 Physical address: 10764 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 43
Page number = 174 Frame Number = 43 offset: 226 
Virtual address: 44770 Physical address: 11234 Value: 43

Page Fault! Obtaining page from disk and assigning to frame 44
Page number = 87 Frame Number = 44 offset: 242 
Virtual address: 22514 Physical address: 11506 Value: 21

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
