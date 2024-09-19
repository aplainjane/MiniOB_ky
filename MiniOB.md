![image-20240916203955998](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20240916203955998.png)

parser: 将sql语句转化为语法树（语法解析

plan cache: 目前不做处理

resolver: 进一步细化 将语句对应对象指出来

transformer optimizer: 低成本找最优方案（优化

transformer: 将条件规则优化（将过于简单的语法删除

optimizer: 根据具体表索引或遍历来寻找最佳寻找路径进行优化

executor: 执行模块

存储结构： 使用记录 缓存 B+树



![image-20240916204012244](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20240916204012244.png)

存储结构



首部头字节 数据块从后开始存

分片存储

blob（大文件 不同磁盘提高访问效率

行、列存储



记录修改：

找空闲块

插入块的空闲位置

维护offset



记录删除：

在头部信息打上删除标记（定期删除



记录修改：

定长，简单覆盖

变长，先打删除标记，再插入修改后的的记录在新的位置





MiniOB文件管理![image-20240917200557124](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20240917200557124.png)



MiniOB添加功能函数

1. stmt.cpp(statement-transform)

   1. case里面包含了实现语义的函数转化（SCF_DROP_TABLE)
   2. 在stmt文件夹下找到你要实现的对应函数，新增cpp、hpp

2. 执行阶段

   1. command_executor(stmt-type)
   2. 头文件包含，在executor文件夹下进行补充

3. 进入db

   1. 添加RC（resolve create）
   2. 在table，create_table创建了一个元信息存储文件、数据文件对record_handler做了初始化
   3. 在drop最后清空record_handler、index

4. 进入bufferpoolmanager（bpm）

   1. 对RC进行添加函数	

5. 进入index函数

   1. 再进入b+树进行覆盖全虚函数
   2. 然后依次修改buffer文件夹下的各个文件（disk_buffer_pool）

   