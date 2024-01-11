#pragma once
#include "Collider.h"

namespace myengine
{
	struct MeshCollider : Collider
	{

	public:
		void onInitialise() override;
		void addTriangles();

	private:
		btTriangleMesh* m_trimesh;
	};
}