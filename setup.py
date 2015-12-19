from distutils.core import setup, Extension

PACKAGE_NAME = 'spam'

MAJOR_VERSION = 1
MINOR_VERSION = 0

module = Extension(PACKAGE_NAME,
    define_macros=[('MAJOR_VERSION', MAJOR_VERSION), ('MINOR_VERSION', MINOR_VERSION)],
    include_dirs = [], libraries = [], library_dirs = [],
    sources = ['src/spammodule.c']
)

setup(name = PACKAGE_NAME,
    version = '%d.%d' % (MAJOR_VERSION, MINOR_VERSION),
    description = 'This is just a demo package',
    author = 'peixinchen',
    author_email = 'peixinchen@foxmail.com',
    url = 'https://github.com/peixinchen/spam',
    long_description = '''
This is just a demo package.
''',
    ext_modules = [module]
)
