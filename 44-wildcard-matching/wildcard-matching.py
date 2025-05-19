from functools import cache

class Solution:
    def isMatch(self, s: str, t: str) -> bool:
        @cache
        def match(si: int, ti: int) -> bool:
            if si < 0 and ti < 0:
                return True
            if ti < 0:
                return False
            if t[ti] == '*':
                if match(si, ti - 1):
                    return True
                if si >= 0 and match(si - 1, ti):
                    return True
                if si >= 0 and match(si - 1, ti - 1):
                    return True
                return False
            if si < 0:
                return False
            if s[si] == t[ti] or t[ti] == '?':
                return match(si - 1, ti - 1)
            return False

        return match(len(s) - 1, len(t) - 1)
