class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        ma = dict((k, v) for v, k in enumerate(list1))
        best_su = len(list1) + len(list2)
        ans = []
        for i, s in enumerate(list2):
            j = ma.get(s, -1)
            if j != -1:
                su = i + j
                if su < best_su:
                    ans = []
                    best_su = su
                if su == best_su:
                    ans.append(s)
        return ans
