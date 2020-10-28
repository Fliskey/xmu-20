# XML

## 期中考试

2020年11月5日

实验课78节

XML DTD Schema 



## 3.Schema

和DTD一样，是约束文档。可有无数XML实例

#### 3.4.2 命名空间

##### 用于指定Schema

 ```xsi:noNamespaceSchemaLocation ```

```xml
<NAME xmlns:xsi="xxx" xsi:noNamespaceSchemaLocation="xx.xsd">
</NAME>
```

##### 缺省命名空间(Schema)

```xmlns=```

```xml
<xsd:schema xmlns:xsd=“http://www.w3.org/2001/XMLSchema” 
            targetNamespace="http://www.xml.com" 
            xmlns="http://www.xml.com">

</xsd:schema>
```

##### 缺省命名空间(XML)

`xmlns=`

```xml
<root xmlns="http://www.xml.com" 
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"          
         xsi:schemaLocation="http://www.xml.com  http://somesite/somexsd.xsd">
......
</root>
```

##### elementFormDefault与attributeFormDefault

##### 例子

```xml
<?xml version="1.0" encoding="UTF-8"?>
<xsd:schema xmlns:xsd="http://www.w3.org/2001/XMLSchema"  targetNamespace="ts"
elementFormDefault="unqualified" attributeFormDefault="qualified">
    <xsd:element name="root">
        <xsd:complexType>（它在ts命名空间下）
            <xsd:sequence>(局部元素，unqualified，无命名空间)
                <xsd:element name="element_a" type="xsd:string"/>
                <xsd:element name="element_b" type="xsd:integer"/>
            </xsd:sequence>
            <xsd:attribute name="att" type="xsd:string"/>（不区分全局局部，全部属性都在ts命名空间下）
        </xsd:complexType>
    </xsd:element>
</xsd:schema> 

<n1:root n1:att="String" xsi:schemaLocation="ts correct.xsd" 
xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:n1="ts">
    <element_a>String</element_a>
    <element_b>0</element_b>
</n1:root> 
```

3.4.3 导入其他Schema



---

## 4.XPath

是一种路径表达语言，实现数据操作，需要有DOM树结构，PSVI，已配上XML类型。

XQuery（类比SQL）、XPointer（简单封装）、XLink（类比超链接，功能更广）需要用到XPath

### 4.1数据模型：序列

Unix：任何东西是文件

Java、C++：任何东西都是对象

XPath：任何值都是一个序列



#### 序列 Sequence

XPath2.0引进

有序的，可重复（节点和原子值）

position：确定当前项位置

count($S)：计算序列中项的个数，第一项位置为1

$S[i]：访问序列中的第i项



#### 序列计算表达式

序列是用()包含的一个列表，用“，”分隔

- 构造表达式
  - 直接构造
  - 空序列
  - 原子节点混合
  - 忽略空序列
  - to

- 筛选表达式
  - 值的条件筛选
  - 位置条件筛选

- 组合表达式
  - 并
  - 交
  - 差



#### 文档树模型

- 文档节点
- 元素节点（以下均可对应到XML）
  - 根元素之上再加一个节点作为文档节点
- 属性节点
- 文本节点
- 命名空间节点
- 处理指令节点
- 注释节点

例

```xml
<doc>
<?Pub Caret?>
<para>Some <em>emphasis</em> here. </para>
<para>Some more stuff.</para>
</doc> 
```



#### 节点的名称

 node-name()函数

- 对元素节点：返回元素标记（名称）
- 对属性、处理指令节点：返回名称
- 对命名空间节点：返回命名空间前缀
- 对文档节点、注释节点、文本节点：返回空序列



#### 节点的字符串值

 string()函数

- 对文本节点：文本内容
- 对属性节点：属性取值
- 对元素节点：以该节点为根的子树，所有文本叶节点从左到右串联起来的结果



#### 节点的标识

用 is 操作符比较两节点是否为同一个节点（同一位置）



### 4.2 XPath的语法

#### 路径对比

操作系统中的路径与 XPath 路径表达式的类比：

| 在操作系统中                                                 | 在  XPath  中                                                |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| /   表示根目录；                                             | /   表示文档节点；  /library 表示根元素；                    |
| 绝对路径表示形式 <br />/users/dir/foo  表示 users  目录下  dir 目录中的 foo  文件，只能有一个。 | /library/book/chapter/section 表示 library 元素下的 book  元素下的  chapter  元素下的所有  section，可以有多个。 |
| 相对路径表示形式<br />  foo 表示当前目录下的 foo  文件，只能有一个 | section 表示当前元素的所有 section  子元素，可以有多个。     |
| .  表示当前目录。                                            | .  表示当前元素。                                            |
| .. 表示父目录。                                              | .. 表示父元素。                                              |
| /users/dave/\* 表示 /users/dave 目录中的所有文件。           | /library/book/chapter/\* 表示: <br /><u>/library/book/chapter</u> 下的所有元素。<br /><br />//表示当前节点下的所有元素；<br /> //section 表示当前文档中的所有 section  元素。 |

#### 完整语法形式

##### 绝对路径表达式

以/开头，后跟相对路径表达式

##### 相对路径表达式

由多个步进(Step)构成

如Step1/Step2/Step3

- 递归定义

```
LocationPath ::= RelativeLocationPath | AbsoluteLocationPath (1)
RelativeLocationPath ::= Step | RelativeLocationPath '/' Step | AbbrevRelativeLocationPath (2)
AbsoluteLocationPath ::= '/’ RelativeLocationPath? | AbbrevAbsoluteLocationPath (3) 
```

##### Step

- 轴标识符（AxisSpecifier）
  - 相对当前节点查找的方向
  - 关系轴标识符**（上到这）**
- 节点测试（NodeTest）
  - 名字测试/类型测试
- 判定谓词（Predicate）