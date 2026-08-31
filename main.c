#include <stdint.h>
#include <stdio.h>


void
print_blanks()
{
  for (int j = 0; j < 4; j++) {
    putchar(' ');
  }
}

void
print_line(char c)
{
  for (int j = 0; j < 3; j++) {
    putchar(c);
  }
}

void
print_cube()
{
  for (int i = 0; i < 3; i++) {
    print_blanks();
    print_line('W');
    putchar('\n');
  }

  putchar('\n');

  for (int i = 0; i < 3; i++) {
    print_line('O');
    putchar(' ');
    print_line('G');
    putchar(' ');
    print_line('R');
    putchar(' ');
    print_line('B');
    putchar('\n');
  }

  putchar('\n');

  for (int i = 0; i < 3; i++) {
    print_blanks();
    print_line('Y');
    putchar('\n');
  }
}


int co[8] = {0};
int cp[8] = {0, 1, 2, 3, 4, 5, 6, 7};
int eo[12] = {0};
int ep[12] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

void
tswap(int *arr, int x, int y)
{
  int z = arr[x];
  arr[x] = y;
  arr[y] = z;
}

void
cycle4(int *arr, int x, int y, int z, int q)
{
  int t = arr[x];
  arr[x] = arr[y];
  arr[y] = arr[z];
  arr[z] = arr[q];
  arr[q] = t;
}

void
orient4(int *arr, int mod, int x, int y, int z, int q)
{
  arr[x] = (arr[x] + 1) % mod;
  arr[y] = (arr[y] + 1) % mod;
  arr[z] = (arr[z] - 1) % mod;
  arr[q] = (arr[q] - 1) % mod;
}

void
move_r()
{
  cycle4(ep, 1, 7, 10, 9);
  cycle4(cp, 2, 6, 7, 1);
  orient4(co, 3, 2, 6, 7, 1);
}

void
move_l()
{
  cycle4(ep, 1, 7, 10, 9);
  cycle4(cp, 2, 6, 7, 1);
  orient4(co, 3, 2, 6, 7, 1);
}

void
move_u()
{
  cycle4(ep, 1, 7, 10, 9);
  cycle4(cp, 2, 6, 7, 1);
  orient4(co, 3, 2, 6, 7, 1);
}

void
move_d()
{
  cycle4(ep, 1, 7, 10, 9);
  cycle4(cp, 2, 6, 7, 1);
  orient4(co, 3, 2, 6, 7, 1);
}

void
move_f()
{
  cycle4(ep, 1, 7, 10, 9);
  cycle4(cp, 2, 6, 7, 1);
  orient4(co, 3, 2, 6, 7, 1);
}

void
move_b()
{
  cycle4(ep, 1, 7, 10, 9);
  cycle4(cp, 2, 6, 7, 1);
  orient4(co, 3, 2, 6, 7, 1);
}



void
print_cp()
{
  printf("CP = {");
  for (int i = 0; i < 7; i++) {
    printf("%d, ", cp[i]);
  }
  printf("%d}\n", cp[7]);
}

void
print_ep()
{
  printf("EP = {");
  for (int i = 0; i < 11; i++) {
    printf("%d, ", ep[i]);
  }
  printf("%d}\n", ep[11]);
}

int
main(int argc, char *argv[])
{
  print_cube(); 

  print_cp();
  print_ep();

  putchar('\n');
  move_r();

  print_cp();
  print_ep();


  return 0;
}

