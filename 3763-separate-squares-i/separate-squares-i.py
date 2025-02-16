from typing import List

class Solution:
    def separateSquares(self, squares: List[List[int]]) -> float:
        total_area = 0
        min_y = float('inf')
        max_y = -float('inf')
        for x, y, l in squares:
            total_area += l * l
            min_y = min(min_y, y)
            max_y = max(max_y, y + l)
        
        target = total_area / 2.0
        
        low = min_y
        high = max_y
        
        # Perform binary search with sufficient iterations for precision
        for _ in range(100):
            mid = (low + high) / 2
            sa = 0.0
            for x, y, l in squares:
                if mid <= y:
                    sa += l * l
                elif mid >= y + l:
                    sa += 0.0
                else:
                    sa += (y + l - mid) * l
            if sa > target:
                low = mid
            else:
                high = mid
        
        return low