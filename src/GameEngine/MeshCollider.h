#pragma once
#include "Collider.h"

namespace myengine
{
	/*
	Mesh shape collider for physics sim
	*/
	struct MeshCollider : Collider
	{

	public:
		void onInitialise() override;
		void addTriangles();//Add all triangles from attatched meshrenderer into the collision shape to be added to the physics world

	private:
		btTriangleMesh* m_trimesh;
	};
}