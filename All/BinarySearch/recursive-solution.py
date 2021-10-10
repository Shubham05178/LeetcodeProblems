import unittest


class Solution:
    def binarySearch(self, a, x, left, right):
        if left > right:
            return -1
        mid = left + ((right - left) // 2)
        if a[mid] == x:
            return mid
        elif a[mid] < x:
            return self.binarySearch(a, x, mid + 1, right)
        else:
            return self.binarySearch(a, x, left, mid - 1)


class Test(unittest.TestCase):
    def testBinarySearch1(self):
        actual = Solution().binarySearch([1, 5, 8, 12, 13], 8, 0, 4)
        expected = 2
        self.assertEqual(actual, expected)

    def testBinarySearch2(self):
        actual = Solution().binarySearch([1, 5, 8, 12, 13], 13, 0, 4)
        expected = 4
        self.assertEqual(actual, expected)

    def testBinarySearch3(self):
        actual = Solution().binarySearch([1, 5, 8, 12, 13], 11, 0, 4)
        expected = -1
        self.assertEqual(actual, expected)


if __name__ == "__main__":
    unittest.main(verbosity=2)
