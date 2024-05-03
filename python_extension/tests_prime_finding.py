from contextlib import redirect_stdout
from io import StringIO

import unittest

# Custom
from speedtest import timeit
from c_primefinder import find_primes


@timeit
def noarg_func():
    """Silly testing function"""
    return 1


@timeit
def arg_func(a, b):
    """Silly testing function"""
    return a + b


@timeit
def kwarg_func(c=1, d=2):
    """Silly testing function"""
    return c + d


@timeit
def generic_func(a, b, c=3, d=4):
    """Silly testing function"""
    return a + b + c + d


class TestTimeit(unittest.TestCase):
    """
    Testing of the timing function
    """

    def test_noarg_func(self):
        """Tests that the timer acts as expected for a function with no arguments."""
        virtual_file = StringIO()
        with redirect_stdout(virtual_file):
            return_val = noarg_func()
        captured_print = virtual_file.getvalue()

        with self.subTest(
            f"Return value for {noarg_func.__name__} is as expected, 1={return_val}"
        ):
            self.assertEqual(return_val, 1)

        with self.subTest(
            f"Check correctness of printed output for {noarg_func.__name__}"
        ):
            self.assertIn(f"{noarg_func.__name__}() execution time", captured_print)

    def test_arg_func(self):
        """Tests that the timer acts as expected for a function with positional arguments."""
        virtual_file = StringIO()
        with redirect_stdout(virtual_file):
            return_val = arg_func(1, 2)
        captured_print = virtual_file.getvalue()

        with self.subTest(
            f"Return value for {arg_func.__name__} is as expected, 1={1+2}"
        ):
            self.assertEqual(return_val, 1 + 2)

        with self.subTest(
            f"Check correctness of printed output for {arg_func.__name__}"
        ):
            self.assertIn(f"{arg_func.__name__}(1, 2) execution time", captured_print)

    def test_kwarg_func1(self):
        """Tests that the timer acts as expected for a function with keyword arguments."""
        virtual_file = StringIO()
        with redirect_stdout(virtual_file):
            return_val = kwarg_func()
        captured_print = virtual_file.getvalue()

        with self.subTest(
            f"Return value for {kwarg_func.__name__} is as expected, 3={3}"
        ):
            self.assertEqual(return_val, 3)

        with self.subTest(
            f"Check correctness of printed output for {kwarg_func.__name__}"
        ):
            self.assertIn(f"{kwarg_func.__name__}() execution time", captured_print)

    def test_kwarg_func2(self):
        """Tests that the timer acts as expected for a function with keyword arguments."""
        _kwargs = {"c": 3, "d": 4}
        virtual_file = StringIO()
        with redirect_stdout(virtual_file):
            return_val = kwarg_func(**_kwargs)
        captured_print = virtual_file.getvalue()

        with self.subTest(
            f"Return value for {kwarg_func.__name__} is as expected, 7={3+4}"
        ):
            self.assertEqual(return_val, 3 + 4)

        with self.subTest(
            f"Check correctness of printed output for {kwarg_func.__name__}"
        ):
            self.assertIn(
                f"{kwarg_func.__name__}(c=3, d=4) execution time", captured_print
            )

    def test_generic_func(self):
        """Tests that the timer acts as expected for a function with any arguments."""

        virtual_file = StringIO()
        with redirect_stdout(virtual_file):
            return_val = generic_func(1, 2, c=3, d=4)
        captured_print = virtual_file.getvalue()

        with self.subTest(
            f"Return value for {generic_func.__name__} is as expected, 10={1+2+3+4}"
        ):
            self.assertEqual(return_val, 1 + 2 + 3 + 4)

        with self.subTest(
            f"Check correctness of printed output for {generic_func.__name__}"
        ):
            self.assertIn(
                f"{generic_func.__name__}(1, 2, c=3, d=4) execution time",
                captured_print,
            )


if __name__ == "__main__":
    unittest.main()
