#include "MeshCollider.h"
#include "Entity.h"
#include "Transform.h"
#include "ModelRenderer.h"


namespace myengine
{
	void MeshCollider::onInitialise()
	{
		m_isStatic = true;
		m_trimesh = new btTriangleMesh();
		addTriangles();		
	}

	void MeshCollider::addTriangles()
	{
		std::shared_ptr < ModelRenderer> mod = getEntity()->getComponent<ModelRenderer>();
		

		std::vector<bu::Face> faces = mod->getFaces();
		for (int i = 0; i < faces.size(); i++)
		{
			btVector3 a{ faces[i].pa.x, faces[i].pa.y, faces[i].pa.z };
			btVector3 b{ faces[i].pb.x, faces[i].pb.y, faces[i].pb.z };
			btVector3 c{ faces[i].pc.x, faces[i].pc.y, faces[i].pc.z };
			m_trimesh->addTriangle(a,b,c);
			break;
		}

		m_shape = new btBvhTriangleMeshShape(m_trimesh, true);
	}
}