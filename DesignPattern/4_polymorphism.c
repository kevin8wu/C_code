#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dl_module
{
    void *handle;
    int (*get_price)(void);
};

struct dl_module* module_open(char *name)
{
    char path[100];
    void *handle = NULL;
    struct dl_module *module = malloc(sizeof(struct dl_module));

    sprintf(path, "lib%s.so", name);
    handle = dlopen(path, RTLD_NOW);

    module->handle = handle;
    module->get_price = (int (*)(void))dlsym(handle, "get_price");
    
    return module;
}

void module_close(struct dl_module *module)
{
    dlclose(module->handle);
    free(module);
}

int main(int argc, char **argv)
{
    /*
    gcc poly_test.c -ldl
    gcc -fPIC module.c -shared -o lib_module.so //build module.c as shared lib
    LD_LIBRARY_PATH=./ ./a.out module
    */

    struct dl_module *module = NULL;

    printf("get %s's price: ", argv[1]);

    module = module_open(argv[1]);

    int value = 0;
    value = (*module->get_price)();
    printf("%d\n", value);

    module_close(module);

    return 0;
}