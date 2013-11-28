#include <jni.h>
#include <stdio.h>
#include <string.h>
#include "lmdb.h"
#include "glmdb_jni.h"

#define	Z	"z"

static void prstat(MDB_stat *ms, char *name) {
	printf("%s\n", name);
	printf("  Tree depth: %u\n", ms->ms_depth);
	printf("  Branch pages: %"Z"u\n", ms->ms_branch_pages);
	printf("  Leaf pages: %"Z"u\n", ms->ms_leaf_pages);
	printf("  Overflow pages: %"Z"u\n", ms->ms_overflow_pages);
	printf("  Entries: %"Z"u\n", ms->ms_entries);
}

JNIEXPORT void JNICALL Java_org_glmdb_blueprints_jni_GlmdbJni_init(JNIEnv *env, jclass that) {

	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_VERSION_MAJOR", "I"), (jint) MDB_VERSION_MAJOR);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_VERSION_MINOR", "I"), (jint) MDB_VERSION_MINOR);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_VERSION_PATCH", "I"), (jint) MDB_VERSION_PATCH);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_VERSION_FULL", "I"), (jint) MDB_VERSION_FULL);
//	(*env)->SetStaticLongField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_VERSION_DATE", "J"), (jlong) (intptr_t) MDB_VERSION_DATE);
//	(*env)->SetStaticLongField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_VERSION_STRING", "J"), (jlong) (intptr_t) MDB_VERSION_STRING);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_FIXEDMAP", "I"), (jint) MDB_FIXEDMAP);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_NOSUBDIR", "I"), (jint) MDB_NOSUBDIR);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_NOSYNC", "I"), (jint) MDB_NOSYNC);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_RDONLY", "I"), (jint) MDB_RDONLY);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_NOMETASYNC", "I"), (jint) MDB_NOMETASYNC);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_WRITEMAP", "I"), (jint) MDB_WRITEMAP);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_MAPASYNC", "I"), (jint) MDB_MAPASYNC);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_NOTLS", "I"), (jint) MDB_NOTLS);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_REVERSEKEY", "I"), (jint) MDB_REVERSEKEY);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_DUPSORT", "I"), (jint) MDB_DUPSORT);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_INTEGERKEY", "I"), (jint) MDB_INTEGERKEY);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_DUPFIXED", "I"), (jint) MDB_DUPFIXED);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_INTEGERDUP", "I"), (jint) MDB_INTEGERDUP);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_REVERSEDUP", "I"), (jint) MDB_REVERSEDUP);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_CREATE", "I"), (jint) MDB_CREATE);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_NOOVERWRITE", "I"), (jint) MDB_NOOVERWRITE);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_NODUPDATA", "I"), (jint) MDB_NODUPDATA);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_CURRENT", "I"), (jint) MDB_CURRENT);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_RESERVE", "I"), (jint) MDB_RESERVE);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_APPEND", "I"), (jint) MDB_APPEND);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_APPENDDUP", "I"), (jint) MDB_APPENDDUP);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_MULTIPLE", "I"), (jint) MDB_MULTIPLE);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_FIRST", "I"), (jint) MDB_FIRST);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_FIRST_DUP", "I"), (jint) MDB_FIRST_DUP);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_GET_BOTH", "I"), (jint) MDB_GET_BOTH);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_GET_BOTH_RANGE", "I"), (jint) MDB_GET_BOTH_RANGE);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_GET_CURRENT", "I"), (jint) MDB_GET_CURRENT);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_GET_MULTIPLE", "I"), (jint) MDB_GET_MULTIPLE);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_LAST", "I"), (jint) MDB_LAST);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_LAST_DUP", "I"), (jint) MDB_LAST_DUP);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_NEXT", "I"), (jint) MDB_NEXT);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_NEXT_DUP", "I"), (jint) MDB_NEXT_DUP);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_NEXT_MULTIPLE", "I"), (jint) MDB_NEXT_MULTIPLE);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_NEXT_NODUP", "I"), (jint) MDB_NEXT_NODUP);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_PREV", "I"), (jint) MDB_PREV);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_PREV_DUP", "I"), (jint) MDB_PREV_DUP);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_PREV_NODUP", "I"), (jint) MDB_PREV_NODUP);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_SET", "I"), (jint) MDB_SET);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_SET_KEY", "I"), (jint) MDB_SET_KEY);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_SET_RANGE", "I"), (jint) MDB_SET_RANGE);
//	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "EINVAL", "I"), (jint) EINVAL);
//	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "EACCES", "I"), (jint) EACCES);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_SUCCESS", "I"), (jint) MDB_SUCCESS);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_KEYEXIST", "I"), (jint) MDB_KEYEXIST);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_NOTFOUND", "I"), (jint) MDB_NOTFOUND);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_PAGE_NOTFOUND", "I"), (jint) MDB_PAGE_NOTFOUND);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_CORRUPTED", "I"), (jint) MDB_CORRUPTED);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_PANIC", "I"), (jint) MDB_PANIC);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_VERSION_MISMATCH", "I"), (jint) MDB_VERSION_MISMATCH);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_INVALID", "I"), (jint) MDB_INVALID);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_MAP_FULL", "I"), (jint) MDB_MAP_FULL);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_DBS_FULL", "I"), (jint) MDB_DBS_FULL);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_READERS_FULL", "I"), (jint) MDB_READERS_FULL);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_TLS_FULL", "I"), (jint) MDB_TLS_FULL);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_TXN_FULL", "I"), (jint) MDB_TXN_FULL);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_CURSOR_FULL", "I"), (jint) MDB_CURSOR_FULL);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_PAGE_FULL", "I"), (jint) MDB_PAGE_FULL);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_MAP_RESIZED", "I"), (jint) MDB_MAP_RESIZED);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_INCOMPATIBLE", "I"), (jint) MDB_INCOMPATIBLE);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_BAD_RSLOT", "I"), (jint) MDB_BAD_RSLOT);
	(*env)->SetStaticIntField(env, that, (*env)->GetStaticFieldID(env, that, "MDB_LAST_ERRCODE", "I"), (jint) MDB_LAST_ERRCODE);
	return;
}

JNIEXPORT jstring JNICALL Java_org_glmdb_blueprints_jni_GlmdbJni_mdb_1strerror(JNIEnv *env, jclass that, jint error) {

	char *mdbError = mdb_strerror(error);
	jstring message = (*env)->NewStringUTF(env, mdbError);
	return message;

}

/*
 * Class:     org_glmdb_blueprints_jni_GlmdbJni
 * Method:    printVertexDb
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_org_glmdb_blueprints_jni_GlmdbJni_printVertexDb(JNIEnv *env, jclass that, jlong glmdbEnv) {

	int rc = 0;
	GLMDB_env * glmdb_env = (GLMDB_env *) (long) glmdbEnv;
	traverseDb(glmdb_env->env, glmdb_env->vertexDb);
	return rc;

}

JNIEXPORT jint JNICALL Java_org_glmdb_blueprints_jni_GlmdbJni_glmdb_1env_1create(JNIEnv * env, jclass that, jstring path,
		jlongArray pointerArray) {

	const char *dbPath = NULL;
	jlong *mdbEnv = NULL;
	jint rc = 0;
	if (path) {
		if ((dbPath = (*env)->GetStringUTFChars(env, path, NULL)) == NULL) {
			goto fail;
		}
	}
	if (pointerArray) {
		if ((mdbEnv = (*env)->GetLongArrayElements(env, pointerArray, NULL)) == NULL) {
			goto fail;
		}
	}
	rc = (jint) openGraph((GLMDB_env **) mdbEnv, dbPath);
	fail: if (pointerArray && mdbEnv) {
		(*env)->ReleaseLongArrayElements(env, pointerArray, mdbEnv, 0);
	}
	if (path && dbPath) {
		(*env)->ReleaseStringUTFChars(env, path, dbPath);
	}
	return rc;
}

JNIEXPORT void JNICALL Java_org_glmdb_blueprints_jni_GlmdbJni_glmdb_1env_1close(JNIEnv *env, jclass that, jlong glmdbEnv) {

	closeGraph((GLMDB_env *) (long) glmdbEnv);

}

JNIEXPORT jint JNICALL Java_org_glmdb_blueprints_jni_GlmdbJni_mdb_1txn_1begin(JNIEnv *env, jclass that, jlong glmdbEnv, jlong parent,
		jlong flags, jlongArray txnArray) {

	jint rc = 0;
	jlong *txn = NULL;
	GLMDB_env * glmdb_env = (GLMDB_env *) (long) glmdbEnv;
	if (txnArray) {
		if ((txn = (*env)->GetLongArrayElements(env, txnArray, NULL)) == NULL) {
			goto fail;
		}
	}
	rc = mdb_txn_begin(glmdb_env->env, (MDB_txn *) (long) parent, (unsigned int) flags, (MDB_txn **) txn);

	fail: if (txnArray && txn) {
		(*env)->ReleaseLongArrayElements(env, txnArray, txn, 0);
	}
	return rc;

}

JNIEXPORT jint JNICALL Java_org_glmdb_blueprints_jni_GlmdbJni_mdb_1txn_1renew(JNIEnv *env, jclass that, jlong txn) {

	jint rc = 0;
	rc = (jint) mdb_txn_renew((MDB_txn *) (long) txn);
	return rc;

}

JNIEXPORT jint JNICALL Java_org_glmdb_blueprints_jni_GlmdbJni_mdb_1txn_1commit(JNIEnv *env, jclass that, jlong txn) {

	jint rc = 0;
	rc = (jint) mdb_txn_commit((MDB_txn *) (long) txn);
	return rc;

}

JNIEXPORT void JNICALL Java_org_glmdb_blueprints_jni_GlmdbJni_mdb_1txn_1reset(JNIEnv *env, jclass that, jlong txn) {

	mdb_txn_reset((MDB_txn *) (long) txn);

}

JNIEXPORT void JNICALL Java_org_glmdb_blueprints_jni_GlmdbJni_mdb_1txn_1abort(JNIEnv *env, jclass that, jlong txn) {

	mdb_txn_abort((MDB_txn *) (long) txn);

}

//JNIEnv *env, jclass that, jlong arg0, jlong arg1, jlongArray arg2
JNIEXPORT jint JNICALL Java_org_glmdb_blueprints_jni_GlmdbJni_mdb_1cursor_1open_1vertex_1db(JNIEnv *env, jclass that, jlong txn,
		jlong glmdbEnv, jlongArray cursorArray) {

	jlong *cursor = NULL;
	jint rc = 0;
	GLMDB_env * glmdb_env = (GLMDB_env *) (long) glmdbEnv;
	if (cursorArray) {
		if ((cursor = (*env)->GetLongArrayElements(env, cursorArray, NULL)) == NULL) {
			goto fail;
		}
	}
	rc = (jint) mdb_cursor_open((MDB_txn *) (long) txn, glmdb_env->vertexDb, (MDB_cursor **) cursor);
	fail: if (cursorArray && cursor) {
		(*env)->ReleaseLongArrayElements(env, cursorArray, cursor, 0);
	}
	return rc;
}

/*
 * Class:     org_glmdb_blueprints_jni_GlmdbJni
 * Method:    mdb_cursor_open_edge_db
 * Signature: (JJ[J)I
 */
JNIEXPORT jint JNICALL Java_org_glmdb_blueprints_jni_GlmdbJni_mdb_1cursor_1open_1edge_1db(JNIEnv *env, jclass that, jlong txn,
		jlong glmdbEnv, jlongArray cursorArray) {

	jlong *cursor = NULL;
	jint rc = 0;
	GLMDB_env * glmdb_env = (GLMDB_env *) (long) glmdbEnv;
	if (cursorArray) {
		if ((cursor = (*env)->GetLongArrayElements(env, cursorArray, NULL)) == NULL) {
			goto fail;
		}
	}
	rc = (jint) mdb_cursor_open((MDB_txn *) (long) txn, glmdb_env->edgeDb, (MDB_cursor **) cursor);
	fail: if (cursorArray && cursor) {
		(*env)->ReleaseLongArrayElements(env, cursorArray, cursor, 0);
	}
	return rc;

}

/*
 * Class:     org_glmdb_blueprints_jni_GlmdbJni
 * Method:    mdb_cursor_close
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_org_glmdb_blueprints_jni_GlmdbJni_mdb_1cursor_1close(JNIEnv *env, jclass that, jlong cursor) {
	mdb_cursor_close((MDB_cursor *) (long) cursor);
}

/*
 * Class:     org_glmdb_blueprints_jni_GlmdbJni
 * Method:    mdb_cursor_renew
 * Signature: (JJ)I
 */
JNIEXPORT jint JNICALL Java_org_glmdb_blueprints_jni_GlmdbJni_mdb_1cursor_1renew(JNIEnv *env, jclass that, jlong txn, jlong cursor) {

	jint rc = 0;
	rc = (jint) mdb_cursor_renew((MDB_txn *) (long) txn, (MDB_cursor *) (long) cursor);
	return rc;

}

/*
 * Class:     org_glmdb_blueprints_jni_GlmdbJni
 * Method:    mdb_add_vertex
 * Signature: (JJ[J)I
 */
JNIEXPORT jint JNICALL Java_org_glmdb_blueprints_jni_GlmdbJni_mdb_1add_1vertex(JNIEnv *env, jclass that, jlong glmdbEnv, jlong cursor,
		jlongArray vertexIdArray) {

	jint rc = 0;
	jlong *vertexId = NULL;
	MDB_val vertexKey;
	GLMDB_env * glmdb_env = (GLMDB_env *) (long) glmdbEnv;
	if (vertexIdArray) {
		if ((vertexId = (*env)->GetLongArrayElements(env, vertexIdArray, NULL)) == NULL) {
			goto fail;
		}
	}
	rc = addVertex((MDB_cursor *) (long) cursor, glmdb_env->vertexDb, glmdb_env->vertexIdSequence, &vertexKey);
	glmdb_env->vertexIdSequence++;
	*vertexId = (*((VertexDbId *) (vertexKey.mv_data))).vertexId;

	fail: if (vertexIdArray && vertexId) {
		(*env)->ReleaseLongArrayElements(env, vertexIdArray, vertexId, 0);
	}
	return rc;

}

/*
 * Class:     org_glmdb_blueprints_jni_GlmdbJni
 * Method:    mdb_add_edge
 * Signature: (JJJJI[J)I
 */
JNIEXPORT jint JNICALL Java_org_glmdb_blueprints_jni_GlmdbJni_mdb_1add_1edge(JNIEnv *env, jclass that, jlong glmdbEnv, jlong txn,
		jlong outVertexId, jlong inVertexId, jint labelId, jlongArray edgeId) {

	jint rc = 0;
	jlong *edgeIdC = NULL;
	GLMDB_env * glmdb_env = (GLMDB_env *) (long) glmdbEnv;

	if (edgeId) {
		if ((edgeIdC = (*env)->GetLongArrayElements(env, edgeId, NULL)) == NULL) {
			goto fail;
		}
	}

	*edgeIdC = glmdb_env->edgeIdSequence++;

	rc = addEdge((MDB_txn *) (long) txn, glmdb_env->vertexDb, glmdb_env->edgeDb, *edgeIdC, (long) labelId, (long) outVertexId,
			(long) inVertexId);

	fail: if (edgeId && edgeIdC) {
		(*env)->ReleaseLongArrayElements(env, edgeId, edgeIdC, 0);
	}
	return rc;
}

/*
 * Class:     org_glmdb_blueprints_jni_GlmdbJni
 * Method:    mdb_set_property_boolean
 * Signature: (JJIZZ)I
 */
JNIEXPORT jint JNICALL Java_org_glmdb_blueprints_jni_GlmdbJni_mdb_1set_1property_1boolean(JNIEnv *env, jclass that, jlong cursor,
		jlong elementId, jint propertyKeyId, jboolean value, jboolean vertexKey) {

	jint rc = 0;
	if (vertexKey) {
		rc = setVertexPropertyBoolean((MDB_cursor *) (long) cursor, (long) elementId, (int) propertyKeyId, &value);
	} else {
		rc = setEdgePropertyBoolean((MDB_cursor *) (long) cursor, (long) elementId, (int) propertyKeyId, &value);
	}
	return rc;

}

/*
 * Class:     org_glmdb_blueprints_jni_GlmdbJni
 * Method:    mdb_set_property_byte
 * Signature: (JJIBZ)I
 */
JNIEXPORT jint JNICALL Java_org_glmdb_blueprints_jni_GlmdbJni_mdb_1set_1property_1byte(JNIEnv *env, jclass that, jlong cursor,
		jlong elementId, jint propertyKeyId, jbyte value, jboolean vertexKey) {

	jint rc = 0;
	if (vertexKey) {
		rc = setVertexPropertyByte((MDB_cursor *) (long) cursor, (long) elementId, (int) propertyKeyId, &value);
	} else {
		rc = setEdgePropertyByte((MDB_cursor *) (long) cursor, (long) elementId, (int) propertyKeyId, &value);
	}
	return rc;

}

/*
 * Class:     org_glmdb_blueprints_jni_GlmdbJni
 * Method:    mdb_set_property_short
 * Signature: (JJISZ)I
 */
JNIEXPORT jint JNICALL Java_org_glmdb_blueprints_jni_GlmdbJni_mdb_1set_1property_1short(JNIEnv *env, jclass that, jlong cursor,
		jlong elementId, jint propertyKeyId, jshort value, jboolean vertexKey) {

	jint rc = 0;
	if (vertexKey) {
		rc = setVertexPropertyShort((MDB_cursor *) (long) cursor, (long) elementId, (int) propertyKeyId, &value);
	} else {
		rc = setEdgePropertyShort((MDB_cursor *) (long) cursor, (long) elementId, (int) propertyKeyId, &value);
	}
	return rc;

}

/*
 * Class:     org_glmdb_blueprints_jni_GlmdbJni
 * Method:    mdb_set_property_int
 * Signature: (JJIIZ)I
 */
JNIEXPORT jint JNICALL Java_org_glmdb_blueprints_jni_GlmdbJni_mdb_1set_1property_1int(JNIEnv *env, jclass that, jlong cursor,
		jlong elementId, jint propertyKeyId, jint value, jboolean vertexKey) {

	jint rc = 0;
	if (vertexKey) {
		rc = setVertexPropertyInt((MDB_cursor *) (long) cursor, (long) elementId, (int) propertyKeyId, &value);
	} else {
		rc = setEdgePropertyInt((MDB_cursor *) (long) cursor, (long) elementId, (int) propertyKeyId, &value);
	}
	return rc;

}

/*
 * Class:     org_glmdb_blueprints_jni_GlmdbJni
 * Method:    mdb_set_property_long
 * Signature: (JJIJZ)I
 */
JNIEXPORT jint JNICALL Java_org_glmdb_blueprints_jni_GlmdbJni_mdb_1set_1property_1long(JNIEnv *env, jclass that, jlong cursor,
		jlong elementId, jint propertyKeyId, jlong value, jboolean vertexKey) {

	jint rc = 0;
	if (vertexKey) {
		rc = setVertexPropertyLong((MDB_cursor *) (long) cursor, (long) elementId, (int) propertyKeyId, &value);
	} else {
		rc = setEdgePropertyLong((MDB_cursor *) (long) cursor, (long) elementId, (int) propertyKeyId, &value);
	}
	return rc;

}

/*
 * Class:     org_glmdb_blueprints_jni_GlmdbJni
 * Method:    mdb_set_property_float
 * Signature: (JJIFZ)I
 */
JNIEXPORT jint JNICALL Java_org_glmdb_blueprints_jni_GlmdbJni_mdb_1set_1property_1float(JNIEnv *env, jclass that, jlong cursor,
		jlong elementId, jint propertyKeyId, jfloat value, jboolean vertexKey) {

	jint rc = 0;
	if (vertexKey) {
		rc = setVertexPropertyFloat((MDB_cursor *) (long) cursor, (long) elementId, (int) propertyKeyId, &value);
	} else {
		rc = setEdgePropertyFloat((MDB_cursor *) (long) cursor, (long) elementId, (int) propertyKeyId, &value);
	}
	return rc;

}

/*
 * Class:     org_glmdb_blueprints_jni_GlmdbJni
 * Method:    mdb_set_property_double
 * Signature: (JJIDZ)I
 */
JNIEXPORT jint JNICALL Java_org_glmdb_blueprints_jni_GlmdbJni_mdb_1set_1property_1double(JNIEnv *env, jclass that, jlong cursor,
		jlong elementId, jint propertyKeyId, jdouble value, jboolean vertexKey) {

	jint rc = 0;
	if (vertexKey) {
		rc = setVertexPropertyDouble((MDB_cursor *) (long) cursor, (long) elementId, (int) propertyKeyId, &value);
	} else {
		rc = setEdgePropertyDouble((MDB_cursor *) (long) cursor, (long) elementId, (int) propertyKeyId, &value);
	}
	return rc;

}

/*
 * Class:     org_glmdb_blueprints_jni_GlmdbJni
 * Method:    mdb_set_property_char
 * Signature: (JJICZ)I
 */
JNIEXPORT jint JNICALL Java_org_glmdb_blueprints_jni_GlmdbJni_mdb_1set_1property_1char(JNIEnv *env, jclass that, jlong cursor,
		jlong elementId, jint propertyKeyId, jchar value, jboolean vertexKey) {

	jint rc = 0;
	if (vertexKey) {
		rc = setVertexPropertyChar((MDB_cursor *) (long) cursor, (long) elementId, (int) propertyKeyId, &value);
	} else {
		rc = setEdgePropertyChar((MDB_cursor *) (long) cursor, (long) elementId, (int) propertyKeyId, &value);
	}
	return rc;

}

/*
 * Class:     org_glmdb_blueprints_jni_GlmdbJni
 * Method:    mdb_set_property_string
 * Signature: (JJILjava/lang/String;Z)I
 */
JNIEXPORT jint JNICALL Java_org_glmdb_blueprints_jni_GlmdbJni_mdb_1set_1property_1string(JNIEnv *env, jclass that, jlong cursor,
		jlong elementId, jint propertyKeyId, jstring value, jboolean vertexKey) {

	jint rc = 0;
	jint strlen = (*env)->GetStringUTFLength(env, value);
	char *propertyValue = malloc(strlen);
	if (value) {
		(*env)->GetStringUTFRegion(env, value, 0, strlen, propertyValue);
		if (propertyValue == NULL) {
			goto fail;
		}
	}
	if (vertexKey) {
		rc = setVertexPropertyString((MDB_cursor *) (long) cursor, (long) elementId, (int) propertyKeyId, propertyValue);
	} else {
		rc = setEdgePropertyString((MDB_cursor *) (long) cursor, (long) elementId, (int) propertyKeyId, propertyValue);
	}

	fail: if (value && propertyValue) {
		(*env)->ReleaseStringUTFChars(env, value, propertyValue);
	}
	return rc;

}

/*
 * Class:     org_glmdb_blueprints_jni_GlmdbJni
 * Method:    mdb_get_property_array
 * Signature: (JJI[[BZ)I
 */
JNIEXPORT jint JNICALL Java_org_glmdb_blueprints_jni_GlmdbJni_mdb_1get_1property_1array(JNIEnv *env, jclass that, jlong cursor,
		jlong elementId, jint propertyKeyId, jobjectArray value, jboolean vertexKey) {

	jint rc = 0;
	MDB_val data;
	if (vertexKey) {
		rc = getVertexProperty((MDB_cursor *) (long) cursor, (long) elementId, (int) propertyKeyId, &data);
	} else {
		rc = getEdgeProperty((MDB_cursor *) (long) cursor, (long) elementId, (int) propertyKeyId, &data);
	}
	if (rc == 0) {
		jbyteArray byteArray = (*env)->NewByteArray(env, (size_t) data.mv_size);
		jbyte *cbytes = (*env)->GetByteArrayElements(env, byteArray, NULL);
		memcpy(cbytes, data.mv_data, data.mv_size);
		(*env)->SetObjectArrayElement(env, value, 0, byteArray);
		(*env)->ReleaseByteArrayElements(env, byteArray, cbytes, 0);
	}
	return rc;

}

/*
 * Class:     org_glmdb_blueprints_jni_GlmdbJni
 * Method:    mdb_get_property
 * Signature: (JJILorg/glmdb/blueprints/jni/Value;)I
 */
JNIEXPORT jint JNICALL Java_org_glmdb_blueprints_jni_GlmdbJni_mdb_1get_1property(JNIEnv *env, jclass that, jlong cursor, jlong vertexId,
		jint propertyKeyId, jobject value) {

	jint rc = 0;
	//TODO cache this
	jclass valueClass = (*env)->GetObjectClass(env, value);
	jfieldID mvDataFieldId = (*env)->GetFieldID(env, valueClass, "mv_data", "[B");

	MDB_val data;
	rc = getVertexProperty((MDB_cursor *) (long) cursor, (long) vertexId, (int) propertyKeyId, &data);

	jbyteArray byteArray = (*env)->NewByteArray(env, (size_t) data.mv_size);
	jbyte *cbytes = (*env)->GetByteArrayElements(env, byteArray, NULL);

	if (rc == 0) {
		memcpy(cbytes, data.mv_data, data.mv_size);
	}
	(*env)->SetObjectField(env, value, mvDataFieldId, byteArray);
	(*env)->ReleaseByteArrayElements(env, byteArray, cbytes, 0);
	return rc;
}

/*
 * Class:     org_glmdb_blueprints_jni_GlmdbJni
 * Method:    mdb_set_propertykey
 * Signature: (JJLjava/lang/String;I[I)I
 */
JNIEXPORT jint JNICALL Java_org_glmdb_blueprints_jni_GlmdbJni_mdb_1set_1propertykey(JNIEnv *env, jclass that, jlong glmdbEnv, jlong txn,
		jstring propertyKey, jint propertyKeyEnum, jintArray propertyKeyIdArray) {

	jint rc = 0;
	jint *propertyKeyId = NULL;
	MDB_cursor *cursor;
	GLMDB_env *glmdb_env = (GLMDB_env *) (long) glmdbEnv;
	MDB_dbi propertyKeyDb = glmdb_env->propertyKeyDb;

	jint strlen = (*env)->GetStringUTFLength(env, propertyKey);
	char *propertyKeyC = malloc(strlen);
	if (propertyKey) {
		(*env)->GetStringUTFRegion(env, propertyKey, 0, strlen, propertyKeyC);
		if (propertyKeyC == NULL) {
			goto fail;
		}
	}

	if (propertyKeyIdArray) {
		if ((propertyKeyId = (*env)->GetIntArrayElements(env, propertyKeyIdArray, NULL)) == NULL) {
			goto fail;
		}
	}

	PropertyKeyStruct *propertyKeyIdStruct = (PropertyKeyStruct*) malloc(sizeof(PropertyKeyStruct));
	propertyKeyIdStruct->propertyKeyId = glmdb_env->propertyKeyIdSequence++;
	switch ((int) propertyKeyEnum) {
	case GLMDB_BOOLEAN:
		propertyKeyIdStruct->type = BOOLEAN;
		break;
	case GLMDB_BYTE:
		propertyKeyIdStruct->type = BYTE;
		break;
	case GLMDB_SHORT:
		propertyKeyIdStruct->type = SHORT;
		break;
	case GLMDB_INT:
		propertyKeyIdStruct->type = INT;
		break;
	case GLMDB_LONG:
		propertyKeyIdStruct->type = LONG;
		break;
	case GLMDB_DOUBLE:
		propertyKeyIdStruct->type = DOUBLE;
		break;
	case GLMDB_CHAR:
		propertyKeyIdStruct->type = CHAR;
		break;
	case GLMDB_STRING:
		propertyKeyIdStruct->type = STRING;
		break;
	case GLMDB_ARRAY_BOOLEAN:
		propertyKeyIdStruct->type = ARRAY_BOOLEAN;
		break;
	case GLMDB_ARRAY_BYTE:
		propertyKeyIdStruct->type = ARRAY_BYTE;
		break;
	case GLMDB_ARRAY_SHORT:
		propertyKeyIdStruct->type = ARRAY_SHORT;
		break;
	case GLMDB_ARRAY_INT:
		propertyKeyIdStruct->type = ARRAY_INT;
		break;
	case GLMDB_ARRAY_LONG:
		propertyKeyIdStruct->type = ARRAY_LONG;
		break;
	case GLMDB_ARRAY_DOUBLE:
		propertyKeyIdStruct->type = ARRAY_DOUBLE;
		break;
	case GLMDB_ARRAY_CHAR:
		propertyKeyIdStruct->type = ARRAY_CHAR;
		break;
	case GLMDB_ARRAY_STRING:
		propertyKeyIdStruct->type = ARRAY_STRING;
		break;
	}

	MDB_val key, data;
	key.mv_size = (size_t) strlen;
	key.mv_data = propertyKeyC;
	data.mv_size = sizeof(PropertyKeyStruct);
	data.mv_data = propertyKeyIdStruct;
	rc = mdb_cursor_open((MDB_txn *) (long) txn, propertyKeyDb, &cursor);
	if (rc != 0)
		goto fail;
	rc = mdb_cursor_put(cursor, &key, &data, MDB_NOOVERWRITE);
	if (rc != 0)
		goto fail;

	*propertyKeyId = (*((PropertyKeyStruct *) (data.mv_data))).propertyKeyId;

	fail: mdb_cursor_close(cursor);
	if (propertyKey && propertyKeyC) {
		(*env)->ReleaseStringUTFChars(env, propertyKey, propertyKeyC);
	}
	if (propertyKeyIdArray && propertyKeyId) {
		(*env)->ReleaseIntArrayElements(env, propertyKeyIdArray, propertyKeyId, 0);
	}
	return rc;
}

/*
 * Class:     org_glmdb_blueprints_jni_GlmdbJni
 * Method:    mdb_set_label
 * Signature: (JJLjava/lang/String;[I)I
 */
JNIEXPORT jint JNICALL Java_org_glmdb_blueprints_jni_GlmdbJni_mdb_1set_1label(JNIEnv *env, jclass that, jlong glmdbEnv, jlong txn,
		jstring label, jintArray labelIdArray) {

	jint rc = 0;
	jint *labelId = NULL;
	MDB_cursor *cursor;
	GLMDB_env *glmdb_env = (GLMDB_env *) (long) glmdbEnv;
	MDB_dbi labelDb = glmdb_env->labelDb;

	jint strlen = (*env)->GetStringUTFLength(env, label);
	char *labelC = malloc(strlen);
	if (label) {
		(*env)->GetStringUTFRegion(env, label, 0, strlen, labelC);
		if (labelC == NULL) {
			goto fail;
		}
	}

	if (labelIdArray) {
		if ((labelId = (*env)->GetIntArrayElements(env, labelIdArray, NULL)) == NULL) {
			goto fail;
		}
	}

	*labelId = glmdb_env->labelIdSequence++;

	MDB_val key, data;
	key.mv_size = (size_t) strlen;
	key.mv_data = labelC;
	data.mv_size = sizeof(jint);
	data.mv_data = labelId;
	rc = mdb_cursor_open((MDB_txn *) (long) txn, labelDb, &cursor);
	if (rc != 0) {
		goto fail;
	}
	rc = mdb_cursor_put(cursor, &key, &data, MDB_NOOVERWRITE);
	if (rc != 0) {
		goto fail;
	}

	*labelId = *((jint *) (data.mv_data));

	fail: mdb_cursor_close(cursor);
	if (label && labelC) {
		(*env)->ReleaseStringUTFChars(env, label, labelC);
	}
	if (labelIdArray && labelId) {
		(*env)->ReleaseIntArrayElements(env, labelIdArray, labelId, 0);
	}
	return rc;

}

/*
 * Class:     org_glmdb_blueprints_jni_GlmdbJni
 * Method:    mdb_get_vertex
 * Signature: (JJ[J)I
 */
JNIEXPORT jint JNICALL Java_org_glmdb_blueprints_jni_GlmdbJni_mdb_1get_1vertex(JNIEnv *env, jclass that, jlong cursor, jlong vertexId,
		jlongArray vertexIdResult) {

	jint rc = 0;
	jlong *vertexIdResultC = NULL;

	if (vertexIdResult) {
		if ((vertexIdResultC = (*env)->GetLongArrayElements(env, vertexIdResult, NULL)) == NULL) {
			goto fail;
		}
	}

	MDB_val key;
	rc = getVertex((MDB_cursor *) (long) cursor, vertexId, &key);
	if (rc != 0) {
		goto fail;
	}

	VertexDbId vertexDbId = *((VertexDbId *) (key.mv_data));
	*vertexIdResultC = vertexDbId.vertexId;

	fail: if (vertexIdResult && vertexIdResultC) {
		(*env)->ReleaseLongArrayElements(env, vertexIdResult, vertexIdResultC, 0);
	}
	return rc;
}

/*
 * Class:     org_glmdb_blueprints_jni_GlmdbJni
 * Method:    mdb_get_first_vertex
 * Signature: (J[J)I
 */
JNIEXPORT jint JNICALL Java_org_glmdb_blueprints_jni_GlmdbJni_mdb_1get_1first_1vertex(JNIEnv *env, jclass that, jlong cursor,
		jlongArray vertexIdResult) {

	jint rc = 0;
	jlong *vertexIdResultC = NULL;

	if (vertexIdResult) {
		if ((vertexIdResultC = (*env)->GetLongArrayElements(env, vertexIdResult, NULL)) == NULL) {
			goto fail;
		}
	}

	unsigned char foundVertex = 1;
	MDB_val key, data;

	rc = mdb_cursor_get((MDB_cursor *) (long) cursor, &key, &data, MDB_FIRST);
	if (rc == 0) {
		VertexDbId vertexDbId = *((VertexDbId *) (key.mv_data));
		if (vertexDbId.coreOrPropertyEnum == VCORE) {
			printf("found it on first entry\n");

			printRecord(key, data);

			foundVertex = 0;
		} else {
			//TODO error codes
			rc = -1;
		}
	}

	if (rc == 0 && foundVertex == 0) {
		VertexDbId vertexDbId = *((VertexDbId *) (key.mv_data));
		*vertexIdResultC = vertexDbId.vertexId;
	}

	fail: if (vertexIdResult && vertexIdResultC) {
		(*env)->ReleaseLongArrayElements(env, vertexIdResult, vertexIdResultC, 0);
	}
	return rc;

}

/*
 * Class:     org_glmdb_blueprints_jni_GlmdbJni
 * Method:    mdb_get_next_vertex
 * Signature: (J[J)I
 */
JNIEXPORT jint JNICALL Java_org_glmdb_blueprints_jni_GlmdbJni_mdb_1get_1next_1vertex(JNIEnv *env, jclass that, jlong cursor,
		jlongArray vertexIdResult) {

	jint rc = 0;
	jlong *vertexIdResultC = NULL;

	if (vertexIdResult) {
		if ((vertexIdResultC = (*env)->GetLongArrayElements(env, vertexIdResult, NULL)) == NULL) {
			goto fail;
		}
	}

	unsigned char foundVertex = 1;
	MDB_val key, data;
	while ((rc = mdb_cursor_get((MDB_cursor *) (long) cursor, &key, &data, MDB_NEXT)) == 0) {
		VertexDbId vertexDbId = *((VertexDbId *) (key.mv_data));
		switch (vertexDbId.coreOrPropertyEnum) {
		case VCORE:
			foundVertex = 0;
			break;
		default:
			break;
		}
		if (foundVertex == 0) {
			break;
		}
	}

	if (rc == 0 && foundVertex == 0) {
		VertexDbId vertexDbId = *((VertexDbId *) (key.mv_data));
		*vertexIdResultC = vertexDbId.vertexId;
	}

	fail: if (vertexIdResult && vertexIdResultC) {
		(*env)->ReleaseLongArrayElements(env, vertexIdResult, vertexIdResultC, 0);
	}
	return rc;

}

/*
 * Class:     org_glmdb_blueprints_jni_GlmdbJni
 * Method:    mdb_get_first_vertex_for_key_value
 * Signature: (J[JI[B)I
 */
JNIEXPORT jint JNICALL Java_org_glmdb_blueprints_jni_GlmdbJni_mdb_1get_1first_1vertex_1for_1key_1value(JNIEnv *env, jclass that,
		jlong cursor, jlongArray vertexIdResult, jint propertyKey, jbyteArray value) {

	jint rc = 0;
	jlong *vertexIdResultC = NULL;
	jbyte *valueC = NULL;

	if (vertexIdResult) {
		if ((vertexIdResultC = (*env)->GetLongArrayElements(env, vertexIdResult, NULL)) == NULL) {
			goto fail;
		}
	}
	if (value) {
		if ((valueC = (*env)->GetByteArrayElements(env, value, NULL)) == NULL) {
			goto fail;
		}
	}

	unsigned char foundPropertyKeyAndValue = 1;
	MDB_val key, data;
	rc = mdb_cursor_get((MDB_cursor *) (long) cursor, &key, &data, MDB_FIRST);
	if (rc == 0) {

		VertexDbId vertexDbId = *((VertexDbId *) (key.mv_data));
		if (vertexDbId.coreOrPropertyEnum == VPROPERTY_KEY && vertexDbId.propertykeyId == (int) propertyKey) {
			//TODO this should never happen as the first entry is VCORE
			rc = -1;
		}

	}
	if (foundPropertyKeyAndValue != 0) {
		while ((rc = mdb_cursor_get((MDB_cursor *) (long) cursor, &key, &data, MDB_NEXT)) == 0) {
			VertexDbId vertexDbId = *((VertexDbId *) (key.mv_data));

			if (vertexDbId.coreOrPropertyEnum == VPROPERTY_KEY && vertexDbId.propertykeyId == (int) propertyKey) {

				if (memcmp(valueC, data.mv_data, data.mv_size) == 0) {
					foundPropertyKeyAndValue = 0;
					break;
				}

			}
		}
	}
	if (rc == 0 && foundPropertyKeyAndValue == 0) {
		VertexDbId vertexDbId = *((VertexDbId *) (key.mv_data));
		*vertexIdResultC = vertexDbId.vertexId;
	}

	fail: if (vertexIdResult && vertexIdResultC) {
		(*env)->ReleaseLongArrayElements(env, vertexIdResult, vertexIdResultC, 0);
	}
	if (value && valueC) {
		(*env)->ReleaseByteArrayElements(env, value, valueC, 0);
	}
	return rc;

}

/*
 * Class:     org_glmdb_blueprints_jni_GlmdbJni
 * Method:    mdb_get_next_vertex_for_key_value
 * Signature: (J[JI[B)I
 */
JNIEXPORT jint JNICALL Java_org_glmdb_blueprints_jni_GlmdbJni_mdb_1get_1next_1vertex_1for_1key_1value(JNIEnv * env, jclass that,
		jlong cursor, jlongArray vertexIdResult, jint propertyKey, jbyteArray value) {

	jint rc = 0;
	jlong *vertexIdResultC = NULL;
	jbyte *valueC = NULL;

	if (vertexIdResult) {
		if ((vertexIdResultC = (*env)->GetLongArrayElements(env, vertexIdResult, NULL)) == NULL) {
			goto fail;
		}
	}
	if (value) {
		if ((valueC = (*env)->GetByteArrayElements(env, value, NULL)) == NULL) {
			goto fail;
		}
	}

	unsigned char foundPropertyKeyAndValue = 1;
	MDB_val key, data;
	while ((rc = mdb_cursor_get((MDB_cursor *) (long) cursor, &key, &data, MDB_NEXT)) == 0) {
		VertexDbId vertexDbId = *((VertexDbId *) (key.mv_data));
		if (vertexDbId.coreOrPropertyEnum == VPROPERTY_KEY && vertexDbId.propertykeyId == (int) propertyKey) {

			if (memcmp(valueC, data.mv_data, data.mv_size) == 0) {
				foundPropertyKeyAndValue = 0;
				break;
			}
		}
	}

	if (rc == 0 && foundPropertyKeyAndValue == 0) {
		VertexDbId vertexDbId = *((VertexDbId *) (key.mv_data));
		*vertexIdResultC = vertexDbId.vertexId;
	}

	fail: if (vertexIdResult && vertexIdResultC) {
		(*env)->ReleaseLongArrayElements(env, vertexIdResult, vertexIdResultC, 0);
	}
	if (value && valueC) {
		(*env)->ReleaseByteArrayElements(env, value, valueC, 0);
	}

	return rc;

}

/*
 * Class:     org_glmdb_blueprints_jni_GlmdbJni
 * Method:    mdb_get_edge
 * Signature: (JJ[J[I[J[J)I
 */
JNIEXPORT jint JNICALL Java_org_glmdb_blueprints_jni_GlmdbJni_mdb_1get_1edge(JNIEnv *env, jclass that, jlong cursor, jlong edgeId,
		jlongArray edgeIdResult, jintArray labelId, jlongArray outVertexId, jlongArray inVertexId) {

	jint rc = 0;
	jlong *edgeIdResultC = NULL;
	jlong *outVertexIdC = NULL;
	jlong *inVertexIdC = NULL;
	jint *labelIdC = NULL;

	if (edgeIdResult) {
		if ((edgeIdResultC = (*env)->GetLongArrayElements(env, edgeIdResult, NULL)) == NULL) {
			goto fail;
		}
	}
	if (outVertexId) {
		if ((outVertexIdC = (*env)->GetLongArrayElements(env, outVertexId, NULL)) == NULL) {
			goto fail;
		}
	}
	if (inVertexId) {
		if ((inVertexIdC = (*env)->GetLongArrayElements(env, inVertexId, NULL)) == NULL) {
			goto fail;
		}
	}
	if (labelId) {
		if ((labelIdC = (*env)->GetIntArrayElements(env, labelId, NULL)) == NULL) {
			goto fail;
		}
	}

	MDB_val key, data;
	EdgeDbId id;
	id.edgeId = (long) edgeId;
	id.coreOrPropertyEnum = ECORE;
	id.propertykeyId = -1;
	key.mv_size = sizeof(EdgeDbId);
	key.mv_data = &id;
	rc = mdb_cursor_get((MDB_cursor *) (long) cursor, &key, &data, MDB_SET_KEY);

	if (rc == 0) {
		EdgeDbId edgeDbId = *((EdgeDbId *) (key.mv_data));
		*edgeIdResultC = edgeDbId.edgeId;
		EdgeData edgeData = *((EdgeData *) (data.mv_data));
		*outVertexIdC = edgeData.vertexOutId;
		*inVertexIdC = edgeData.vertexInId;
		*labelIdC = edgeData.labelId;
	}

	fail: if (edgeIdResult && edgeIdResultC) {
		(*env)->ReleaseLongArrayElements(env, edgeIdResult, edgeIdResultC, 0);
	}
	if (outVertexId && outVertexIdC) {
		(*env)->ReleaseLongArrayElements(env, outVertexId, outVertexIdC, 0);
	}
	if (inVertexId && inVertexIdC) {
		(*env)->ReleaseLongArrayElements(env, inVertexId, inVertexIdC, 0);
	}
	if (labelId && labelIdC) {
		(*env)->ReleaseIntArrayElements(env, labelId, labelIdC, 0);
	}
	return rc;

}

/*
 * Class:     org_glmdb_blueprints_jni_GlmdbJni
 * Method:    mdb_get_first_edge
 * Signature: (J[J[I[J[J)I
 */
JNIEXPORT jint JNICALL Java_org_glmdb_blueprints_jni_GlmdbJni_mdb_1get_1first_1edge(JNIEnv * env, jclass that, jlong cursor,
		jlongArray edgeIdResult, jintArray labelId, jlongArray outVertexId, jlongArray inVertexId) {

	jint rc = 0;
	jlong *edgeIdResultC = NULL;
	jlong *outVertexIdC = NULL;
	jlong *inVertexIdC = NULL;
	jint *labelIdC = NULL;

	if (edgeIdResult) {
		if ((edgeIdResultC = (*env)->GetLongArrayElements(env, edgeIdResult, NULL)) == NULL) {
			goto fail;
		}
	}
	if (outVertexId) {
		if ((outVertexIdC = (*env)->GetLongArrayElements(env, outVertexId, NULL)) == NULL) {
			goto fail;
		}
	}
	if (inVertexId) {
		if ((inVertexIdC = (*env)->GetLongArrayElements(env, inVertexId, NULL)) == NULL) {
			goto fail;
		}
	}
	if (labelId) {
		if ((labelIdC = (*env)->GetIntArrayElements(env, labelId, NULL)) == NULL) {
			goto fail;
		}
	}

	unsigned char foundEdge = 1;
	MDB_val key, data;
	EdgeDbId id;
	id.edgeId = -1;
	id.coreOrPropertyEnum = ECORE;
	id.propertykeyId = -1;
	key.mv_size = sizeof(EdgeDbId);
	key.mv_data = &id;

	rc = mdb_cursor_get((MDB_cursor *) (long) cursor, &key, &data, MDB_FIRST);
	if (rc == 0) {
		EdgeDbId edgeDbId = *((EdgeDbId *) (key.mv_data));
		switch (edgeDbId.coreOrPropertyEnum) {
		case ECORE:
			foundEdge = 0;
			break;
		default:
			printf("did not understand mdb_cursor_get_first_edge, this should never happen!\n");
			//TODO glmdb error codes
			rc = -1;
			break;
		}
	}

	if (rc == 0 && foundEdge == 0) {
		EdgeDbId edgeDbId = *((EdgeDbId *) (key.mv_data));
		*edgeIdResultC = edgeDbId.edgeId;
		EdgeData edgeData = *((EdgeData *) (data.mv_data));
		*outVertexIdC = edgeData.vertexOutId;
		*inVertexIdC = edgeData.vertexInId;
		*labelIdC = edgeData.labelId;
	}

	fail: if (edgeIdResult && edgeIdResultC) {
		(*env)->ReleaseLongArrayElements(env, edgeIdResult, edgeIdResultC, 0);
	}
	if (outVertexId && outVertexIdC) {
		(*env)->ReleaseLongArrayElements(env, outVertexId, outVertexIdC, 0);
	}
	if (inVertexId && inVertexIdC) {
		(*env)->ReleaseLongArrayElements(env, inVertexId, inVertexIdC, 0);
	}
	if (labelId && labelIdC) {
		(*env)->ReleaseIntArrayElements(env, labelId, labelIdC, 0);
	}
	return rc;

}

/*
 * Class:     org_glmdb_blueprints_jni_GlmdbJni
 * Method:    mdb_get_next_edge
 * Signature: (J[J[I[J[J)I
 */
JNIEXPORT jint JNICALL Java_org_glmdb_blueprints_jni_GlmdbJni_mdb_1get_1next_1edge(JNIEnv *env, jclass that, jlong cursor,
		jlongArray edgeIdResult, jintArray labelId, jlongArray outVertexId, jlongArray inVertexId) {

	jint rc = 0;
	jlong *edgeIdResultC = NULL;
	jlong *outVertexIdC = NULL;
	jlong *inVertexIdC = NULL;
	jint *labelIdC = NULL;

	if (edgeIdResult) {
		if ((edgeIdResultC = (*env)->GetLongArrayElements(env, edgeIdResult, NULL)) == NULL) {
			goto fail;
		}
	}
	if (outVertexId) {
		if ((outVertexIdC = (*env)->GetLongArrayElements(env, outVertexId, NULL)) == NULL) {
			goto fail;
		}
	}
	if (inVertexId) {
		if ((inVertexIdC = (*env)->GetLongArrayElements(env, inVertexId, NULL)) == NULL) {
			goto fail;
		}
	}
	if (labelId) {
		if ((labelIdC = (*env)->GetIntArrayElements(env, labelId, NULL)) == NULL) {
			goto fail;
		}
	}

	unsigned char foundEdge = 1;
	MDB_val key, data;
	EdgeDbId id;
	id.edgeId = -1;
	id.coreOrPropertyEnum = ECORE;
	id.propertykeyId = -1;
	key.mv_size = sizeof(EdgeDbId);
	key.mv_data = &id;

	while ((rc = mdb_cursor_get((MDB_cursor *) (long) cursor, &key, &data, MDB_NEXT)) == 0) {
		EdgeDbId edgeDbId = *((EdgeDbId *) (key.mv_data));
		switch (edgeDbId.coreOrPropertyEnum) {
		case ECORE:
			foundEdge = 0;
			break;
		default:
			break;
		}
		if (foundEdge == 0) {
			break;
		}
	}

	if (rc == 0 && foundEdge == 0) {
		EdgeDbId edgeDbId = *((EdgeDbId *) (key.mv_data));
		*edgeIdResultC = edgeDbId.edgeId;
		EdgeData edgeData = *((EdgeData *) (data.mv_data));
		*outVertexIdC = edgeData.vertexOutId;
		*inVertexIdC = edgeData.vertexInId;
		*labelIdC = edgeData.labelId;
	}

	fail: if (edgeIdResult && edgeIdResultC) {
		(*env)->ReleaseLongArrayElements(env, edgeIdResult, edgeIdResultC, 0);
	}
	if (outVertexId && outVertexIdC) {
		(*env)->ReleaseLongArrayElements(env, outVertexId, outVertexIdC, 0);
	}
	if (inVertexId && inVertexIdC) {
		(*env)->ReleaseLongArrayElements(env, inVertexId, inVertexIdC, 0);
	}
	if (labelId && labelIdC) {
		(*env)->ReleaseIntArrayElements(env, labelId, labelIdC, 0);
	}
	return rc;
}

/*
 * Class:     org_glmdb_blueprints_jni_GlmdbJni
 * Method:    mdb_get_first_edge_for_key_value
 * Signature: (J[J[I[J[JI[B)I
 */
JNIEXPORT jint JNICALL Java_org_glmdb_blueprints_jni_GlmdbJni_mdb_1get_1first_1edge_1for_1key_1value(JNIEnv *env, jclass that, jlong cursor,
		jlongArray edgeIdResult, jintArray labelId, jlongArray outVertexId, jlongArray inVertexId, jint propertyKey, jbyteArray value) {

	jint rc = 0;
	jlong *edgeIdResultC = NULL;
	jlong *outVertexIdC = NULL;
	jlong *inVertexIdC = NULL;
	jint *labelIdC = NULL;
	jbyte *valueC = NULL;

	if (edgeIdResult) {
		if ((edgeIdResultC = (*env)->GetLongArrayElements(env, edgeIdResult, NULL)) == NULL) {
			goto fail;
		}
	}
	if (outVertexId) {
		if ((outVertexIdC = (*env)->GetLongArrayElements(env, outVertexId, NULL)) == NULL) {
			goto fail;
		}
	}
	if (inVertexId) {
		if ((inVertexIdC = (*env)->GetLongArrayElements(env, inVertexId, NULL)) == NULL) {
			goto fail;
		}
	}
	if (labelId) {
		if ((labelIdC = (*env)->GetIntArrayElements(env, labelId, NULL)) == NULL) {
			goto fail;
		}
	}
	if (value) {
		if ((valueC = (*env)->GetByteArrayElements(env, value, NULL)) == NULL) {
			goto fail;
		}
	}

	unsigned char foundPropertyKeyAndValue = 1;
	MDB_val key, data;
	rc = mdb_cursor_get((MDB_cursor *) (long) cursor, &key, &data, MDB_FIRST);
	if (rc == 0) {

		EdgeDbId edgeDbId = *((EdgeDbId *) (key.mv_data));
		if (edgeDbId.coreOrPropertyEnum == EPROPERTY_KEY && edgeDbId.propertykeyId == (int) propertyKey) {
			//TODO this should never happen as the first entry is ECORE
			rc = -1;
		}

	}
	if (foundPropertyKeyAndValue != 0) {
		while ((rc = mdb_cursor_get((MDB_cursor *) (long) cursor, &key, &data, MDB_NEXT)) == 0) {
			EdgeDbId edgeDbId = *((EdgeDbId *) (key.mv_data));

			if (edgeDbId.coreOrPropertyEnum == EPROPERTY_KEY && edgeDbId.propertykeyId == (int) propertyKey) {

				if (memcmp(valueC, data.mv_data, data.mv_size) == 0) {
					foundPropertyKeyAndValue = 0;
					break;
				}

			}
		}
	}

	if (rc == 0 && foundPropertyKeyAndValue == 0) {
		EdgeDbId edgeDbId = *((EdgeDbId *) (key.mv_data));
		*edgeIdResultC = edgeDbId.edgeId;
		EdgeData edgeData = *((EdgeData *) (data.mv_data));
		*outVertexIdC = edgeData.vertexOutId;
		*inVertexIdC = edgeData.vertexInId;
		*labelIdC = edgeData.labelId;
	}

	fail: if (edgeIdResult && edgeIdResultC) {
		(*env)->ReleaseLongArrayElements(env, edgeIdResult, edgeIdResultC, 0);
	}
	if (outVertexId && outVertexIdC) {
		(*env)->ReleaseLongArrayElements(env, outVertexId, outVertexIdC, 0);
	}
	if (inVertexId && inVertexIdC) {
		(*env)->ReleaseLongArrayElements(env, inVertexId, inVertexIdC, 0);
	}
	if (labelId && labelIdC) {
		(*env)->ReleaseIntArrayElements(env, labelId, labelIdC, 0);
	}
	if (value && valueC) {
		(*env)->ReleaseByteArrayElements(env, value, valueC, 0);
	}
	return rc;

}

/*
 * Class:     org_glmdb_blueprints_jni_GlmdbJni
 * Method:    mdb_get_next_edge_for_key_value
 * Signature: (J[J[I[J[JI[B)I
 */
JNIEXPORT jint JNICALL Java_org_glmdb_blueprints_jni_GlmdbJni_mdb_1get_1next_1edge_1for_1key_1value(JNIEnv *env, jclass that, jlong cursor,
		jlongArray edgeIdResult, jintArray labelId, jlongArray outVertexId, jlongArray inVertexId, jint propertyKey, jbyteArray value) {

	jint rc = 0;
	jlong *edgeIdResultC = NULL;
	jlong *outVertexIdC = NULL;
	jlong *inVertexIdC = NULL;
	jint *labelIdC = NULL;
	jbyte *valueC = NULL;

	if (edgeIdResult) {
		if ((edgeIdResultC = (*env)->GetLongArrayElements(env, edgeIdResult, NULL)) == NULL) {
			goto fail;
		}
	}
	if (outVertexId) {
		if ((outVertexIdC = (*env)->GetLongArrayElements(env, outVertexId, NULL)) == NULL) {
			goto fail;
		}
	}
	if (inVertexId) {
		if ((inVertexIdC = (*env)->GetLongArrayElements(env, inVertexId, NULL)) == NULL) {
			goto fail;
		}
	}
	if (labelId) {
		if ((labelIdC = (*env)->GetIntArrayElements(env, labelId, NULL)) == NULL) {
			goto fail;
		}
	}
	if (value) {
		if ((valueC = (*env)->GetByteArrayElements(env, value, NULL)) == NULL) {
			goto fail;
		}
	}

	unsigned char foundPropertyKeyAndValue = 1;
	MDB_val key, data;
	while ((rc = mdb_cursor_get((MDB_cursor *) (long) cursor, &key, &data, MDB_NEXT)) == 0) {
		EdgeDbId edgeDbId = *((EdgeDbId *) (key.mv_data));
		if (edgeDbId.coreOrPropertyEnum == EPROPERTY_KEY && edgeDbId.propertykeyId == (int) propertyKey) {

			if (memcmp(valueC, data.mv_data, data.mv_size) == 0) {
				foundPropertyKeyAndValue = 0;
				break;
			}
		}
	}

	if (rc == 0 && foundPropertyKeyAndValue == 0) {
		EdgeDbId edgeDbId = *((EdgeDbId *) (key.mv_data));
		*edgeIdResultC = edgeDbId.edgeId;
		EdgeData edgeData = *((EdgeData *) (data.mv_data));
		*outVertexIdC = edgeData.vertexOutId;
		*inVertexIdC = edgeData.vertexInId;
		*labelIdC = edgeData.labelId;
	}

	fail: if (edgeIdResult && edgeIdResultC) {
		(*env)->ReleaseLongArrayElements(env, edgeIdResult, edgeIdResultC, 0);
	}
	if (outVertexId && outVertexIdC) {
		(*env)->ReleaseLongArrayElements(env, outVertexId, outVertexIdC, 0);
	}
	if (inVertexId && inVertexIdC) {
		(*env)->ReleaseLongArrayElements(env, inVertexId, inVertexIdC, 0);
	}
	if (labelId && labelIdC) {
		(*env)->ReleaseIntArrayElements(env, labelId, labelIdC, 0);
	}
	if (value && valueC) {
		(*env)->ReleaseByteArrayElements(env, value, valueC, 0);
	}
	return rc;

}

/*
 * Class:     org_glmdb_blueprints_jni_GlmdbJni
 * Method:    mdb_get_first_edge_from_vertex
 * Signature: (JIJ[J[J[J)I
 */
JNIEXPORT jint JNICALL Java_org_glmdb_blueprints_jni_GlmdbJni_mdb_1get_1first_1edge_1from_1vertex(JNIEnv * env, jclass that, jlong cursor,
		jint labelId, jlong fromVertexId, jlongArray edgeIdResult, jlongArray outVertexId, jlongArray inVertexId) {

	jint rc = 0;
	jlong *edgeIdResultC = NULL;
	jlong *outVertexIdC = NULL;
	jlong *inVertexIdC = NULL;

	if (edgeIdResult) {
		if ((edgeIdResultC = (*env)->GetLongArrayElements(env, edgeIdResult, NULL)) == NULL) {
			goto fail;
		}
	}
	if (outVertexId) {
		if ((outVertexIdC = (*env)->GetLongArrayElements(env, outVertexId, NULL)) == NULL) {
			goto fail;
		}
	}
	if (inVertexId) {
		if ((inVertexIdC = (*env)->GetLongArrayElements(env, inVertexId, NULL)) == NULL) {
			goto fail;
		}
	}

	rc = getFirstEdgefromVertex((MDB_cursor *) (long) cursor, labelId, fromVertexId, edgeIdResultC, outVertexIdC, inVertexIdC);

	fail: if (edgeIdResult && edgeIdResultC) {
		(*env)->ReleaseLongArrayElements(env, edgeIdResult, edgeIdResultC, 0);
	}
	if (outVertexId && outVertexIdC) {
		(*env)->ReleaseLongArrayElements(env, outVertexId, outVertexIdC, 0);
	}
	if (inVertexId && inVertexIdC) {
		(*env)->ReleaseLongArrayElements(env, inVertexId, inVertexIdC, 0);
	}
	return rc;

}

/*
 * Class:     org_glmdb_blueprints_jni_GlmdbJni
 * Method:    mdb_get_next_edge_from_vertex
 * Signature: (JIJ[J[J[J)I
 */
JNIEXPORT jint JNICALL Java_org_glmdb_blueprints_jni_GlmdbJni_mdb_1get_1next_1edge_1from_1vertex(JNIEnv *env, jclass that, jlong cursor,
		jint labelId, jlong fromVertexId, jlongArray edgeIdResult, jlongArray outVertexId, jlongArray inVertexId) {

	jint rc = 0;
	jlong *edgeIdResultC = NULL;
	jlong *outVertexIdC = NULL;
	jlong *inVertexIdC = NULL;

	if (edgeIdResult) {
		if ((edgeIdResultC = (*env)->GetLongArrayElements(env, edgeIdResult, NULL)) == NULL) {
			goto fail;
		}
	}
	if (outVertexId) {
		if ((outVertexIdC = (*env)->GetLongArrayElements(env, outVertexId, NULL)) == NULL) {
			goto fail;
		}
	}
	if (inVertexId) {
		if ((inVertexIdC = (*env)->GetLongArrayElements(env, inVertexId, NULL)) == NULL) {
			goto fail;
		}
	}

	rc = getNextEdgefromVertex((MDB_cursor *) (long) cursor, labelId, fromVertexId, edgeIdResultC, outVertexIdC, inVertexIdC);

	fail: if (edgeIdResult && edgeIdResultC) {
		(*env)->ReleaseLongArrayElements(env, edgeIdResult, edgeIdResultC, 0);
	}
	if (outVertexId && outVertexIdC) {
		(*env)->ReleaseLongArrayElements(env, outVertexId, outVertexIdC, 0);
	}
	if (inVertexId && inVertexIdC) {
		(*env)->ReleaseLongArrayElements(env, inVertexId, inVertexIdC, 0);
	}
	return rc;

}

void buffer_copy(const void *source, size_t source_pos, void *dest, size_t dest_pos, size_t length) {
	memmove(((char *) dest) + dest_pos, ((const char *) source) + source_pos, length);
}

int openGraph(GLMDB_env **genv, const char *path) {
	int rc;

	GLMDB_env *e;
	e = calloc(sizeof(GLMDB_env), 1);

	MDB_txn *txn;
	MDB_env *env;
	MDB_dbi configDb;
	MDB_dbi vertexDb;
	MDB_dbi edgeDb;
	MDB_dbi propertyKeyDb;
	MDB_dbi labelDb;

	rc = mdb_env_create(&env);
	if (rc != 0) {
		return rc;
	}
	rc = mdb_env_set_mapsize(env, 107374182400); //100G
	if (rc != 0) {
		return rc;
	}
	rc = mdb_env_set_maxdbs(env, 5);
	if (rc != 0) {
		return rc;
	}
	rc = mdb_env_open(env, path, MDB_NOSYNC, 0664);
	if (rc != 0) {
		return rc;
	}

//Create the config db
	rc = mdb_txn_begin(env, NULL, 0, &txn);
	if (rc != 0) {
		mdb_txn_abort(txn);
		return rc;
	}
	rc = mdb_open(txn, "configDb", MDB_CREATE, &configDb);
	if (rc != 0) {
		mdb_txn_abort(txn);
		return rc;
	}
	rc = mdb_txn_commit(txn);
	if (rc != 0) {
		return rc;
	}

//Create the vertex db
	rc = mdb_txn_begin(env, NULL, 0, &txn);
	if (rc != 0) {
		mdb_txn_abort(txn);
		return rc;
	}
	rc = mdb_open(txn, "vertexDb", MDB_CREATE|MDB_INTEGERKEY, &vertexDb);
	if (rc != 0) {
		mdb_txn_abort(txn);
		return rc;
	}
	rc = mdb_set_compare(txn, vertexDb, compareVertexDbId);
	if (rc != 0) {
		mdb_txn_abort(txn);
		return rc;
	}
	rc = mdb_txn_commit(txn);
	if (rc != 0) {
		mdb_txn_abort(txn);
		return rc;
	}

//Create the edge db
	rc = mdb_txn_begin(env, NULL, 0, &txn);
	if (rc != 0) {
		mdb_txn_abort(txn);
		return rc;
	}
	rc = mdb_open(txn, "edgeDb", MDB_CREATE|MDB_INTEGERKEY, &edgeDb);
	if (rc != 0) {
		mdb_txn_abort(txn);
		return rc;
	}
	rc = mdb_set_compare(txn, edgeDb, compareEdgeDbId);
	if (rc != 0) {
		mdb_txn_abort(txn);
		return rc;
	}
	rc = mdb_txn_commit(txn);
	if (rc != 0) {
		mdb_txn_abort(txn);
		return rc;
	}

//Create the property key db
	rc = mdb_txn_begin(env, NULL, 0, &txn);
	if (rc != 0) {
		mdb_txn_abort(txn);
		return rc;
	}
	rc = mdb_open(txn, "propertyKeyDb", MDB_CREATE, &propertyKeyDb);
	if (rc != 0) {
		mdb_txn_abort(txn);
		return rc;
	}
	rc = mdb_txn_commit(txn);
	if (rc != 0) {
		mdb_txn_abort(txn);
		return rc;
	}

	//Create the label db
	rc = mdb_txn_begin(env, NULL, 0, &txn);
	if (rc != 0) {
		mdb_txn_abort(txn);
		return rc;
	}
	rc = mdb_open(txn, "labelDb", MDB_CREATE, &labelDb);
	if (rc != 0) {
		mdb_txn_abort(txn);
		return rc;
	}
	rc = mdb_txn_commit(txn);
	if (rc != 0) {
		mdb_txn_abort(txn);
		return rc;
	}

	e->env = env;
	e->configDb = configDb;
	e->vertexDb = vertexDb;
	e->edgeDb = edgeDb;
	e->propertyKeyDb = propertyKeyDb;
	e->labelDb = labelDb;
	//TODO load from configDb
	e->vertexIdSequence = 0LL;
	e->edgeIdSequence = 0LL;
	e->propertyKeyIdSequence = 0;
	e->labelIdSequence = 0;
	*genv = e;
	return rc;
}

void closeGraph(GLMDB_env *genv) {
	MDB_env *env = genv->env;
	MDB_dbi configDb = genv->configDb;
	MDB_dbi vertexDb = genv->vertexDb;
	MDB_dbi edgeDb = genv->edgeDb;
	MDB_dbi propertyKeyDb = genv->propertyKeyDb;
	MDB_dbi labelDb = genv->labelDb;

	printDbStats(env, configDb, "configDb");
	printDbStats(env, vertexDb, "vertexDb");
	printDbStats(env, edgeDb, "edgeDb");
	printDbStats(env, propertyKeyDb, "propertyKeyDb");
	printDbStats(env, labelDb, "labelDb");

	mdb_close(env, configDb);
	mdb_close(env, vertexDb);
	mdb_close(env, edgeDb);
	mdb_close(env, propertyKeyDb);
	mdb_close(env, labelDb);
	mdb_env_close(env);
}

//MDB_val *vertexKey is out only
int addVertex(MDB_cursor *cursor, MDB_dbi vertexDb, jlong vertexId, MDB_val *vertexKey) {
	MDB_val data;
	VertexDbId id;
	initVertexDbId(&id);
	id.vertexId = vertexId;
	id.coreOrPropertyEnum = VCORE;
	(*vertexKey).mv_size = sizeof(VertexDbId);
	(*vertexKey).mv_data = &id;
	char myNull = '\0';
	data.mv_size = sizeof(char);
	data.mv_data = &myNull;
	return mdb_cursor_put(cursor, vertexKey, &data, MDB_NOOVERWRITE);
}

int getVertex(MDB_cursor *cursor, jlong vertexId, MDB_val *vertexKey) {
	MDB_val data;
	VertexDbId id;
	initVertexDbId(&id);
	id.vertexId = (long) vertexId;
	id.coreOrPropertyEnum = VCORE;
	(*vertexKey).mv_size = sizeof(VertexDbId);
	(*vertexKey).mv_data = &id;
	return mdb_cursor_get((MDB_cursor *) (long) cursor, vertexKey, &data, MDB_SET_KEY);
}

int getFirstEdgefromVertex(MDB_cursor *cursor, jint labelId, jlong fromVertexId, jlong *edgeIdResultC, jlong *outVertexIdC,
		jlong *inVertexIdC) {

	int rc;
	MDB_val key, data;
	VertexDbId id;
	initVertexDbId(&id);
	id.vertexId = fromVertexId;
	id.coreOrPropertyEnum = OUTLABEL;
	id.labelId = labelId;
	key.mv_size = sizeof(VertexDbId);
	key.mv_data = &id;
	rc = mdb_cursor_get((MDB_cursor *) (long) cursor, &key, &data, MDB_SET_RANGE);
	if (rc == 0) {
		VertexDbId vertexDbId = (*((VertexDbId *) (key.mv_data)));
		*edgeIdResultC = vertexDbId.edgeId;
		*outVertexIdC = vertexDbId.vertexId;
		*inVertexIdC = *((signed long long *) data.mv_data);
	}
	return rc;
}

int getNextEdgefromVertex(MDB_cursor *cursor, jint labelId, jlong fromVertexId, jlong *edgeIdResultC, jlong *outVertexIdC,
		jlong *inVertexIdC) {

	int rc = 0;
	VertexDbId id;
	initVertexDbId(&id);
	MDB_val key, data;
	key.mv_size = sizeof(VertexDbId);
	key.mv_data = &id;
	rc = mdb_cursor_get((MDB_cursor *) (long) cursor, &key, &data, MDB_NEXT);
	if (rc == 0) {
		VertexDbId vertexDbId = *((VertexDbId *) (key.mv_data));
		if (fromVertexId == vertexDbId.vertexId && vertexDbId.coreOrPropertyEnum == OUTLABEL && labelId == vertexDbId.labelId) {
			*edgeIdResultC = vertexDbId.edgeId;
			*outVertexIdC = vertexDbId.vertexId;
			*inVertexIdC = *((jlong *) (data.mv_data));
		} else {
			rc = GLMDB_END_OF_EDGES;
		}
	}
	return rc;
}

int setVertexPropertyString(MDB_cursor *cursor, jlong vertexId, jint propertyKeyId, char *propertyValue) {
	if (propertyValue != NULL) {
		MDB_val key, data;
		VertexDbId id;
		id.vertexId = vertexId;
		id.coreOrPropertyEnum = VPROPERTY_KEY;
		id.propertykeyId = propertyKeyId;
		id.labelId = -1;
		id.edgeId = -1LL;
		key.mv_size = sizeof(VertexDbId);
		key.mv_data = &id;
		data.mv_size = strlen(propertyValue);
		data.mv_data = propertyValue;
		return mdb_cursor_put(cursor, &key, &data, 0);
	} else {
		return GLMDB_WRITE_NULL;
	}
}

int setEdgePropertyString(MDB_cursor *cursor, jlong edgeId, jint propertyKeyId, char *propertyValue) {
	if (propertyValue != NULL) {
		MDB_val key, data;
		EdgeDbId id;
		id.edgeId = edgeId;
		id.coreOrPropertyEnum = EPROPERTY_KEY;
		id.propertykeyId = propertyKeyId;
		key.mv_size = sizeof(EdgeDbId);
		key.mv_data = &id;
		data.mv_size = strlen(propertyValue);
		data.mv_data = propertyValue;
		return mdb_cursor_put(cursor, &key, &data, 0);
	} else {
		return GLMDB_WRITE_NULL;
	}
}

int setVertexPropertyBoolean(MDB_cursor *cursor, jlong vertexId, jint propertyKeyId, jboolean *propertyValue) {
	if (propertyValue != NULL) {
		MDB_val key, data;
		VertexDbId id;
		id.vertexId = vertexId;
		id.coreOrPropertyEnum = VPROPERTY_KEY;
		id.propertykeyId = propertyKeyId;
		id.labelId = -1;
		id.edgeId = -1LL;
		key.mv_size = sizeof(VertexDbId);
		key.mv_data = &id;
		data.mv_size = sizeof(jboolean);
		data.mv_data = propertyValue;
		return mdb_cursor_put(cursor, &key, &data, 0);
	} else {
		return GLMDB_WRITE_NULL;
	}
}

int setEdgePropertyBoolean(MDB_cursor *cursor, jlong edgeId, jint propertyKeyId, jboolean *propertyValue) {
	if (propertyValue != NULL) {
		MDB_val key, data;
		EdgeDbId id;
		id.edgeId = edgeId;
		id.coreOrPropertyEnum = EPROPERTY_KEY;
		id.propertykeyId = propertyKeyId;
		key.mv_size = sizeof(EdgeDbId);
		key.mv_data = &id;
		data.mv_size = sizeof(jboolean);
		data.mv_data = propertyValue;
		return mdb_cursor_put(cursor, &key, &data, 0);
	} else {
		return GLMDB_WRITE_NULL;
	}
}

int setVertexPropertyByte(MDB_cursor *cursor, jlong vertexId, jint propertyKeyId, jbyte *propertyValue) {
	if (propertyValue != NULL) {
		MDB_val key, data;
		VertexDbId id;
		id.vertexId = vertexId;
		id.coreOrPropertyEnum = VPROPERTY_KEY;
		id.propertykeyId = propertyKeyId;
		id.labelId = -1;
		id.edgeId = -1LL;
		key.mv_size = sizeof(VertexDbId);
		key.mv_data = &id;
		data.mv_size = sizeof(jbyte);
		data.mv_data = propertyValue;
		return mdb_cursor_put(cursor, &key, &data, 0);
	} else {
		return GLMDB_WRITE_NULL;
	}
}

int setEdgePropertyByte(MDB_cursor *cursor, jlong edgeId, jint propertyKeyId, jbyte *propertyValue) {
	if (propertyValue != NULL) {
		MDB_val key, data;
		EdgeDbId id;
		id.edgeId = edgeId;
		id.coreOrPropertyEnum = EPROPERTY_KEY;
		id.propertykeyId = propertyKeyId;
		key.mv_size = sizeof(EdgeDbId);
		key.mv_data = &id;
		data.mv_size = sizeof(jbyte);
		data.mv_data = propertyValue;
		return mdb_cursor_put(cursor, &key, &data, 0);
	} else {
		return GLMDB_WRITE_NULL;
	}
}

int setVertexPropertyShort(MDB_cursor *cursor, jlong vertexId, jint propertyKeyId, jshort *propertyValue) {
	if (propertyValue != NULL) {
		MDB_val key, data;
		VertexDbId id;
		id.vertexId = vertexId;
		id.coreOrPropertyEnum = VPROPERTY_KEY;
		id.propertykeyId = propertyKeyId;
		id.labelId = -1;
		id.edgeId = -1LL;
		key.mv_size = sizeof(VertexDbId);
		key.mv_data = &id;
		data.mv_size = sizeof(jshort);
		data.mv_data = propertyValue;
		return mdb_cursor_put(cursor, &key, &data, 0);
	} else {
		return GLMDB_WRITE_NULL;
	}
}

int setEdgePropertyShort(MDB_cursor *cursor, jlong edgeId, jint propertyKeyId, jshort *propertyValue) {
	if (propertyValue != NULL) {
		MDB_val key, data;
		EdgeDbId id;
		id.edgeId = edgeId;
		id.coreOrPropertyEnum = EPROPERTY_KEY;
		id.propertykeyId = propertyKeyId;
		key.mv_size = sizeof(EdgeDbId);
		key.mv_data = &id;
		data.mv_size = sizeof(jshort);
		data.mv_data = propertyValue;
		return mdb_cursor_put(cursor, &key, &data, 0);
	} else {
		return GLMDB_WRITE_NULL;
	}
}

int setVertexPropertyInt(MDB_cursor *cursor, jlong vertexId, jint propertyKeyId, jint *propertyValue) {
	if (propertyValue != NULL) {
		MDB_val key, data;
		VertexDbId id;
		id.vertexId = vertexId;
		id.coreOrPropertyEnum = VPROPERTY_KEY;
		id.propertykeyId = propertyKeyId;
		id.labelId = -1;
		id.edgeId = -1LL;
		key.mv_size = sizeof(VertexDbId);
		key.mv_data = &id;
		data.mv_size = sizeof(jint);
		data.mv_data = propertyValue;
		return mdb_cursor_put(cursor, &key, &data, 0);
	} else {
		return GLMDB_WRITE_NULL;
	}
}

int setEdgePropertyInt(MDB_cursor *cursor, jlong edgeId, jint propertyKeyId, jint *propertyValue) {
	if (propertyValue != NULL) {
		MDB_val key, data;
		EdgeDbId id;
		id.edgeId = edgeId;
		id.coreOrPropertyEnum = EPROPERTY_KEY;
		id.propertykeyId = propertyKeyId;
		key.mv_size = sizeof(EdgeDbId);
		key.mv_data = &id;
		data.mv_size = sizeof(jint);
		data.mv_data = propertyValue;
		return mdb_cursor_put(cursor, &key, &data, 0);
	} else {
		return GLMDB_WRITE_NULL;
	}
}

int setVertexPropertyLong(MDB_cursor *cursor, jlong vertexId, jint propertyKeyId, jlong *propertyValue) {
	if (propertyValue != NULL) {
		MDB_val key, data;
		VertexDbId id;
		id.vertexId = vertexId;
		id.coreOrPropertyEnum = VPROPERTY_KEY;
		id.propertykeyId = propertyKeyId;
		id.labelId = -1;
		id.edgeId = -1LL;
		key.mv_size = sizeof(VertexDbId);
		key.mv_data = &id;
		data.mv_size = sizeof(jlong);
		data.mv_data = propertyValue;
		return mdb_cursor_put(cursor, &key, &data, 0);
	} else {
		return GLMDB_WRITE_NULL;
	}
}

int setEdgePropertyLong(MDB_cursor *cursor, jlong edgeId, jint propertyKeyId, jlong *propertyValue) {
	if (propertyValue != NULL) {
		MDB_val key, data;
		EdgeDbId id;
		id.edgeId = edgeId;
		id.coreOrPropertyEnum = EPROPERTY_KEY;
		id.propertykeyId = propertyKeyId;
		key.mv_size = sizeof(EdgeDbId);
		key.mv_data = &id;
		data.mv_size = sizeof(jlong);
		data.mv_data = propertyValue;
		return mdb_cursor_put(cursor, &key, &data, 0);
	} else {
		return GLMDB_WRITE_NULL;
	}
}

int setVertexPropertyFloat(MDB_cursor *cursor, jlong vertexId, jint propertyKeyId, jfloat *propertyValue) {
	if (propertyValue != NULL) {
		MDB_val key, data;
		VertexDbId id;
		id.vertexId = vertexId;
		id.coreOrPropertyEnum = VPROPERTY_KEY;
		id.propertykeyId = propertyKeyId;
		id.labelId = -1;
		id.edgeId = -1LL;
		key.mv_size = sizeof(VertexDbId);
		key.mv_data = &id;
		data.mv_size = sizeof(jfloat);
		data.mv_data = propertyValue;
		return mdb_cursor_put(cursor, &key, &data, 0);
	} else {
		return GLMDB_WRITE_NULL;
	}
}

int setEdgePropertyFloat(MDB_cursor *cursor, jlong edgeId, jint propertyKeyId, jfloat *propertyValue) {
	if (propertyValue != NULL) {
		MDB_val key, data;
		EdgeDbId id;
		id.edgeId = edgeId;
		id.coreOrPropertyEnum = EPROPERTY_KEY;
		id.propertykeyId = propertyKeyId;
		key.mv_size = sizeof(EdgeDbId);
		key.mv_data = &id;
		data.mv_size = sizeof(jfloat);
		data.mv_data = propertyValue;
		return mdb_cursor_put(cursor, &key, &data, 0);
	} else {
		return GLMDB_WRITE_NULL;
	}
}

int setVertexPropertyDouble(MDB_cursor *cursor, jlong vertexId, jint propertyKeyId, jdouble *propertyValue) {
	if (propertyValue != NULL) {
		MDB_val key, data;
		VertexDbId id;
		id.vertexId = vertexId;
		id.coreOrPropertyEnum = VPROPERTY_KEY;
		id.propertykeyId = propertyKeyId;
		id.labelId = -1;
		id.edgeId = -1LL;
		key.mv_size = sizeof(VertexDbId);
		key.mv_data = &id;
		data.mv_size = sizeof(jdouble);
		data.mv_data = propertyValue;
		return mdb_cursor_put(cursor, &key, &data, 0);
	} else {
		return GLMDB_WRITE_NULL;
	}
}

int setEdgePropertyDouble(MDB_cursor *cursor, jlong edgeId, jint propertyKeyId, jdouble *propertyValue) {
	if (propertyValue != NULL) {
		MDB_val key, data;
		EdgeDbId id;
		id.edgeId = edgeId;
		id.coreOrPropertyEnum = EPROPERTY_KEY;
		id.propertykeyId = propertyKeyId;
		key.mv_size = (sizeof(EdgeDbId));
		key.mv_data = &id;
		data.mv_size = sizeof(jdouble);
		data.mv_data = propertyValue;
		return mdb_cursor_put(cursor, &key, &data, 0);
	} else {
		return GLMDB_WRITE_NULL;
	}
}

int setVertexPropertyChar(MDB_cursor *cursor, jlong vertexId, jint propertyKeyId, jchar *propertyValue) {
	if (propertyValue != NULL) {
		MDB_val key, data;
		VertexDbId id;
		id.vertexId = vertexId;
		id.coreOrPropertyEnum = VPROPERTY_KEY;
		id.propertykeyId = propertyKeyId;
		id.labelId = -1;
		id.edgeId = -1LL;
		key.mv_size = sizeof(VertexDbId);
		key.mv_data = &id;
		data.mv_size = sizeof(jchar);
		data.mv_data = propertyValue;
		return mdb_cursor_put(cursor, &key, &data, 0);
	} else {
		return GLMDB_WRITE_NULL;
	}
}

int setEdgePropertyChar(MDB_cursor *cursor, jlong edgeId, jint propertyKeyId, jchar *propertyValue) {
	if (propertyValue != NULL) {
		MDB_val key, data;
		EdgeDbId id;
		id.edgeId = edgeId;
		id.coreOrPropertyEnum = EPROPERTY_KEY;
		id.propertykeyId = propertyKeyId;
		key.mv_size = sizeof(EdgeDbId);
		key.mv_data = &id;
		data.mv_size = sizeof(jchar);
		data.mv_data = propertyValue;
		return mdb_cursor_put(cursor, &key, &data, 0);
	} else {
		return GLMDB_WRITE_NULL;
	}
}

int getVertexProperty(MDB_cursor *cursor, jlong vertexId, jint propertyKeyId, MDB_val *data) {
	MDB_val key;
	VertexDbId id;
	id.vertexId = vertexId;
	id.coreOrPropertyEnum = VPROPERTY_KEY;
	id.propertykeyId = propertyKeyId;
	id.labelId = -1;
	id.edgeId = -1LL;
	key.mv_size = sizeof(VertexDbId);
	key.mv_data = &id;
	return mdb_cursor_get(cursor, &key, data, MDB_SET_KEY);
}

int getEdgeProperty(MDB_cursor *cursor, jlong edgeId, jint propertyKeyId, MDB_val *data) {
	MDB_val key;
	EdgeDbId id;
	id.edgeId = edgeId;
	id.coreOrPropertyEnum = EPROPERTY_KEY;
	id.propertykeyId = propertyKeyId;
	key.mv_size = sizeof(EdgeDbId);
	key.mv_data = &id;
	return mdb_cursor_get(cursor, &key, data, MDB_SET_KEY);
}

//MDB_val *edgeKey is out only
int addEdge(MDB_txn *txn, MDB_dbi vertexDb, MDB_dbi edgeDb, jlong edgeId, jint labelId, jlong vertexOutId, jlong vertexInId) {
	int rc = addEdgeToEdgeDb(txn, edgeDb, edgeId, labelId, vertexOutId, vertexInId);
	if (rc == 0) {
		rc = addEdgeToVertexDb(txn, vertexDb, edgeId, labelId, vertexOutId, vertexInId);
	}
	return rc;
}

int addEdgeToEdgeDb(MDB_txn *txn, MDB_dbi edgeDb, jlong edgeId, jint labelId, jlong vertexOutId, jlong vertexInId) {
	MDB_val data, edgeKey;
	EdgeDbId id;
	id.edgeId = edgeId;
	id.coreOrPropertyEnum = ECORE;
	id.propertykeyId = -1;
	edgeKey.mv_size = (sizeof(EdgeDbId));
	edgeKey.mv_data = &id;

	EdgeData edgeData;
	edgeData.vertexInId = vertexInId;
	edgeData.vertexOutId = vertexOutId;
	edgeData.labelId = labelId;

	data.mv_size = sizeof(EdgeData);
	data.mv_data = &edgeData;
	return mdb_put(txn, edgeDb, &edgeKey, &data, MDB_NOOVERWRITE);
}

int addEdgeToVertexDb(MDB_txn *txn, MDB_dbi vertexDb, jlong edgeId, jint labelId, jlong vertexOutId, jlong vertexInId) {
	MDB_val edgeVertexDbKeyOut, dataOut;
	VertexDbId idOut;
	idOut.vertexId = vertexOutId;
	idOut.coreOrPropertyEnum = OUTLABEL;
	idOut.propertykeyId = -1;
	idOut.edgeId = edgeId;
	idOut.labelId = labelId;

	edgeVertexDbKeyOut.mv_size = sizeof(VertexDbId);
	edgeVertexDbKeyOut.mv_data = &idOut;
	dataOut.mv_size = sizeof(jlong);
	dataOut.mv_data = &vertexInId;
	int rc = mdb_put(txn, vertexDb, &edgeVertexDbKeyOut, &dataOut, MDB_NOOVERWRITE);
	if (rc == 0) {
		MDB_val edgeVertexDbKeyIn, dataIn;
		VertexDbId idIn;
		idIn.vertexId = vertexInId;
		idIn.coreOrPropertyEnum = INLABEL;
		idIn.propertykeyId = -1;
		idIn.edgeId = edgeId;
		idIn.labelId = labelId;

		edgeVertexDbKeyIn.mv_size = sizeof(VertexDbId);
		edgeVertexDbKeyIn.mv_data = &idIn;
		dataIn.mv_size = sizeof(jlong);
		dataIn.mv_data = &vertexOutId;
		rc = mdb_put(txn, vertexDb, &edgeVertexDbKeyIn, &dataIn, MDB_NOOVERWRITE);
	} else {
		printf("oops %i\n", rc);
	}
	return rc;
}

int compareVertexDbId(const MDB_val *key1, const MDB_val *key2) {
	jlong vertex1Id = (*(VertexDbId *) (key1->mv_data)).vertexId;
	jlong vertex2Id = (*(VertexDbId *) (key2->mv_data)).vertexId;
	if (vertex1Id == vertex2Id) {
		//Need to compare further on core or property. core comes first
		enum VertexCoreOrPropertyEnum coreOrProperty1 = (*(VertexDbId *) (key1->mv_data)).coreOrPropertyEnum;
		enum VertexCoreOrPropertyEnum coreOrProperty2 = (*(VertexDbId *) (key2->mv_data)).coreOrPropertyEnum;
		if (coreOrProperty1 == coreOrProperty2) {
			switch (coreOrProperty1) {
			case VCORE:
				return 0;
				break;
			case VPROPERTY_KEY:
				;
				jint propertyKey1 = (*(VertexDbId *) (key1->mv_data)).propertykeyId;
				jint propertyKey2 = (*(VertexDbId *) (key2->mv_data)).propertykeyId;
				return (propertyKey1 > propertyKey2) - (propertyKey1 < propertyKey2);
				break;
			case OUTLABEL:
				;
				jint labelId1 = (*(VertexDbId *) (key1->mv_data)).labelId;
				jint labelId2 = (*(VertexDbId *) (key2->mv_data)).labelId;
				if (labelId1 == labelId2) {
					jlong edgeId1 = (*(VertexDbId *) (key1->mv_data)).edgeId;
					jlong edgeId2 = (*(VertexDbId *) (key2->mv_data)).edgeId;
					return (edgeId1 > edgeId2) - (edgeId1 < edgeId2);
				} else {
					return (labelId1 > labelId2) - (labelId1 < labelId2);
				}
				break;
			case INLABEL:
				;
				jint labelId11 = (*(VertexDbId *) (key1->mv_data)).labelId;
				jint labelId22 = (*(VertexDbId *) (key2->mv_data)).labelId;
				if (labelId11 == labelId22) {
					jlong edgeId11 = (*(VertexDbId *) (key1->mv_data)).edgeId;
					jlong edgeId22 = (*(VertexDbId *) (key2->mv_data)).edgeId;
					return (edgeId11 > edgeId22) - (edgeId11 < edgeId22);
				} else {
					return (labelId11 > labelId22) - (labelId11 < labelId22);
				}
				break;
			}

		} else {
			return (coreOrProperty1 > coreOrProperty2) - (coreOrProperty1 < coreOrProperty2);
		}
	} else {
		return (vertex1Id > vertex2Id) - (vertex1Id < vertex2Id);
	}
	return 0;
}

int compareEdgeDbId(const MDB_val *key1, const MDB_val *key2) {
	jlong edge1Id = (*(EdgeDbId *) (key1->mv_data)).edgeId;
	jlong edge2Id = (*(EdgeDbId *) (key2->mv_data)).edgeId;
	if (edge1Id == edge2Id) {
		//Need to compare further on core or property. core comes first
		enum EdgeCoreOrPropertyEnum coreOrProperty1 = (*(EdgeDbId *) (key1->mv_data)).coreOrPropertyEnum;
		enum EdgeCoreOrPropertyEnum coreOrProperty2 = (*(EdgeDbId *) (key2->mv_data)).coreOrPropertyEnum;
		if (coreOrProperty1 == coreOrProperty2) {
			switch (coreOrProperty1) {
			case ECORE:
				return 0;
				break;
			case EPROPERTY_KEY:
				;
				jint propertyKey1 = (*(EdgeDbId *) (key1->mv_data)).propertykeyId;
				jint propertyKey2 = (*(EdgeDbId *) (key2->mv_data)).propertykeyId;
				return (propertyKey1 > propertyKey2) - (propertyKey1 < propertyKey2);
				break;
			}
		} else {
			return (coreOrProperty1 > coreOrProperty2) - (coreOrProperty1 < coreOrProperty2);
		}
	} else {
		return (edge1Id > edge2Id) - (edge1Id < edge2Id);
	}
	return 0;
}

void printDbStats(MDB_env *env, MDB_dbi vertexDb, char *name) {
	MDB_txn *txn;
	MDB_stat stat;
	mdb_txn_begin(env, NULL, 1, &txn);
	mdb_stat(txn, vertexDb, &stat);
	prstat(&stat, name);
	mdb_txn_commit(txn);
}

void printRecord(MDB_val key, MDB_val data) {

	VertexDbId vertexDbId = (*((VertexDbId *) (key.mv_data)));
	switch (vertexDbId.coreOrPropertyEnum) {
	case VCORE:
		printf("key: %lld, type = VCORE, propertyKey: %i, labelId = %i, edgeId = %lld,  data: %s\n", (long long) vertexDbId.vertexId,
				vertexDbId.propertykeyId, vertexDbId.labelId, (long long) vertexDbId.edgeId,
				*((char *) data.mv_data) == '\0' ? "NULL" : "????");
		break;
	case VPROPERTY_KEY:
		printf("key: %lld, type = VPROPERTY_KEY, propertyKey: %i, labelId = %i, edgeId = %lld,  data: %.*s\n",
				(long long) vertexDbId.vertexId, vertexDbId.propertykeyId, vertexDbId.labelId, (long long) vertexDbId.edgeId,
				(int) data.mv_size, (char *) data.mv_data);
		break;
	case OUTLABEL:
		printf("key: %lld, type = OUTLABEL, propertyKey: %i, labelId = %i, edgeId = %lld,  data: %lld\n", (long long) vertexDbId.vertexId,
				vertexDbId.propertykeyId, vertexDbId.labelId, (long long) vertexDbId.edgeId, *(long long *) data.mv_data);
		break;
	case INLABEL:
		printf("key: %lld, type = INLABEL, propertyKey: %i, labelId = %i, edgeId = %lld,  data: %lld\n", (long long) vertexDbId.vertexId,
				vertexDbId.propertykeyId, vertexDbId.labelId, (long long) vertexDbId.edgeId, *(long long *) data.mv_data);
		break;
	}
}

void printKey(MDB_val key) {

	VertexDbId vertexDbId = (*((VertexDbId *) (key.mv_data)));
	switch (vertexDbId.coreOrPropertyEnum) {
	case VCORE:
		printf("key: %lld, type = VCORE, propertyKey: %i, labelId = %i, edgeId = %lld\n", (long long) vertexDbId.vertexId,
				vertexDbId.propertykeyId, vertexDbId.labelId, (long long) vertexDbId.edgeId);
		break;
	case VPROPERTY_KEY:
		printf("key: %lld, type = VPROPERTY_KEY, propertyKey: %i, labelId = %i, edgeId = %lld\n", (long long) vertexDbId.vertexId,
				vertexDbId.propertykeyId, vertexDbId.labelId, (long long) vertexDbId.edgeId);
		break;
	case OUTLABEL:
		printf("key: %lld, type = OUTLABEL, propertyKey: %i, labelId = %i, edgeId = %lld\n", (long long) vertexDbId.vertexId,
				vertexDbId.propertykeyId, vertexDbId.labelId, (long long) vertexDbId.edgeId);
		break;
	case INLABEL:
		printf("key: %lld, type = INLABEL, propertyKey: %i, labelId = %i, edgeId = %lld\n", (long long) vertexDbId.vertexId,
				vertexDbId.propertykeyId, vertexDbId.labelId, (long long) vertexDbId.edgeId);
		break;
	default:
		printf("bust\n");
		break;
	}
}

int traverseDb(MDB_env *env, MDB_dbi dbi) {
	int rc, i = 0;
	MDB_txn *txn;
	MDB_cursor *cursor;
	MDB_val key, data;
	mdb_txn_begin(env, NULL, 1, &txn);
	mdb_cursor_open(txn, dbi, &cursor);
	while ((rc = mdb_cursor_get(cursor, &key, &data, MDB_NEXT)) == 0) {
//		if (i % 10000 == 0) {
		printRecord(key, data);
		i = i + 1;
//		}
	}
	mdb_cursor_close(cursor);
	mdb_txn_abort(txn);
	printf("traverse fini\n");
	return 0;
}

void initVertexDbId(VertexDbId *vertexDbId) {
	vertexDbId->vertexId = -1LL;
	vertexDbId->coreOrPropertyEnum = VCORE;
	vertexDbId->propertykeyId = -1;
	vertexDbId->labelId = -1;
	vertexDbId->edgeId = -1LL;
}

void initEdgeDbId(EdgeDbId *edgeDbId) {
	edgeDbId->edgeId = -1LL;
	edgeDbId->coreOrPropertyEnum = ECORE;
	edgeDbId->propertykeyId = -1;
}

void initEdgeData(EdgeData *edgeData) {
	edgeData->vertexInId = -1LL;
	edgeData->vertexOutId = -1LL;
	edgeData->labelId = -1;
}
