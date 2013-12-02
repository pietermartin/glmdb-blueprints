package org.glmdb.blueprints.test;

import com.tinkerpop.blueprints.Direction;
import com.tinkerpop.blueprints.Edge;
import com.tinkerpop.blueprints.Vertex;
import org.glmdb.blueprints.GlmdbGraph;
import org.junit.Assert;
import org.junit.Test;

import java.util.ArrayList;
import java.util.List;

/**
 * Date: 2013/11/26
 * Time: 9:52 PM
 */
public class GlmdbVertexesFromVertexTest extends BaseGlmdbGraphTest {

    @Test
    public void testVerticesFromVertices() {
        GlmdbGraph glmdbGraph = new GlmdbGraph(this.dbPath);
        Vertex vertex1 = glmdbGraph.addVertex(null);
        vertex1.setProperty("name", "vertexOut1");
        for (int i = 0; i < 10; i++) {
            Vertex vertex2 = glmdbGraph.addVertex(null);
            vertex2.setProperty("name", "vertexIn" + i);
            Edge edge = glmdbGraph.addEdge(null, vertex1, vertex2, "testLabel1");
            edge.setProperty("name", "edge" + i);
        }
        glmdbGraph.commit();

        List<String> edgeName = new ArrayList<String>();
        int count = 0;
        Vertex vertex1_1 = glmdbGraph.getVertex(0L);
        for (Edge edge : vertex1_1.getEdges(Direction.BOTH, "testLabel1")) {
            edgeName.add((String) edge.getProperty("name"));
            count++;
        }
        Assert.assertEquals(10, count);
        glmdbGraph.commit();

        List<String> vertexName = new ArrayList<String>();
        count = 0;
        vertex1_1 = glmdbGraph.getVertex(0L);
        for (Vertex vertex : vertex1_1.getVertices(Direction.BOTH, "testLabel1")) {
            vertexName.add((String) vertex.getProperty("name"));
            count++;
        }
        Assert.assertEquals(10, count);
        Assert.assertEquals("vertexIn0", vertexName.get(0));
        Assert.assertEquals("vertexIn3", vertexName.get(3));
        Assert.assertEquals("vertexIn6", vertexName.get(6));
        Assert.assertEquals("vertexIn9", vertexName.get(9));
        glmdbGraph.commit();

        vertexName.clear();
        count = 0;
        vertex1_1 = glmdbGraph.getVertex(0L);
        for (Vertex vertex : vertex1_1.getVertices(Direction.BOTH)) {
            vertexName.add((String) vertex.getProperty("name"));
            count++;
        }
        Assert.assertEquals(10, count);
        Assert.assertEquals("vertexIn0", vertexName.get(0));
        Assert.assertEquals("vertexIn3", vertexName.get(3));
        Assert.assertEquals("vertexIn6", vertexName.get(6));
        Assert.assertEquals("vertexIn9", vertexName.get(9));
        glmdbGraph.commit();

        glmdbGraph.shutdown();
    }


    @Test
    public void testVerticesFromVerticesMultipleLabels() {
        GlmdbGraph glmdbGraph = new GlmdbGraph(this.dbPath);
        Vertex vertex1 = glmdbGraph.addVertex(null);
        vertex1.setProperty("name", "vertexOut1");
        for (int i = 0; i < 100; i++) {
            Vertex vertex2 = glmdbGraph.addVertex(null);
            vertex2.setProperty("name", "vertexIn" + i);
            Edge edge;
            if (i < 20) {
                edge = glmdbGraph.addEdge(null, vertex1, vertex2, "testLabel20");
            } else if (i < 40) {
                edge = glmdbGraph.addEdge(null, vertex1, vertex2, "testLabel40");
            } else if (i < 60) {
                edge = glmdbGraph.addEdge(null, vertex1, vertex2, "testLabel60");
            } else if (i < 80) {
                edge = glmdbGraph.addEdge(null, vertex1, vertex2, "testLabel80");
            } else {
                edge = glmdbGraph.addEdge(null, vertex1, vertex2, "testLabel100");
            }
            edge.setProperty("name", "edge" + i);
        }
        glmdbGraph.commit();

        int count = 0;
        Vertex vertex1_1 = glmdbGraph.getVertex(0L);
        for (Edge edge : vertex1_1.getEdges(Direction.OUT, "testLabel20")) {
            count++;
        }
        Assert.assertEquals(20, count);
        glmdbGraph.commit();

        count = 0;
        vertex1_1 = glmdbGraph.getVertex(0L);
        for (Edge edge : vertex1_1.getEdges(Direction.OUT, "testLabel40")) {
            count++;
        }
        Assert.assertEquals(20, count);
        glmdbGraph.commit();

        count = 0;
        vertex1_1 = glmdbGraph.getVertex(0L);
        for (Edge edge : vertex1_1.getEdges(Direction.OUT, "testLabel60")) {
            count++;
        }
        Assert.assertEquals(20, count);
        glmdbGraph.commit();

        count = 0;
        vertex1_1 = glmdbGraph.getVertex(0L);
        for (Edge edge : vertex1_1.getEdges(Direction.OUT, "testLabel80")) {
            count++;
        }
        Assert.assertEquals(20, count);
        glmdbGraph.commit();

        count = 0;
        vertex1_1 = glmdbGraph.getVertex(0L);
        for (Edge edge : vertex1_1.getEdges(Direction.OUT, "testLabel100")) {
            count++;
        }
        Assert.assertEquals(20, count);
        glmdbGraph.commit();

        count = 0;
        vertex1_1 = glmdbGraph.getVertex(0L);
        for (Edge edge : vertex1_1.getEdges(Direction.OUT)) {
            count++;
        }
        Assert.assertEquals(100, count);
        glmdbGraph.commit();

        glmdbGraph.shutdown();
    }

}