class Solution:
    def countGoodRectangles(self, rectangles: List[List[int]]) -> int:
        mins = list(map(min, rectangles))
        max_len = max(mins)
        return len(list(filter(lambda x: x >= max_len, mins)))
