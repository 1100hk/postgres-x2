/*-------------------------------------------------------------------------
 *
 * postgresql_fdw.h
 *
 *		foreign-data wrapper for PostgreSQL
 *
 * Portions Copyright (c) 1996-2011, PostgreSQL Global Development Group
 * Portions Copyright (c) 2010-2012, Postgres-XC Development Group
 *
 * src/include/pgxc/postgresql_fdw.h
 *
 *-------------------------------------------------------------------------
 */

#ifndef POSTGRES_FDW_H
#define POSTGRES_FDW_H

#include "postgres.h"
#include "pgxc/execRemote.h"
typedef struct
{
	bool	collect_vars;
	List 	*aggs;
	List	*vars;
} foreign_qual_context;
void pgxc_foreign_qual_context_init(foreign_qual_context *context);
void pgxc_foreign_qual_context_free(foreign_qual_context *context);

bool is_immutable_func(Oid funcid);
char *deparseSql(RemoteQueryState *scanstate);
bool is_foreign_expr(Node *node, foreign_qual_context *context);
#endif
