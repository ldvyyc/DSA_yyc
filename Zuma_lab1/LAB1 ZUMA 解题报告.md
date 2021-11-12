# LAB1 ZUMA	解题报告



##### 经02-计08	于雨琛	2020011846

### 01：

错误类型：Runtime Error

错误原因：play(rank)函数递归调用在从0开始最前面的3个连消后，在char color = a.at(rank)语句，at(rank)返回string a[-1]，报错。

思路：构造最开始的三位连消。测例中初始情况AAB，在0处插入A后即为此情况。

### 02：

错误类型：Runtime Error

错误原因：play(rank)函数未特判全消情况。当全消时left=0=rank，下一次递归调用中char color = a.at(rank)返回string a[0]，报错。

思路：构造全消。测例中初始情况AABBA，在2处插入B后即为此情况。

### 03：

错误类型：Time Limit Exceeded 

错误原因：string插入需要自动扩容，且string操作数大，因此插入数据数量过大会导致超时。

思路：插入400000次数据，构造超时。

### 04：

错误类型：Wrong Answer

错误原因：play(rank)函数中判断连消长度错误，会多消除一位不相同字符，导致整串错误。

思路：构造连消情况，初始为AABBA，在2处插入B后即为此情况。

### 05：

错误类型：Wrong Answer

错误原因：读入过程中采用cin读入，当初始值为空时cin认为还没有输入，会将操作数读成初始数据。

思路：初始值为空即可。

### 06：

错误类型：Wrong Answer

错误原因：play函数中没有块重组过程，在插入中若当前块总长度超过4096，会从后向前将现有数据覆盖掉。

思路：构造将第一个块插入超过4096位数即可。

### 07：

错误类型：Wrong Answer

错误原因：play(rank)函数中的eliminated过程中在移动lfirst的过程中没有采用while判断，而是使用了if判断，这样如果前一个块此前已经被消为空，则当下不会继续判断再前面的块，即在这种情况下跨过当前块向前的连消会错误。

思路：构造第二个块消至0，此后第三个块与第一个块连消情况。

### 08：

错误类型：Wrong Answer

错误原因：play函数中的eliminated过程没有while(1)，即不能够连消。

思路：构造三位连消即可。测例中初始情况AABBA，在2处插入B后即为此情况。

### 09：

错误类型：Runtime Error

错误原因：play函数中eliminated过程中没有判断是否在同一个块中，当在同一个块中且不在边界上时，l.first不改变。if (l.first >= 0) {plen[l.first] = l.second + 1;}将plen[l.first]赋值成l.second+1，后续int len = plen[r.first] - r.second;中len变为负数。这样在p2a过程中，memcpy(&a[copied], p[i], plen[i]);因为plen[i]类型为size_t，是无符号类型，因此负数将变成一个非常大的正数，如此则memcpy超限（memcpy的最大值是unsigned int上限），出现segmentation fault。

思路：构造同一个块内不在边界时的消除情况。测例中初始情况ABBC，在1处插入B后即为此情况。

### 10：

错误类型：Wrong Answer

错误原因：play函数递在eliminated成立时for (int i = l.first; i < r.first; i++) plen[i] = 0;初始化i = l.first没有＋1，导致把前面的还没有空的块清空，多清空了一个块。

思路：构造第二个块消至0的情况，此时第一个块的长度也被清零，再进行比如第一个块与第三个块连消的情况即会出现错误。
