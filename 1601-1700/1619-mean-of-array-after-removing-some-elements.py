class Solution(object):
    def trimMean(self, arr):
        """
        :type arr: List[int]
        :rtype: float
        """
        arr.sort()
        five = int((len(arr) * 0.05))
        arr = arr[five:-five]
        if len(arr) == 0:
            return 0
        return sum(arr) / len(arr)


if __name__ == '__main__':
    arr = [1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3]
    print(Solution().trimMean(arr))
    arr = [6,0,7,0,7,5,7,8,3,4,0,7,8,1,6,8,1,1,2,4,8,1,9,5,4,3,8,5,10,8,6,6,1,0,6,10,8,2,3,4]
    print(Solution().trimMean(arr))
