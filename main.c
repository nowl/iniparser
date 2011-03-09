#include "iniparser.h"
#include "assert.h"

int
main(int argc, char *argv[])
{
    char *value;

    /* ini_r is a structure that holds state to make this reader
     * reentrant */
	struct read_ini *ini_r = NULL;

    /* "test.ini" will be parsed into "ini" */
	struct ini *ini = read_ini(&ini_r, "test.ini");

    /* pretty printing of ini structure */
	ini_pp(ini);

    /* retrieve a value */
    value = ini_get_value(ini, "section 2", "key1");
    printf("%s\n", value);
    value = ini_get_value(ini, "section1", "key3");
    printf("%d\n", atoi(value));
    value = ini_get_value(ini, "section1", "key2");
    printf("%f\n", atof(value));
    value = ini_get_value(ini, "section1", "key 17");
    assert(!value);

    /* free memory */
	destroy_ini(ini);
    cleanup_readini(ini_r);

	return 0;
}
