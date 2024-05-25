
typedef struct spinlock
{
    volatile uint lock;
} spinlock_t;

xchg(volatile uint *addr, uint newval)
{
    uint result;

    // The + in "+m" denotes a read−modify−write operand.
    asm volatile("lock; xchgl %0, %1" :
    "+m" (*addr), "=a" (result) :
    "1" (newval) : "cc");
    // use assembly to exchange 2 memory content and check related value

    return result;
}

void lock(spinlock_t *lock)
{
    //xchg(a,b) exchange 2 arg and return previous value
    while(xchg(lock->lock, 1) != 0);
}
void unlock(spinlock_t *lock)
{
    lock->lock = 0;
}


