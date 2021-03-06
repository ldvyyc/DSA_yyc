# A×B_Problem解题报告

#### 于雨琛  2020011846  经02-计08



### 一. 所使用数据结构与算法的构思、原理和实现要点。

本题是一道长整数乘法的问题，最终的程序采用了提升进制的方式，采用了100000000进制的形式。首先使用string读入数据，之后使用stoi()每8位转化为long long，每一位使用一个long long数组的一位来存储，long long最多允许大于16位的数据，因此不会造成溢出。之后按照对应项的乘法逐位相乘，若超过8位则进位，并在最后特判是否为0的情况。

本题原理是提升进制，并使用数组的每一位来代替进制中的每一位，首先判断当两者长度均小于9时直接输出结果；否则先将数据转化为long long记录到数组中，再按照传统的两整数乘法的方式迭代一遍，之后再进行一次进位的判断。

实现要点：合理选取进制是这种方法最重要的点，由于int型可以完整存储8位，long long可以完整存储16位，因此要选用最多8进制可以满足内存限制，且时间复杂度最低。

### 完成过程中遇到的问题，排除问题的主要过程、使用的方法和技巧，以及参考资料。

首先是数据结构的组织，开始时通过学习Python长整数乘法的Karatsuba方式，后来发现还需要将十进制转化成二进制，且对于不同长度的数据需要不同处理，因此改为直接修改进制。之后还遇到过几个关键问题，包括没有填充0，这样会导致结果中没有0，通过每次判断长度是否为8，若不是则补0来修改；未进行输出为0的特判，在有一个输入为0时会输出空串，通过对输出长度进行特判解决。最后，在cout时设置ios::sync_with_stdio(false); 加快输出速度。

参考资料：助教习题课。

### 三. 时间和空间复杂度的估算。

在操作上，需要做一次对应位置的乘法，这一步需要n^2/64的时间复杂度，之后还需要O(n)的时间完善进位，与O(n)的时间输出。整体上是O(n^2)的复杂度，但可以通过进制的切换将常数控制在1/64，能够满足题目要求。

空间上需要四个数组，每个数组存储均为输入数据，因此空间复杂度为O(n)。