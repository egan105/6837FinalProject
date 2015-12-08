set(BIN_NAME terrain)

set(CPP_FILES
    main.cpp
    Bullet.cpp
    Camera.cpp
    FirstPersonCamera.cpp
    Generator.cpp
    ParticleSystem.cpp
    ProceduralBlock.cpp
    ProceduralWorld.cpp
    Stand.cpp
    Target.cpp
    World.cpp
    )

set(CPP_HEADERS
    Bullet.h
    Camera.h
    FirstPersonCamera.h
    Generator.h
    ParticleSystem.h
    ProceduralBlock.h
    ProceduralWorld.h
    Stand.h
    Target.h
    TextureLoader.h
    World.h
    )

set(LIBS_USED
    vecmath
    ${OPENGL_LIBRARIES}
    ${GLUT_LIBRARIES}
    )

if (CMAKE_SYSTEM_NAME STREQUAL Linux)
    set(LIBS_USED ${LIBS_USED} dl)
endif()

add_executable(${BIN_NAME} ${CPP_FILES} ${CPP_HEADERS})
target_link_libraries(${BIN_NAME} ${LIBS_USED})
install(TARGETS ${BIN_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX})
