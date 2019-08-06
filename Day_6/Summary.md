# 第六天总结

## 今日感想
唉，尝试听以下最低难度的联赛课（听说讲课的学长还是清北学堂的），然而第一题就睡着了，还闻到一股粽子香，我果然是个蒟蒻Orz  
于是一整天在勤勤恳恳写程序，上午复习了堆并学习了STL和VIM，下午复习并查集和树状数组。  
然而我太弱了，被提高组难度暴虐，只过了两道基础题（还看了题解）Orz  

---
## 竞赛技巧
### 关于STL
1. 优先队列   
```template <typename T, typename Container=std::vector<T>, typename Compare=std::less<T>> class priority_queue```  
性质：  
* 内部使用algorithm的heap()从小到大排序  
* 支持```push(),top(),pop(),size(),empty()```  
* 容器可以换成链表
2. 链表<list>
3. 模板定义```template <typename T> function/class```
4. ```greater<T>()```可以直接当作cmp函数
### 关于算法
1. 种类并查集：用于维护元素关系 -> ```[1-N]本身，[N-2N]猎物，[2N-3N]天敌...```
2. 该开始刷蓝题了
