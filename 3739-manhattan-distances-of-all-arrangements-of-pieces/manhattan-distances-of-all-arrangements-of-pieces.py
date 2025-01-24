MOD = 10**9 + 7
max_fact = 10**5

# Precompute factorial and inverse factorial arrays
fact = [1] * (max_fact + 1)
for i in range(1, max_fact + 1):
    fact[i] = fact[i-1] * i % MOD

inv_fact = [1] * (max_fact + 1)
inv_fact[max_fact] = pow(fact[max_fact], MOD-2, MOD)
for i in range(max_fact - 1, -1, -1):
    inv_fact[i] = inv_fact[i+1] * (i + 1) % MOD
inv6 = pow(6, MOD-2, MOD)

class Solution:
    def distanceSum(self, m: int, n: int, k: int) -> int:
        a = m * n - 2
        b = k - 2
        comb_val = 0
        if a >= 0 and b >= 0 and a >= b:
            comb_val = fact[a] * inv_fact[b] % MOD
            comb_val = comb_val * inv_fact[a - b] % MOD
        
        # Compute sum_row_diff
        m_mod = m % MOD
        term_row = m_mod * ((m - 1) % MOD) % MOD
        term_row = term_row * ((m + 1) % MOD) % MOD
        sum_row = term_row * inv6 % MOD
        
        # Compute sum_col_diff
        n_mod = n % MOD
        term_col = n_mod * ((n - 1) % MOD) % MOD
        term_col = term_col * ((n + 1) % MOD) % MOD
        sum_col = term_col * inv6 % MOD
        
        # Compute sum_x_part and sum_y_part
        sum_x = sum_row * pow(n, 2, MOD) % MOD
        sum_y = sum_col * pow(m, 2, MOD) % MOD
        total = (sum_x + sum_y) % MOD
        
        ans = total * comb_val % MOD
        return ans