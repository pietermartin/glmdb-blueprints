package org.glmdb.blueprints;

import com.tinkerpop.blueprints.Edge;

import java.util.Iterator;

/**
 * Date: 2013/11/24
 * Time: 10:22 AM
 */
public class GlmdbEdgeForKeyValueIterable<T extends Edge> implements Iterable<GlmdbEdge> {

    private final ThunderGraph thunderGraph;
    private final TransactionAndCursor tc;
    private String key;
    private Object value;

    public GlmdbEdgeForKeyValueIterable(ThunderGraph thunderGraph, String key, Object value) {
        this.thunderGraph = thunderGraph;
        this.tc = this.thunderGraph.getReadOnlyTx();
        this.key = key;
        this.value = value;
    }

    @Override
    public Iterator<GlmdbEdge> iterator() {
        return new Iterator<GlmdbEdge>() {

            private GlmdbEdge next;
            private boolean goToFirst = true;

            @Override
            public boolean hasNext() {
                this.next = internalNext();
                return this.next != null;
            }

            @Override
            public GlmdbEdge next() {
                return this.next;
            }

            @Override
            public void remove() {
                //To change body of implemented methods use File | Settings | File Templates.
            }

            private GlmdbEdge internalNext() {
                long edgeIdArray[] = new long[1];
                String labelArray[] = new String[1];
                long outVertexIdArray[] = new long[1];
                long inVertexIdArray[] = new long[1];
                if (this.goToFirst) {
                    this.goToFirst = false;
                    if (GlmdbEdgeForKeyValueIterable.this.thunderGraph.getGlmdb().getFirstEdgeForKeyValue(tc.getEdgeCursor(), edgeIdArray, labelArray, outVertexIdArray, inVertexIdArray, GlmdbEdgeForKeyValueIterable.this.key, GlmdbEdgeForKeyValueIterable.this.value)) {
                        return new GlmdbEdge(GlmdbEdgeForKeyValueIterable.this.thunderGraph, edgeIdArray[0], labelArray[0], outVertexIdArray[0], inVertexIdArray[0]);
                    } else {
                        return null;
                    }
                } else {
                    if (GlmdbEdgeForKeyValueIterable.this.thunderGraph.getGlmdb().getNextEdgeForKeyValue(tc.getEdgeCursor(), edgeIdArray, labelArray, outVertexIdArray, inVertexIdArray, GlmdbEdgeForKeyValueIterable.this.key, GlmdbEdgeForKeyValueIterable.this.value)) {
                        return new GlmdbEdge(GlmdbEdgeForKeyValueIterable.this.thunderGraph, edgeIdArray[0], labelArray[0], outVertexIdArray[0], inVertexIdArray[0]);
                    } else {
                        return null;
                    }
                }
            }

        };
    }
}