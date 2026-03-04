#  cJSON核心数据结构图
## cJSON结构体内存布局表
| 字段名         | 初始化值 | 核心作用                     |
|----------------|----------|------------------------------|
| next           | NULL     | 指向同级下一个节点           |
| prev           | NULL     | 指向同级上一个节点           |
| child          | NULL     | 指向对象/数组的第一个子节点  |
| type           | 0        | 节点类型                     |
| valuestring    | NULL     | 存储字符串类型的值           |
| valueint       | 0        | 存储整数                     |
| valuedouble    | 0.0      | 统一存储所有数字             |
| string         | NULL     | 存储对象子节点的键名         |
# 根节点
根节点 (type: cJSON_Object)
├─ child 指针 → 指向name子节点
└─ name子节点
   ├─ string: "name"         // JSON的key
   ├─ type: cJSON_String     // 节点类型
   ├─ valuestring: "cJSON"   // JSON的value
   ├─ next: NULL             // 无下一级同级节点
   └─ prev: NULL             // 无上一级同级节点
flowchart TD
    A[输入JSON：{"name":"cJSON"}] --> B[skip_whitespace跳过空白]
    B --> C[创建根节点（Object）]
    C --> D[创建name子节点（String）]
    D --> E[根节点child指向name节点]
    E --> F[返回根节点（总入口）]
/**
 * @brief cJSON树状结构核心逻辑
 * 1. 根节点：JSON最顶层容器（Object/Array），单独作为总入口；
 * 2. 子节点：挂在根节点child指针下，存储具体key-value；
 * 3. 双向链表：同级子节点通过next/prev关联，层级通过child关联；
 */
cJSON *root = cJSON_Parse("{\"name\":\"cJSON\"}"); // 根节点是唯一返回值
