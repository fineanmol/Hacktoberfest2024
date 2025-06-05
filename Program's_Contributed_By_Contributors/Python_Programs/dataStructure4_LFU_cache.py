'''Design and implement a data structure for a Least Frequently Used (LFU) cache.
Implement the LFUCache class:
* LFUCache(int capacity) Initializes the object with the capacity of the data structure.
* int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
* void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.
To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with the smallest use counter is the least frequently used key.
When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use counter for a key in the cache is incremented either a get or put operation is called on it.
The functions get and put must each run in O(1) average time complexity.'''
from collections import defaultdict, OrderedDict

#https://leetcode.com/problems/lfu-cache/description/

class LFUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.key_to_value = {}
        self.key_to_count = {}
        self.count_to_keys = defaultdict(OrderedDict)
        self.min_count = 0

    def get(self, key: int) -> int:
        if key in self.key_to_value:
            count = self.key_to_count[key]
            value = self.key_to_value[key]

            self.key_to_count[key] += 1

            del self.count_to_keys[count][key]
            self.count_to_keys[count + 1][key] = None

            if not self.count_to_keys[count] and count == self.min_count:
                self.min_count = count + 1

            return value
        else:
            return -1

    def put(self, key: int, value: int) -> None:
        if self.capacity == 0:
            return

        if key in self.key_to_value:
            self.key_to_value[key] = value
            self.get(key)
        else:
            if len(self.key_to_value) >= self.capacity:
                lfu_key = next(iter(self.count_to_keys[self.min_count]))
                del self.key_to_value[lfu_key]
                del self.key_to_count[lfu_key]
                del self.count_to_keys[self.min_count][lfu_key]

            self.key_to_value[key] = value
            self.key_to_count[key] = 1
            self.count_to_keys[1][key] = None
            self.min_count = 1

# Example case
lfu = LFUCache(2)
output = []
output.append(None)
lfu.put(1, 1)
output.append(None)
lfu.put(2, 2)
output.append(None)
output.append(lfu.get(1))
lfu.put(3, 3)
output.append(None)
output.append(lfu.get(2))
output.append(lfu.get(3))
lfu.put(4, 4)
output.append(None)
output.append(lfu.get(1))
output.append(lfu.get(3))
output.append(lfu.get(4))
print(output)
