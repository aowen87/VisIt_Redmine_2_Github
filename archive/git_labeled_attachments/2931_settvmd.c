#include <silo.h>
#include <assert.h>

static void settvmd(char const *fname)
{
    int const tvflag = 1;
    int const one = 1;
    int dbwrite_failed;
    DBfile *db = DBOpen(fname, DB_UNKNOWN, DB_APPEND);
    assert(db);
    dbwrite_failed = DBWrite(db, "/MetadataIsTimeVarying", &tvflag, &one, 1, DB_INT);
    assert(!dbwrite_failed);
    DBClose(db);
}

int main(int argc, char **argv)
{
    int i;

    assert(argc > 1);
    for (i = 1; i < argc; i++)
        settvmd(argv[i]);
    return 0;
}
