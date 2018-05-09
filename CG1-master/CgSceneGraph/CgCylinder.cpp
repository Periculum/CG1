#include "CgCylinder.h"
#include <math.h>
#include "CgBase/CgEnums.h"

#define P 0.2

CgCylinder::CgCylinder(int id, int anzahl_kreispunkte, int anzahl_hoehe , double hoehe): m_type(Cg::TriangleMesh),
    m_id(id)
{
    this->anzahl_kreispunkte = anzahl_kreispunkte;
    this->anzahl_hoehe = anzahl_hoehe;
    this->hoehe = hoehe;

    punkte();
    kreisflaechen();
    mantel();

}

void CgCylinder::mantel() {

    for(int i = 1; i < anzahl_kreispunkte +2 ; i++){
            for(int j = 0; j < anzahl_hoehe ; j++){
                if(i < anzahl_kreispunkte){
                    m_triangle_indices.push_back(i+j*(anzahl_kreispunkte+1));       //unteres linkes Dreieck
                    m_triangle_indices.push_back((i+1)+j*(anzahl_kreispunkte+1));
                    m_triangle_indices.push_back(i+(j+1)*(anzahl_kreispunkte+1));

                    m_triangle_indices.push_back((i+1)+j*(anzahl_kreispunkte+1));       //oberes rechtes Dreieck
                    m_triangle_indices.push_back((i+1)+(j+1)*(anzahl_kreispunkte+1));
                    m_triangle_indices.push_back(i+(j+1)*(anzahl_kreispunkte+1));

                }else if(i < anzahl_kreispunkte+1){
                    m_triangle_indices.push_back(i+j*(anzahl_kreispunkte+1));       //unteres linkes Dreieck
                    m_triangle_indices.push_back((i-anzahl_kreispunkte+1)+j*(anzahl_kreispunkte+1));
                    m_triangle_indices.push_back(i+(j+1)*(anzahl_kreispunkte+1));
                }
            }

    }
}

void CgCylinder::kreisflaechen() {
    for(int j=1; j < anzahl_kreispunkte; j++) {
        m_triangle_indices.push_back(0);
        m_triangle_indices.push_back(0+j);
        m_triangle_indices.push_back(0+j+1);
    }

    m_triangle_indices.push_back(0);
    m_triangle_indices.push_back(anzahl_kreispunkte);
    m_triangle_indices.push_back(1);

    int m = (anzahl_kreispunkte+1)*anzahl_hoehe;

    for(int i = 1; i < anzahl_kreispunkte; i++) {
        m_triangle_indices.push_back(m);
        m_triangle_indices.push_back(m+i);
        m_triangle_indices.push_back(m+i+1);
    }

    m_triangle_indices.push_back(m);
    m_triangle_indices.push_back(m+anzahl_kreispunkte);
    m_triangle_indices.push_back(m+1);
}


void CgCylinder::punkte() {
    float winkel = 2*M_PI/anzahl_kreispunkte;
    float phi = 0;
    float x, y, z;
    glm::vec3 mittelpunkt = glm::vec3(0,0,0);
    glm::vec3 kreispunkt;
    //anzahl_hoehe+1 f+r Anzahl Ebenen in denen die Punkte liegen

    for(int j =0; j<anzahl_hoehe+1; j++) {
        m_vertices.push_back(mittelpunkt);
        z = mittelpunkt.z;
        //Zeichne Punkte in einem Kreis, beginnend mit Mittelpunkt

    for(int i=0; i<anzahl_kreispunkte; i++) {
        x = P* glm::cos(phi);
        y = P* glm::sin(phi);
        kreispunkt = glm::vec3(x,y,z);
        m_vertices.push_back(kreispunkt);


        phi+=winkel;

    }
        mittelpunkt.z += hoehe/anzahl_hoehe;

    }
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

