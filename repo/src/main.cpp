#include <iostream>
#include <dlfcn.h>

int main(int argc, char** argv) {

    // load the library
    void* lib_handle = dlopen("/librepo/build/libMPIWrapper.so", RTLD_NOW);
    if (!lib_handle) {
        std::cerr << "dlopen failed: " << dlerror() << std::endl;
	return 1;
    }

    // extract the mp_init symbol
    typedef int(*mp_init_t)( int* argc_ptr, char*** argv_ptr );
    mp_init_t mp_init;
    mp_init = (mp_init_t) dlsym(lib_handle, "mp_init");
    if (dlerror() != NULL) {
        std::cerr << "dlsym failed: " << dlerror() << std::endl;
	return 1;
    }

    // extract the mp_comm_size symbol
    typedef int(*mp_comm_size_t)(int*);
    mp_comm_size_t mp_comm_size = (mp_comm_size_t) dlsym(lib_handle, "mp_comm_size"); 
    if (dlerror() != NULL) {
        std::cerr << "dlsym failed: " << dlerror() << std::endl;
	return 1;
    }

    // extract the mp_comm_rank symbol
    typedef int(*mp_comm_rank_t)(int*);
    mp_comm_rank_t mp_comm_rank = (mp_comm_rank_t) dlsym(lib_handle, "mp_comm_rank"); 
    if (dlerror() != NULL) {
        std::cerr << "dlsym failed: " << dlerror() << std::endl;
	return 1;
    }

    // extract the mp_finalize symbol
    typedef int(*mp_finalize_t)();
    mp_finalize_t mp_finalize = (mp_finalize_t) dlsym(lib_handle, "mp_finalize"); 
    if (dlerror() != NULL) {
        std::cerr << "dlsym failed: " << dlerror() << std::endl;
	return 1;
    }

    mp_init(&argc, &argv);

    int world_size;
    mp_comm_size(&world_size);

    int world_rank;
    mp_comm_rank(&world_rank);

    if (world_rank == 0) {
        std::cout << "World size: " << world_size << std::endl;
    }

    mp_finalize();
    return 0;
}
