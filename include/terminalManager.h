#ifndef TERM_MANAGER_H
#define TERM_MANAGER_H

#include <vector>

struct VBO {
    std::vector<float> vertices;
    
    // for early version, require [xyzw][rgba]
    // thus stride=8, posOffset=0, colorOffset=4

    int stride;
    int posOffset;
    int colorOffset;
};

struct EBO {
    std::vector<int> vertexIndices;
};

class TerminalManager {
    float* pixels;
    int width, height;
    std::vector<VBO> VBOs;
    std::vector<EBO> EBOs;

public:
    void getTerminalSize(int& width, int& height);

    /** Translate position [a, b] in [0, 1]x[0, 1] to
     * pixel position [a', b'] in [0, width]x[0, height]
     */
    void posToPixel(float* posArr, int* pixelArr);

    /** Add a VBO and an EBO.
     *
     * @returns the index of the newest VBO/EBO.
     */
    bool addVertexSet();

    /** Add a vertex to a specified VBO
     *
     * @param index the index of the targeted VBO
     * @param pos the array of 4 floats xyzw
     * @param color the array of 4 floats rgba
     *
     * @returns true if success, false otherwise
     * @note failure only results from index out of range
     */
    bool addVertexToVBO(int index, const float* pos, const float* color);

    /** Add a vertex index to a specified EBO
     * 
     * @param index the index of targeted EBO
     * @param vertexIndex the index of the corresponding VBO's vertex
     * 
     * @returns true if success, false otherwise
     * @note failure is either index out of range or
     * vertexIndex >= VBO index count
     */
    bool addIndexToEBO(int index, int vertexIndex);

    /** Draw triangle from a specified VBO
     *
     * @param index the index of the targeted VBO
     * @returns true if success, false otherwise
     *
     * @note if corresponding EBO is empty, we use direct VBO to draw.
     * Otherwise use EBO to draw.
     */
    bool drawTriangles(int index);
};

#endif
