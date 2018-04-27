#include "CgCylinder.h"
#include "CgBase/CgEnums.h"

CgCylinder::CgCylinder(int id, int anzahl, float hoehe): m_type(Cg::TriangleMesh),
    m_id(id)
{

}

CgCylinder::~CgCylinder()
{
m_vertices.clear();
m_vertex_normals.clear();
m_vertex_colors.clear();
m_tex_coords.clear();
m_triangle_indices.clear();
m_face_normals.clear();
m_face_colors.clear();
}



const std::vector<glm::vec3>& CgCylinder::getVertices() const
{

return m_vertices;
}

const std::vector<glm::vec3>& CgCylinder::getVertexNormals() const
{
return m_vertex_normals;
}

const std::vector<glm::vec3>& CgCylinder::getVertexColors() const
{
return m_vertex_colors;
}

const std::vector<glm::vec2>& CgCylinder:: getVertexTexCoords() const
{
return m_tex_coords;
}

const std::vector<unsigned int>& CgCylinder::getTriangleIndices() const
{
return m_triangle_indices;
}

const std::vector<glm::vec3>& CgCylinder::getFaceNormals() const
{
return m_face_normals;
}

const std::vector<glm::vec3>& CgCylinder::getFaceColors() const
{
return m_face_colors;
}

