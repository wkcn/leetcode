class Solution:
    def dayOfYear(self, date: str) -> int:
        year, month, day = map(int, date.split('-'))
        run = (year % 400 == 0) or (year % 100 != 0 and year % 4 == 0)
        days = [31, 29 if run else 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        return day + sum(days[:month - 1])
