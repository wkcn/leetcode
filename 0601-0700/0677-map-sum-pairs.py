from collections import defaultdict
class MapSum:

    def __init__(self):
        self.record = defaultdict(int)
        self.old_kvs = dict()

    def insert(self, key: str, val: int) -> None:
        v = val
        if key in self.old_kvs:
            val -= self.old_kvs[key]
        self.old_kvs[key] = v
        for i in range(len(key)):
            self.record[key[:i+1]] += val

    def sum(self, prefix: str) -> int:
        return self.record[prefix]
