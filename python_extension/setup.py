from distutils.core import setup, Extension

module = Extension("c_primefinder", sources=["primefinderfunc.c", "primefinder.c"])

setup(
    name="c_primefinder",
    version="0.1",
    description="An example of C extension made callable to the Python API.",
    ext_modules=[module],
)
