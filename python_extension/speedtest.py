# The normal stuff
from functools import wraps
from time import perf_counter
from sys import argv
from typing import Any, Callable, List

# Our C extension to the python language
from c_primefinder import find_primes


def timeit(func: Callable) -> Callable[[Callable], Callable]:
    """
    A decorator which times how long a function takes to execute

    :param func: The function to time
    :type func: Callable
    :return:
    :rtype: Callable[[Callable], Callable]
    """

    @wraps(func)
    def modified_function(*args, **kwargs) -> Any:
        tic: float = perf_counter()
        result = func(*args, **kwargs)
        toc: float = perf_counter()

        _name: str = func.__name__
        _args: str = ", ".join((str(_) for _ in args))
        _args += ", " if len(kwargs) > 0 and len(args) > 0 else ""
        _kwargs: str = ", ".join(f"{k}={v}" for k, v in kwargs.items())

        print(f"{_name}({_args}{_kwargs}) execution time {toc-tic:4f}s")
        return result

    return modified_function


def generate_primes_c_copy(desired_primes: int, prime_numbers: List[int]) -> None:
    """
    Generate the prime numbers. Use the same (as close) algorithm as in c to make the test fair.
    The code looks quite weird (un-idomatic) in python

    :param desired_primes: How many primes should be generated
    :type desired_primes: int
    :param prime_numbers: In place list in which to store the generated prime numbers
    :type prime_numbers: List[int]
    """
    current_prime, current_value = 2, 3
    prime_numbers[0] = 2
    prime_numbers[1] = 3

    while current_prime < desired_primes:
        is_prime = True
        current_value += 1

        for i in range(current_prime):  # Maybe cheating?
            if current_value % prime_numbers[i] == 0:
                is_prime = False
                break

        if is_prime:
            prime_numbers[current_prime] = current_value
            current_prime += 1


@timeit
def generate_primes(desired_primes: int) -> List[int]:
    """
    Silly wrapper function for the above

    :param desired_primes: Desired number of primes
    :type desired_primes: int
    :return: List containing prime numbers
    :rtype: List[int]
    """
    result_holder: List[int] = [None] * desired_primes
    generate_primes_c_copy(desired_primes, result_holder)
    return result_holder


if __name__ == "__main__":
    if len(argv) != 2:
        raise IOError(
            "Incorrect number of arguments. "
            "Please enter the number of desired primes"
        )

    DESIRED_NUM_PRIMES = int(argv[1])

    cfunction_result: List[int] = timeit(find_primes)(DESIRED_NUM_PRIMES)
    pythonfunc_result: List[int] = generate_primes(DESIRED_NUM_PRIMES)
