# STL 数据结构



| 数据结构       | 底层实现                                                     | 特点                                           |
| -------------- | ------------------------------------------------------------ | ---------------------------------------------- |
| vector         | 底层数据结构为数组。                                         | 支持快速随机访问。                             |
| list           | 底层数据结构为双向链表。                                     | 支持快速增删。                                 |
| deque          | 底层数据结构为一个中央控制器和多个缓冲区。                   | 支持首尾（中间不能）快速增删，也支持随机访问。 |
| stack          | 底层一般用 list 和 deque 实现，封闭头部即可，不用 vector 的原因应该是容量大小有限制。 | 扩容耗时。                                     |
| queue          | 底层一般用 list 和 deque 实现，封闭头部即可，不用 vector 的原因应该是容量大小有限制。 | 扩容耗时。                                     |
| priority_queue | 底层数据结构一般为 vector 为底层容器。                       | 堆 heap 为处理规则来管理底层容器实现。         |
| set            | 底层数据结构为红黑树。                                       | 有序，不重复。                                 |
| multiset       | 底层数据结构为红黑树。                                       | 有序，不重复。                                 |
| map            | 底层数据结构为红黑树。                                       | 有序，不重复。                                 |
| multimap       | 底层数据结构为红黑树。                                       | 有序，不重复。                                 |
| hash_set       | 底层数据结构为 hash 表。                                     | 无序，不重复。                                 |
| hash_multiset  | 底层数据结构为 hash 表。                                     | 无序，不重复。                                 |
| hash_map       | 底层数据结构为 hash 表。                                     | 无序，不重复。                                 |
| hash_multimap  | 底层数据结构为 hash 表。                                     | 无序，不重复。                                 |