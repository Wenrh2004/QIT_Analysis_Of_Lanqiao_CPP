# Largest Rectangle area

## Description

给定n个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
求在该柱状图中，能够勾勒出来的矩形的最大面积。

---

## Input

输入一个非0整数n（n<1000)
在下一行输入n个整数表示矩形高度中间用逗号隔开(<1000)

---

## Output

矩形的最大面积

---

## Sample Input and Output

|     | Sample Input       | Sample Output |
|-----|--------------------|---------------|
| 1st | 6 <br> 2,1,5,6,2,3 | 10            |

---

## Analysis

很经典的单调栈问题，但是为了这道题不那么单调，写了一份 `DP` 的 [解法](largest_rectangle_area_dp.cpp)，有兴趣的可以看一下 

这道题目的数据处理算是一个比较罕见而且相对来讲比较复杂的部分，关于这部分希望大家多去看一下标准库中对输入函数的作用

**思路**

- **数据处理** 
  - 获取**第一行**，总数
    - 读入后，清除换行符 `\n`
  - 读入柱高，放入容器
    - 当读到 `,` 清除 `,`
- **计算最大矩形面积**
  - 创建一个 `stack`， 遍历 `heights` 的索引将 `height` 存入栈
  - 如果当前 `height` 小于栈顶元素的 `height`，将当前栈顶元素弹出，将当前 `height` 压入栈，得到当前最大面积即可

## [example](./largest_rectangle_area_stack.cpp)

## [explainer video](https://www.bilibili.com/video/BV1fz421R7QD/?vd_source=7653e6d91a76b6d1facaa378459d564f)
