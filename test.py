# -*- coding: utf-8 -*-

import sys, time
import numpy as np


def find_prime(upper):
    """找出小于upper的所有质数"""

    prime_list = list()
    mid = int(np.sqrt(upper))
    nums = np.arange(upper)
    nums[1] = 0

    while True:
        primes = nums[nums > 0]
        if primes.any():
            p = primes[0]
            prime_list.append(p)
            nums[p::p] = 0
            if p > mid:
                break
        else:
            break

    prime_list.extend(nums[nums > 0].tolist())
    return prime_list


def fast_find_prime(upper, base=100000, block=20000000):
    """快速找出小于upper的所有质数"""

    if upper <= base:
        return find_prime(upper)

    mid = int(np.sqrt(upper))
    prime_list = find_prime(base)
    prime_array = np.array(prime_list)
    prime_array = prime_array[prime_array <= mid]

    start = base
    while start < upper:
        end = start + block
        if end > upper:
            end = upper
        print((start, end))

        prime_list.extend(process_func(start, np.copy(prime_array), (start, end)))
        start += block

    return prime_list


def process_func(id, primes, task_range):
    """执行分块任务的函数

    primes      - 用以剔除非质数的质数表
    task_range  - 分块任务的数值范围
    """

    nums = np.arange(task_range[0], task_range[1])
    for p in primes:
        k = (p - task_range[0] % p) % p
        nums[k::p] = 0

    return nums[nums > 0].tolist()


upper = 2000000000
t0 = time.time()
prime_list = fast_find_prime(upper)
t1 = time.time()
print('查找%d以内的质数耗时%0.3f秒，共找到%d个质数' % (upper, t1 - t0, len(prime_list)))

