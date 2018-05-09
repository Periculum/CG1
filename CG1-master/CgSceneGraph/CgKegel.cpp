
#include "CgKegel.h"
#include "CgBase/CgEnums.h"
#include <stdio.h>
#include <math.h>
#include <string.h>

#define r 0.25;

CgKegel::CgKegel(int id): m_type(Cg::TriangleMesh),
    m_id(id)
{

}

CgKegel::CgKegel(int id, int anzahl_kreispunkte, int anzahl_hoehe, double hoehe): m_type(Cg::TriangleMesh),
    m_id(id)
{
     this->anzahl_kreispunkte= anzahl_kreispunkte;
     this->hoehe= hoehe;
        this->anzahl_hoehe= anzahl_hoehe;
     radius= r;


        punkte();

        kreisflaeche();
        mantelflaeche();

}


CgKegel::~CgKegel()
{
m_vertices.clear();
m_vertex_normals.clear();
m_vertex_colors.clear();
m_tex_coords.clear();
m_triangle_indices.clear();
m_face_normals.clear();
m_face_colors.clear();
}




void CgKegel::punkte() {
    float winkel = 2*M_PI/anzahl_kreispunkte;
    float phi = 0;
    float x, y, z;
    //berechnungen für die radien innerhalb des kegels
    float seitenlaenge = sqrt(pow(hoehe,2)+ pow(radius,2));
    float zwischenseitenlaenge = seitenlaenge/anzahl_hoehe;
    float radiusdifferenz = sqrt(pow(zwischenseitenlaenge,2) - pow(hoehe/anzahl_hoehe,2));
    glm::vec3 mittelpunkt = glm::vec3(0,0,0);
    glm::vec3 kreispunkt;
    //anzahl_hoehe für anzahl kreise, anders als beim kegel, oben kein kreis, da wird nur danach ein punkt gezeichnet
    for(int j =0; j<anzahl_hoehe; j++) {
        m_vertices.push_back(mittelpunkt);
        z = mittelpunkt.z;
        //Zeichne Punkte in einem Kreis, beginnend mit Mittelpunkt
        for(int i=0; i<anzahl_kreispunkte; i++) {
            x = radius* glm::cos(phi);
            y = radius* glm::sin(phi);
            kreispunkt = glm::vec3(x,y,z);
            m_vertices.push_back(kreispunkt);


            phi+=winkel;
        }
        mittelpunkt.z += hoehe/anzahl_hoehe;
        radius -= radiusdifferenz;
    }







    //spitze des kegels
    m_vertices.push_back(mittelpunkt);
    /*printf(" Anzahl Elemente in Vektor: %d\n", m_vertices.size());
    for(int i = 0; i < m_vertices.size(); i++) {
        printf("punkt %d: %.3f %.3f %.3f\n", i, m_vertices.at(i).x, m_vertices.at(i).y, m_vertices.at(i).z);
    }*/
}

//zeichne die kreisfläche unten
void CgKegel::kreisflaeche() {
       for(int j=1; j < anzahl_kreispunkte; j++) {
           m_triangle_indices.push_back(0);
           m_triangle_indices.push_back(0+j);
           m_triangle_indices.push_back(0+j+1);
    }
       m_triangle_indices.push_back(0);
       m_triangle_indices.push_back(anzahl_kreispunkte);
       m_triangle_indices.push_back(1);
}


//zeichnet die dreiecke in der mantelfläche
void CgKegel::mantelflaeche() {

    int anzahl_punkte = m_vertices.size();
    int i;

    //dreiecke in den unteren ebenen, oberste ebene muss gesondert behandelt werden, da dort alle dreiecke den gleichen oberen punkt nutzen
    for(int j=0; j< anzahl_punkte-(anzahl_kreispunkte+1)-1;j+=(anzahl_kreispunkte+1)) {

        for(i=1; i<anzahl_kreispunkte; i++) {
            //rechts untere dreiecke
            m_triangle_indices.push_back(i+j);
            m_triangle_indices.push_back(i+j+1);
            m_triangle_indices.push_back(i+j+1+(anzahl_kreispunkte+1));
            //links obere dreiecke
            m_triangle_indices.push_back(i+j);
            m_triangle_indices.push_back(i+j+1+(anzahl_kreispunkte+1));
            m_triangle_indices.push_back(i+j+(anzahl_kreispunkte+1));
        }
        //rechts unten abschließende dreiecke
        m_triangle_indices.push_back(i+j);
        m_triangle_indices.push_back(j+1);
        m_triangle_indices.push_back(j+1 + (anzahl_kreispunkte+1));

        //links oben abschließende dreiecke
        m_triangle_indices.push_back(i+j);
        m_triangle_indices.push_back(i+j+2);
        m_triangle_indices.push_back(i+j+(anzahl_kreispunkte+1));

    }

    //dreiecke an der spitze
    int spitze = m_vertices.size() - 1;
    int oberste_reihe = (anzahl_hoehe-1) * (anzahl_kreispunkte+1);
    for(i = 1; i < anzahl_kreispunkte; i++) {
        m_triangle_indices.push_back(oberste_reihe + i);
        m_triangle_indices.push_back(oberste_reihe + i + 1);
        m_triangle_indices.push_back(spitze);

    }


}





const std::vector<glm::vec3>& CgKegel::getVertices() const
{
    return m_vertices;
}

const std::vector<glm::vec3>& CgKegel::getVertexNormals() const
{
    return m_vertex_normals;
}

const std::vector<glm::vec3>& CgKegel::getVertexColors() const
{
    return m_vertex_colors;
}

const std::vector<glm::vec2>& CgKegel:: getVertexTexCoords() const
{
    return m_tex_coords;
}

const std::vector<unsigned int>& CgKegel::getTriangleIndices() const
{
    return m_triangle_indices;
}

const std::vector<glm::vec3>& CgKegel::getFaceNormals() const
{
    return m_face_normals;
}

const std::vector<glm::vec3>& CgKegel::getFaceColors() const
{
    return m_face_colors;
}
