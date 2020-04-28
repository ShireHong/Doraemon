C++ STL中最基本以及最常用的类或容器无非就是以下几个：
•string
•vector
•deque
•list
•forward_list
•queue
•priority_queue
•stack

# ifstream   ofstream

对文件进行读写操作首先必须要定义一个数据流对象指针，数据流对象指针有三种类型，它们分别是：
Ifstream：表示读取文件流，使用的时候必须包含头文件“ifstream”；
ofstream：表示文件写入流，使用的时候必须包含头文件“ofstream”；
fstream：表示文件读取/写入流，使用的时候必须包含头文件“fstream”；

ofstream是从内存到硬盘，ifstream是从硬盘到内存


##string c_str:
c_str()函数返回一个指向正规C字符串的指针常量, 内容与本string串相同。这是为了与c语言兼容，在c语言中没有string类型，故必须通过string类对象的成员函数c_str()把string 对象转换成c中的字符串样式。
注意：一定要使用strcpy()函数 等来操作方法c_str()返回的指针。

#c++成员函数后面加const
这个const指明了这个函数不会修改该类的任何成员数据的值，称为常量成员函数。

#explicit
禁止编译器执行非预期的类型转换，要求使用者按照规则使用构造函数。