class Solution:
    def beautifulNumbers(self, l: int, r: int) -> int:
        return count_up_to(r) - count_up_to(l - 1)
        
def count_up_to(n):
    if n == 0:
        return 0
    n_str = str(n)
    L = len(n_str)
    max_S = min(90, 9 * L)
    total_count = 0
    for S in range(1, max_S + 1):
        cache0 = {}
        cache1 = {}
        cnt = dp1(0, True, False, 0, 1, n_str, S, cache0, cache1)
        total_count += cnt
    return total_count

def dp0(pos, tight, started, current_sum, n_str, S, cache0, cache1):
    L = len(n_str)
    if pos == L:
        return 1 if (started and current_sum == S) else 0
    key = (pos, tight, started, current_sum)
    if key in cache0:
        return cache0[key]
    total = 0
    up = int(n_str[pos]) if tight else 9
    for d in range(0, up + 1):
        new_tight = tight and (d == up)
        if not started and d == 0:
            total += dp0(pos + 1, new_tight, False, current_sum, n_str, S, cache0, cache1)
        else:
            new_started = True
            new_sum = current_sum + d
            if new_sum > S:
                continue
            remaining = L - pos - 1
            if new_sum + 9 * remaining < S:
                continue
            total += dp0(pos + 1, new_tight, new_started, new_sum, n_str, S, cache0, cache1)
    cache0[key] = total
    return total

def dp1(pos, tight, started, current_sum, prod_mod, n_str, S, cache0, cache1):
    L = len(n_str)
    if pos == L:
        return 1 if (started and current_sum == S and prod_mod == 0) else 0
    key = (pos, tight, started, current_sum, prod_mod)
    if key in cache1:
        return cache1[key]
    total = 0
    up = int(n_str[pos]) if tight else 9
    for d in range(0, up + 1):
        new_tight = tight and (d == up)
        if not started and d == 0:
            total += dp1(pos + 1, new_tight, False, current_sum, prod_mod, n_str, S, cache0, cache1)
        else:
            new_started = True
            new_sum = current_sum + d
            if new_sum > S:
                continue
            remaining = L - pos - 1
            if new_sum + 9 * remaining < S:
                continue
            if d == 0:
                total += dp0(pos + 1, new_tight, new_started, new_sum, n_str, S, cache0, cache1)
            else:
                if not started:
                    new_prod = (d) % S
                else:
                    new_prod = (prod_mod * d) % S
                total += dp1(pos + 1, new_tight, new_started, new_sum, new_prod, n_str, S, cache0, cache1)
    cache1[key] = total
    return total

    