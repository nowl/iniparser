#ifndef __INI_PARSER_H__
#define __INI_PARSER_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* public data structures */

struct config
{
	char *key;
	char *value;
};

struct section
{
	char *name;
	int num_configs;
	struct config **configs;
};

struct ini
{
	int num_sections;
	struct section **sections;	
};

struct read_ini;                /* private */

/* public API */

/* This will parse a given ini file contained in filename and return
 * the result as an allocated ini structure. The read_ini structure
 * should be declared and then set to NULL beforehand (this is to make
 * the reader thread-safe. */
struct ini* read_ini(struct read_ini **read_inip, char *filename);

/* Retrieves a value from a section/key combination and returns that
 * as a string. Note the returned value should not be freed. NULL is
 * returned if the section/key combination can not be found. */
char *ini_get_value(struct ini* ini, char *section, char *key);

/* Pretty print a given ini structure. */
void ini_pp(struct ini* ini);

/* Free memory associated with an ini structure. */
void destroy_ini(struct ini* ini);

/* Free memory associated with a read_ini structure. */
void cleanup_readini(struct read_ini* read_ini);

#endif  /* __INI_PARSER_H__ */
