#include "mem.h"
#include "k_stdio.h"
#include "my_setjmp.h"

#define setjmp my_setjmp
#define longjmp my_longjmp

#define TRY do { switch((ex_code = setjmp(ex_buf__))) { case 0:
#define CATCH(x) break; case x : 
#define ETRY break; } } while(0);
#define THROW(x) longjmp(ex_buf__, x)

#define NOFREE_MEM 5

jmp_buf ex_buf__;

using namespace DS; 
using namespace std;

#include <vector>
#include <string>
#include <map>

void *dso_handle_;
void *__dso_handle;

extern "C" void _exit()
{
}

char brk_area[10240];

extern "C" char *_sbrk(char *increment)
{
  char *ptr = brk_area;
  return ptr;
}

extern "C"
int _kill(int a, int b)
{
  return a;
}

extern "C"
int _getpid()
{
  int i;
  return i;
}

extern "C"
int _write(int fd, const void *buf, int count)
{
}

extern "C"
int open(const char *pathname, int flags, int mode)
{
}

extern "C"
int _open(const char *pathname, int flags, int mode)
{
}


extern "C"
int _isatty(int fd)
{
}


extern "C"
int _close(int fd)
{
}

extern "C"
int _fstat(int fd, struct stat *buf)
{
}

extern "C"
int _read(int fd, void *buf, int count)
{
}

extern "C"
int _lseek(int fd, int offset, int whence)
{
}

static char memarea[10240];

void out_of_mem()
{
  while(1);
}

template <class T>
class my_allocator
{
public:
  typedef int    size_type;
  typedef int difference_type;
  typedef T*        pointer;
  typedef const T*  const_pointer;
  typedef T&        reference;
  typedef const T&  const_reference;
  typedef T         value_type;

  my_allocator() {}
  my_allocator(const my_allocator&) {}



  pointer   allocate(size_type n, const void * = 0) {
              T* t = (T*) mymalloc(n * sizeof(T));
              if (t==0)
              {
                printf("cannot alloc memory\n");
                //throw std::bad_alloc();
                THROW(NOFREE_MEM);
                //out_of_mem();
                //exit(-1);
              }
              printf("used my_allocator to allocate at address %x n: %d sizeof(T): %d", (int)t, n, sizeof(T));
              printf("\r\n");

              return t;
            }
  
  void      deallocate(void* p, size_type) {
              if (p) {
                myfree(p);
                printf("used my_allocator to free address %x", (int)p);
                printf("\r\n");
              } 
            }

  pointer           address(reference x) const { return &x; }
  const_pointer     address(const_reference x) const { return &x; }
  my_allocator<T>&  operator=(const my_allocator&) { return *this; }
  void              construct(pointer p, const T& val) 
                    { new ((T*) p) T(val); }
  void              destroy(pointer p) { p->~T(); }

  size_type         max_size() const { return int(-1); }

  template <class U>
  struct rebind { typedef my_allocator<U> other; };

  template <class U>
  my_allocator(const my_allocator<U>&) {}

  template <class U>
  my_allocator& operator=(const my_allocator<U>&) { return *this; }
};

class Io
{
  public:
    Io()
    {
      i=56;
      printf("ctor i: %d\r\n", i);
    }
    ~Io()
    {
      printf("dtor i: %d\r\n", i);
    }
  private:
    int i;
};

Io io;

void vec_test_eh(void)
{
  int ex_code = 0;
  printf("\r\nthrow ex test\r\n");

  TRY
  {
    std::vector<char, my_allocator<char> > vec;
    for (int i=0 ; i < 2000 ; ++i)
    {
      vec.push_back(i);
    }
  }
  CATCH(NOFREE_MEM)
  {
    printf("\r\ngot no free mem\r\n");
  }
  ETRY
  while(1);
}

void vec_test()
{
  int ex_code = 0;
  char a, b, c , d, e, f;
  //std::vector<int, __gnu_cxx::new_allocator<int> > vec;
  std::vector<char, my_allocator<char> > vec;
  //std::map<char, my_allocator<char> > mymap;

  for (int i=0 ; i < 5 ; ++i)
  {
    vec.push_back(i);
  }
  for (int i=0 ; i < 5 ; ++i)
  {
    printf("%d\r\n", vec[i]);
  }

  a = vec[0];
  b = vec[1];
  c = vec[2];
  d = vec[3];
  e = vec[4];

  char z=a+b+c+d;
  printf("\r\n");
  print_memarea();

  map<int, int, less<int>, my_allocator<pair<int, int> > > mymap;

  mymap[1] = 111;
  mymap[2] = 222;
  printf("\r\n");
  printf("%d\n", mymap[1]);
  printf("%d\n", mymap[2]);
  printf("\r\n");
  print_memarea();

  //basic_string<char>
  typedef basic_string<char, std::char_traits<char>, my_allocator<char> > MyString;

  //MyString str1="abc", str2="xyz";
  MyString str1;
  MyString str2;

  str1="abc";
  str2="xyz";
  MyString str;

  #if 0
  str1 + str2;
  MyString str = str1+str2;
  printf("\r\n");
  printf("%s\n", str.c_str());
  printf("\r\n");
  #endif

  while(1);
}

