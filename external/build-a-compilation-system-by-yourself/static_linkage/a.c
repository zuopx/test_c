extern int shared;

int main()
{
    int a = 100;
    swap(&a, &shared);
}

/*
gcc -c a.c b.c
ld -o ab.out a.o b.o
*/