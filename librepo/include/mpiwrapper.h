#ifndef mpiwrapper
#define mpiwrapper

extern "C" int mp_init( int *argc, char ***argv);
extern "C" int mp_finalize(void);
extern "C" int mp_comm_rank( int *rank );
extern "C" int mp_comm_size( int *size );

#endif
