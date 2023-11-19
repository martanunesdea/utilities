
cost = 10000
deposit = 1000
P = cost - deposit
interest = 0.5
term = 25


r = interest / 12
N = 12 * term

A = (1 + r)^N

monthly_payments = P * r * A / (A - 1)

total_cost = monthly_payments * N
