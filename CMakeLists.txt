cmake_minimum_required(VERSION ${CMAKE_VERSION})
project(GAMEENGINE)

message(${CMAKE_SYSTEM_NAME})

if(${CMAKE_SYSTEM_NAME} MATCHES "Emscripten")
  include_directories(
    contrib/emcc-emscripten-wasm/include
    contrib/include
    src/pellet
    src
  )

  link_directories(
  contrib/emcc-emscripten-wasm/lib
  )

  set(CMAKE_EXECUTABLE_SUFFIX ".html")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --preload-file ${CMAKE_SOURCE_DIR}/resources@resources")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s TOTAL_MEMORY=1500MB")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s TOTAL_STACK=1000MB")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s NO_DISABLE_EXCEPTION_CATCHING")
  set(LIBOPENAL openal)
else()
  include_directories(
   contrib/windows-cl-amd64/include
   contrib/include
    src/pellet
   src
  )
  link_directories(
   ${PROJECT_SOURCE_DIR}/contrib/windows-cl-amd64/lib
  )
  
endif()






add_library(Graphics
src/Graphics/Model.cpp
src/Graphics/Model.h
src/Graphics/rend.h
src/Graphics/RenderTexture.cpp
src/Graphics/RenderTexture.h
src/Graphics/Shader.cpp
src/Graphics/Shader.h
src/Graphics/Texture.cpp
src/Graphics/Texture.h
src/Graphics/Vao.cpp
src/Graphics/Vao.h
src/Graphics/Vbo.cpp
src/Graphics/Vbo.h
src/Graphics/stb_image.h
src/Graphics/bugl.h
src/Graphics/Camera.h
src/Graphics/Camera.cpp
)

if(${CMAKE_SYSTEM_NAME} MATCHES "Emscripten")
  target_link_libraries(Graphics GL)
else()
  target_link_libraries(Graphics glew32 opengl32)
endif()

add_library(pellet
  src/pellet/Bullet3Collision/BroadPhaseCollision/b3DynamicBvh.cpp
  src/pellet/Bullet3Collision/BroadPhaseCollision/b3DynamicBvhBroadphase.cpp
  src/pellet/Bullet3Collision/BroadPhaseCollision/b3OverlappingPairCache.cpp
  src/pellet/Bullet3Collision/NarrowPhaseCollision/b3ConvexUtility.cpp
  src/pellet/Bullet3Collision/NarrowPhaseCollision/b3CpuNarrowPhase.cpp
  src/pellet/Bullet3Common/b3AlignedAllocator.cpp
  src/pellet/Bullet3Common/b3Logging.cpp
  src/pellet/Bullet3Common/b3Vector3.cpp
  src/pellet/Bullet3Dynamics/b3CpuRigidBodyPipeline.cpp
  src/pellet/Bullet3Dynamics/ConstraintSolver/b3FixedConstraint.cpp
  src/pellet/Bullet3Dynamics/ConstraintSolver/b3Generic6DofConstraint.cpp
  src/pellet/Bullet3Dynamics/ConstraintSolver/b3PgsJacobiSolver.cpp
  src/pellet/Bullet3Dynamics/ConstraintSolver/b3Point2PointConstraint.cpp
  src/pellet/Bullet3Dynamics/ConstraintSolver/b3TypedConstraint.cpp
  src/pellet/Bullet3Geometry/b3ConvexHullComputer.cpp
  src/pellet/Bullet3Geometry/b3GeometryUtil.cpp
  src/pellet/BulletCollision/BroadphaseCollision/btAxisSweep3.cpp
  src/pellet/BulletCollision/BroadphaseCollision/btBroadphaseProxy.cpp
  src/pellet/BulletCollision/BroadphaseCollision/btCollisionAlgorithm.cpp
  src/pellet/BulletCollision/BroadphaseCollision/btDbvt.cpp
  src/pellet/BulletCollision/BroadphaseCollision/btDbvtBroadphase.cpp
  src/pellet/BulletCollision/BroadphaseCollision/btDispatcher.cpp
  src/pellet/BulletCollision/BroadphaseCollision/btOverlappingPairCache.cpp
  src/pellet/BulletCollision/BroadphaseCollision/btQuantizedBvh.cpp
  src/pellet/BulletCollision/BroadphaseCollision/btSimpleBroadphase.cpp
  src/pellet/BulletCollision/CollisionDispatch/btActivatingCollisionAlgorithm.cpp
  src/pellet/BulletCollision/CollisionDispatch/btBox2dBox2dCollisionAlgorithm.cpp
  src/pellet/BulletCollision/CollisionDispatch/btBoxBoxCollisionAlgorithm.cpp
  src/pellet/BulletCollision/CollisionDispatch/btBoxBoxDetector.cpp
  src/pellet/BulletCollision/CollisionDispatch/btCollisionDispatcher.cpp
  src/pellet/BulletCollision/CollisionDispatch/btCollisionObject.cpp
  src/pellet/BulletCollision/CollisionDispatch/btCollisionWorld.cpp
  src/pellet/BulletCollision/CollisionDispatch/btCollisionWorldImporter.cpp
  src/pellet/BulletCollision/CollisionDispatch/btCompoundCollisionAlgorithm.cpp
  src/pellet/BulletCollision/CollisionDispatch/btCompoundCompoundCollisionAlgorithm.cpp
  src/pellet/BulletCollision/CollisionDispatch/btConvex2dConvex2dAlgorithm.cpp
  src/pellet/BulletCollision/CollisionDispatch/btConvexConcaveCollisionAlgorithm.cpp
  src/pellet/BulletCollision/CollisionDispatch/btConvexConvexAlgorithm.cpp
  src/pellet/BulletCollision/CollisionDispatch/btConvexPlaneCollisionAlgorithm.cpp
  src/pellet/BulletCollision/CollisionDispatch/btDefaultCollisionConfiguration.cpp
  src/pellet/BulletCollision/CollisionDispatch/btEmptyCollisionAlgorithm.cpp
  src/pellet/BulletCollision/CollisionDispatch/btGhostObject.cpp
  src/pellet/BulletCollision/CollisionDispatch/btHashedSimplePairCache.cpp
  src/pellet/BulletCollision/CollisionDispatch/btInternalEdgeUtility.cpp
  src/pellet/BulletCollision/CollisionDispatch/btManifoldResult.cpp
  src/pellet/BulletCollision/CollisionDispatch/btSimulationIslandManager.cpp
  src/pellet/BulletCollision/CollisionDispatch/btSphereBoxCollisionAlgorithm.cpp
  src/pellet/BulletCollision/CollisionDispatch/btSphereSphereCollisionAlgorithm.cpp
  src/pellet/BulletCollision/CollisionDispatch/btSphereTriangleCollisionAlgorithm.cpp
  src/pellet/BulletCollision/CollisionDispatch/btUnionFind.cpp
  src/pellet/BulletCollision/CollisionDispatch/SphereTriangleDetector.cpp
  src/pellet/BulletCollision/CollisionShapes/btBox2dShape.cpp
  src/pellet/BulletCollision/CollisionShapes/btBoxShape.cpp
  src/pellet/BulletCollision/CollisionShapes/btBvhTriangleMeshShape.cpp
  src/pellet/BulletCollision/CollisionShapes/btCapsuleShape.cpp
  src/pellet/BulletCollision/CollisionShapes/btCollisionShape.cpp
  src/pellet/BulletCollision/CollisionShapes/btCompoundShape.cpp
  src/pellet/BulletCollision/CollisionShapes/btConcaveShape.cpp
  src/pellet/BulletCollision/CollisionShapes/btConeShape.cpp
  src/pellet/BulletCollision/CollisionShapes/btConvex2dShape.cpp
  src/pellet/BulletCollision/CollisionShapes/btConvexHullShape.cpp
  src/pellet/BulletCollision/CollisionShapes/btConvexInternalShape.cpp
  src/pellet/BulletCollision/CollisionShapes/btConvexPointCloudShape.cpp
  src/pellet/BulletCollision/CollisionShapes/btConvexPolyhedron.cpp
  src/pellet/BulletCollision/CollisionShapes/btConvexShape.cpp
  src/pellet/BulletCollision/CollisionShapes/btConvexTriangleMeshShape.cpp
  src/pellet/BulletCollision/CollisionShapes/btCylinderShape.cpp
  src/pellet/BulletCollision/CollisionShapes/btEmptyShape.cpp
  src/pellet/BulletCollision/CollisionShapes/btHeightfieldTerrainShape.cpp
  src/pellet/BulletCollision/CollisionShapes/btMinkowskiSumShape.cpp
  src/pellet/BulletCollision/CollisionShapes/btMultimaterialTriangleMeshShape.cpp
  src/pellet/BulletCollision/CollisionShapes/btMultiSphereShape.cpp
  src/pellet/BulletCollision/CollisionShapes/btOptimizedBvh.cpp
  src/pellet/BulletCollision/CollisionShapes/btPolyhedralConvexShape.cpp
  src/pellet/BulletCollision/CollisionShapes/btScaledBvhTriangleMeshShape.cpp
  src/pellet/BulletCollision/CollisionShapes/btShapeHull.cpp
  src/pellet/BulletCollision/CollisionShapes/btSphereShape.cpp
  src/pellet/BulletCollision/CollisionShapes/btStaticPlaneShape.cpp
  src/pellet/BulletCollision/CollisionShapes/btStridingMeshInterface.cpp
  src/pellet/BulletCollision/CollisionShapes/btTetrahedronShape.cpp
  src/pellet/BulletCollision/CollisionShapes/btTriangleBuffer.cpp
  src/pellet/BulletCollision/CollisionShapes/btTriangleCallback.cpp
  src/pellet/BulletCollision/CollisionShapes/btTriangleIndexVertexArray.cpp
  src/pellet/BulletCollision/CollisionShapes/btTriangleIndexVertexMaterialArray.cpp
  src/pellet/BulletCollision/CollisionShapes/btTriangleMesh.cpp
  src/pellet/BulletCollision/CollisionShapes/btTriangleMeshShape.cpp
  src/pellet/BulletCollision/CollisionShapes/btUniformScalingShape.cpp
  src/pellet/BulletCollision/Gimpact/btContactProcessing.cpp
  src/pellet/BulletCollision/Gimpact/btGenericPoolAllocator.cpp
  src/pellet/BulletCollision/Gimpact/btGImpactBvh.cpp
  src/pellet/BulletCollision/Gimpact/btGImpactCollisionAlgorithm.cpp
  src/pellet/BulletCollision/Gimpact/btGImpactQuantizedBvh.cpp
  src/pellet/BulletCollision/Gimpact/btGImpactShape.cpp
  src/pellet/BulletCollision/Gimpact/btTriangleShapeEx.cpp
  src/pellet/BulletCollision/Gimpact/gim_box_set.cpp
  src/pellet/BulletCollision/Gimpact/gim_contact.cpp
  src/pellet/BulletCollision/Gimpact/gim_memory.cpp
  src/pellet/BulletCollision/Gimpact/gim_tri_collision.cpp
  src/pellet/BulletCollision/NarrowPhaseCollision/btContinuousConvexCollision.cpp
  src/pellet/BulletCollision/NarrowPhaseCollision/btConvexCast.cpp
  src/pellet/BulletCollision/NarrowPhaseCollision/btGjkConvexCast.cpp
  src/pellet/BulletCollision/NarrowPhaseCollision/btGjkEpa2.cpp
  src/pellet/BulletCollision/NarrowPhaseCollision/btGjkEpaPenetrationDepthSolver.cpp
  src/pellet/BulletCollision/NarrowPhaseCollision/btGjkPairDetector.cpp
  src/pellet/BulletCollision/NarrowPhaseCollision/btMinkowskiPenetrationDepthSolver.cpp
  src/pellet/BulletCollision/NarrowPhaseCollision/btPersistentManifold.cpp
  src/pellet/BulletCollision/NarrowPhaseCollision/btPolyhedralContactClipping.cpp
  src/pellet/BulletCollision/NarrowPhaseCollision/btRaycastCallback.cpp
  src/pellet/BulletCollision/NarrowPhaseCollision/btSubSimplexConvexCast.cpp
  src/pellet/BulletCollision/NarrowPhaseCollision/btVoronoiSimplexSolver.cpp
  src/pellet/BulletDynamics/Character/btKinematicCharacterController.cpp
  src/pellet/BulletDynamics/ConstraintSolver/btConeTwistConstraint.cpp
  src/pellet/BulletDynamics/ConstraintSolver/btContactConstraint.cpp
  src/pellet/BulletDynamics/ConstraintSolver/btFixedConstraint.cpp
  src/pellet/BulletDynamics/ConstraintSolver/btGearConstraint.cpp
  src/pellet/BulletDynamics/ConstraintSolver/btGeneric6DofConstraint.cpp
  src/pellet/BulletDynamics/ConstraintSolver/btGeneric6DofSpring2Constraint.cpp
  src/pellet/BulletDynamics/ConstraintSolver/btGeneric6DofSpringConstraint.cpp
  src/pellet/BulletDynamics/ConstraintSolver/btHinge2Constraint.cpp
  src/pellet/BulletDynamics/ConstraintSolver/btHingeConstraint.cpp
  src/pellet/BulletDynamics/ConstraintSolver/btNNCGConstraintSolver.cpp
  src/pellet/BulletDynamics/ConstraintSolver/btPoint2PointConstraint.cpp
  src/pellet/BulletDynamics/ConstraintSolver/btSequentialImpulseConstraintSolver.cpp
  src/pellet/BulletDynamics/ConstraintSolver/btSliderConstraint.cpp
  src/pellet/BulletDynamics/ConstraintSolver/btSolve2LinearConstraint.cpp
  src/pellet/BulletDynamics/ConstraintSolver/btTypedConstraint.cpp
  src/pellet/BulletDynamics/ConstraintSolver/btUniversalConstraint.cpp
  src/pellet/BulletDynamics/Dynamics/btDiscreteDynamicsWorld.cpp
  src/pellet/BulletDynamics/Dynamics/btDiscreteDynamicsWorldMt.cpp
  src/pellet/BulletDynamics/Dynamics/btRigidBody.cpp
  src/pellet/BulletDynamics/Dynamics/btSimpleDynamicsWorld.cpp
  src/pellet/BulletDynamics/Dynamics/btSimulationIslandManagerMt.cpp
  src/pellet/BulletDynamics/Featherstone/btMultiBody.cpp
  src/pellet/BulletDynamics/Featherstone/btMultiBodyConstraint.cpp
  src/pellet/BulletDynamics/Featherstone/btMultiBodyConstraintSolver.cpp
  src/pellet/BulletDynamics/Featherstone/btMultiBodyDynamicsWorld.cpp
  src/pellet/BulletDynamics/Featherstone/btMultiBodyFixedConstraint.cpp
  src/pellet/BulletDynamics/Featherstone/btMultiBodyJointLimitConstraint.cpp
  src/pellet/BulletDynamics/Featherstone/btMultiBodyJointMotor.cpp
  src/pellet/BulletDynamics/Featherstone/btMultiBodyPoint2Point.cpp
  src/pellet/BulletDynamics/Featherstone/btMultiBodySliderConstraint.cpp
  src/pellet/BulletDynamics/MLCPSolvers/btDantzigLCP.cpp
  src/pellet/BulletDynamics/MLCPSolvers/btLemkeAlgorithm.cpp
  src/pellet/BulletDynamics/MLCPSolvers/btMLCPSolver.cpp
  src/pellet/BulletDynamics/Vehicle/btRaycastVehicle.cpp
  src/pellet/BulletDynamics/Vehicle/btWheelInfo.cpp
  src/pellet/BulletInverseDynamics/details/MultiBodyTreeImpl.cpp
  src/pellet/BulletInverseDynamics/details/MultiBodyTreeInitCache.cpp
  src/pellet/BulletInverseDynamics/IDMath.cpp
  src/pellet/BulletInverseDynamics/MultiBodyTree.cpp
  src/pellet/BulletSoftBody/btDefaultSoftBodySolver.cpp
  src/pellet/BulletSoftBody/btSoftBody.cpp
  src/pellet/BulletSoftBody/btSoftBodyConcaveCollisionAlgorithm.cpp
  src/pellet/BulletSoftBody/btSoftBodyHelpers.cpp
  src/pellet/BulletSoftBody/btSoftBodyRigidBodyCollisionConfiguration.cpp
  src/pellet/BulletSoftBody/btSoftMultiBodyDynamicsWorld.cpp
  src/pellet/BulletSoftBody/btSoftRigidCollisionAlgorithm.cpp
  src/pellet/BulletSoftBody/btSoftRigidDynamicsWorld.cpp
  src/pellet/BulletSoftBody/btSoftSoftCollisionAlgorithm.cpp
  src/pellet/LinearMath/btAlignedAllocator.cpp
  src/pellet/LinearMath/btConvexHull.cpp
  src/pellet/LinearMath/btConvexHullComputer.cpp
  src/pellet/LinearMath/btGeometryUtil.cpp
  src/pellet/LinearMath/btPolarDecomposition.cpp
  src/pellet/LinearMath/btQuickprof.cpp
  src/pellet/LinearMath/btSerializer.cpp
  src/pellet/LinearMath/btThreads.cpp
  src/pellet/LinearMath/btVector3.cpp
)

add_library(GameEngine
src/GameEngine/Core.cpp
src/GameEngine/Core.h
src/GameEngine/Entity.h
src/GameEngine/Entity.cpp
src/GameEngine/Component.cpp
src/GameEngine/Component.h
src/GameEngine/Transform.h
src/GameEngine/Transform.cpp
src/GameEngine/TriangleRenderer.cpp
src/GameEngine/TriangleRenderer.h
src/GameEngine/NativeWindow.h
src/GameEngine/NativeWindow.cpp
src/GameEngine/Enviroment.cpp
src/GameEngine/Enviroment.h
src/GameEngine/Texture.cpp
src/GameEngine/Texture.h
src/GameEngine/Model.cpp
src/GameEngine/Model.h
src/GameEngine/Resource.cpp
src/GameEngine/Resource.h
src/GameEngine/Resources.cpp
src/GameEngine/Resources.h
src/GameEngine/Shader.cpp
src/GameEngine/Shader.h
src/GameEngine/Input.cpp
src/GameEngine/Input.h
src/GameEngine/Cat.cpp
src/GameEngine/Cat.h
src/GameEngine/ModelRenderer.cpp
src/GameEngine/ModelRenderer.h
src/GameEngine/BoxCollider.cpp
src/GameEngine/BoxCollider.h
src/GameEngine/Collider.cpp
src/GameEngine/Collider.h
src/GameEngine/RigidBody.cpp
src/GameEngine/RigidBody.h
src/GameEngine/SoundSource.cpp
src/GameEngine/SoundSource.h
src/GameEngine/AudioSource.cpp
src/GameEngine/AudioSource.h
src/GameEngine/Audio.cpp
src/GameEngine/Audio.h
src/GameEngine/Camera.cpp
src/GameEngine/Camera.h
src/GameEngine/Gui.h
src/GameEngine/Gui.cpp
src/GameEngine/TriangleGui.h
src/GameEngine/TriangleGui.cpp
src/GameEngine/Utility.h
src/GameEngine/Utility.cpp
src/GameEngine/Physics.h
src/GameEngine/Physics.cpp
#src/GameEngine/raytri.c
src/GameEngine/MeshCollider.h
src/GameEngine/MeshCollider.cpp
src/GameEngine/AudioListener.h
src/GameEngine/AudioListener.cpp
src/GameEngine/PointLight.h
src/GameEngine/PointLight.cpp
)


add_executable(demo
src/demo/main.cpp
src/demo/Map.cpp
src/demo/Map.h
)

if(${CMAKE_SYSTEM_NAME} MATCHES "Emscripten")
  target_link_libraries(demo GameEngine pellet Graphics SDL2 AL)
  set(LIBOPENAL AL)
else()
  target_link_libraries(demo GameEngine pellet Graphics SDL2 openal32)
endif()
