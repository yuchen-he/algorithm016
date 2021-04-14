# 运用你所掌握的数据结构，设计和实现一个 LRU (最近最少使用) 缓存机制 。 
# 
#  
#  
#  实现 LRUCache 类： 
# 
#  
#  LRUCache(int capacity) 以正整数作为容量 capacity 初始化 LRU 缓存 
#  int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。 
#  void put(int key, int value) 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字-值」。当缓存容量达到上
# 限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。 
#  
# 
#  
#  
#  
# 
#  进阶：你是否可以在 O(1) 时间复杂度内完成这两种操作？ 
# 
#  
# 
#  示例： 
# 
#  
# 输入
# ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
# [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
# 输出
# [null, null, null, 1, null, -1, null, -1, 3, 4]
# 
# 解释
# LRUCache lRUCache = new LRUCache(2);
# lRUCache.put(1, 1); // 缓存是 {1=1}
# lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
# lRUCache.get(1);    // 返回 1
# lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
# lRUCache.get(2);    // 返回 -1 (未找到)
# lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
# lRUCache.get(1);    // 返回 -1 (未找到)
# lRUCache.get(3);    // 返回 3
# lRUCache.get(4);    // 返回 4
#  
# 
#  
# 
#  提示： 
# 
#  
#  1 <= capacity <= 3000 
#  0 <= key <= 3000 
#  0 <= value <= 104 
#  最多调用 3 * 104 次 get 和 put 
#  
#  Related Topics 设计 
#  👍 1209 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
class DLinkedNode:
    def __init__(self, key = 0, value = 0):
        self.key = key
        self.value = value
        self.prev = None
        self.next = None

class DoubleLinkedList:
    """这个才是真正操作LRUCache这个数据结构的地方
    必须要有dummy的head/tail，否则addFirst和removeLast不好实现"""
    def __init__(self):
        self.dummy_head = DLinkedNode(-1, -1)           # 双向链表中要有dummy的头/尾节点，以便添加与删除其他节点
        self.dummy_tail = DLinkedNode(-1, -1)
        self.dummy_head.next = self.dummy_tail          # 初始化时，两个dummy需要互相连接，以便添加与删除其他节点
        self.dummy_tail.prev = self.dummy_head
        self.size = 0

    def addFirst(self, node: DLinkedNode):
        """node已经拥有key和value（在get方法里面提前赋值了），这里只需要补充它的前驱/后继节点"""
        cur_first = self.dummy_head.next                # dummy_head的next有可能是已添加的其他node
        node.prev = self.dummy_head
        node.next = cur_first
        self.dummy_head.next = node
        cur_first.prev = node

        self.size += 1

    def removeLast(self):
        """把dummy_tail之前的那个节点last删除，然后与last.prev相连"""
        last_node = self.dummy_tail.prev
        last_node_prev = last_node.prev
        last_node_prev.next = self.dummy_tail
        self.dummy_tail.prev = last_node_prev

        self.size -= 1
        return last_node

    def removeNode(self, node: DLinkedNode):
        """传入的节点已经是当前双链表中的某一节点了（包含前驱/后继的信息），所以把它删除，把它的前驱/后继连上即可"""
        prev = node.prev
        next = node.next
        prev.next = next
        next.prev = prev
        node.prev = None
        node.next = None

        self.size -= 1

    def getSize(self):
        return self.size

class LRUCache:
    """双向链表 + 哈希表 (官方题解做法: 也可以把DoubleLinkedList中的方法在本类中实现)
    <=> 最久未使用：进来地早，而且没被使用
    1. get
        1.1. 前提1: 每次get一个存在的key时，要把它放到最近使用的位置，防止由于进来地早被作废（因为这是recent use）
        1.2. 前提2: O(1)时间复杂度
        => 被访问的key可能在当前已添加的key中的任意位置 -> 需要用"链表"来完成O(1)的操作，并且要"双向链表"。因为在移动当前node时，单向链表无法找到前驱节点
        => 如果只用链表，那么查找某元素就会是O(N)复杂度 -> 需要用"哈希表"来完成O(1)的查找操作（key -> 链表中node的映射）
    2. put
        2.1. 前提1: 需要先判断key是否存在与当前数据结构中 -> 利用上面的"哈希表来查找"
                    如果在   -> 把value替换，并且把这个key对应的链表中的node提到链表头！！（先拷贝一份只含key/value的node，然后删除原节点，再再链表头增加新node）
                    如果不在 ->  判断cache是否已满，如果满了则需要先把链表尾的node删除！！
                                然后在链表头添加该node，并且在哈希表中添加该key到node的映射。
        2.3. 前提3: O(1)时间复杂度
    """

    def __init__(self, capacity: int):
        self.cache = DoubleLinkedList()                  # 定义一个双向链表的对象
        self.map = collections.defaultdict()             # 定义一个hash_map
        self.cap = capacity

    def get(self, key: int) -> int:
        if key not in self.map:
            return -1
        val = self.map[key].value                        # 在map中找到这个key对应的node，取得把它的val
        self.put(key, val)                               # 然后使用put方法把这个node提前（因为put中如果key存在，则会把对应节点复制一份，然后删掉原来的node，把新node添加到链表头）
        return val


    def put(self, key: int, value: int) -> None:
        new_node = DLinkedNode(key, value)
        if key in self.map:
            self.cache.removeNode(self.map[key])         # 关键点: 当存在这个key时，把key对应的原来node删掉，然后把有新val的key对应节点添加到链表头
            self.cache.addFirst(new_node)
            self.map[key] = new_node                     # 要等addFirst方法把new_node的前驱后继给设定好之后，再更新到map里面
        else:                                            # 要加入一个新节点
            if self.cache.getSize() == self.cap:
                last_node = self.cache.removeLast()      # 如果cache满了，先删除最后一个节点
                self.map.pop(last_node.key)              # 并且要在map中也把它删除掉！！！
            self.cache.addFirst(new_node)                # 然后再在链表头加入新节点即可
            self.map[key] = new_node                     # 并且要在map中也把它添加上！！！


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
# leetcode submit region end(Prohibit modification and deletion)
