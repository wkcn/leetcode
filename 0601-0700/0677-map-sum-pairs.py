class MapSum:

    def __init__(self):
        self.rec = defaultdict(int)
        self.keys = dict()

    def insert(self, key: str, val: int) -> None:
        d = val - self.keys.get(key, 0)
        self.keys[key] = val
        for i in range(len(key)):
            self.rec[key[:i + 1]] += d

    def sum(self, prefix: str) -> int:
        return self.rec.get(prefix, 0)



# Your MapSum object will be instantiated and called as such:
# obj = MapSum()
# obj.insert(key,val)
# param_2 = obj.sum(prefix)
