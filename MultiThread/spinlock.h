
#if defined(WILD_SPINLOCK)
/* this method may let some of CPU just idle */

typedef struct spinlock
{
    volatile uint lock;
} spinlock_t;

xchg(volatile uint *addr, uint newval)
{
    uint result;

    // It swaps the values in two operands (%0 and %1) and simultaneously stores the original value from %0 into the register indicated by %1.
    // output : The + for read−modify−write operand, m for memory, from the value of *addr
    // output : = for output operand, a for accumulator, store value in result
    // input : the value of newval is placed into register 1
    // clobbers : cc for condition code flag, inform compiler to perserve it if used elsewhere
    asm volatile("lock; xchgl %0, %1" :
    "+m" (*addr), "=a" (result) :
    "1" (newval) : "cc");

    return result;
}

void lock(spinlock_t *lock)
{
    //xchg(a,b) exchange the value of 2 arg and return original value from first arg
    while(xchg(&lock->lock, 1) != 0);
}

void unlock(spinlock_t *lock)
{
    lock->lock = 0;
}

#elif defined(TICKET_SPINLOCK)
/* this method can let each CPU get equal access, but may waste cache bandwidth */

typedef struct spinlock
{
    unsigned short owner;
    unsigned short next;
} spinlock_t;

void spin_lock(spinlock_t *lock)
{
    //xadd(a,b) write the result of a+b in memory, and return a 
    unsigned short next = xadd(&lock->next,1);
    while(lock->owner != next);
}

void spin_unlock(spinlock_t *lock)
{
    lock->owner++;
}

#endif

