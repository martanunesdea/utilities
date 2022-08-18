import unittest
from my_math.my_math import sum

class TestSum (unittest.TestCase):
    def test_list_int(self):
        """
        Test that it can sum a list of integers
        """
        data = [1, 2, 3]
        result = sum(data)
        self.assertEqual(result, 6)

    def test_list_char(self):
        """
        Test when list is char 
        """
        data = ['a', 'b', 'c']
        result = sum(data)
        self.assertEqual(result, False)

if __name__ == '__main__':
    unittest.main()