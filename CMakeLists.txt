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
        paginas/modosgamewidget.h paginas/modosgamewidget.cpp
        paginas/authwidget.h paginas/authwidget.cpp
        paginas/portadawidget.h paginas/portadawidget.cpp
        persistencia/gestorbasedatos.h persistencia/gestorbasedatos.cpp

        # Interface del juego
        paginas/gamewidget.cpp paginas/gamewidget.h # Contenenedor
        paginas/ui-game/topbarwidget.cpp paginas/ui-game/topbarwidget.h
        paginas/ui-game/eventlogwidget.cpp paginas/ui-game/eventlogwidget.h
        game/levelmanager.cpp
        game/levelmanager.h
        game/scenes/nivel1scene.cpp
        game/scenes/nivel1scene.h
        paginas/ui-game/basehud.h paginas/ui-game/basehud.cpp
        paginas/ui-game/level1hud.h paginas/ui-game/level1hud.cpp
        paginas/ui-game/level1hud.h paginas/ui-game/level1hud.cpp
        paginas/ui-game/level2hud.h paginas/ui-game/level2hud.cpp
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
