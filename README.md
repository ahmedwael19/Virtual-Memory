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

Page Fault! Obtaining page from disk and assigning to frame 45
Page number = 11 Frame Number = 45 offset: 251 
Virtual address: 3067 Physical address: 11771 Value: -2

Page Fault! Obtaining page from disk and assigning to frame 46
Page number = 61 Frame Number = 46 offset: 141 
Virtual address: 15757 Physical address: 11917 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 47
Page number = 123 Frame Number = 47 offset: 161 
Virtual address: 31649 Physical address: 12193 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 48
Page number = 42 Frame Number = 48 offset: 90 
Virtual address: 10842 Physical address: 12378 Value: 10

Page Fault! Obtaining page from disk and assigning to frame 49
Page number = 170 Frame Number = 49 offset: 245 
Virtual address: 43765 Physical address: 12789 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 50
Page number = 130 Frame Number = 50 offset: 125 
Virtual address: 33405 Physical address: 12925 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 51
Page number = 175 Frame Number = 51 offset: 154 
Virtual address: 44954 Physical address: 13210 Value: 43

Page Fault! Obtaining page from disk and assigning to frame 52
Page number = 221 Frame Number = 52 offset: 81 
Virtual address: 56657 Physical address: 13393 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 53
Page number = 19 Frame Number = 53 offset: 139 
Virtual address: 5003 Physical address: 13707 Value: -30

Page Fault! Obtaining page from disk and assigning to frame 54
Page number = 196 Frame Number = 54 offset: 51 
Virtual address: 50227 Physical address: 13875 Value: 12

Page Fault! Obtaining page from disk and assigning to frame 55
Page number = 75 Frame Number = 55 offset: 158 
Virtual address: 19358 Physical address: 14238 Value: 18

Page Fault! Obtaining page from disk and assigning to frame 56
Page number = 142 Frame Number = 56 offset: 177 
Virtual address: 36529 Physical address: 14513 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 57
Page number = 40 Frame Number = 57 offset: 152 
Virtual address: 10392 Physical address: 14744 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 58
Page number = 230 Frame Number = 58 offset: 2 
Virtual address: 58882 Physical address: 14850 Value: 57

Page Fault! Obtaining page from disk and assigning to frame 59
Page number = 20 Frame Number = 59 offset: 9 
Virtual address: 5129 Physical address: 15113 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 60
Page number = 228 Frame Number = 60 offset: 186 
Virtual address: 58554 Physical address: 15546 Value: 57

Page number = 228 Frame Number = 60 offset: 216 
Virtual address: 58584 Physical address: 15576 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 61
Page number = 107 Frame Number = 61 offset: 52 
Virtual address: 27444 Physical address: 15668 Value: 0

Page number = 230 Frame Number = 58 offset: 102 
Virtual address: 58982 Physical address: 14950 Value: 57

Page Fault! Obtaining page from disk and assigning to frame 62
Page number = 201 Frame Number = 62 offset: 20 
Virtual address: 51476 Physical address: 15892 Value: 0

Page number = 26 Frame Number = 26 offset: 140 
Virtual address: 6796 Physical address: 6796 Value: 0

Page number = 83 Frame Number = 35 offset: 63 
Virtual address: 21311 Physical address: 9023 Value: -49

Page Fault! Obtaining page from disk and assigning to frame 63
Page number = 119 Frame Number = 63 offset: 241 
Virtual address: 30705 Physical address: 16369 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 64
Page number = 113 Frame Number = 64 offset: 36 
Virtual address: 28964 Physical address: 16420 Value: 0

Page number = 160 Frame Number = 34 offset: 43 
Virtual address: 41003 Physical address: 8747 Value: 10

Page Fault! Obtaining page from disk and assigning to frame 65
Page number = 79 Frame Number = 65 offset: 35 
Virtual address: 20259 Physical address: 16675 Value: -56

Found in TLB, page number = 226 correspond to frame = 12 
Page number = 226 Frame Number = 12 offset: 1 
Virtual address: 57857 Physical address: 3073 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 66
Page number = 247 Frame Number = 66 offset: 26 
Virtual address: 63258 Physical address: 16922 Value: 61

Page number = 142 Frame Number = 56 offset: 22 
Virtual address: 36374 Physical address: 14358 Value: 35

Page Fault! Obtaining page from disk and assigning to frame 67
Page number = 2 Frame Number = 67 offset: 180 
Virtual address: 692 Physical address: 17332 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 68
Page number = 168 Frame Number = 68 offset: 113 
Virtual address: 43121 Physical address: 17521 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 69
Page number = 188 Frame Number = 69 offset: 0 
Virtual address: 48128 Physical address: 17664 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 70
Page number = 135 Frame Number = 70 offset: 1 
Virtual address: 34561 Physical address: 17921 Value: 0

Page number = 192 Frame Number = 33 offset: 61 
Virtual address: 49213 Physical address: 8509 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 71
Page number = 144 Frame Number = 71 offset: 58 
Virtual address: 36922 Physical address: 18234 Value: 36

Page number = 231 Frame Number = 40 offset: 26 
Virtual address: 59162 Physical address: 10266 Value: 57

Page Fault! Obtaining page from disk and assigning to frame 72
Page number = 197 Frame Number = 72 offset: 120 
Virtual address: 50552 Physical address: 18552 Value: 0

Page number = 69 Frame Number = 38 offset: 202 
Virtual address: 17866 Physical address: 9930 Value: 17

Page Fault! Obtaining page from disk and assigning to frame 73
Page number = 70 Frame Number = 73 offset: 225 
Virtual address: 18145 Physical address: 18913 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 74
Page number = 15 Frame Number = 74 offset: 44 
Virtual address: 3884 Physical address: 18988 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 75
Page number = 212 Frame Number = 75 offset: 116 
Virtual address: 54388 Physical address: 19316 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 76
Page number = 167 Frame Number = 76 offset: 180 
Virtual address: 42932 Physical address: 19636 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 77
Page number = 183 Frame Number = 77 offset: 71 
Virtual address: 46919 Physical address: 19783 Value: -47

Page number = 230 Frame Number = 58 offset: 12 
Virtual address: 58892 Physical address: 14860 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 78
Page number = 33 Frame Number = 78 offset: 172 
Virtual address: 8620 Physical address: 20140 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 79
Page number = 149 Frame Number = 79 offset: 192 
Virtual address: 38336 Physical address: 20416 Value: 0

Page number = 251 Frame Number = 19 offset: 101 
Virtual address: 64357 Physical address: 4965 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 80
Page number = 91 Frame Number = 80 offset: 91 
Virtual address: 23387 Physical address: 20571 Value: -42

Page Fault! Obtaining page from disk and assigning to frame 81
Page number = 166 Frame Number = 81 offset: 136 
Virtual address: 42632 Physical address: 20872 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 82
Page number = 62 Frame Number = 82 offset: 41 
Virtual address: 15913 Physical address: 21033 Value: 0

Page number = 61 Frame Number = 46 offset: 63 
Virtual address: 15679 Physical address: 11839 Value: 79

Page number = 87 Frame Number = 44 offset: 229 
Virtual address: 22501 Physical address: 11493 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 83
Page number = 146 Frame Number = 83 offset: 164 
Virtual address: 37540 Physical address: 21412 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 84
Page number = 21 Frame Number = 84 offset: 151 
Virtual address: 5527 Physical address: 21655 Value: 101

Page Fault! Obtaining page from disk and assigning to frame 85
Page number = 249 Frame Number = 85 offset: 177 
Virtual address: 63921 Physical address: 21937 Value: 0

Page number = 244 Frame Number = 1 offset: 252 
Virtual address: 62716 Physical address: 508 Value: 0

Page number = 128 Frame Number = 16 offset: 106 
Virtual address: 32874 Physical address: 4202 Value: 32

Page number = 251 Frame Number = 19 offset: 134 
Virtual address: 64390 Physical address: 4998 Value: 62

Page Fault! Obtaining page from disk and assigning to frame 86
Page number = 246 Frame Number = 86 offset: 125 
Virtual address: 63101 Physical address: 22141 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 87
Page number = 241 Frame Number = 87 offset: 106 
Virtual address: 61802 Physical address: 22378 Value: 60

Page Fault! Obtaining page from disk and assigning to frame 88
Page number = 76 Frame Number = 88 offset: 192 
Virtual address: 19648 Physical address: 22720 Value: 0

Page number = 113 Frame Number = 64 offset: 103 
Virtual address: 29031 Physical address: 16487 Value: 89

Page number = 175 Frame Number = 51 offset: 181 
Virtual address: 44981 Physical address: 13237 Value: 0

Found in TLB, page number = 109 correspond to frame = 13 
Page number = 109 Frame Number = 13 offset: 188 
Virtual address: 28092 Physical address: 3516 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 89
Page number = 36 Frame Number = 89 offset: 232 
Virtual address: 9448 Physical address: 23016 Value: 0

Page number = 174 Frame Number = 43 offset: 200 
Virtual address: 44744 Physical address: 11208 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 90
Page number = 240 Frame Number = 90 offset: 56 
Virtual address: 61496 Physical address: 23096 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 91
Page number = 122 Frame Number = 91 offset: 221 
Virtual address: 31453 Physical address: 23517 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 92
Page number = 237 Frame Number = 92 offset: 74 
Virtual address: 60746 Physical address: 23626 Value: 59

Found in TLB, page number = 47 correspond to frame = 10 
Page number = 47 Frame Number = 10 offset: 167 
Virtual address: 12199 Physical address: 2727 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 93
Page number = 243 Frame Number = 93 offset: 47 
Virtual address: 62255 Physical address: 23855 Value: -53

Page Fault! Obtaining page from disk and assigning to frame 94
Page number = 85 Frame Number = 94 offset: 33 
Virtual address: 21793 Physical address: 24097 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 95
Page number = 103 Frame Number = 95 offset: 176 
Virtual address: 26544 Physical address: 24496 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 96
Page number = 58 Frame Number = 96 offset: 116 
Virtual address: 14964 Physical address: 24692 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 97
Page number = 161 Frame Number = 97 offset: 246 
Virtual address: 41462 Physical address: 25078 Value: 40

Page Fault! Obtaining page from disk and assigning to frame 98
Page number = 219 Frame Number = 98 offset: 25 
Virtual address: 56089 Physical address: 25113 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 99
Page number = 203 Frame Number = 99 offset: 70 
Virtual address: 52038 Physical address: 25414 Value: 50

Page Fault! Obtaining page from disk and assigning to frame 100
Page number = 187 Frame Number = 100 offset: 110 
Virtual address: 47982 Physical address: 25710 Value: 46

Page Fault! Obtaining page from disk and assigning to frame 101
Page number = 232 Frame Number = 101 offset: 92 
Virtual address: 59484 Physical address: 25948 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 102
Page number = 198 Frame Number = 102 offset: 236 
Virtual address: 50924 Physical address: 26348 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 103
Page number = 27 Frame Number = 103 offset: 30 
Virtual address: 6942 Physical address: 26398 Value: 6

Page Fault! Obtaining page from disk and assigning to frame 104
Page number = 136 Frame Number = 104 offset: 182 
Virtual address: 34998 Physical address: 26806 Value: 34

Page Fault! Obtaining page from disk and assigning to frame 105
Page number = 105 Frame Number = 105 offset: 189 
Virtual address: 27069 Physical address: 27069 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 106
Page number = 202 Frame Number = 106 offset: 214 
Virtual address: 51926 Physical address: 27350 Value: 50

Page number = 236 Frame Number = 28 offset: 229 
Virtual address: 60645 Physical address: 7397 Value: 0

Page number = 168 Frame Number = 68 offset: 173 
Virtual address: 43181 Physical address: 17581 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 107
Page number = 41 Frame Number = 107 offset: 63 
Virtual address: 10559 Physical address: 27455 Value: 79

Page Fault! Obtaining page from disk and assigning to frame 108
Page number = 18 Frame Number = 108 offset: 56 
Virtual address: 4664 Physical address: 27704 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 109
Page number = 111 Frame Number = 109 offset: 162 
Virtual address: 28578 Physical address: 28066 Value: 27

Page number = 232 Frame Number = 101 offset: 124 
Virtual address: 59516 Physical address: 25980 Value: 0

Page number = 152 Frame Number = 15 offset: 0 
Virtual address: 38912 Physical address: 3840 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 110
Page number = 248 Frame Number = 110 offset: 74 
Virtual address: 63562 Physical address: 28234 Value: 62

Found in TLB, page number = 253 correspond to frame = 8 
Page number = 253 Frame Number = 8 offset: 78 
Virtual address: 64846 Physical address: 2126 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 111
Page number = 245 Frame Number = 111 offset: 218 
Virtual address: 62938 Physical address: 28634 Value: 61

Page Fault! Obtaining page from disk and assigning to frame 112
Page number = 106 Frame Number = 112 offset: 58 
Virtual address: 27194 Physical address: 28730 Value: 26

Page number = 112 Frame Number = 5 offset: 132 
Virtual address: 28804 Physical address: 1412 Value: 0

Page number = 241 Frame Number = 87 offset: 7 
Virtual address: 61703 Physical address: 22279 Value: 65

Page number = 42 Frame Number = 48 offset: 246 
Virtual address: 10998 Physical address: 12534 Value: 10

Page Fault! Obtaining page from disk and assigning to frame 113
Page number = 25 Frame Number = 113 offset: 196 
Virtual address: 6596 Physical address: 29124 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 114
Page number = 147 Frame Number = 114 offset: 89 
Virtual address: 37721 Physical address: 29273 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 115
Page number = 169 Frame Number = 115 offset: 166 
Virtual address: 43430 Physical address: 29606 Value: 42

Found in TLB, page number = 88 correspond to frame = 11 
Page number = 88 Frame Number = 11 offset: 164 
Virtual address: 22692 Physical address: 2980 Value: 0

Page number = 245 Frame Number = 111 offset: 251 
Virtual address: 62971 Physical address: 28667 Value: 126

Page Fault! Obtaining page from disk and assigning to frame 116
Page number = 184 Frame Number = 116 offset: 21 
Virtual address: 47125 Physical address: 29717 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 117
Page number = 205 Frame Number = 117 offset: 41 
Virtual address: 52521 Physical address: 29993 Value: 0

Page number = 135 Frame Number = 70 offset: 86 
Virtual address: 34646 Physical address: 18006 Value: 33

Page number = 128 Frame Number = 16 offset: 121 
Virtual address: 32889 Physical address: 4217 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 118
Page number = 50 Frame Number = 118 offset: 255 
Virtual address: 13055 Physical address: 30463 Value: -65

Page Fault! Obtaining page from disk and assigning to frame 119
Page number = 255 Frame Number = 119 offset: 136 
Virtual address: 65416 Physical address: 30600 Value: 0

Page number = 245 Frame Number = 111 offset: 149 
Virtual address: 62869 Physical address: 28565 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 120
Page number = 223 Frame Number = 120 offset: 226 
Virtual address: 57314 Physical address: 30946 Value: 55

Page Fault! Obtaining page from disk and assigning to frame 121
Page number = 49 Frame Number = 121 offset: 115 
Virtual address: 12659 Physical address: 31091 Value: 92

Page Fault! Obtaining page from disk and assigning to frame 122
Page number = 54 Frame Number = 122 offset: 228 
Virtual address: 14052 Physical address: 31460 Value: 0

Page number = 128 Frame Number = 16 offset: 188 
Virtual address: 32956 Physical address: 4284 Value: 0

Page number = 192 Frame Number = 33 offset: 121 
Virtual address: 49273 Physical address: 8569 Value: 0

Page number = 196 Frame Number = 54 offset: 176 
Virtual address: 50352 Physical address: 14000 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 123
Page number = 194 Frame Number = 123 offset: 73 
Virtual address: 49737 Physical address: 31561 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 124
Page number = 60 Frame Number = 124 offset: 195 
Virtual address: 15555 Physical address: 31939 Value: 48

Page Fault! Obtaining page from disk and assigning to frame 125
Page number = 185 Frame Number = 125 offset: 115 
Virtual address: 47475 Physical address: 32115 Value: 92

Page Fault! Obtaining page from disk and assigning to frame 126
Page number = 59 Frame Number = 126 offset: 224 
Virtual address: 15328 Physical address: 32480 Value: 0

Page number = 135 Frame Number = 70 offset: 61 
Virtual address: 34621 Physical address: 17981 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 127
Page number = 200 Frame Number = 127 offset: 165 
Virtual address: 51365 Physical address: 32677 Value: 0

Page number = 128 Frame Number = 16 offset: 52 
Virtual address: 32820 Physical address: 4148 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 128
Page number = 190 Frame Number = 128 offset: 215 
Virtual address: 48855 Physical address: 32983 Value: -75

Found in TLB, page number = 47 correspond to frame = 10 
Page number = 47 Frame Number = 10 offset: 192 
Virtual address: 12224 Physical address: 2752 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 129
Page number = 7 Frame Number = 129 offset: 243 
Virtual address: 2035 Physical address: 33267 Value: -4

Page number = 236 Frame Number = 28 offset: 123 
Virtual address: 60539 Physical address: 7291 Value: 30

Page Fault! Obtaining page from disk and assigning to frame 130
Page number = 57 Frame Number = 130 offset: 3 
Virtual address: 14595 Physical address: 33283 Value: 64

Page number = 54 Frame Number = 122 offset: 29 
Virtual address: 13853 Physical address: 31261 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 131
Page number = 94 Frame Number = 131 offset: 79 
Virtual address: 24143 Physical address: 33615 Value: -109

Page number = 59 Frame Number = 126 offset: 112 
Virtual address: 15216 Physical address: 32368 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 132
Page number = 31 Frame Number = 132 offset: 177 
Virtual address: 8113 Physical address: 33969 Value: 0

Found in TLB, page number = 88 correspond to frame = 11 
Page number = 88 Frame Number = 11 offset: 112 
Virtual address: 22640 Physical address: 2928 Value: 0

Page number = 128 Frame Number = 16 offset: 210 
Virtual address: 32978 Physical address: 4306 Value: 32

Page number = 152 Frame Number = 15 offset: 239 
Virtual address: 39151 Physical address: 4079 Value: 59

Page number = 76 Frame Number = 88 offset: 64 
Virtual address: 19520 Physical address: 22592 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 133
Page number = 227 Frame Number = 133 offset: 29 
Virtual address: 58141 Physical address: 34077 Value: 0

Page number = 249 Frame Number = 85 offset: 215 
Virtual address: 63959 Physical address: 21975 Value: 117

Page Fault! Obtaining page from disk and assigning to frame 134
Page number = 207 Frame Number = 134 offset: 48 
Virtual address: 53040 Physical address: 34352 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 135
Page number = 218 Frame Number = 135 offset: 34 
Virtual address: 55842 Physical address: 34594 Value: 54

Page number = 2 Frame Number = 67 offset: 73 
Virtual address: 585 Physical address: 17225 Value: 0

Page number = 200 Frame Number = 127 offset: 29 
Virtual address: 51229 Physical address: 32541 Value: 0

Page number = 250 Frame Number = 17 offset: 181 
Virtual address: 64181 Physical address: 4533 Value: 0

Found in TLB, page number = 214 correspond to frame = 14 
Page number = 214 Frame Number = 14 offset: 95 
Virtual address: 54879 Physical address: 3679 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 136
Page number = 110 Frame Number = 136 offset: 50 
Virtual address: 28210 Physical address: 34866 Value: 27

Page number = 40 Frame Number = 57 offset: 28 
Virtual address: 10268 Physical address: 14620 Value: 0

Page number = 60 Frame Number = 124 offset: 35 
Virtual address: 15395 Physical address: 31779 Value: 8

Page number = 50 Frame Number = 118 offset: 84 
Virtual address: 12884 Physical address: 30292 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 137
Page number = 8 Frame Number = 137 offset: 101 
Virtual address: 2149 Physical address: 35173 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 138
Page number = 208 Frame Number = 138 offset: 235 
Virtual address: 53483 Physical address: 35563 Value: 58

Page number = 232 Frame Number = 101 offset: 214 
Virtual address: 59606 Physical address: 26070 Value: 58

Page number = 58 Frame Number = 96 offset: 133 
Virtual address: 14981 Physical address: 24709 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 139
Page number = 143 Frame Number = 139 offset: 64 
Virtual address: 36672 Physical address: 35648 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 140
Page number = 90 Frame Number = 140 offset: 157 
Virtual address: 23197 Physical address: 35997 Value: 0

Page number = 142 Frame Number = 56 offset: 166 
Virtual address: 36518 Physical address: 14502 Value: 35

Page Fault! Obtaining page from disk and assigning to frame 141
Page number = 52 Frame Number = 141 offset: 49 
Virtual address: 13361 Physical address: 36145 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 142
Page number = 77 Frame Number = 142 offset: 98 
Virtual address: 19810 Physical address: 36450 Value: 19

Page Fault! Obtaining page from disk and assigning to frame 143
Page number = 101 Frame Number = 143 offset: 99 
Virtual address: 25955 Physical address: 36707 Value: 88

Page number = 244 Frame Number = 1 offset: 214 
Virtual address: 62678 Physical address: 470 Value: 61

Page number = 101 Frame Number = 143 offset: 165 
Virtual address: 26021 Physical address: 36773 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 144
Page number = 114 Frame Number = 144 offset: 225 
Virtual address: 29409 Physical address: 37089 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 145
Page number = 148 Frame Number = 145 offset: 223 
Virtual address: 38111 Physical address: 37343 Value: 55

Page number = 228 Frame Number = 60 offset: 205 
Virtual address: 58573 Physical address: 15565 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 146
Page number = 222 Frame Number = 146 offset: 8 
Virtual address: 56840 Physical address: 37384 Value: 0

Page number = 161 Frame Number = 97 offset: 90 
Virtual address: 41306 Physical address: 24922 Value: 40

Page number = 212 Frame Number = 75 offset: 154 
Virtual address: 54426 Physical address: 19354 Value: 53

Page number = 14 Frame Number = 39 offset: 33 
Virtual address: 3617 Physical address: 10017 Value: 0

Page number = 197 Frame Number = 72 offset: 220 
Virtual address: 50652 Physical address: 18652 Value: 0

Page number = 161 Frame Number = 97 offset: 236 
Virtual address: 41452 Physical address: 25068 Value: 0

Page number = 79 Frame Number = 65 offset: 17 
Virtual address: 20241 Physical address: 16657 Value: 0

Page number = 123 Frame Number = 47 offset: 235 
Virtual address: 31723 Physical address: 12267 Value: -6

Page number = 209 Frame Number = 3 offset: 243 
Virtual address: 53747 Physical address: 1011 Value: 124

Page number = 111 Frame Number = 109 offset: 134 
Virtual address: 28550 Physical address: 28038 Value: 27

Page number = 91 Frame Number = 80 offset: 106 
Virtual address: 23402 Physical address: 20586 Value: 22

Page Fault! Obtaining page from disk and assigning to frame 147
Page number = 82 Frame Number = 147 offset: 213 
Virtual address: 21205 Physical address: 37845 Value: 0

Page number = 219 Frame Number = 98 offset: 117 
Virtual address: 56181 Physical address: 25205 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 148
Page number = 224 Frame Number = 148 offset: 126 
Virtual address: 57470 Physical address: 38014 Value: 56

Page Fault! Obtaining page from disk and assigning to frame 149
Page number = 155 Frame Number = 149 offset: 253 
Virtual address: 39933 Physical address: 38397 Value: 0

Page number = 136 Frame Number = 104 offset: 148 
Virtual address: 34964 Physical address: 26772 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 150
Page number = 96 Frame Number = 150 offset: 205 
Virtual address: 24781 Physical address: 38605 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 151
Page number = 163 Frame Number = 151 offset: 19 
Virtual address: 41747 Physical address: 38675 Value: -60

Page number = 244 Frame Number = 1 offset: 100 
Virtual address: 62564 Physical address: 356 Value: 0

Page number = 228 Frame Number = 60 offset: 93 
Virtual address: 58461 Physical address: 15453 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 152
Page number = 81 Frame Number = 152 offset: 122 
Virtual address: 20858 Physical address: 39034 Value: 20

Page number = 192 Frame Number = 33 offset: 149 
Virtual address: 49301 Physical address: 8597 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 153
Page number = 158 Frame Number = 153 offset: 124 
Virtual address: 40572 Physical address: 39292 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 154
Page number = 93 Frame Number = 154 offset: 32 
Virtual address: 23840 Physical address: 39456 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 155
Page number = 137 Frame Number = 155 offset: 206 
Virtual address: 35278 Physical address: 39886 Value: 34

Page number = 245 Frame Number = 111 offset: 185 
Virtual address: 62905 Physical address: 28601 Value: 0

Page number = 221 Frame Number = 52 offset: 74 
Virtual address: 56650 Physical address: 13386 Value: 55

Page Fault! Obtaining page from disk and assigning to frame 156
Page number = 43 Frame Number = 156 offset: 141 
Virtual address: 11149 Physical address: 40077 Value: 0

Page number = 152 Frame Number = 15 offset: 8 
Virtual address: 38920 Physical address: 3848 Value: 0

Page number = 91 Frame Number = 80 offset: 134 
Virtual address: 23430 Physical address: 20614 Value: 22

Page number = 224 Frame Number = 148 offset: 248 
Virtual address: 57592 Physical address: 38136 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 157
Page number = 12 Frame Number = 157 offset: 8 
Virtual address: 3080 Physical address: 40200 Value: 0

Page number = 26 Frame Number = 26 offset: 21 
Virtual address: 6677 Physical address: 6677 Value: 0

Page number = 198 Frame Number = 102 offset: 16 
Virtual address: 50704 Physical address: 26128 Value: 0

Page number = 202 Frame Number = 106 offset: 171 
Virtual address: 51883 Physical address: 27307 Value: -86

Page number = 245 Frame Number = 111 offset: 79 
Virtual address: 62799 Physical address: 28495 Value: 83

Page Fault! Obtaining page from disk and assigning to frame 158
Page number = 78 Frame Number = 158 offset: 220 
Virtual address: 20188 Physical address: 40668 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 159
Page number = 4 Frame Number = 159 offset: 221 
Virtual address: 1245 Physical address: 40925 Value: 0

Found in TLB, page number = 47 correspond to frame = 10 
Page number = 47 Frame Number = 10 offset: 188 
Virtual address: 12220 Physical address: 2748 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 160
Page number = 68 Frame Number = 160 offset: 194 
Virtual address: 17602 Physical address: 41154 Value: 17

Page number = 111 Frame Number = 109 offset: 193 
Virtual address: 28609 Physical address: 28097 Value: 0

Page number = 166 Frame Number = 81 offset: 198 
Virtual address: 42694 Physical address: 20934 Value: 41

Page Fault! Obtaining page from disk and assigning to frame 161
Page number = 116 Frame Number = 161 offset: 130 
Virtual address: 29826 Physical address: 41346 Value: 29

Page number = 54 Frame Number = 122 offset: 3 
Virtual address: 13827 Physical address: 31235 Value: -128

Page number = 106 Frame Number = 112 offset: 200 
Virtual address: 27336 Physical address: 28872 Value: 0

Page number = 208 Frame Number = 138 offset: 95 
Virtual address: 53343 Physical address: 35423 Value: 23

Page Fault! Obtaining page from disk and assigning to frame 162
Page number = 45 Frame Number = 162 offset: 13 
Virtual address: 11533 Physical address: 41485 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 163
Page number = 162 Frame Number = 163 offset: 241 
Virtual address: 41713 Physical address: 41969 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 164
Page number = 132 Frame Number = 164 offset: 98 
Virtual address: 33890 Physical address: 42082 Value: 33

Page number = 19 Frame Number = 53 offset: 30 
Virtual address: 4894 Physical address: 13598 Value: 4

Page number = 224 Frame Number = 148 offset: 255 
Virtual address: 57599 Physical address: 38143 Value: 63

Page number = 15 Frame Number = 74 offset: 30 
Virtual address: 3870 Physical address: 18974 Value: 3

Page number = 228 Frame Number = 60 offset: 254 
Virtual address: 58622 Physical address: 15614 Value: 57

Page number = 116 Frame Number = 161 offset: 84 
Virtual address: 29780 Physical address: 41300 Value: 0

Page number = 244 Frame Number = 1 offset: 89 
Virtual address: 62553 Physical address: 345 Value: 0

Page number = 8 Frame Number = 137 offset: 255 
Virtual address: 2303 Physical address: 35327 Value: 63

Page number = 202 Frame Number = 106 offset: 203 
Virtual address: 51915 Physical address: 27339 Value: -78

Page number = 24 Frame Number = 29 offset: 107 
Virtual address: 6251 Physical address: 7531 Value: 26

Page number = 148 Frame Number = 145 offset: 219 
Virtual address: 38107 Physical address: 37339 Value: 54

Page number = 231 Frame Number = 40 offset: 189 
Virtual address: 59325 Physical address: 10429 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 165
Page number = 239 Frame Number = 165 offset: 111 
Virtual address: 61295 Physical address: 42351 Value: -37

Page Fault! Obtaining page from disk and assigning to frame 166
Page number = 104 Frame Number = 166 offset: 75 
Virtual address: 26699 Physical address: 42571 Value: 18

Page Fault! Obtaining page from disk and assigning to frame 167
Page number = 199 Frame Number = 167 offset: 244 
Virtual address: 51188 Physical address: 42996 Value: 0

Page number = 232 Frame Number = 101 offset: 127 
Virtual address: 59519 Physical address: 25983 Value: 31

Page Fault! Obtaining page from disk and assigning to frame 168
Page number = 28 Frame Number = 168 offset: 177 
Virtual address: 7345 Physical address: 43185 Value: 0

Page number = 79 Frame Number = 65 offset: 101 
Virtual address: 20325 Physical address: 16741 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 169
Page number = 154 Frame Number = 169 offset: 209 
Virtual address: 39633 Physical address: 43473 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 170
Page number = 6 Frame Number = 170 offset: 26 
Virtual address: 1562 Physical address: 43546 Value: 1

Page number = 29 Frame Number = 24 offset: 156 
Virtual address: 7580 Physical address: 6300 Value: 0

Page number = 31 Frame Number = 132 offset: 234 
Virtual address: 8170 Physical address: 34026 Value: 7

Page number = 243 Frame Number = 93 offset: 48 
Virtual address: 62256 Physical address: 23856 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 171
Page number = 139 Frame Number = 171 offset: 239 
Virtual address: 35823 Physical address: 44015 Value: -5

Page Fault! Obtaining page from disk and assigning to frame 172
Page number = 108 Frame Number = 172 offset: 142 
Virtual address: 27790 Physical address: 44174 Value: 27

Page Fault! Obtaining page from disk and assigning to frame 173
Page number = 51 Frame Number = 173 offset: 135 
Virtual address: 13191 Physical address: 44423 Value: -31

Page Fault! Obtaining page from disk and assigning to frame 174
Page number = 38 Frame Number = 174 offset: 44 
Virtual address: 9772 Physical address: 44588 Value: 0

Page number = 29 Frame Number = 24 offset: 53 
Virtual address: 7477 Physical address: 6197 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 175
Page number = 173 Frame Number = 175 offset: 167 
Virtual address: 44455 Physical address: 44967 Value: 105

Page number = 232 Frame Number = 101 offset: 154 
Virtual address: 59546 Physical address: 26010 Value: 58

Page number = 192 Frame Number = 33 offset: 195 
Virtual address: 49347 Physical address: 8643 Value: 48

Page number = 142 Frame Number = 56 offset: 187 
Virtual address: 36539 Physical address: 14523 Value: -82

Page Fault! Obtaining page from disk and assigning to frame 176
Page number = 48 Frame Number = 176 offset: 165 
Virtual address: 12453 Physical address: 45221 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 177
Page number = 193 Frame Number = 177 offset: 232 
Virtual address: 49640 Physical address: 45544 Value: 0

Page number = 110 Frame Number = 136 offset: 130 
Virtual address: 28290 Physical address: 34946 Value: 27

Page number = 175 Frame Number = 51 offset: 17 
Virtual address: 44817 Physical address: 13073 Value: 0

Page number = 33 Frame Number = 78 offset: 117 
Virtual address: 8565 Physical address: 20085 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 178
Page number = 64 Frame Number = 178 offset: 15 
Virtual address: 16399 Physical address: 45583 Value: 3

Page number = 163 Frame Number = 151 offset: 206 
Virtual address: 41934 Physical address: 38862 Value: 40

Page Fault! Obtaining page from disk and assigning to frame 179
Page number = 177 Frame Number = 179 offset: 145 
Virtual address: 45457 Physical address: 45969 Value: 0

Page number = 132 Frame Number = 164 offset: 64 
Virtual address: 33856 Physical address: 42048 Value: 0

Page number = 76 Frame Number = 88 offset: 42 
Virtual address: 19498 Physical address: 22570 Value: 19

Page number = 68 Frame Number = 160 offset: 253 
Virtual address: 17661 Physical address: 41213 Value: 0

Page number = 249 Frame Number = 85 offset: 85 
Virtual address: 63829 Physical address: 21845 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 180
Page number = 164 Frame Number = 180 offset: 50 
Virtual address: 42034 Physical address: 46130 Value: 41

Page number = 113 Frame Number = 64 offset: 0 
Virtual address: 28928 Physical address: 16384 Value: 0

Page number = 119 Frame Number = 63 offset: 247 
Virtual address: 30711 Physical address: 16375 Value: -3

Page Fault! Obtaining page from disk and assigning to frame 181
Page number = 34 Frame Number = 181 offset: 96 
Virtual address: 8800 Physical address: 46432 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 182
Page number = 204 Frame Number = 182 offset: 111 
Virtual address: 52335 Physical address: 46703 Value: 27

Page Fault! Obtaining page from disk and assigning to frame 183
Page number = 151 Frame Number = 183 offset: 119 
Virtual address: 38775 Physical address: 46967 Value: -35

Page number = 205 Frame Number = 117 offset: 224 
Virtual address: 52704 Physical address: 30176 Value: 0

Page number = 95 Frame Number = 6 offset: 60 
Virtual address: 24380 Physical address: 1596 Value: 0

Page number = 76 Frame Number = 88 offset: 146 
Virtual address: 19602 Physical address: 22674 Value: 19

Found in TLB, page number = 226 correspond to frame = 12 
Page number = 226 Frame Number = 12 offset: 142 
Virtual address: 57998 Physical address: 3214 Value: 0

Page number = 11 Frame Number = 45 offset: 103 
Virtual address: 2919 Physical address: 11623 Value: -39

Page Fault! Obtaining page from disk and assigning to frame 184
Page number = 32 Frame Number = 184 offset: 170 
Virtual address: 8362 Physical address: 47274 Value: 8

Page number = 69 Frame Number = 38 offset: 220 
Virtual address: 17884 Physical address: 9948 Value: 0

Page number = 178 Frame Number = 30 offset: 169 
Virtual address: 45737 Physical address: 7849 Value: 0

Page number = 187 Frame Number = 100 offset: 22 
Virtual address: 47894 Physical address: 25622 Value: 46

Page Fault! Obtaining page from disk and assigning to frame 185
Page number = 233 Frame Number = 185 offset: 19 
Virtual address: 59667 Physical address: 47379 Value: 68

Page number = 40 Frame Number = 57 offset: 145 
Virtual address: 10385 Physical address: 14737 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 186
Page number = 206 Frame Number = 186 offset: 46 
Virtual address: 52782 Physical address: 47662 Value: 51

Page number = 251 Frame Number = 19 offset: 160 
Virtual address: 64416 Physical address: 5024 Value: 0

Page number = 159 Frame Number = 32 offset: 242 
Virtual address: 40946 Physical address: 8434 Value: 39

Page Fault! Obtaining page from disk and assigning to frame 187
Page number = 65 Frame Number = 187 offset: 138 
Virtual address: 16778 Physical address: 48010 Value: 16

Page number = 106 Frame Number = 112 offset: 23 
Virtual address: 27159 Physical address: 28695 Value: -123

Page number = 95 Frame Number = 6 offset: 4 
Virtual address: 24324 Physical address: 1540 Value: 0

Page number = 126 Frame Number = 27 offset: 194 
Virtual address: 32450 Physical address: 7106 Value: 31

Page Fault! Obtaining page from disk and assigning to frame 188
Page number = 35 Frame Number = 188 offset: 148 
Virtual address: 9108 Physical address: 48276 Value: 0

Page number = 255 Frame Number = 119 offset: 25 
Virtual address: 65305 Physical address: 30489 Value: 0

Page number = 76 Frame Number = 88 offset: 119 
Virtual address: 19575 Physical address: 22647 Value: 29

Page number = 43 Frame Number = 156 offset: 109 
Virtual address: 11117 Physical address: 40045 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 189
Page number = 254 Frame Number = 189 offset: 146 
Virtual address: 65170 Physical address: 48530 Value: 63

Found in TLB, page number = 226 correspond to frame = 12 
Page number = 226 Frame Number = 12 offset: 157 
Virtual address: 58013 Physical address: 3229 Value: 0

Page number = 240 Frame Number = 90 offset: 236 
Virtual address: 61676 Physical address: 23276 Value: 0

Page number = 248 Frame Number = 110 offset: 22 
Virtual address: 63510 Physical address: 28182 Value: 62

Page number = 68 Frame Number = 160 offset: 50 
Virtual address: 17458 Physical address: 41010 Value: 17

Page Fault! Obtaining page from disk and assigning to frame 190
Page number = 213 Frame Number = 190 offset: 147 
Virtual address: 54675 Physical address: 48787 Value: 100

Page number = 6 Frame Number = 170 offset: 177 
Virtual address: 1713 Physical address: 43697 Value: 0

Page number = 215 Frame Number = 20 offset: 65 
Virtual address: 55105 Physical address: 5185 Value: 0

Page number = 255 Frame Number = 119 offset: 41 
Virtual address: 65321 Physical address: 30505 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 191
Page number = 176 Frame Number = 191 offset: 222 
Virtual address: 45278 Physical address: 49118 Value: 44

Page Fault! Obtaining page from disk and assigning to frame 192
Page number = 102 Frame Number = 192 offset: 144 
Virtual address: 26256 Physical address: 49296 Value: 0

Page number = 250 Frame Number = 17 offset: 198 
Virtual address: 64198 Physical address: 4550 Value: 62

Page Fault! Obtaining page from disk and assigning to frame 193
Page number = 115 Frame Number = 193 offset: 1 
Virtual address: 29441 Physical address: 49409 Value: 0

Page number = 7 Frame Number = 129 offset: 136 
Virtual address: 1928 Physical address: 33160 Value: 0

Page number = 154 Frame Number = 169 offset: 1 
Virtual address: 39425 Physical address: 43265 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 194
Page number = 125 Frame Number = 194 offset: 0 
Virtual address: 32000 Physical address: 49664 Value: 0

Page number = 111 Frame Number = 109 offset: 133 
Virtual address: 28549 Physical address: 28037 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 195
Page number = 180 Frame Number = 195 offset: 215 
Virtual address: 46295 Physical address: 50135 Value: 53

Found in TLB, page number = 88 correspond to frame = 11 
Page number = 88 Frame Number = 11 offset: 244 
Virtual address: 22772 Physical address: 3060 Value: 0

Page number = 227 Frame Number = 133 offset: 116 
Virtual address: 58228 Physical address: 34164 Value: 0

Page number = 248 Frame Number = 110 offset: 37 
Virtual address: 63525 Physical address: 28197 Value: 0

Page number = 127 Frame Number = 37 offset: 90 
Virtual address: 32602 Physical address: 9562 Value: 31

Page number = 180 Frame Number = 195 offset: 115 
Virtual address: 46195 Physical address: 50035 Value: 28

Page number = 218 Frame Number = 135 offset: 41 
Virtual address: 55849 Physical address: 34601 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 196
Page number = 181 Frame Number = 196 offset: 118 
Virtual address: 46454 Physical address: 50294 Value: 45

Page number = 29 Frame Number = 24 offset: 63 
Virtual address: 7487 Physical address: 6207 Value: 79

Page number = 132 Frame Number = 164 offset: 87 
Virtual address: 33879 Physical address: 42071 Value: 21

Page number = 164 Frame Number = 180 offset: 20 
Virtual address: 42004 Physical address: 46100 Value: 0

Page number = 33 Frame Number = 78 offset: 151 
Virtual address: 8599 Physical address: 20119 Value: 101

Page number = 72 Frame Number = 21 offset: 209 
Virtual address: 18641 Physical address: 5585 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 197
Page number = 191 Frame Number = 197 offset: 119 
Virtual address: 49015 Physical address: 50551 Value: -35

Page number = 104 Frame Number = 166 offset: 206 
Virtual address: 26830 Physical address: 42702 Value: 26

Page number = 135 Frame Number = 70 offset: 194 
Virtual address: 34754 Physical address: 18114 Value: 33

Page number = 57 Frame Number = 130 offset: 76 
Virtual address: 14668 Physical address: 33356 Value: 0

Page number = 149 Frame Number = 79 offset: 218 
Virtual address: 38362 Physical address: 20442 Value: 37

Page number = 151 Frame Number = 183 offset: 135 
Virtual address: 38791 Physical address: 46983 Value: -31

Page Fault! Obtaining page from disk and assigning to frame 198
Page number = 16 Frame Number = 198 offset: 75 
Virtual address: 4171 Physical address: 50763 Value: 18

Page Fault! Obtaining page from disk and assigning to frame 199
Page number = 179 Frame Number = 199 offset: 151 
Virtual address: 45975 Physical address: 51095 Value: -27

Page number = 57 Frame Number = 130 offset: 31 
Virtual address: 14623 Physical address: 33311 Value: 71

Page number = 243 Frame Number = 93 offset: 185 
Virtual address: 62393 Physical address: 23993 Value: 0

Page number = 252 Frame Number = 25 offset: 146 
Virtual address: 64658 Physical address: 6546 Value: 63

Page number = 42 Frame Number = 48 offset: 211 
Virtual address: 10963 Physical address: 12499 Value: -76

Page number = 35 Frame Number = 188 offset: 98 
Virtual address: 9058 Physical address: 48226 Value: 8

Page number = 199 Frame Number = 167 offset: 87 
Virtual address: 51031 Physical address: 42839 Value: -43

Page number = 126 Frame Number = 27 offset: 169 
Virtual address: 32425 Physical address: 7081 Value: 0

Page number = 177 Frame Number = 179 offset: 171 
Virtual address: 45483 Physical address: 45995 Value: 106

Page number = 174 Frame Number = 43 offset: 67 
Virtual address: 44611 Physical address: 11075 Value: -112

Page number = 248 Frame Number = 110 offset: 176 
Virtual address: 63664 Physical address: 28336 Value: 0

Found in TLB, page number = 214 correspond to frame = 14 
Page number = 214 Frame Number = 14 offset: 136 
Virtual address: 54920 Physical address: 3720 Value: 0

Page number = 29 Frame Number = 24 offset: 239 
Virtual address: 7663 Physical address: 6383 Value: 123

Page Fault! Obtaining page from disk and assigning to frame 200
Page number = 220 Frame Number = 200 offset: 160 
Virtual address: 56480 Physical address: 51360 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 201
Page number = 5 Frame Number = 201 offset: 209 
Virtual address: 1489 Physical address: 51665 Value: 0

Page number = 111 Frame Number = 109 offset: 22 
Virtual address: 28438 Physical address: 27926 Value: 27

Page number = 255 Frame Number = 119 offset: 169 
Virtual address: 65449 Physical address: 30633 Value: 0

Page number = 48 Frame Number = 176 offset: 153 
Virtual address: 12441 Physical address: 45209 Value: 0

Page number = 228 Frame Number = 60 offset: 162 
Virtual address: 58530 Physical address: 15522 Value: 57

Page number = 248 Frame Number = 110 offset: 82 
Virtual address: 63570 Physical address: 28242 Value: 62

Page number = 102 Frame Number = 192 offset: 139 
Virtual address: 26251 Physical address: 49291 Value: -94

Page number = 62 Frame Number = 82 offset: 100 
Virtual address: 15972 Physical address: 21092 Value: 0

Page number = 139 Frame Number = 171 offset: 242 
Virtual address: 35826 Physical address: 44018 Value: 34

Page number = 21 Frame Number = 84 offset: 115 
Virtual address: 5491 Physical address: 21619 Value: 92

Page Fault! Obtaining page from disk and assigning to frame 202
Page number = 211 Frame Number = 202 offset: 237 
Virtual address: 54253 Physical address: 51949 Value: 0

Page number = 193 Frame Number = 177 offset: 247 
Virtual address: 49655 Physical address: 45559 Value: 125

Page Fault! Obtaining page from disk and assigning to frame 203
Page number = 22 Frame Number = 203 offset: 236 
Virtual address: 5868 Physical address: 52204 Value: 0

Page number = 78 Frame Number = 158 offset: 195 
Virtual address: 20163 Physical address: 40643 Value: -80

Page number = 199 Frame Number = 167 offset: 135 
Virtual address: 51079 Physical address: 42887 Value: -31

Page number = 83 Frame Number = 35 offset: 150 
Virtual address: 21398 Physical address: 9110 Value: 20

Page number = 127 Frame Number = 37 offset: 244 
Virtual address: 32756 Physical address: 9716 Value: 0

Page number = 250 Frame Number = 17 offset: 196 
Virtual address: 64196 Physical address: 4548 Value: 0

Page number = 168 Frame Number = 68 offset: 210 
Virtual address: 43218 Physical address: 17618 Value: 42

Page Fault! Obtaining page from disk and assigning to frame 204
Page number = 84 Frame Number = 204 offset: 79 
Virtual address: 21583 Physical address: 52303 Value: 19

Page Fault! Obtaining page from disk and assigning to frame 205
Page number = 97 Frame Number = 205 offset: 254 
Virtual address: 25086 Physical address: 52734 Value: 24

Page number = 177 Frame Number = 179 offset: 203 
Virtual address: 45515 Physical address: 46027 Value: 114

Page number = 50 Frame Number = 118 offset: 93 
Virtual address: 12893 Physical address: 30301 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 206
Page number = 89 Frame Number = 206 offset: 130 
Virtual address: 22914 Physical address: 52866 Value: 22

Page number = 230 Frame Number = 58 offset: 89 
Virtual address: 58969 Physical address: 14937 Value: 0

Page number = 78 Frame Number = 158 offset: 126 
Virtual address: 20094 Physical address: 40574 Value: 19

Page Fault! Obtaining page from disk and assigning to frame 207
Page number = 53 Frame Number = 207 offset: 162 
Virtual address: 13730 Physical address: 53154 Value: 13

Page Fault! Obtaining page from disk and assigning to frame 208
Page number = 172 Frame Number = 208 offset: 27 
Virtual address: 44059 Physical address: 53275 Value: 6

Page number = 113 Frame Number = 64 offset: 3 
Virtual address: 28931 Physical address: 16387 Value: 64

Page number = 52 Frame Number = 141 offset: 221 
Virtual address: 13533 Physical address: 36317 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 209
Page number = 129 Frame Number = 209 offset: 110 
Virtual address: 33134 Physical address: 53614 Value: 32

Page number = 111 Frame Number = 109 offset: 67 
Virtual address: 28483 Physical address: 27971 Value: -48

Page number = 4 Frame Number = 159 offset: 196 
Virtual address: 1220 Physical address: 40900 Value: 0

Page number = 149 Frame Number = 79 offset: 30 
Virtual address: 38174 Physical address: 20254 Value: 37

Page number = 208 Frame Number = 138 offset: 254 
Virtual address: 53502 Physical address: 35582 Value: 52

Page number = 169 Frame Number = 115 offset: 64 
Virtual address: 43328 Physical address: 29504 Value: 0

Page number = 19 Frame Number = 53 offset: 106 
Virtual address: 4970 Physical address: 13674 Value: 4

Page number = 31 Frame Number = 132 offset: 154 
Virtual address: 8090 Physical address: 33946 Value: 7

Page Fault! Obtaining page from disk and assigning to frame 210
Page number = 10 Frame Number = 210 offset: 101 
Virtual address: 2661 Physical address: 53861 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 211
Page number = 210 Frame Number = 211 offset: 143 
Virtual address: 53903 Physical address: 54159 Value: -93

Page number = 43 Frame Number = 156 offset: 17 
Virtual address: 11025 Physical address: 39953 Value: 0

Page number = 104 Frame Number = 166 offset: 3 
Virtual address: 26627 Physical address: 42499 Value: 0

Page number = 70 Frame Number = 73 offset: 197 
Virtual address: 18117 Physical address: 18885 Value: 0

Page number = 56 Frame Number = 22 offset: 169 
Virtual address: 14505 Physical address: 5801 Value: 0

Page number = 240 Frame Number = 90 offset: 88 
Virtual address: 61528 Physical address: 23128 Value: 0

Page number = 79 Frame Number = 65 offset: 199 
Virtual address: 20423 Physical address: 16839 Value: -15

Page number = 105 Frame Number = 105 offset: 82 
Virtual address: 26962 Physical address: 26962 Value: 26

Page number = 142 Frame Number = 56 offset: 40 
Virtual address: 36392 Physical address: 14376 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 212
Page number = 44 Frame Number = 212 offset: 101 
Virtual address: 11365 Physical address: 54373 Value: 0

Page number = 198 Frame Number = 102 offset: 194 
Virtual address: 50882 Physical address: 26306 Value: 49

Page number = 162 Frame Number = 163 offset: 196 
Virtual address: 41668 Physical address: 41924 Value: 0

Page number = 119 Frame Number = 63 offset: 33 
Virtual address: 30497 Physical address: 16161 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 213
Page number = 141 Frame Number = 213 offset: 120 
Virtual address: 36216 Physical address: 54648 Value: 0

Page number = 21 Frame Number = 84 offset: 243 
Virtual address: 5619 Physical address: 21747 Value: 124

Page number = 144 Frame Number = 71 offset: 119 
Virtual address: 36983 Physical address: 18295 Value: 29

Page number = 232 Frame Number = 101 offset: 165 
Virtual address: 59557 Physical address: 26021 Value: 0

Page number = 143 Frame Number = 139 offset: 55 
Virtual address: 36663 Physical address: 35639 Value: -51

Page number = 142 Frame Number = 56 offset: 84 
Virtual address: 36436 Physical address: 14420 Value: 0

Page number = 144 Frame Number = 71 offset: 193 
Virtual address: 37057 Physical address: 18369 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 214
Page number = 92 Frame Number = 214 offset: 33 
Virtual address: 23585 Physical address: 54817 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 215
Page number = 229 Frame Number = 215 offset: 167 
Virtual address: 58791 Physical address: 55207 Value: 105

Page Fault! Obtaining page from disk and assigning to frame 216
Page number = 182 Frame Number = 216 offset: 74 
Virtual address: 46666 Physical address: 55370 Value: 45

Page number = 251 Frame Number = 19 offset: 219 
Virtual address: 64475 Physical address: 5083 Value: -10

Page number = 84 Frame Number = 204 offset: 111 
Virtual address: 21615 Physical address: 52335 Value: 27

Page number = 160 Frame Number = 34 offset: 130 
Virtual address: 41090 Physical address: 8834 Value: 40

Page number = 6 Frame Number = 170 offset: 235 
Virtual address: 1771 Physical address: 43755 Value: -70

Page number = 185 Frame Number = 125 offset: 153 
Virtual address: 47513 Physical address: 32153 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 217
Page number = 153 Frame Number = 217 offset: 170 
Virtual address: 39338 Physical address: 55722 Value: 38

Page number = 5 Frame Number = 201 offset: 110 
Virtual address: 1390 Physical address: 51566 Value: 1

Page number = 151 Frame Number = 183 offset: 116 
Virtual address: 38772 Physical address: 46964 Value: 0

Page number = 227 Frame Number = 133 offset: 37 
Virtual address: 58149 Physical address: 34085 Value: 0

Page number = 28 Frame Number = 168 offset: 28 
Virtual address: 7196 Physical address: 43036 Value: 0

Page number = 35 Frame Number = 188 offset: 163 
Virtual address: 9123 Physical address: 48291 Value: -24

Page number = 29 Frame Number = 24 offset: 67 
Virtual address: 7491 Physical address: 6211 Value: 80

Page number = 244 Frame Number = 1 offset: 152 
Virtual address: 62616 Physical address: 408 Value: 0

Page number = 60 Frame Number = 124 offset: 76 
Virtual address: 15436 Physical address: 31820 Value: 0

Page number = 68 Frame Number = 160 offset: 83 
Virtual address: 17491 Physical address: 41043 Value: 20

Page number = 209 Frame Number = 3 offset: 152 
Virtual address: 53656 Physical address: 920 Value: 0

Page number = 103 Frame Number = 95 offset: 81 
Virtual address: 26449 Physical address: 24401 Value: 0

Page number = 136 Frame Number = 104 offset: 119 
Virtual address: 34935 Physical address: 26743 Value: 29

Page number = 77 Frame Number = 142 offset: 152 
Virtual address: 19864 Physical address: 36504 Value: 0

Page number = 200 Frame Number = 127 offset: 188 
Virtual address: 51388 Physical address: 32700 Value: 0

Page number = 59 Frame Number = 126 offset: 51 
Virtual address: 15155 Physical address: 32307 Value: -52

Found in TLB, page number = 253 correspond to frame = 8 
Page number = 253 Frame Number = 8 offset: 7 
Virtual address: 64775 Physical address: 2055 Value: 0

Page number = 187 Frame Number = 100 offset: 97 
Virtual address: 47969 Physical address: 25697 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 218
Page number = 63 Frame Number = 218 offset: 187 
Virtual address: 16315 Physical address: 55995 Value: -18

Page number = 5 Frame Number = 201 offset: 62 
Virtual address: 1342 Physical address: 51518 Value: 1

Page number = 199 Frame Number = 167 offset: 241 
Virtual address: 51185 Physical address: 42993 Value: 0

Page number = 23 Frame Number = 36 offset: 155 
Virtual address: 6043 Physical address: 9371 Value: -26

Page number = 83 Frame Number = 35 offset: 150 
Virtual address: 21398 Physical address: 9110 Value: 20

Page number = 12 Frame Number = 157 offset: 201 
Virtual address: 3273 Physical address: 40393 Value: 0

Page number = 36 Frame Number = 89 offset: 154 
Virtual address: 9370 Physical address: 22938 Value: 9

Page Fault! Obtaining page from disk and assigning to frame 219
Page number = 138 Frame Number = 219 offset: 135 
Virtual address: 35463 Physical address: 56199 Value: -95

Page number = 110 Frame Number = 136 offset: 45 
Virtual address: 28205 Physical address: 34861 Value: 0

Page number = 9 Frame Number = 18 offset: 47 
Virtual address: 2351 Physical address: 4655 Value: 75

Page number = 113 Frame Number = 64 offset: 71 
Virtual address: 28999 Physical address: 16455 Value: 81

Page Fault! Obtaining page from disk and assigning to frame 220
Page number = 186 Frame Number = 220 offset: 83 
Virtual address: 47699 Physical address: 56403 Value: -108

Page number = 183 Frame Number = 77 offset: 22 
Virtual address: 46870 Physical address: 19734 Value: 45

Page number = 87 Frame Number = 44 offset: 39 
Virtual address: 22311 Physical address: 11303 Value: -55

Page Fault! Obtaining page from disk and assigning to frame 221
Page number = 86 Frame Number = 221 offset: 108 
Virtual address: 22124 Physical address: 56684 Value: 0

Page number = 87 Frame Number = 44 offset: 155 
Virtual address: 22427 Physical address: 11419 Value: -26

Page number = 192 Frame Number = 33 offset: 192 
Virtual address: 49344 Physical address: 8640 Value: 0

Page number = 90 Frame Number = 140 offset: 184 
Virtual address: 23224 Physical address: 36024 Value: 0

Page number = 21 Frame Number = 84 offset: 138 
Virtual address: 5514 Physical address: 21642 Value: 5

Page Fault! Obtaining page from disk and assigning to frame 222
Page number = 80 Frame Number = 222 offset: 24 
Virtual address: 20504 Physical address: 56856 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 223
Page number = 1 Frame Number = 223 offset: 120 
Virtual address: 376 Physical address: 57208 Value: 0

Page number = 7 Frame Number = 129 offset: 222 
Virtual address: 2014 Physical address: 33246 Value: 1

Page number = 151 Frame Number = 183 offset: 44 
Virtual address: 38700 Physical address: 46892 Value: 0

Page number = 51 Frame Number = 173 offset: 42 
Virtual address: 13098 Physical address: 44330 Value: 12

Page number = 243 Frame Number = 93 offset: 227 
Virtual address: 62435 Physical address: 24035 Value: -8

Page number = 187 Frame Number = 100 offset: 174 
Virtual address: 48046 Physical address: 25774 Value: 46

Page number = 247 Frame Number = 66 offset: 232 
Virtual address: 63464 Physical address: 17128 Value: 0

Page number = 49 Frame Number = 121 offset: 254 
Virtual address: 12798 Physical address: 31230 Value: 12

Page number = 199 Frame Number = 167 offset: 234 
Virtual address: 51178 Physical address: 42986 Value: 49

Page number = 33 Frame Number = 78 offset: 179 
Virtual address: 8627 Physical address: 20147 Value: 108

Page number = 105 Frame Number = 105 offset: 203 
Virtual address: 27083 Physical address: 27083 Value: 114

Page number = 184 Frame Number = 116 offset: 94 
Virtual address: 47198 Physical address: 29790 Value: 46

Page Fault! Obtaining page from disk and assigning to frame 224
Page number = 171 Frame Number = 224 offset: 245 
Virtual address: 44021 Physical address: 57589 Value: 0

Page number = 128 Frame Number = 16 offset: 24 
Virtual address: 32792 Physical address: 4120 Value: 0

Page number = 171 Frame Number = 224 offset: 220 
Virtual address: 43996 Physical address: 57564 Value: 0

Page number = 160 Frame Number = 34 offset: 166 
Virtual address: 41126 Physical address: 8870 Value: 40

Page number = 250 Frame Number = 17 offset: 244 
Virtual address: 64244 Physical address: 4596 Value: 0

Page number = 144 Frame Number = 71 offset: 183 
Virtual address: 37047 Physical address: 18359 Value: 45

Page Fault! Obtaining page from disk and assigning to frame 225
Page number = 235 Frame Number = 225 offset: 121 
Virtual address: 60281 Physical address: 57721 Value: 0

Page number = 206 Frame Number = 186 offset: 168 
Virtual address: 52904 Physical address: 47784 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 226
Page number = 30 Frame Number = 226 offset: 88 
Virtual address: 7768 Physical address: 57944 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 227
Page number = 216 Frame Number = 227 offset: 63 
Virtual address: 55359 Physical address: 58175 Value: 15

Page number = 12 Frame Number = 157 offset: 158 
Virtual address: 3230 Physical address: 40350 Value: 3

Page number = 175 Frame Number = 51 offset: 13 
Virtual address: 44813 Physical address: 13069 Value: 0

Page number = 16 Frame Number = 198 offset: 20 
Virtual address: 4116 Physical address: 50708 Value: 0

Page number = 254 Frame Number = 189 offset: 198 
Virtual address: 65222 Physical address: 48582 Value: 63

Found in TLB, page number = 109 correspond to frame = 13 
Page number = 109 Frame Number = 13 offset: 179 
Virtual address: 28083 Physical address: 3507 Value: 0

Page number = 236 Frame Number = 28 offset: 244 
Virtual address: 60660 Physical address: 7412 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 228
Page number = 0 Frame Number = 228 offset: 39 
Virtual address: 39 Physical address: 58407 Value: 9

Page number = 1 Frame Number = 223 offset: 72 
Virtual address: 328 Physical address: 57160 Value: 0

Page number = 186 Frame Number = 220 offset: 252 
Virtual address: 47868 Physical address: 56572 Value: 0

Page number = 50 Frame Number = 118 offset: 209 
Virtual address: 13009 Physical address: 30417 Value: 0

Page number = 87 Frame Number = 44 offset: 106 
Virtual address: 22378 Physical address: 11370 Value: 21

Page number = 153 Frame Number = 217 offset: 136 
Virtual address: 39304 Physical address: 55688 Value: 0

Page number = 43 Frame Number = 156 offset: 163 
Virtual address: 11171 Physical address: 40099 Value: -24

Page number = 31 Frame Number = 132 offset: 143 
Virtual address: 8079 Physical address: 33935 Value: -29

Page number = 206 Frame Number = 186 offset: 143 
Virtual address: 52879 Physical address: 47759 Value: -93

Page number = 20 Frame Number = 59 offset: 3 
Virtual address: 5123 Physical address: 15107 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 229
Page number = 17 Frame Number = 229 offset: 4 
Virtual address: 4356 Physical address: 58628 Value: 0

Page number = 178 Frame Number = 30 offset: 177 
Virtual address: 45745 Physical address: 7857 Value: 0

Page number = 128 Frame Number = 16 offset: 184 
Virtual address: 32952 Physical address: 4280 Value: 0

Page number = 18 Frame Number = 108 offset: 49 
Virtual address: 4657 Physical address: 27697 Value: 0

Page number = 94 Frame Number = 131 offset: 78 
Virtual address: 24142 Physical address: 33614 Value: 23

Page number = 91 Frame Number = 80 offset: 23 
Virtual address: 23319 Physical address: 20503 Value: -59

Page number = 53 Frame Number = 207 offset: 39 
Virtual address: 13607 Physical address: 53031 Value: 73

Page number = 180 Frame Number = 195 offset: 224 
Virtual address: 46304 Physical address: 50144 Value: 0

Page number = 69 Frame Number = 38 offset: 13 
Virtual address: 17677 Physical address: 9741 Value: 0

Page number = 233 Frame Number = 185 offset: 43 
Virtual address: 59691 Physical address: 47403 Value: 74

Page number = 199 Frame Number = 167 offset: 23 
Virtual address: 50967 Physical address: 42775 Value: -59

Page number = 30 Frame Number = 226 offset: 137 
Virtual address: 7817 Physical address: 57993 Value: 0

Page number = 33 Frame Number = 78 offset: 97 
Virtual address: 8545 Physical address: 20065 Value: 0

Page number = 216 Frame Number = 227 offset: 1 
Virtual address: 55297 Physical address: 58113 Value: 0

Page number = 206 Frame Number = 186 offset: 218 
Virtual address: 52954 Physical address: 47834 Value: 51

Page number = 155 Frame Number = 149 offset: 40 
Virtual address: 39720 Physical address: 38184 Value: 0

Page number = 72 Frame Number = 21 offset: 23 
Virtual address: 18455 Physical address: 5399 Value: 5

Page Fault! Obtaining page from disk and assigning to frame 230
Page number = 118 Frame Number = 230 offset: 141 
Virtual address: 30349 Physical address: 59021 Value: 0

Page number = 247 Frame Number = 66 offset: 38 
Virtual address: 63270 Physical address: 16934 Value: 61

Page number = 106 Frame Number = 112 offset: 20 
Virtual address: 27156 Physical address: 28692 Value: 0

Page number = 80 Frame Number = 222 offset: 134 
Virtual address: 20614 Physical address: 56966 Value: 20

Page number = 75 Frame Number = 55 offset: 172 
Virtual address: 19372 Physical address: 14252 Value: 0

Page number = 190 Frame Number = 128 offset: 49 
Virtual address: 48689 Physical address: 32817 Value: 0

Page number = 192 Frame Number = 33 offset: 234 
Virtual address: 49386 Physical address: 8682 Value: 48

Page number = 197 Frame Number = 72 offset: 152 
Virtual address: 50584 Physical address: 18584 Value: 0

Page number = 202 Frame Number = 106 offset: 224 
Virtual address: 51936 Physical address: 27360 Value: 0

Page number = 135 Frame Number = 70 offset: 145 
Virtual address: 34705 Physical address: 18065 Value: 0

Page number = 53 Frame Number = 207 offset: 85 
Virtual address: 13653 Physical address: 53077 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 231
Page number = 195 Frame Number = 231 offset: 157 
Virtual address: 50077 Physical address: 59293 Value: 0

Page number = 212 Frame Number = 75 offset: 246 
Virtual address: 54518 Physical address: 19446 Value: 53

Page number = 162 Frame Number = 163 offset: 10 
Virtual address: 41482 Physical address: 41738 Value: 40

Page number = 16 Frame Number = 198 offset: 73 
Virtual address: 4169 Physical address: 50761 Value: 0

Page number = 141 Frame Number = 213 offset: 22 
Virtual address: 36118 Physical address: 54550 Value: 35

Page Fault! Obtaining page from disk and assigning to frame 232
Page number = 37 Frame Number = 232 offset: 112 
Virtual address: 9584 Physical address: 59504 Value: 0

Page number = 72 Frame Number = 21 offset: 58 
Virtual address: 18490 Physical address: 5434 Value: 18

Page number = 216 Frame Number = 227 offset: 124 
Virtual address: 55420 Physical address: 58236 Value: 0

Page number = 22 Frame Number = 203 offset: 76 
Virtual address: 5708 Physical address: 52044 Value: 0

Page number = 91 Frame Number = 80 offset: 210 
Virtual address: 23506 Physical address: 20690 Value: 22

Page number = 60 Frame Number = 124 offset: 31 
Virtual address: 15391 Physical address: 31775 Value: 7

Page number = 142 Frame Number = 56 offset: 16 
Virtual address: 36368 Physical address: 14352 Value: 0

Page number = 152 Frame Number = 15 offset: 64 
Virtual address: 38976 Physical address: 3904 Value: 0

Page number = 196 Frame Number = 54 offset: 230 
Virtual address: 50406 Physical address: 14054 Value: 49

Page number = 192 Frame Number = 33 offset: 84 
Virtual address: 49236 Physical address: 8532 Value: 0

Page number = 254 Frame Number = 189 offset: 11 
Virtual address: 65035 Physical address: 48395 Value: -126

Page number = 117 Frame Number = 2 offset: 168 
Virtual address: 30120 Physical address: 680 Value: 0

Page number = 244 Frame Number = 1 offset: 87 
Virtual address: 62551 Physical address: 343 Value: 21

Page number = 182 Frame Number = 216 offset: 217 
Virtual address: 46809 Physical address: 55513 Value: 0

Page number = 84 Frame Number = 204 offset: 183 
Virtual address: 21687 Physical address: 52407 Value: 45

Page number = 210 Frame Number = 211 offset: 79 
Virtual address: 53839 Physical address: 54095 Value: -109

Page number = 8 Frame Number = 137 offset: 50 
Virtual address: 2098 Physical address: 35122 Value: 2

Page number = 48 Frame Number = 176 offset: 76 
Virtual address: 12364 Physical address: 45132 Value: 0

Page number = 177 Frame Number = 179 offset: 54 
Virtual address: 45366 Physical address: 45878 Value: 44

Page number = 197 Frame Number = 72 offset: 5 
Virtual address: 50437 Physical address: 18437 Value: 0

Page number = 143 Frame Number = 139 offset: 67 
Virtual address: 36675 Physical address: 35651 Value: -48

Page number = 216 Frame Number = 227 offset: 86 
Virtual address: 55382 Physical address: 58198 Value: 54

Page Fault! Obtaining page from disk and assigning to frame 233
Page number = 46 Frame Number = 233 offset: 70 
Virtual address: 11846 Physical address: 59718 Value: 11

Page number = 191 Frame Number = 197 offset: 231 
Virtual address: 49127 Physical address: 50663 Value: -7

Page number = 77 Frame Number = 142 offset: 188 
Virtual address: 19900 Physical address: 36540 Value: 0

Page number = 80 Frame Number = 222 offset: 74 
Virtual address: 20554 Physical address: 56906 Value: 20

Page number = 75 Frame Number = 55 offset: 19 
Virtual address: 19219 Physical address: 14099 Value: -60

Page number = 201 Frame Number = 62 offset: 27 
Virtual address: 51483 Physical address: 15899 Value: 70

Found in TLB, page number = 226 correspond to frame = 12 
Page number = 226 Frame Number = 12 offset: 234 
Virtual address: 58090 Physical address: 3306 Value: 0

Page number = 152 Frame Number = 15 offset: 162 
Virtual address: 39074 Physical address: 4002 Value: 38

Page number = 62 Frame Number = 82 offset: 188 
Virtual address: 16060 Physical address: 21180 Value: 0

Page number = 40 Frame Number = 57 offset: 207 
Virtual address: 10447 Physical address: 14799 Value: 51

Page number = 211 Frame Number = 202 offset: 153 
Virtual address: 54169 Physical address: 51865 Value: 0

Page number = 80 Frame Number = 222 offset: 154 
Virtual address: 20634 Physical address: 56986 Value: 20

Page number = 224 Frame Number = 148 offset: 211 
Virtual address: 57555 Physical address: 38099 Value: 52

Page number = 239 Frame Number = 165 offset: 26 
Virtual address: 61210 Physical address: 42266 Value: 59

Page number = 1 Frame Number = 223 offset: 13 
Virtual address: 269 Physical address: 57101 Value: 0

Page number = 129 Frame Number = 209 offset: 130 
Virtual address: 33154 Physical address: 53634 Value: 32

Page number = 251 Frame Number = 19 offset: 231 
Virtual address: 64487 Physical address: 5095 Value: -7

Page number = 239 Frame Number = 165 offset: 39 
Virtual address: 61223 Physical address: 42279 Value: -55

Page number = 184 Frame Number = 116 offset: 188 
Virtual address: 47292 Physical address: 29884 Value: 0

Page number = 85 Frame Number = 94 offset: 92 
Virtual address: 21852 Physical address: 24156 Value: 0

Page number = 20 Frame Number = 59 offset: 161 
Virtual address: 5281 Physical address: 15265 Value: 0

Page number = 179 Frame Number = 199 offset: 88 
Virtual address: 45912 Physical address: 51032 Value: 0

Page number = 127 Frame Number = 37 offset: 20 
Virtual address: 32532 Physical address: 9492 Value: 0

Page number = 246 Frame Number = 86 offset: 91 
Virtual address: 63067 Physical address: 22107 Value: -106

Page number = 162 Frame Number = 163 offset: 211 
Virtual address: 41683 Physical address: 41939 Value: -76

Page number = 81 Frame Number = 152 offset: 245 
Virtual address: 20981 Physical address: 39157 Value: 0

Page number = 132 Frame Number = 164 offset: 89 
Virtual address: 33881 Physical address: 42073 Value: 0

Page number = 163 Frame Number = 151 offset: 57 
Virtual address: 41785 Physical address: 38713 Value: 0

Page number = 17 Frame Number = 229 offset: 228 
Virtual address: 4580 Physical address: 58852 Value: 0

Page number = 161 Frame Number = 97 offset: 173 
Virtual address: 41389 Physical address: 25005 Value: 0

Page number = 111 Frame Number = 109 offset: 156 
Virtual address: 28572 Physical address: 28060 Value: 0

Page number = 3 Frame Number = 31 offset: 14 
Virtual address: 782 Physical address: 7950 Value: 0

Page number = 118 Frame Number = 230 offset: 65 
Virtual address: 30273 Physical address: 58945 Value: 0

Page number = 243 Frame Number = 93 offset: 59 
Virtual address: 62267 Physical address: 23867 Value: -50

Page number = 70 Frame Number = 73 offset: 2 
Virtual address: 17922 Physical address: 18690 Value: 17

Page number = 247 Frame Number = 66 offset: 6 
Virtual address: 63238 Physical address: 16902 Value: 61

Page number = 12 Frame Number = 157 offset: 236 
Virtual address: 3308 Physical address: 40428 Value: 0

Page number = 103 Frame Number = 95 offset: 177 
Virtual address: 26545 Physical address: 24497 Value: 0

Page number = 173 Frame Number = 175 offset: 107 
Virtual address: 44395 Physical address: 44907 Value: 90

Page number = 152 Frame Number = 15 offset: 208 
Virtual address: 39120 Physical address: 4048 Value: 0

Page number = 84 Frame Number = 204 offset: 202 
Virtual address: 21706 Physical address: 52426 Value: 21

Page number = 27 Frame Number = 103 offset: 232 
Virtual address: 7144 Physical address: 26600 Value: 0

Page number = 118 Frame Number = 230 offset: 36 
Virtual address: 30244 Physical address: 58916 Value: 0

Page number = 14 Frame Number = 39 offset: 141 
Virtual address: 3725 Physical address: 10125 Value: 0

Page number = 213 Frame Number = 190 offset: 104 
Virtual address: 54632 Physical address: 48744 Value: 0

Page number = 119 Frame Number = 63 offset: 110 
Virtual address: 30574 Physical address: 16238 Value: 29

Page number = 33 Frame Number = 78 offset: 25 
Virtual address: 8473 Physical address: 19993 Value: 0

Page number = 48 Frame Number = 176 offset: 98 
Virtual address: 12386 Physical address: 45154 Value: 12

Page number = 160 Frame Number = 34 offset: 154 
Virtual address: 41114 Physical address: 8858 Value: 40

Found in TLB, page number = 226 correspond to frame = 12 
Page number = 226 Frame Number = 12 offset: 74 
Virtual address: 57930 Physical address: 3146 Value: 0

Page number = 59 Frame Number = 126 offset: 237 
Virtual address: 15341 Physical address: 32493 Value: 0

Page number = 60 Frame Number = 124 offset: 238 
Virtual address: 15598 Physical address: 31982 Value: 15

Page number = 234 Frame Number = 41 offset: 18 
Virtual address: 59922 Physical address: 10514 Value: 58

Found in TLB, page number = 71 correspond to frame = 9 
Page number = 71 Frame Number = 9 offset: 50 
Virtual address: 18226 Physical address: 2354 Value: 0

Page number = 188 Frame Number = 69 offset: 34 
Virtual address: 48162 Physical address: 17698 Value: 47

Page number = 161 Frame Number = 97 offset: 34 
Virtual address: 41250 Physical address: 24866 Value: 40

Page number = 5 Frame Number = 201 offset: 232 
Virtual address: 1512 Physical address: 51688 Value: 0

Page number = 9 Frame Number = 18 offset: 242 
Virtual address: 2546 Physical address: 4850 Value: 2

Page number = 162 Frame Number = 163 offset: 210 
Virtual address: 41682 Physical address: 41938 Value: 40

Page number = 1 Frame Number = 223 offset: 66 
Virtual address: 322 Physical address: 57154 Value: 0

Page number = 3 Frame Number = 31 offset: 112 
Virtual address: 880 Physical address: 8048 Value: 0

Page number = 81 Frame Number = 152 offset: 155 
Virtual address: 20891 Physical address: 39067 Value: 102

Page number = 221 Frame Number = 52 offset: 28 
Virtual address: 56604 Physical address: 13340 Value: 0

Page number = 156 Frame Number = 4 offset: 230 
Virtual address: 40166 Physical address: 1254 Value: 39

Page number = 104 Frame Number = 166 offset: 167 
Virtual address: 26791 Physical address: 42663 Value: 41

Page number = 174 Frame Number = 43 offset: 16 
Virtual address: 44560 Physical address: 11024 Value: 0

Page number = 151 Frame Number = 183 offset: 42 
Virtual address: 38698 Physical address: 46890 Value: 37

Page number = 250 Frame Number = 17 offset: 127 
Virtual address: 64127 Physical address: 4479 Value: -97

Page number = 58 Frame Number = 96 offset: 180 
Virtual address: 15028 Physical address: 24756 Value: 0

Page number = 151 Frame Number = 183 offset: 13 
Virtual address: 38669 Physical address: 46861 Value: 0

Page number = 178 Frame Number = 30 offset: 69 
Virtual address: 45637 Physical address: 7749 Value: 0

Page number = 168 Frame Number = 68 offset: 143 
Virtual address: 43151 Physical address: 17551 Value: 35

Page number = 36 Frame Number = 89 offset: 249 
Virtual address: 9465 Physical address: 23033 Value: 0

Page number = 9 Frame Number = 18 offset: 194 
Virtual address: 2498 Physical address: 4802 Value: 2

Page number = 54 Frame Number = 122 offset: 154 
Virtual address: 13978 Physical address: 31386 Value: 13

Page number = 63 Frame Number = 218 offset: 198 
Virtual address: 16326 Physical address: 56006 Value: 15

Page number = 200 Frame Number = 127 offset: 242 
Virtual address: 51442 Physical address: 32754 Value: 50

Page number = 136 Frame Number = 104 offset: 29 
Virtual address: 34845 Physical address: 26653 Value: 0

Page number = 248 Frame Number = 110 offset: 179 
Virtual address: 63667 Physical address: 28339 Value: 44

Page number = 153 Frame Number = 217 offset: 202 
Virtual address: 39370 Physical address: 55754 Value: 38

Page Fault! Obtaining page from disk and assigning to frame 234
Page number = 217 Frame Number = 234 offset: 119 
Virtual address: 55671 Physical address: 60023 Value: 93

Page number = 251 Frame Number = 19 offset: 240 
Virtual address: 64496 Physical address: 5104 Value: 0

Page number = 30 Frame Number = 226 offset: 87 
Virtual address: 7767 Physical address: 57943 Value: -107

Page number = 24 Frame Number = 29 offset: 139 
Virtual address: 6283 Physical address: 7563 Value: 34

Page number = 218 Frame Number = 135 offset: 76 
Virtual address: 55884 Physical address: 34636 Value: 0

Page number = 238 Frame Number = 23 offset: 175 
Virtual address: 61103 Physical address: 6063 Value: -85

Page Fault! Obtaining page from disk and assigning to frame 235
Page number = 39 Frame Number = 235 offset: 200 
Virtual address: 10184 Physical address: 60360 Value: 0

Page number = 154 Frame Number = 169 offset: 119 
Virtual address: 39543 Physical address: 43383 Value: -99

Page number = 37 Frame Number = 232 offset: 83 
Virtual address: 9555 Physical address: 59475 Value: 84

Page number = 54 Frame Number = 122 offset: 139 
Virtual address: 13963 Physical address: 31371 Value: -94

Page number = 230 Frame Number = 58 offset: 95 
Virtual address: 58975 Physical address: 14943 Value: -105

Page number = 76 Frame Number = 88 offset: 81 
Virtual address: 19537 Physical address: 22609 Value: 0

Page number = 23 Frame Number = 36 offset: 213 
Virtual address: 6101 Physical address: 9429 Value: 0

Page number = 161 Frame Number = 97 offset: 205 
Virtual address: 41421 Physical address: 25037 Value: 0

Page number = 177 Frame Number = 179 offset: 190 
Virtual address: 45502 Physical address: 46014 Value: 44

Page number = 114 Frame Number = 144 offset: 144 
Virtual address: 29328 Physical address: 37008 Value: 0

Page number = 31 Frame Number = 132 offset: 213 
Virtual address: 8149 Physical address: 34005 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 236
Page number = 99 Frame Number = 236 offset: 106 
Virtual address: 25450 Physical address: 60522 Value: 24

Page number = 230 Frame Number = 58 offset: 64 
Virtual address: 58944 Physical address: 14912 Value: 0

Page number = 197 Frame Number = 72 offset: 234 
Virtual address: 50666 Physical address: 18666 Value: 49

Page number = 90 Frame Number = 140 offset: 44 
Virtual address: 23084 Physical address: 35884 Value: 0

Page number = 142 Frame Number = 56 offset: 116 
Virtual address: 36468 Physical address: 14452 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 237
Page number = 131 Frame Number = 237 offset: 109 
Virtual address: 33645 Physical address: 60781 Value: 0

Page number = 97 Frame Number = 205 offset: 170 
Virtual address: 25002 Physical address: 52650 Value: 24

Page number = 209 Frame Number = 3 offset: 211 
Virtual address: 53715 Physical address: 979 Value: 116

Page number = 235 Frame Number = 225 offset: 13 
Virtual address: 60173 Physical address: 57613 Value: 0

Page number = 181 Frame Number = 196 offset: 18 
Virtual address: 46354 Physical address: 50194 Value: 45

Page number = 18 Frame Number = 108 offset: 100 
Virtual address: 4708 Physical address: 27748 Value: 0

Page number = 110 Frame Number = 136 offset: 48 
Virtual address: 28208 Physical address: 34864 Value: 0

Page number = 229 Frame Number = 215 offset: 220 
Virtual address: 58844 Physical address: 55260 Value: 0

Page number = 86 Frame Number = 221 offset: 157 
Virtual address: 22173 Physical address: 56733 Value: 0

Page number = 33 Frame Number = 78 offset: 87 
Virtual address: 8535 Physical address: 20055 Value: 85

Page number = 165 Frame Number = 42 offset: 21 
Virtual address: 42261 Physical address: 10773 Value: 0

Page number = 115 Frame Number = 193 offset: 247 
Virtual address: 29687 Physical address: 49655 Value: -3

Page number = 147 Frame Number = 114 offset: 167 
Virtual address: 37799 Physical address: 29351 Value: -23

Found in TLB, page number = 88 correspond to frame = 11 
Page number = 88 Frame Number = 11 offset: 38 
Virtual address: 22566 Physical address: 2854 Value: 0

Page number = 244 Frame Number = 1 offset: 56 
Virtual address: 62520 Physical address: 312 Value: 0

Page number = 16 Frame Number = 198 offset: 2 
Virtual address: 4098 Physical address: 50690 Value: 4

Page number = 187 Frame Number = 100 offset: 127 
Virtual address: 47999 Physical address: 25727 Value: -33

Page number = 193 Frame Number = 177 offset: 252 
Virtual address: 49660 Physical address: 45564 Value: 0

Page number = 144 Frame Number = 71 offset: 199 
Virtual address: 37063 Physical address: 18375 Value: 49

Page number = 163 Frame Number = 151 offset: 128 
Virtual address: 41856 Physical address: 38784 Value: 0

Page number = 21 Frame Number = 84 offset: 41 
Virtual address: 5417 Physical address: 21545 Value: 0

Page number = 190 Frame Number = 128 offset: 216 
Virtual address: 48856 Physical address: 32984 Value: 0

Page number = 41 Frame Number = 107 offset: 186 
Virtual address: 10682 Physical address: 27578 Value: 10

Page number = 87 Frame Number = 44 offset: 98 
Virtual address: 22370 Physical address: 11362 Value: 21

Page number = 247 Frame Number = 66 offset: 49 
Virtual address: 63281 Physical address: 16945 Value: 0

Page number = 243 Frame Number = 93 offset: 244 
Virtual address: 62452 Physical address: 24052 Value: 0

Page number = 197 Frame Number = 72 offset: 100 
Virtual address: 50532 Physical address: 18532 Value: 0

Page number = 35 Frame Number = 188 offset: 62 
Virtual address: 9022 Physical address: 48190 Value: 8

Page number = 231 Frame Number = 40 offset: 164 
Virtual address: 59300 Physical address: 10404 Value: 0

Page number = 229 Frame Number = 215 offset: 36 
Virtual address: 58660 Physical address: 55076 Value: 0

Page number = 220 Frame Number = 200 offset: 81 
Virtual address: 56401 Physical address: 51281 Value: 0

Page number = 33 Frame Number = 78 offset: 70 
Virtual address: 8518 Physical address: 20038 Value: 8

Page number = 246 Frame Number = 86 offset: 90 
Virtual address: 63066 Physical address: 22106 Value: 61

Page number = 247 Frame Number = 66 offset: 18 
Virtual address: 63250 Physical address: 16914 Value: 61

Found in TLB, page number = 189 correspond to frame = 7 
Page number = 189 Frame Number = 7 offset: 208 
Virtual address: 48592 Physical address: 2000 Value: 0

Page number = 112 Frame Number = 5 offset: 99 
Virtual address: 28771 Physical address: 1379 Value: 24

Page number = 147 Frame Number = 114 offset: 41 
Virtual address: 37673 Physical address: 29225 Value: 0

Page number = 237 Frame Number = 92 offset: 104 
Virtual address: 60776 Physical address: 23656 Value: 0

Page number = 220 Frame Number = 200 offset: 118 
Virtual address: 56438 Physical address: 51318 Value: 55

Page number = 236 Frame Number = 28 offset: 8 
Virtual address: 60424 Physical address: 7176 Value: 0

Page number = 156 Frame Number = 4 offset: 57 
Virtual address: 39993 Physical address: 1081 Value: 0

Page number = 218 Frame Number = 135 offset: 196 
Virtual address: 56004 Physical address: 34756 Value: 0

Page number = 230 Frame Number = 58 offset: 122 
Virtual address: 59002 Physical address: 14970 Value: 57

Page number = 132 Frame Number = 164 offset: 190 
Virtual address: 33982 Physical address: 42174 Value: 33

Page number = 99 Frame Number = 236 offset: 154 
Virtual address: 25498 Physical address: 60570 Value: 24

Page number = 222 Frame Number = 146 offset: 215 
Virtual address: 57047 Physical address: 37591 Value: -75

Page number = 5 Frame Number = 201 offset: 121 
Virtual address: 1401 Physical address: 51577 Value: 0

Page number = 59 Frame Number = 126 offset: 26 
Virtual address: 15130 Physical address: 32282 Value: 14

Page number = 167 Frame Number = 76 offset: 208 
Virtual address: 42960 Physical address: 19664 Value: 0

Page number = 241 Frame Number = 87 offset: 131 
Virtual address: 61827 Physical address: 22403 Value: 96

Page number = 126 Frame Number = 27 offset: 186 
Virtual address: 32442 Physical address: 7098 Value: 31

Page number = 251 Frame Number = 19 offset: 48 
Virtual address: 64304 Physical address: 4912 Value: 0

Page number = 118 Frame Number = 230 offset: 65 
Virtual address: 30273 Physical address: 58945 Value: 0

Page number = 148 Frame Number = 145 offset: 194 
Virtual address: 38082 Physical address: 37314 Value: 37

Page number = 87 Frame Number = 44 offset: 132 
Virtual address: 22404 Physical address: 11396 Value: 0

Page number = 14 Frame Number = 39 offset: 224 
Virtual address: 3808 Physical address: 10208 Value: 0

Page number = 65 Frame Number = 187 offset: 243 
Virtual address: 16883 Physical address: 48115 Value: 124

Page number = 90 Frame Number = 140 offset: 71 
Virtual address: 23111 Physical address: 35911 Value: -111

Page number = 243 Frame Number = 93 offset: 209 
Virtual address: 62417 Physical address: 24017 Value: 0

Page number = 235 Frame Number = 225 offset: 204 
Virtual address: 60364 Physical address: 57804 Value: 0

Page number = 17 Frame Number = 229 offset: 190 
Virtual address: 4542 Physical address: 58814 Value: 4

Page number = 57 Frame Number = 130 offset: 237 
Virtual address: 14829 Physical address: 33517 Value: 0

Page number = 175 Frame Number = 51 offset: 164 
Virtual address: 44964 Physical address: 13220 Value: 0

Page number = 132 Frame Number = 164 offset: 132 
Virtual address: 33924 Physical address: 42116 Value: 0

Page number = 8 Frame Number = 137 offset: 93 
Virtual address: 2141 Physical address: 35165 Value: 0

Page number = 75 Frame Number = 55 offset: 45 
Virtual address: 19245 Physical address: 14125 Value: 0

Page number = 184 Frame Number = 116 offset: 64 
Virtual address: 47168 Physical address: 29760 Value: 0

Page number = 93 Frame Number = 154 offset: 240 
Virtual address: 24048 Physical address: 39664 Value: 0

Page number = 3 Frame Number = 31 offset: 254 
Virtual address: 1022 Physical address: 8190 Value: 0

Page number = 90 Frame Number = 140 offset: 35 
Virtual address: 23075 Physical address: 35875 Value: -120

Page number = 97 Frame Number = 205 offset: 56 
Virtual address: 24888 Physical address: 52536 Value: 0

Page number = 192 Frame Number = 33 offset: 95 
Virtual address: 49247 Physical address: 8543 Value: 23

Page number = 19 Frame Number = 53 offset: 36 
Virtual address: 4900 Physical address: 13604 Value: 0

Found in TLB, page number = 88 correspond to frame = 11 
Page number = 88 Frame Number = 11 offset: 128 
Virtual address: 22656 Physical address: 2944 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 238
Page number = 133 Frame Number = 238 offset: 69 
Virtual address: 34117 Physical address: 60997 Value: 0

Page number = 217 Frame Number = 234 offset: 3 
Virtual address: 55555 Physical address: 59907 Value: 64

Page number = 191 Frame Number = 197 offset: 51 
Virtual address: 48947 Physical address: 50483 Value: -52

Page number = 232 Frame Number = 101 offset: 141 
Virtual address: 59533 Physical address: 25997 Value: 0

Page number = 83 Frame Number = 35 offset: 64 
Virtual address: 21312 Physical address: 9024 Value: 0

Page number = 83 Frame Number = 35 offset: 167 
Virtual address: 21415 Physical address: 9127 Value: -23

Page number = 3 Frame Number = 31 offset: 45 
Virtual address: 813 Physical address: 7981 Value: 0

Page number = 75 Frame Number = 55 offset: 219 
Virtual address: 19419 Physical address: 14299 Value: -10

Page number = 7 Frame Number = 129 offset: 207 
Virtual address: 1999 Physical address: 33231 Value: -13

Page number = 78 Frame Number = 158 offset: 187 
Virtual address: 20155 Physical address: 40635 Value: -82

Page number = 84 Frame Number = 204 offset: 17 
Virtual address: 21521 Physical address: 52241 Value: 0

Page number = 53 Frame Number = 207 offset: 102 
Virtual address: 13670 Physical address: 53094 Value: 13

Page number = 75 Frame Number = 55 offset: 89 
Virtual address: 19289 Physical address: 14169 Value: 0

Page number = 228 Frame Number = 60 offset: 115 
Virtual address: 58483 Physical address: 15475 Value: 28

Page number = 161 Frame Number = 97 offset: 102 
Virtual address: 41318 Physical address: 24934 Value: 40

Page number = 63 Frame Number = 218 offset: 23 
Virtual address: 16151 Physical address: 55831 Value: -59

Page number = 53 Frame Number = 207 offset: 43 
Virtual address: 13611 Physical address: 53035 Value: 74

Page number = 84 Frame Number = 204 offset: 10 
Virtual address: 21514 Physical address: 52234 Value: 21

Page number = 52 Frame Number = 141 offset: 187 
Virtual address: 13499 Physical address: 36283 Value: 46

Page number = 178 Frame Number = 30 offset: 15 
Virtual address: 45583 Physical address: 7695 Value: -125

Page number = 191 Frame Number = 197 offset: 117 
Virtual address: 49013 Physical address: 50549 Value: 0

Found in TLB, page number = 253 correspond to frame = 8 
Page number = 253 Frame Number = 8 offset: 75 
Virtual address: 64843 Physical address: 2123 Value: 0

Page number = 247 Frame Number = 66 offset: 253 
Virtual address: 63485 Physical address: 17149 Value: 0

Page number = 151 Frame Number = 183 offset: 41 
Virtual address: 38697 Physical address: 46889 Value: 0

Page number = 231 Frame Number = 40 offset: 52 
Virtual address: 59188 Physical address: 10292 Value: 0

Page number = 96 Frame Number = 150 offset: 17 
Virtual address: 24593 Physical address: 38417 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 239
Page number = 225 Frame Number = 239 offset: 41 
Virtual address: 57641 Physical address: 61225 Value: 0

Page number = 142 Frame Number = 56 offset: 172 
Virtual address: 36524 Physical address: 14508 Value: 0

Page number = 222 Frame Number = 146 offset: 148 
Virtual address: 56980 Physical address: 37524 Value: 0

Page number = 143 Frame Number = 139 offset: 202 
Virtual address: 36810 Physical address: 35786 Value: 35

Page number = 23 Frame Number = 36 offset: 208 
Virtual address: 6096 Physical address: 9424 Value: 0

Page number = 43 Frame Number = 156 offset: 62 
Virtual address: 11070 Physical address: 39998 Value: 10

Page number = 234 Frame Number = 41 offset: 220 
Virtual address: 60124 Physical address: 10716 Value: 0

Page number = 146 Frame Number = 83 offset: 200 
Virtual address: 37576 Physical address: 21448 Value: 0

Page number = 58 Frame Number = 96 offset: 248 
Virtual address: 15096 Physical address: 24824 Value: 0

Page number = 176 Frame Number = 191 offset: 191 
Virtual address: 45247 Physical address: 49087 Value: 47

Page number = 128 Frame Number = 16 offset: 15 
Virtual address: 32783 Physical address: 4111 Value: 3

Page number = 228 Frame Number = 60 offset: 22 
Virtual address: 58390 Physical address: 15382 Value: 57

Page number = 237 Frame Number = 92 offset: 201 
Virtual address: 60873 Physical address: 23753 Value: 0

Page number = 92 Frame Number = 214 offset: 167 
Virtual address: 23719 Physical address: 54951 Value: 41

Page number = 95 Frame Number = 6 offset: 65 
Virtual address: 24385 Physical address: 1601 Value: 0

Page number = 87 Frame Number = 44 offset: 35 
Virtual address: 22307 Physical address: 11299 Value: -56

Page Fault! Obtaining page from disk and assigning to frame 240
Page number = 67 Frame Number = 240 offset: 223 
Virtual address: 17375 Physical address: 61663 Value: -9

Page number = 62 Frame Number = 82 offset: 118 
Virtual address: 15990 Physical address: 21110 Value: 15

Page number = 80 Frame Number = 222 offset: 46 
Virtual address: 20526 Physical address: 56878 Value: 20

Page number = 101 Frame Number = 143 offset: 48 
Virtual address: 25904 Physical address: 36656 Value: 0

Page number = 164 Frame Number = 180 offset: 240 
Virtual address: 42224 Physical address: 46320 Value: 0

Page number = 36 Frame Number = 89 offset: 95 
Virtual address: 9311 Physical address: 22879 Value: 23

Page number = 30 Frame Number = 226 offset: 182 
Virtual address: 7862 Physical address: 58038 Value: 7

Page number = 14 Frame Number = 39 offset: 251 
Virtual address: 3835 Physical address: 10235 Value: -66

Page number = 119 Frame Number = 63 offset: 71 
Virtual address: 30535 Physical address: 16199 Value: -47

Page number = 254 Frame Number = 189 offset: 155 
Virtual address: 65179 Physical address: 48539 Value: -90

Page number = 224 Frame Number = 148 offset: 43 
Virtual address: 57387 Physical address: 37931 Value: 10

Page number = 248 Frame Number = 110 offset: 91 
Virtual address: 63579 Physical address: 28251 Value: 22

Page number = 19 Frame Number = 53 offset: 82 
Virtual address: 4946 Physical address: 13650 Value: 4

Page number = 35 Frame Number = 188 offset: 77 
Virtual address: 9037 Physical address: 48205 Value: 0

Page number = 238 Frame Number = 23 offset: 105 
Virtual address: 61033 Physical address: 5993 Value: 0

Page number = 216 Frame Number = 227 offset: 247 
Virtual address: 55543 Physical address: 58359 Value: 61

Page number = 196 Frame Number = 54 offset: 185 
Virtual address: 50361 Physical address: 14009 Value: 0

Page number = 25 Frame Number = 113 offset: 80 
Virtual address: 6480 Physical address: 29008 Value: 0

Page number = 54 Frame Number = 122 offset: 218 
Virtual address: 14042 Physical address: 31450 Value: 13

Page number = 84 Frame Number = 204 offset: 27 
Virtual address: 21531 Physical address: 52251 Value: 6

Page number = 153 Frame Number = 217 offset: 27 
Virtual address: 39195 Physical address: 55579 Value: 70

Page number = 146 Frame Number = 83 offset: 135 
Virtual address: 37511 Physical address: 21383 Value: -95

Page number = 92 Frame Number = 214 offset: 144 
Virtual address: 23696 Physical address: 54928 Value: 0

Page number = 107 Frame Number = 61 offset: 48 
Virtual address: 27440 Physical address: 15664 Value: 0

Page number = 110 Frame Number = 136 offset: 41 
Virtual address: 28201 Physical address: 34857 Value: 0

Page number = 90 Frame Number = 140 offset: 32 
Virtual address: 23072 Physical address: 35872 Value: 0

Page number = 30 Frame Number = 226 offset: 134 
Virtual address: 7814 Physical address: 57990 Value: 7

Page number = 25 Frame Number = 113 offset: 152 
Virtual address: 6552 Physical address: 29080 Value: 0

Page number = 170 Frame Number = 49 offset: 117 
Virtual address: 43637 Physical address: 12661 Value: 0

Page number = 137 Frame Number = 155 offset: 41 
Virtual address: 35113 Physical address: 39721 Value: 0

Page number = 136 Frame Number = 104 offset: 74 
Virtual address: 34890 Physical address: 26698 Value: 34

Page number = 239 Frame Number = 165 offset: 113 
Virtual address: 61297 Physical address: 42353 Value: 0

Page number = 178 Frame Number = 30 offset: 65 
Virtual address: 45633 Physical address: 7745 Value: 0

Page number = 239 Frame Number = 165 offset: 247 
Virtual address: 61431 Physical address: 42487 Value: -3

Page number = 179 Frame Number = 199 offset: 208 
Virtual address: 46032 Physical address: 51152 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 241
Page number = 73 Frame Number = 241 offset: 86 
Virtual address: 18774 Physical address: 61782 Value: 18

Page number = 246 Frame Number = 86 offset: 15 
Virtual address: 62991 Physical address: 22031 Value: -125

Found in TLB, page number = 109 correspond to frame = 13 
Page number = 109 Frame Number = 13 offset: 155 
Virtual address: 28059 Physical address: 3483 Value: 0

Page number = 137 Frame Number = 155 offset: 157 
Virtual address: 35229 Physical address: 39837 Value: 0

Page number = 200 Frame Number = 127 offset: 30 
Virtual address: 51230 Physical address: 32542 Value: 50

Page number = 56 Frame Number = 22 offset: 69 
Virtual address: 14405 Physical address: 5701 Value: 0

Page number = 204 Frame Number = 182 offset: 18 
Virtual address: 52242 Physical address: 46610 Value: 51

Page number = 168 Frame Number = 68 offset: 145 
Virtual address: 43153 Physical address: 17553 Value: 0

Page number = 10 Frame Number = 210 offset: 149 
Virtual address: 2709 Physical address: 53909 Value: 0

Page number = 187 Frame Number = 100 offset: 91 
Virtual address: 47963 Physical address: 25691 Value: -42

Page number = 144 Frame Number = 71 offset: 79 
Virtual address: 36943 Physical address: 18255 Value: 19

Page number = 211 Frame Number = 202 offset: 50 
Virtual address: 54066 Physical address: 51762 Value: 52

Page number = 39 Frame Number = 235 offset: 70 
Virtual address: 10054 Physical address: 60230 Value: 9

Page number = 168 Frame Number = 68 offset: 43 
Virtual address: 43051 Physical address: 17451 Value: 10

Page number = 45 Frame Number = 162 offset: 5 
Virtual address: 11525 Physical address: 41477 Value: 0

Page number = 69 Frame Number = 38 offset: 20 
Virtual address: 17684 Physical address: 9748 Value: 0

Page number = 162 Frame Number = 163 offset: 209 
Virtual address: 41681 Physical address: 41937 Value: 0

Page number = 108 Frame Number = 172 offset: 235 
Virtual address: 27883 Physical address: 44267 Value: 58

Page number = 222 Frame Number = 146 offset: 77 
Virtual address: 56909 Physical address: 37453 Value: 0

Page number = 178 Frame Number = 30 offset: 204 
Virtual address: 45772 Physical address: 7884 Value: 0

Page number = 107 Frame Number = 61 offset: 104 
Virtual address: 27496 Physical address: 15720 Value: 0

Page number = 182 Frame Number = 216 offset: 250 
Virtual address: 46842 Physical address: 55546 Value: 45

Page number = 151 Frame Number = 183 offset: 78 
Virtual address: 38734 Physical address: 46926 Value: 37

Page number = 113 Frame Number = 64 offset: 44 
Virtual address: 28972 Physical address: 16428 Value: 0

Page number = 233 Frame Number = 185 offset: 36 
Virtual address: 59684 Physical address: 47396 Value: 0

Page number = 44 Frame Number = 212 offset: 120 
Virtual address: 11384 Physical address: 54392 Value: 0

Page number = 82 Frame Number = 147 offset: 26 
Virtual address: 21018 Physical address: 37658 Value: 20

Page number = 8 Frame Number = 137 offset: 144 
Virtual address: 2192 Physical address: 35216 Value: 0

Found in TLB, page number = 71 correspond to frame = 9 
Page number = 71 Frame Number = 9 offset: 208 
Virtual address: 18384 Physical address: 2512 Value: 0

Page number = 52 Frame Number = 141 offset: 152 
Virtual address: 13464 Physical address: 36248 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 242
Page number = 121 Frame Number = 242 offset: 42 
Virtual address: 31018 Physical address: 61994 Value: 30

Page number = 245 Frame Number = 111 offset: 238 
Virtual address: 62958 Physical address: 28654 Value: 61

Page number = 119 Frame Number = 63 offset: 147 
Virtual address: 30611 Physical address: 16275 Value: -28

Page number = 7 Frame Number = 129 offset: 121 
Virtual address: 1913 Physical address: 33145 Value: 0

Page number = 73 Frame Number = 241 offset: 216 
Virtual address: 18904 Physical address: 61912 Value: 0

Page number = 104 Frame Number = 166 offset: 149 
Virtual address: 26773 Physical address: 42645 Value: 0

Page number = 216 Frame Number = 227 offset: 195 
Virtual address: 55491 Physical address: 58307 Value: 48

Page number = 85 Frame Number = 94 offset: 139 
Virtual address: 21899 Physical address: 24203 Value: 98

Page number = 251 Frame Number = 19 offset: 157 
Virtual address: 64413 Physical address: 5021 Value: 0

Page number = 184 Frame Number = 116 offset: 30 
Virtual address: 47134 Physical address: 29726 Value: 46

Page number = 90 Frame Number = 140 offset: 132 
Virtual address: 23172 Physical address: 35972 Value: 0

Page number = 28 Frame Number = 168 offset: 94 
Virtual address: 7262 Physical address: 43102 Value: 7

Page number = 49 Frame Number = 121 offset: 161 
Virtual address: 12705 Physical address: 31137 Value: 0

Page number = 29 Frame Number = 24 offset: 98 
Virtual address: 7522 Physical address: 6242 Value: 7

Page number = 229 Frame Number = 215 offset: 191 
Virtual address: 58815 Physical address: 55231 Value: 111

Page number = 136 Frame Number = 104 offset: 100 
Virtual address: 34916 Physical address: 26724 Value: 0

Page number = 14 Frame Number = 39 offset: 218 
Virtual address: 3802 Physical address: 10202 Value: 3

Found in TLB, page number = 226 correspond to frame = 12 
Page number = 226 Frame Number = 12 offset: 152 
Virtual address: 58008 Physical address: 3224 Value: 0

Page number = 4 Frame Number = 159 offset: 215 
Virtual address: 1239 Physical address: 40919 Value: 53

Page number = 249 Frame Number = 85 offset: 203 
Virtual address: 63947 Physical address: 21963 Value: 114

Page number = 1 Frame Number = 223 offset: 125 
Virtual address: 381 Physical address: 57213 Value: 0

Page number = 237 Frame Number = 92 offset: 62 
Virtual address: 60734 Physical address: 23614 Value: 59

Page number = 190 Frame Number = 128 offset: 129 
Virtual address: 48769 Physical address: 32897 Value: 0

Page number = 163 Frame Number = 151 offset: 210 
Virtual address: 41938 Physical address: 38866 Value: 40

Page number = 148 Frame Number = 145 offset: 137 
Virtual address: 38025 Physical address: 37257 Value: 0

Page number = 215 Frame Number = 20 offset: 59 
Virtual address: 55099 Physical address: 5179 Value: -50

Page number = 221 Frame Number = 52 offset: 115 
Virtual address: 56691 Physical address: 13427 Value: 92

Page number = 154 Frame Number = 169 offset: 106 
Virtual address: 39530 Physical address: 43370 Value: 38

Page number = 230 Frame Number = 58 offset: 123 
Virtual address: 59003 Physical address: 14971 Value: -98

Page number = 23 Frame Number = 36 offset: 141 
Virtual address: 6029 Physical address: 9357 Value: 0

Page number = 81 Frame Number = 152 offset: 184 
Virtual address: 20920 Physical address: 39096 Value: 0

Page number = 31 Frame Number = 132 offset: 141 
Virtual address: 8077 Physical address: 33933 Value: 0

Page number = 166 Frame Number = 81 offset: 137 
Virtual address: 42633 Physical address: 20873 Value: 0

Page number = 68 Frame Number = 160 offset: 35 
Virtual address: 17443 Physical address: 40995 Value: 8

Page number = 209 Frame Number = 3 offset: 66 
Virtual address: 53570 Physical address: 834 Value: 52

Page number = 89 Frame Number = 206 offset: 49 
Virtual address: 22833 Physical address: 52785 Value: 0

Page number = 14 Frame Number = 39 offset: 198 
Virtual address: 3782 Physical address: 10182 Value: 3

Page number = 186 Frame Number = 220 offset: 142 
Virtual address: 47758 Physical address: 56462 Value: 46

Page number = 86 Frame Number = 221 offset: 120 
Virtual address: 22136 Physical address: 56696 Value: 0

Page number = 87 Frame Number = 44 offset: 155 
Virtual address: 22427 Physical address: 11419 Value: -26

Page number = 93 Frame Number = 154 offset: 59 
Virtual address: 23867 Physical address: 39483 Value: 78

Page number = 234 Frame Number = 41 offset: 64 
Virtual address: 59968 Physical address: 10560 Value: 0

Page Fault! Obtaining page from disk and assigning to frame 243
Page number = 242 Frame Number = 243 offset: 214 
Virtual address: 62166 Physical address: 62422 Value: 60

Page number = 27 Frame Number = 103 offset: 60 
Virtual address: 6972 Physical address: 26428 Value: 0

Page number = 248 Frame Number = 110 offset: 196 
Virtual address: 63684 Physical address: 28356 Value: 0

Page number = 181 Frame Number = 196 offset: 52 
Virtual address: 46388 Physical address: 50228 Value: 0

Page number = 163 Frame Number = 151 offset: 214 
Virtual address: 41942 Physical address: 38870 Value: 40

Page number = 142 Frame Number = 56 offset: 172 
Virtual address: 36524 Physical address: 14508 Value: 0

Page number = 36 Frame Number = 89 offset: 107 
Virtual address: 9323 Physical address: 22891 Value: 26

Page number = 121 Frame Number = 242 offset: 138 
Virtual address: 31114 Physical address: 62090 Value: 30

Page number = 87 Frame Number = 44 offset: 73 
Virtual address: 22345 Physical address: 11337 Value: 0

Page number = 181 Frame Number = 196 offset: 127 
Virtual address: 46463 Physical address: 50303 Value: 95

Page number = 213 Frame Number = 190 offset: 143 
Virtual address: 54671 Physical address: 48783 Value: 99

Page number = 35 Frame Number = 188 offset: 254 
Virtual address: 9214 Physical address: 48382 Value: 8

Page number = 28 Frame Number = 168 offset: 89 
Virtual address: 7257 Physical address: 43097 Value: 0

Page number = 129 Frame Number = 209 offset: 126 
Virtual address: 33150 Physical address: 53630 Value: 32

Page number = 162 Frame Number = 163 offset: 93 
Virtual address: 41565 Physical address: 41821 Value: 0

Page number = 102 Frame Number = 192 offset: 102 
Virtual address: 26214 Physical address: 49254 Value: 25

Page number = 14 Frame Number = 39 offset: 11 
Virtual address: 3595 Physical address: 9995 Value: -126

Page number = 70 Frame Number = 73 offset: 12 
Virtual address: 17932 Physical address: 18700 Value: 0

Page number = 135 Frame Number = 70 offset: 100 
Virtual address: 34660 Physical address: 18020 Value: 0

Page number = 202 Frame Number = 106 offset: 249 
Virtual address: 51961 Physical address: 27385 Value: 0

Page number = 229 Frame Number = 215 offset: 10 
Virtual address: 58634 Physical address: 55050 Value: 57

Found in TLB, page number = 226 correspond to frame = 12 
Page number = 226 Frame Number = 12 offset: 134 
Virtual address: 57990 Physical address: 3206 Value: 0

Page number = 112 Frame Number = 5 offset: 176 
Virtual address: 28848 Physical address: 1456 Value: 0

Page number = 195 Frame Number = 231 offset: 0 
Virtual address: 49920 Physical address: 59136 Value: 0

Found in TLB, page number = 71 correspond to frame = 9 
Page number = 71 Frame Number = 9 offset: 175 
Virtual address: 18351 Physical address: 2479 Value: 0

Page number = 209 Frame Number = 3 offset: 165 
Virtual address: 53669 Physical address: 933 Value: 0

Page number = 132 Frame Number = 164 offset: 204 
Virtual address: 33996 Physical address: 42188 Value: 0

Page number = 26 Frame Number = 26 offset: 85 
Virtual address: 6741 Physical address: 6741 Value: 0

Page number = 250 Frame Number = 17 offset: 98 
Virtual address: 64098 Physical address: 4450 Value: 62

Page number = 2 Frame Number = 67 offset: 94 
Virtual address: 606 Physical address: 17246 Value: 0

Page number = 106 Frame Number = 112 offset: 247 
Virtual address: 27383 Physical address: 28919 Value: -67

Page number = 246 Frame Number = 86 offset: 164 
Virtual address: 63140 Physical address: 22180 Value: 0

Page number = 125 Frame Number = 194 offset: 228 
Virtual address: 32228 Physical address: 49892 Value: 0

Page number = 247 Frame Number = 66 offset: 205 
Virtual address: 63437 Physical address: 17101 Value: 0

Page number = 113 Frame Number = 64 offset: 157 
Virtual address: 29085 Physical address: 16541 Value: 0

Page number = 254 Frame Number = 189 offset: 56 
Virtual address: 65080 Physical address: 48440 Value: 0

Page number = 151 Frame Number = 183 offset: 97 
Virtual address: 38753 Physical address: 46945 Value: 0

Page number = 62 Frame Number = 82 offset: 169 
Virtual address: 16041 Physical address: 21161 Value: 0

Page number = 35 Frame Number = 188 offset: 81 
Virtual address: 9041 Physical address: 48209 Value: 0

Page number = 164 Frame Number = 180 offset: 106 
Virtual address: 42090 Physical address: 46186 Value: 41

Page number = 181 Frame Number = 196 offset: 52 
Virtual address: 46388 Physical address: 50228 Value: 0

Page number = 248 Frame Number = 110 offset: 162 
Virtual address: 63650 Physical address: 28322 Value: 62

Page number = 143 Frame Number = 139 offset: 28 
Virtual address: 36636 Physical address: 35612 Value: 0

Page number = 85 Frame Number = 94 offset: 187 
Virtual address: 21947 Physical address: 24251 Value: 110

Page number = 77 Frame Number = 142 offset: 121 
Virtual address: 19833 Physical address: 36473 Value: 0

Page number = 142 Frame Number = 56 offset: 112 
Virtual address: 36464 Physical address: 14448 Value: 0

Page number = 33 Frame Number = 78 offset: 93 
Virtual address: 8541 Physical address: 20061 Value: 0

Page number = 49 Frame Number = 121 offset: 168 
Virtual address: 12712 Physical address: 31144 Value: 0

Page number = 191 Frame Number = 197 offset: 59 
Virtual address: 48955 Physical address: 50491 Value: -50

Page number = 153 Frame Number = 217 offset: 38 
Virtual address: 39206 Physical address: 55590 Value: 38

Page number = 60 Frame Number = 124 offset: 218 
Virtual address: 15578 Physical address: 31962 Value: 15

Page number = 192 Frame Number = 33 offset: 53 
Virtual address: 49205 Physical address: 8501 Value: 0

Page number = 30 Frame Number = 226 offset: 51 
Virtual address: 7731 Physical address: 57907 Value: -116

Page number = 168 Frame Number = 68 offset: 38 
Virtual address: 43046 Physical address: 17446 Value: 42

Page number = 236 Frame Number = 28 offset: 82 
Virtual address: 60498 Physical address: 7250 Value: 59

Page number = 36 Frame Number = 89 offset: 21 
Virtual address: 9237 Physical address: 22805 Value: 0

Page number = 186 Frame Number = 220 offset: 90 
Virtual address: 47706 Physical address: 56410 Value: 46

Page number = 171 Frame Number = 224 offset: 197 
Virtual address: 43973 Physical address: 57541 Value: 0

Page number = 164 Frame Number = 180 offset: 24 
Virtual address: 42008 Physical address: 46104 Value: 0

Page number = 107 Frame Number = 61 offset: 68 
Virtual address: 27460 Physical address: 15684 Value: 0

Page number = 97 Frame Number = 205 offset: 167 
Virtual address: 24999 Physical address: 52647 Value: 105

Page number = 202 Frame Number = 106 offset: 221 
Virtual address: 51933 Physical address: 27357 Value: 0

Page number = 133 Frame Number = 238 offset: 22 
Virtual address: 34070 Physical address: 60950 Value: 33

Page number = 254 Frame Number = 189 offset: 131 
Virtual address: 65155 Physical address: 48515 Value: -96

Page number = 234 Frame Number = 41 offset: 51 
Virtual address: 59955 Physical address: 10547 Value: -116

Page number = 36 Frame Number = 89 offset: 61 
Virtual address: 9277 Physical address: 22845 Value: 0

Page number = 79 Frame Number = 65 offset: 196 
Virtual address: 20420 Physical address: 16836 Value: 0

Page number = 175 Frame Number = 51 offset: 60 
Virtual address: 44860 Physical address: 13116 Value: 0

Page number = 199 Frame Number = 167 offset: 48 
Virtual address: 50992 Physical address: 42800 Value: 0

Page number = 41 Frame Number = 107 offset: 87 
Virtual address: 10583 Physical address: 27479 Value: 85

Page number = 225 Frame Number = 239 offset: 151 
Virtual address: 57751 Physical address: 61335 Value: 101

Page number = 90 Frame Number = 140 offset: 155 
Virtual address: 23195 Physical address: 35995 Value: -90

Page number = 106 Frame Number = 112 offset: 91 
Virtual address: 27227 Physical address: 28763 Value: -106

Page number = 167 Frame Number = 76 offset: 64 
Virtual address: 42816 Physical address: 19520 Value: 0

Page number = 227 Frame Number = 133 offset: 107 
Virtual address: 58219 Physical address: 34155 Value: -38

Page number = 146 Frame Number = 83 offset: 230 
Virtual address: 37606 Physical address: 21478 Value: 36

Found in TLB, page number = 71 correspond to frame = 9 
Page number = 71 Frame Number = 9 offset: 250 
Virtual address: 18426 Physical address: 2554 Value: 0

Page number = 82 Frame Number = 147 offset: 246 
Virtual address: 21238 Physical address: 37878 Value: 20

Page number = 46 Frame Number = 233 offset: 207 
Virtual address: 11983 Physical address: 59855 Value: -77

Found in TLB, page number = 189 correspond to frame = 7 
Page number = 189 Frame Number = 7 offset: 10 
Virtual address: 48394 Physical address: 1802 Value: 0

Page number = 43 Frame Number = 156 offset: 28 
Virtual address: 11036 Physical address: 39964 Value: 0

Page number = 119 Frame Number = 63 offset: 93 
Virtual address: 30557 Physical address: 16221 Value: 0

Page number = 91 Frame Number = 80 offset: 157 
Virtual address: 23453 Physical address: 20637 Value: 0

Page number = 194 Frame Number = 123 offset: 183 
Virtual address: 49847 Physical address: 31671 Value: -83

Page number = 117 Frame Number = 2 offset: 80 
Virtual address: 30032 Physical address: 592 Value: 0

Page number = 187 Frame Number = 100 offset: 193 
Virtual address: 48065 Physical address: 25793 Value: 0

Page number = 27 Frame Number = 103 offset: 45 
Virtual address: 6957 Physical address: 26413 Value: 0

Page number = 8 Frame Number = 137 offset: 253 
Virtual address: 2301 Physical address: 35325 Value: 0

Page number = 30 Frame Number = 226 offset: 56 
Virtual address: 7736 Physical address: 57912 Value: 0

Page number = 122 Frame Number = 91 offset: 28 
Virtual address: 31260 Physical address: 23324 Value: 0

Page number = 66 Frame Number = 0 offset: 175 
Virtual address: 17071 Physical address: 175 Value: -85

Page number = 34 Frame Number = 181 offset: 236 
Virtual address: 8940 Physical address: 46572 Value: 0

Page number = 38 Frame Number = 174 offset: 201 
Virtual address: 9929 Physical address: 44745 Value: 0

Page number = 177 Frame Number = 179 offset: 251 
Virtual address: 45563 Physical address: 46075 Value: 126

Found in TLB, page number = 47 correspond to frame = 10 
Page number = 47 Frame Number = 10 offset: 75 
Virtual address: 12107 Physical address: 2635 Value: 0

Number of page faults = 244
Number of TLB Hits = 60
```

## Built With

* [GCC](https://gcc.gnu.org/) - The GNU Compiler Collection
* [Ubuntu 16.04 LTS](releases.ubuntu.com/16.04/) - Xenial Xerus

## Authors

* **Mohamed Elsayed** - [Github](https://github.com/mohamedelsayed95)
* **Ahmed Wael** - [Github](https://github.com/ahmedwael19)

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.
