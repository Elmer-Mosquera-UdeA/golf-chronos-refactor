cmake_minimum_required(VERSION 3.19)
project(refactor-chrono-golf LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets Sql Multimedia)

set(CMAKE_AUTORCC ON)

qt_standard_project_setup()

qt_add_executable(refactor-chrono-golf
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    recursos.qrc
    modosgamewidget.h modosgamewidget.cpp
    authwidget.h authwidget.cpp
    portadawidget.h portadawidget.cpp
    gestorbasedatos.h gestorbasedatos.cpp
    juego.h juego.cpp

)

target_link_libraries(refactor-chrono-golf
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt::Sql
        Qt6::Multimedia
)

install(TARGETS refactor-chrono-golf
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET refactor-chrono-golf
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
