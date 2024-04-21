
typedef struct spinlock
{
    volatile uint lock;
} spinlock_t;

void lock(spinlock_t *lock)
{
    while(xchg(lock->lock, 1) != 0);
}
void unlock(spinlock_t *lock)
{
    lock->lock = 0;
}


