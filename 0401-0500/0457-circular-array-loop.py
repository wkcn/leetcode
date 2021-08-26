from typing import List

class Solution2:
    def circularArrayLoop(self, nums: List[int]) -> bool:
        n = len(nums)
        if n == 0:
            return False
        vis = [None] * n
        for i in range(n):
            if vis[i] is None:
                vis[i] = i
                s = nums[i]
                j = (i + s) % n
                if i == j:
                    continue
                while 1:
                    if vis[j] is not None:
                        if vis[j] == i:
                            return True
                        else:
                            break
                    else:
                        new_s = nums[j]
                        if new_s * s > 0:
                            vis[j] = i
                            s = new_s
                            old_j = j
                            j = (j + s) % n
                            if j == old_j:
                                break
                        else:
                            break
        return False


# 快慢指针
class Solution:
    def circularArrayLoop(self, nums: List[int]) -> bool:
        n = len(nums)
        if n == 0:
            return False
        for i in range(n):
            if nums[i] % n == 0:
                continue
            slow = i
            fast = (i + nums[i]) % n
            step = nums[i]
            while slow != fast:
                # 注意有两种终止条件！！nums[fast]为n的倍数或者nums[fast]和step的正负不同
                if nums[fast] % n == 0 or nums[fast] * step <= 0:
                    break
                fast = (fast + nums[fast]) % n
                if nums[fast] % n == 0 or nums[fast] * step <= 0:
                    break
                fast = (fast + nums[fast]) % n

                slow = (slow + nums[slow]) % n
            if slow == fast:
                return True
            slow = i
            while nums[slow] * step > 0:
                old_slow = slow
                slow = (slow + nums[slow]) % n
                nums[old_slow] = 0
        return False


solution = Solution()
assert solution.circularArrayLoop([1,-1,2,4,4])
assert solution.circularArrayLoop([-1,2,1,2])
assert not solution.circularArrayLoop([-1,-2,-3,-4,-5])
assert solution.circularArrayLoop([2,-1,1,2,2])
assert not solution.circularArrayLoop([-1,2])
assert not solution.circularArrayLoop([-2,1,-1,-2,-2])
