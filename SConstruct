# -*-python-*-

import os
from SCons.Errors import EnvironmentError

env = Environment(tools = ['toolchain'])

VECTORS = ['Index',
           'double']

SETS = { 'less': ['Index',
                  'double']}

HEADER = """\
#ifndef STATISKIT_STL_H
#define STATISKIT_STL_H

#include <vector>
#include <set>

#if defined WIN32 || defined _WIN32 || defined __CYGWIN__
    #ifdef LIBSTATISKIT_STL
        #ifdef __GNUC__
            #define STATISKIT_STL_API __attribute__ ((dllexport))
        #else
            #define STATISKIT_STL_API __declspec(dllexport)
        #endif
    #else
        #ifdef __GNUC__
            #define STATISKIT_STL_API __attribute__ ((dllimport))
        #else
            #define STATISKIT_STL_API __declspec(dllimport)
        #endif
    #endif
#else
    #if __GNUC__ >= 4
        #define STATISKIT_STL_API __attribute__ ((visibility ("default")))
    #else
        #define STATISKIT_STL_API
    #endif
#endif

namespace statiskit
{
    typedef std::size_t Index;

    namespace stl
    {

        template<class T>
            class Generator
            {
                public:
                    Generator(const T& iterable)
                    { 
                        _cur = iterable.begin();
                        _end = iterable.end();
                    }

                    virtual ~Generator()
                    {}

                    Generator(const Generator< T >& generator)
                    { 
                        _cur = generator._cur;
                        _end = generator._end;
                    }

                    bool is_valid() const
                    { return _cur != _end; }

                    Generator< T >& operator++()
                    { 
                        ++_cur;
                        return *this;
                    }

                    typename T::value_type value() const
                    { return *_cur; }

                protected:
                    typename T::const_iterator _cur;
                    typename T::const_iterator _end;
            };

"""

def capitalize(T):
    return ''.join([t.capitalize() for t in T.replace('std::', '').replace('_', ' ').split()])

with open('src/cpp/STL.h', 'w') as filehandler:
    filehandler.write(HEADER)
    filehandler.write('\n')
    for T in VECTORS:
        filehandler.write('\t\ttypedef std::vector< ' + T + ' > Vector' + capitalize(T) +';\n')
    filehandler.write('\n')
    for sort in SETS:
        for T in SETS[sort]:
            filehandler.write('\t\ttypedef std::set< ' + T + ', std::' + sort + '< ' + T + ' > > Set' + sort.capitalize() + capitalize(T) +';\n')
            filehandler.write('\t\tSTATISKIT_STL_API Generator< std::set< ' + T + ', std::' + sort + '< ' + T + ' > > > generator(const std::set< ' + T + ', std::' + sort + '< ' + T + ' > >& iterable);\n')
            filehandler.write('\t\tSTATISKIT_STL_API bool insert(std::set< ' + T + ', std::' + sort + '< ' + T + ' > >& iterable, const ' + T + '& value);\n')
    filehandler.write('\n')
    filehandler.write('\t}\n}\n\n\n#endif')

with open('src/cpp/STL.cpp', 'w') as filehandler:
    filehandler.write('#include "STL.h"\n\nnamespace statiskit\n{\n\tnamespace stl\n\t{\n')
    for sort in SETS:
        for T in SETS[sort]:
            setstring = 'std::set< ' + T + ', std::' + sort + '< ' + T + ' >, std::allocator< ' + T + ' > >'
            filehandler.write('\t\tGenerator< ' + setstring + ' > generator(const ' + setstring + '& iterable)\n')
            filehandler.write('\t\t{ return Generator< ' + setstring + ' >(iterable); }\n\n')
            filehandler.write('\t\tbool insert(' + setstring + '& iterable, const ' + T + '& value)\n')
            filehandler.write('\t\t{ return iterable.insert(value).second; }\n\n')
    filehandler.write('\t}\n}')

VariantDir('build', 'src')
try:
  SConscript(os.path.join('build', 'cpp', 'SConscript'), exports="env")
except EnvironmentError:
  pass
except Exception:
    raise
try:
  SConscript(os.path.join('build', 'py', 'SConscript'), exports="env")
except EnvironmentError:
  pass
except Exception:
    raise
try:
  SConscript(os.path.join('test', 'SConscript'), exports="env")
except EnvironmentError:
  pass
except Exception:
    raise
try:
  SConscript(os.path.join('conda', 'SConscript'), exports="env")
except EnvironmentError:
  pass
except Exception:
    raise
Default("install")
