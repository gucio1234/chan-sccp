/*!
 * \file        sccp_cli_table.h
 * \brief       SCCP CLI Table Macro Header
 * \author      Diederik de Groot <ddegroot [at] users.sf.net>
 * \note        This program is free software and may be modified and distributed under the terms of the GNU Public License.
 *              See the LICENSE file at the top of the source tree.
 *
 */
#include "config.h"
__BEGIN_C_EXTERN__

#ifndef DOXYGEN_SHOULD_SKIP_THIS

#ifndef _CLI_AMI_TABLE_INCLUDE
#define _CLI_AMI_TABLE_INCLUDE

#define _CLI_AMI_TABLE_LIST_LOCK(...) CLI_AMI_TABLE_LIST_LOCK(__VA_ARGS__)
#define _CLI_AMI_TABLE_LIST_ITERATOR(...) CLI_AMI_TABLE_LIST_ITERATOR(__VA_ARGS__)
#define _CLI_AMI_TABLE_LIST_UNLOCK(...) CLI_AMI_TABLE_LIST_UNLOCK(__VA_ARGS__)

#define MERGE2_(_a,_b) _a##_b
#define UNIQUE_VAR(_a,_b) MERGE2_(_a,_b)

#define AMI_OUTPUT_PARAM(param, width, fmt, ...) 							\
{													\
	char *camelParam = pbx_strdupa(param);								\
	CLI_AMI_CAMEL_PARAM(param, camelParam);								\
	astman_append(s, "%s: " fmt "\r\n", camelParam, __VA_ARGS__);					\
	local_line_total++;										\
}
#endif
	// =========== Code To be generated by include file ===============
pbx_cli(fd, "\n");
#ifdef CLI_AMI_TABLE_LIST_ITER_TYPE
CLI_AMI_TABLE_LIST_ITER_TYPE *CLI_AMI_TABLE_LIST_ITER_VAR = NULL;
#endif

#ifndef CLI_AMI_TABLE_BEFORE_ITERATION
#define CLI_AMI_TABLE_BEFORE_ITERATION
#endif
#ifndef CLI_AMI_TABLE_AFTER_ITERATION
#define CLI_AMI_TABLE_AFTER_ITERATION
#endif

	/* print headers */
int UNIQUE_VAR(table_width_, CLI_AMI_TABLE_NAME) = 0;
int UNIQUE_VAR(table_entries_, CLI_AMI_TABLE_NAME) = 0;
const char *UNIQUE_VAR(id, CLI_AMI_TABLE_NAME);
char UNIQUE_VAR(idtext, CLI_AMI_TABLE_NAME)[256] = "";

#define CLI_AMI_TABLE_FIELD(_a,_b,_c,_d,_e) UNIQUE_VAR(table_width_,CLI_AMI_TABLE_NAME)=UNIQUE_VAR(table_width_,CLI_AMI_TABLE_NAME) + _d+ 1;
#define CLI_AMI_TABLE_UTF8_FIELD CLI_AMI_TABLE_FIELD
CLI_AMI_TABLE_FIELDS
#undef CLI_AMI_TABLE_FIELD
if (!s)
{
pbx_cli(fd, "+--- %s %.*s+\n", STRINGIFY(CLI_AMI_TABLE_NAME), UNIQUE_VAR(table_width_, CLI_AMI_TABLE_NAME) - (int) strlen(STRINGIFY(CLI_AMI_TABLE_NAME)) - 4, "------------------------------------------------------------------------------------------------------------------------------------------------------------------");

pbx_cli(fd, "| ");
#define CLI_AMI_TABLE_FIELD(_a,_b,_c,_d,_e) pbx_cli(fd,"%*s ",-_d,#_a);
CLI_AMI_TABLE_FIELDS
#undef CLI_AMI_TABLE_FIELD
    pbx_cli(fd, "|\n");

pbx_cli(fd, "+ ");
#define CLI_AMI_TABLE_FIELD(_a,_b,_c,_d,_e) pbx_cli(fd,"%." STRINGIFY(_d) "s ",	"==================================================================================================================================================================");
CLI_AMI_TABLE_FIELDS
#undef CLI_AMI_TABLE_FIELD
    pbx_cli(fd, "+\n");
} else {
	astman_append(s, "Event: TableStart\r\n");
	local_line_total++;
	astman_append(s, "TableName: %s\r\n", STRINGIFY(CLI_AMI_TABLE_NAME));
	local_line_total++;

	UNIQUE_VAR(id, CLI_AMI_TABLE_NAME) = astman_get_header(m, "ActionID");
	if (!pbx_strlen_zero(UNIQUE_VAR(id, CLI_AMI_TABLE_NAME))) {
		snprintf(UNIQUE_VAR(idtext, CLI_AMI_TABLE_NAME), sizeof(UNIQUE_VAR(idtext, CLI_AMI_TABLE_NAME)), "ActionID: %s\r\n", UNIQUE_VAR(id, CLI_AMI_TABLE_NAME));
		astman_append(s, "%s\r\n", UNIQUE_VAR(idtext, CLI_AMI_TABLE_NAME));
		local_line_total++;
	} else {
	        astman_append(s, "\r\n");
	}
}

	/* iterator through list */
if (!s) {
#define CLI_AMI_TABLE_FIELD(_a,_b,_c,_d,_e) pbx_cli(fd,"%" _b #_c " ",_e);
#undef CLI_AMI_TABLE_UTF8_FIELD
#define CLI_AMI_TABLE_UTF8_FIELD(_a,_b,_c,_d,_e) pbx_cli(fd,"%-*" #_c " ", sccp_utf8_columnwidth(_d,_e), _e);
#ifdef CLI_AMI_TABLE_LIST_ITERATOR
	_CLI_AMI_TABLE_LIST_LOCK(CLI_AMI_TABLE_LIST_ITER_HEAD);
	_CLI_AMI_TABLE_LIST_ITERATOR(CLI_AMI_TABLE_LIST_ITER_HEAD, CLI_AMI_TABLE_LIST_ITER_VAR, list) {
#else
	CLI_AMI_TABLE_ITERATOR {
#endif
		CLI_AMI_TABLE_BEFORE_ITERATION pbx_cli(fd, "| ");
		CLI_AMI_TABLE_FIELDS pbx_cli(fd, "|\n");
	CLI_AMI_TABLE_AFTER_ITERATION}
#ifdef CLI_AMI_TABLE_LIST_ITERATOR
	_CLI_AMI_TABLE_LIST_UNLOCK(CLI_AMI_TABLE_LIST_ITER_HEAD);
#endif
#undef CLI_AMI_TABLE_FIELD
#undef CLI_AMI_TABLE_UTF8_FIELD
#define CLI_AMI_TABLE_UTF8_FIELD CLI_AMI_TABLE_FIELD
} else {
#define CLI_AMI_TABLE_FIELD(_a,_b,_c,_d,_e) AMI_OUTPUT_PARAM(#_a, 0, "%" #_c, _e);
#ifdef CLI_AMI_TABLE_LIST_ITERATOR
	_CLI_AMI_TABLE_LIST_LOCK(CLI_AMI_TABLE_LIST_ITER_HEAD);
	_CLI_AMI_TABLE_LIST_ITERATOR(CLI_AMI_TABLE_LIST_ITER_HEAD, CLI_AMI_TABLE_LIST_ITER_VAR, list) {
#else
	CLI_AMI_TABLE_ITERATOR {
#endif
		CLI_AMI_TABLE_BEFORE_ITERATION astman_append(s, "Event: SCCP%sEntry\r\n", STRINGIFY(CLI_AMI_TABLE_PER_ENTRY_NAME));
		UNIQUE_VAR(table_entries_, CLI_AMI_TABLE_NAME)++;

		local_line_total++;
		astman_append(s, "ChannelType: SCCP\r\n");
		local_line_total++;
		astman_append(s, "ChannelObjectType: %s\r\n", STRINGIFY(CLI_AMI_TABLE_PER_ENTRY_NAME));
		local_line_total++;
		if (!pbx_strlen_zero(UNIQUE_VAR(id, CLI_AMI_TABLE_NAME))) {
			astman_append(s, "%s", UNIQUE_VAR(idtext, CLI_AMI_TABLE_NAME));
		}
		CLI_AMI_TABLE_FIELDS
		astman_append(s, "\r\n");
		local_line_total++;
	CLI_AMI_TABLE_AFTER_ITERATION}
#ifdef CLI_AMI_TABLE_LIST_ITERATOR
	_CLI_AMI_TABLE_LIST_UNLOCK(CLI_AMI_TABLE_LIST_ITER_HEAD);
#endif
#undef CLI_AMI_TABLE_FIELD
}

	/* print footer */
if (!s) {
	pbx_cli(fd, "+%.*s+\n", UNIQUE_VAR(table_width_, CLI_AMI_TABLE_NAME) + 1, "------------------------------------------------------------------------------------------------------------------------------------------------------------------");

} else {
	astman_append(s, "Event: TableEnd\r\n");
	local_line_total++;
	astman_append(s, "TableName: %s\r\n", STRINGIFY(CLI_AMI_TABLE_NAME));
	local_line_total++;
	astman_append(s, "TableEntries: %d\r\n", UNIQUE_VAR(table_entries_, CLI_AMI_TABLE_NAME));
	local_line_total++;
	if (!pbx_strlen_zero(UNIQUE_VAR(id, CLI_AMI_TABLE_NAME))) {
		astman_append(s, "%s\r\n", UNIQUE_VAR(idtext, CLI_AMI_TABLE_NAME));
		local_line_total++;
	} else {
	        astman_append(s, "\r\n");
	}
	local_line_total++;
}

#ifdef CLI_AMI_TABLE_NAME
#undef CLI_AMI_TABLE_NAME
#endif

#ifdef CLI_AMI_TABLE_PER_ENTRY_NAME
#undef CLI_AMI_TABLE_PER_ENTRY_NAME
#endif

#ifdef CLI_AMI_TABLE_LIST_ITER_TYPE
#undef CLI_AMI_TABLE_LIST_ITER_TYPE
#endif

#ifdef CLI_AMI_TABLE_LIST_ITER_VAR
#undef CLI_AMI_TABLE_LIST_ITER_VAR
#endif

#ifdef CLI_AMI_TABLE_LIST_ITER_HEAD
#undef CLI_AMI_TABLE_LIST_ITER_HEAD
#endif

#ifdef CLI_AMI_TABLE_LIST_LOCK
#undef CLI_AMI_TABLE_LIST_LOCK
#endif

#ifdef CLI_AMI_TABLE_LIST_ITERATOR
#undef CLI_AMI_TABLE_LIST_ITERATOR
#endif

#ifdef CLI_AMI_TABLE_ITERATOR
#undef CLI_AMI_TABLE_ITERATOR
#endif

#ifdef CLI_AMI_TABLE_BEFORE_ITERATION
#undef CLI_AMI_TABLE_BEFORE_ITERATION
#endif

#ifdef CLI_AMI_TABLE_AFTER_ITERATION
#undef CLI_AMI_TABLE_AFTER_ITERATION
#endif

#ifdef CLI_AMI_TABLE_LIST_UNLOCK
#undef CLI_AMI_TABLE_LIST_UNLOCK
#endif

#ifdef CLI_AMI_TABLE_FIELDS
#undef CLI_AMI_TABLE_FIELDS
#endif
	// =========== End of Code To be generated by include file ============
#endif														/* DOXYGEN_SHOULD_SKIP_THIS */
__END_C_EXTERN__
// kate: indent-width 8; replace-tabs off; indent-mode cstyle; auto-insert-doxygen on; line-numbers on; tab-indents on; keep-extra-spaces off; auto-brackets off;
