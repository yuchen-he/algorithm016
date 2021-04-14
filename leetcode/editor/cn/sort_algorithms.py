"""
Implementations for some basic sort algorithms
"""
import numpy as np


class MySort:
    def __init__(self, array_orig, method):
        self.array = array_orig
        self.method = method
        self.method_list = ["selection", "bubble", "insertion", "quick", "merge", "heap"]

    def runSort(self):
        if self.method not in self.method_list:
            raise KeyError("{} is not supported in {}.".format(self.method, self.method_list))
        else:
            if self.method == "selection":
                self.selectionSort()
            elif self.method == "bubble":
                self.bubbleSort()
            elif self.method == "insertion":
                self.insertionSort()
            elif self.method == "quick":
                self.quickSort(begin_id=0, end_id=len(self.array) - 1)
            elif self.method == "merge":
                self.mergeSort(begin_id=0, end_id=len(self.array) - 1)
            elif self.method == "heap":
                self.heapSort()
            else:
                return 0
            self.checkArray()
            return self.array

    def checkArray(self):
        for i in range(len(self.array) - 1):
            if self.array[i] > self.array[i + 1]:
                print("Checking sorted array...False")
                return
        print("Checking sorted array...True")

    def selectionSort(self):
        array_len = len(self.array)
        for i in range(array_len - 1):  # 代表要插入的位置
            min_index = i
            for j in range(i + 1, array_len):
                if self.array[j] < self.array[min_index]:
                    min_index = j
            self.array[i], self.array[min_index] = self.array[min_index], self.array[i]

    def bubbleSort(self):
        array_len = len(self.array)
        for i in range(array_len - 1):   # i = 筛选的遍数
            for j in range(array_len - 1 - i):
                if self.array[j] > self.array[j + 1]:
                    self.array[j], self.array[j + 1] = self.array[j + 1], self.array[j]

    def insertionSort(self):
        array_len = len(self.array)
        for i in range(1, array_len):
            insert_elem = self.array[i]
            j = i - 1
            # while j >= 0:
            #     if insert_elem < self.array[j]:
            #         self.array[j+1], self.array[j] = self.array[j], insert_elem
            #         j -= 1
            #     else:
            #         break

            # 更优写法
            while j >= 0 and self.array[j] > insert_elem:
                self.array[j + 1] = self.array[j]  # 要点: 不能等到最后来插入，那样又多一次O(N)
                j -= 1
            self.array[j + 1] = insert_elem

    def partition(self, begin_id, end_id):
        """pivot at end"""
        pivot, counter = end_id, begin_id + 0
        for i in range(begin_id, end_id):
            # 循环过程中，pivot位置的元素作为一个参照物不变，把其他比他大/小的数分成两边。
            # 循环之后，counter就是第一个比pivot大的数的位置了，与pivot处的位置的元素调换，即可让counter位置的元素为中间值
            if self.array[i] < self.array[pivot]:
                self.array[i], self.array[counter] = self.array[counter], self.array[i]
                counter += 1
        self.array[pivot], self.array[counter] = self.array[counter], self.array[pivot]
        return counter

    def _partition(self, begin_id, end_id):
        """pivot at begin"""
        pivot = counter = begin_id
        for i in range(begin_id + 1, end_id + 1):
            if self.array[i] < self.array[pivot]:
                # 因为counter最开始与pivot同位置，所以循环当中要调换的时候需要先把counter++
                counter += 1
                self.array[i], self.array[counter] = self.array[counter], self.array[i]
        # 循环过后，counter是最后一个小于pivot元素的位置（与pivot at end不同）
        self.array[pivot], self.array[counter] = self.array[counter], self.array[pivot]
        return counter

    def quickSort(self, begin_id=0, end_id=0):
        """不要忘记这个terminator"""
        if begin_id >= end_id:
            return

        pivot = self.partition(begin_id, end_id)
        self.quickSort(begin_id, pivot - 1)
        self.quickSort(pivot + 1, end_id)

    def merge(self, begin_id, mid_id, end_id):
        """
        temp: 额外空间的数组（归并排序必须用到）
        left:  (begin_id, mid_id)
        right: (mid_id+1, end_id)
        i: 遍历左边
        j: 遍历右边
        """
        temp = [0] * (end_id - begin_id + 1)
        i, j, k = begin_id, mid_id + 1, 0

        # 任何合并两个序列的题目，都需要3个while循环（e.g. [21]合并两个有序链表）
        while i <= mid_id and j <= end_id:
            # C++可以用这一句完成
            # temp[k++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];
            if self.array[i] <= self.array[j]:
                temp[k] = self.array[i]
                i += 1
            else:
                temp[k] = self.array[j]
                j += 1
            k += 1

        # 上面循环之后，肯定有一边数组全部放入了temp中。所以要把另外一边的数组全部放到temp后边。
        while i <= mid_id:
            temp[k] = self.array[i]
            i += 1
            k += 1
        while j <= end_id:
            temp[k] = self.array[j]
            j += 1
            k += 1

        # 把temp复制到self.array中去
        self.array[begin_id:end_id + 1] = temp

    def mergeSort(self, begin_id=0, end_id=0):
        if begin_id >= end_id:
            return

        # 位运算更快，相当于(a+b)//2
        mid = (begin_id + end_id) >> 1

        # 在任一当前层逻辑中，假定mergeSort可以把两边都排序好
        self.mergeSort(begin_id, mid)
        self.mergeSort(mid + 1, end_id)
        # 然后把排序好的两边merge到一起
        self.merge(begin_id, mid, end_id)

    def _heapifyDown(self, parent, end):
        """end是向下调整过程的终点位置(且不包含end)。
        end位置之后的元素不作调整。
        """
        left_child, right_child = 2 * parent + 1, 2 * parent + 2
        largest = parent

        # 找到parent和左右孩子中的最大元素的位置
        if left_child < end and self.array[left_child] > self.array[largest]:
            largest = left_child
        if right_child < end and self.array[right_child] > self.array[largest]:
            largest = right_child

        # 如果largest就是parent，说明这棵树（包括下层的子树，因为heapSort是从最后一个非叶子节点开始的）全都排序好了
        if largest != parent:
            # 把最大的元素放到parent的位置
            self.array[largest], self.array[parent] = self.array[parent], self.array[largest]

            # 关键点: 然后以刚才最大的元素所在位置为parent，递归下去（因为这个位置的值变了，所以要确认下面的子树是否合法）
            self._heapifyDown(largest, end)

    def heapifyDown(self, parent, length):
        """_heapifyDown的版本更容易理解"""
        # temp保存父节点值, 用于最后的赋值
        temp = self.array[parent]
        # 先把child设为左孩子
        child = 2 * parent + 1

        # 对于有多层子树的parent，这个while循环能保证从该parent一直heapify下探调整到最底层的叶子节点
        while child < length:
            # 找到两个孩子中的更大值
            # 如果有右孩子, 且右孩子小于左孩子的值，则定位到右孩子 (右孩子是2i+2，所以是当前child+1)
            if child + 1 < length and self.array[child + 1] > self.array[child]:
                child = child + 1

            # 如果父节点大于任何一个孩子的值，则直接跳出（因为说明这棵小树已经满足大顶堆了）
            if self.array[parent] >= self.array[child]:
                break

            # 如果父节点小于最大的孩子，则把最大孩子对应的元素赋值给父节点所在位置
            self.array[parent] = self.array[child]

            # 把parent定位到更大的那个子节点处
            # Todo: 为什么这里不改变child位置的元素（改为temp），这样while循环下去的话parent节点的值不就不对了嘛？
            parent = child

            # 定位到更大的那个子节点的左孩子，继续heapifyDown
            child = 2 * parent + 1

        # 把保存的temp赋值到刚才更大的那个子节点处（因为它的元素已经被赋值到最开始的parent了。继承皇位了。）
        self.array[parent] = temp

    def heapSort(self):
        # 建立大顶堆
        length = len(self.array)
        for i in range((length - 2) // 2, -1, -1):     # (length-1)是最后一个节点位置，(length-1-1)//2是求其父节点位置
            # 先假定当前array是一个待调整的大顶堆。
            # 从最后一个非叶子节点开始，依次做heapifyDown调整
            self._heapifyDown(i, length)

        # 1. 每次把堆顶（最大元素）和j对换，此时j之前的堆无序，j与j之后的数组元素有序
        # 2. 之后调整j之前的堆
        for j in range(length - 1, 0, -1):
            # 把堆顶（即最大元素）与当前j的位置的元素对换，j-1即是剩余元素中的最大值应插入的位置
            self.array[j], self.array[0] = self.array[0], self.array[j]

            # 从堆顶向下调整，并且只调整到j-1（因为j及j之后是已经排序好了的）
            self._heapifyDown(0, j)


random_array = np.random.randint(0, 100, 10).tolist()
print("Before: ", random_array)

method_list = ["selection", "bubble", "insertion", "quick", "merge", "heap"]
sort_method = method_list[5]
print("Using {} sort...".format(sort_method))
ms = MySort(random_array, sort_method)
print("After : ", ms.runSort())
