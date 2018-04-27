#ifndef CGCYLINDER_H
#define CGCYLINDER_H

#include <vector>
#include <glm/glm.hpp>

#include "CgBase/CgBaseTriangleMesh.h"


class CgCylinder : public CgBaseTriangleMesh {

    public:
        CgCylinder(int id, int anzahl, float hoehe);
        ~CgCylinder();

        //inherited from CgBaseRenderableObject
        Cg::ObjectType getType() const;
        unsigned int getID() const;

        //inherited from CgBaseTriangleMesh
        const std::vector<glm::vec3>& getVertices() const;
        const std::vector<glm::vec3>& getVertexNormals() const;
        const std::vector<glm::vec3>& getVertexColors() const;
        const std::vector<glm::vec2>& getVertexTexCoords() const;

        const std::vector<unsigned int>& getTriangleIndices() const;

        const std::vector<glm::vec3>& getFaceNormals() const;
        const std::vector<glm::vec3>& getFaceColors() const;

    private:
        //mathematische Definition des Zylinders -> zum finden der Punkte und Schnittberechnungen wichtig. Die gefundenen Punkte dann als Vertexliste benutzen, dreiecke etc...
        glm::vec3 mittelpunkt;
        double radius;
        glm::vec3 hoehe;

        //für Bild relevante Methoden
        std::vector<glm::vec3> m_vertices;
        std::vector<glm::vec3> m_vertex_normals;
        std::vector<glm::vec3> m_vertex_colors;
        std::vector<glm::vec2> m_tex_coords;

        std::vector<unsigned int>  m_triangle_indices;

        std::vector<glm::vec3> m_face_normals;
        std::vector<glm::vec3> m_face_colors;

        const Cg::ObjectType m_type;
        const unsigned int m_id;
};

//art und weise wie es festgelegt wird, damit es später nicht mehr gemacht werden muss
inline Cg::ObjectType  CgCylinder::getType() const {return m_type;}
inline unsigned int CgCylinder::getID() const {return m_id;}

#endif // CGCYLINDER_H
