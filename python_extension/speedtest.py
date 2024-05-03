# The normal stuff
from functools import wraps
from time import perf_counter
from typing import Any, Callable, List

# C extension to the python language
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

        print(f"{_name}({_args}{_kwargs}) execution time {toc-tic:4f}")
        return result

    return modified_function


if __name__ == "__main__":
    cfunction: List[int] = timeit(find_primes)(50000)


########################################################
# For testing that the timer does what I want it to do #
########################################################


@timeit
def simplefunc():
    return 1


@timeit
def func_with_args(a, b):
    return a + b


@timeit
def func_with_kwargs(c=1, d=2):
    return c + d


@timeit
def func_with_args_and_kwargs(a, b, c=1, d=2):
    return a + b + c + d
