#include "windows_backend.h"

int main(int ArgumentCount, char **Argument)
{
    int Result = 1;

    Print("%% Hello, wold! %%\n");
    Print("%% Hello, wold! %%\n");
    Print("%% Hello, wold! %%\n");

    Print("%c %c %c\n", 'Z', 'Y', 'X');
    Print("%c %c %c\n", 'Z', 'Y', 'X');
    Print("%c %c %c\n", 'Z', 'Y', 'X');

    Print("%d %i %d\n", 0, -1, 1234);
    Print("%d %i %d\n", 0, -1, 1234);
    Print("%d %i %d\n", 0, -1, 1234);

    Print("%f %f %f\n", 0.0, -1.0, 1.234);
    Print("%f %f %f\n", 0.0, -1.0, 1.234);
    Print("%f %f %f\n", 0.0, -1.0, 1.234);

    Print("%lld %lli\n", 0x7FFFFFFFFFFFFFFF, 0x7FFFFFFFFFFFFFFF);
    Print("%lld %lli\n", 0x7FFFFFFFFFFFFFFF, 0x7FFFFFFFFFFFFFFF);
    Print("%lld %lli\n", 0x7FFFFFFFFFFFFFFF, 0x7FFFFFFFFFFFFFFF);

    Print("%llu\n", 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF );
    Print("%llu\n", 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF );
    Print("%llu\n", 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF );

    Print("%o %o %o\n", 0, 8, 16);
    Print("%o %o %o\n", 0, 8, 16);
    Print("%o %o %o\n", 0, 8, 16);

    Print("%p %p %p\n", 0, main, Argument);
    Print("%p %p %p\n", 0, main, Argument);
    Print("%p %p %p\n", 0, main, Argument);

    Print("%s %s %s\n", "ZYX", "WVUT", "SRQ");
    Print("%s %s %s\n", "ZYX", "WVUT", "SRQ");
    Print("%s %s %s\n", "ZYX", "WVUT", "SRQ");

    Print("%u %u %u\n", 0, -1, 1234);
    Print("%u %u %u\n", 0, -1, 1234);
    Print("%u %u %u\n", 0, -1, 1234);

    Print("%x %X %x\n", 0, -1, 255);
    Print("%x %X %x\n", 0, -1, 255);
    Print("%x %X %x\n", 0, -1, 255);

    Result = 0;
    return Result;
}