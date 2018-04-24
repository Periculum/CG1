#include "CgTriangle.h"
#include "CgBase/CgEnums.h"

#define SIZE 0.25

CgTriangle::CgTriangle(int id):
m_type(Cg::TriangleMesh),
m_id(id){

m_vertices.push_back(glm::vec3(-SIZE,-SIZE,SIZE)); //0 //Würfel
m_vertices.push_back(glm::vec3(SIZE,-SIZE,SIZE)); //1
m_vertices.push_back(glm::vec3(-SIZE,SIZE,SIZE)); //2
m_vertices.push_back(glm::vec3(SIZE,SIZE,SIZE)); //3

m_vertices.push_back(glm::vec3(-SIZE,-SIZE,-SIZE)); //4
m_vertices.push_back(glm::vec3(SIZE,-SIZE,-SIZE)); //5
m_vertices.push_back(glm::vec3(-SIZE,SIZE,-SIZE)); //6
m_vertices.push_back(glm::vec3(SIZE,SIZE,-SIZE)); //7

m_triangle_indices.push_back(0);
m_triangle_indices.push_back(1);
m_triangle_indices.push_back(2);

m_triangle_indices.push_back(2);
m_triangle_indices.push_back(1);
m_triangle_indices.push_back(3);

m_triangle_indices.push_back(1);
m_triangle_indices.push_back(3);
m_triangle_indices.push_back(7);

m_triangle_indices.push_back(5);
m_triangle_indices.push_back(7);
m_triangle_indices.push_back(1);

m_triangle_indices.push_back(6);
m_triangle_indices.push_back(7);
m_triangle_indices.push_back(2);

m_triangle_indices.push_back(2);
m_triangle_indices.push_back(3);
m_triangle_indices.push_back(7);

m_triangle_indices.push_back(4);
m_triangle_indices.push_back(6);
m_triangle_indices.push_back(2);

m_triangle_indices.push_back(0);
m_triangle_indices.push_back(2);
m_triangle_indices.push_back(4);

m_triangle_indices.push_back(4);
m_triangle_indices.push_back(5);
m_triangle_indices.push_back(0);

m_triangle_indices.push_back(5);
m_triangle_indices.push_back(1);
m_triangle_indices.push_back(7);

m_triangle_indices.push_back(4);
m_triangle_indices.push_back(5);
m_triangle_indices.push_back(6);

m_triangle_indices.push_back(5);
m_triangle_indices.push_back(6);
m_triangle_indices.push_back(7);

m_vertex_normals.push_back(glm::vec3(0.0,0.0,1.0));
m_vertex_normals.push_back(glm::vec3(0.0,0.0,1.0));
m_vertex_normals.push_back(glm::vec3(0.0,0.0,1.0));
m_vertex_normals.push_back(glm::vec3(0.0,0.0,1.0));
m_vertex_normals.push_back(glm::vec3(0.0,0.0,1.0));
m_vertex_normals.push_back(glm::vec3(0.0,0.0,1.0));

}


CgTriangle::~CgTriangle()
{
m_vertices.clear();
m_vertex_normals.clear();
m_vertex_colors.clear();
m_tex_coords.clear();
m_triangle_indices.clear();
m_face_normals.clear();
m_face_colors.clear();
}


const std::vector<glm::vec3>& CgTriangle::getVertices() const
{

return m_vertices;
}

const std::vector<glm::vec3>& CgTriangle::getVertexNormals() const
{
return m_vertex_normals;
}

const std::vector<glm::vec3>& CgTriangle::getVertexColors() const
{
return m_vertex_colors;
}

const std::vector<glm::vec2>& CgTriangle:: getVertexTexCoords() const
{
return m_tex_coords;
}

const std::vector<unsigned int>& CgTriangle::getTriangleIndices() const
{
return m_triangle_indices;
}

const std::vector<glm::vec3>& CgTriangle::getFaceNormals() const
{
return m_face_normals;
}

const std::vector<glm::vec3>& CgTriangle::getFaceColors() const
{
return m_face_colors;
}


