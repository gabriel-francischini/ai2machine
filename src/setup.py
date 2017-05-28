from distutils.core import setup, Extension
setup(name="pymachine", version="1.0",
      ext_modules=[Extension("pymachine",
                             ["pymachine.cpp"],
                             include_dirs=['/usr/include/python3.5'],
                             libraries=['python3.5m'],
                             extra_compile_args=['-std=c++11'])])
