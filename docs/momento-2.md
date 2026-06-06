## Descripción detallada de las vistas

Estas vista fueron descritas de forma detallada en el [momento 1](momento-1.md). Es una descripción muy completa. Con el fin de cumplir los [requisitos](requisitos-udea.md), y aclarar la vista del juego, se agrega a continuación dibujos informales hechos en excalidraw, con el fin de complementar la transparencia de este proyecto, dejare los ficheros .excalidraw editables en la rama chore, de este proyecto, pero dejaré a continuación el 
## Dibujo de las vistas

### Nivel 1

![Concepto visual del nivel 1, dibujo hecho en excalidraw](imgs/concepto-nivel-1.png)

Nota: La vista anterior no contiene la pre-visualización completa del nivel, ya que faltan elementos, como, péndulos, grietas, y el mismo agente que será añadido en el juego.

### Nivel 2

==PENDIENTE==

## Diagrama de clases con nivel

```mermaid
classDiagram

class Juego{
    -bool ejecutando
    +iniciar()
    +actualizar()
    +finalizar()
}

class GestorNiveles{
    -vector~Nivel*~ niveles
    -int nivelActual
    +cargarNivel()
    +cambiarNivel()
}

class Nivel{
    <<abstract>>
    #string nombre
    +inicializar()
    +actualizar()
    +objetivoCumplido()
}

class NivelGolf{
    +calcularGolpe()
}

class NivelLaberinto{
    +recolectarDocumento()
}

class Entidad{
    <<abstract>>
    #int id
    #Vector2 posicion
    +actualizar()
}

class Chronoa{
    -GestorHabilidades habilidades
    +usarHabilidad()
}

class Pelota{
    -Vector2 velocidad
    +golpear()
}

class AgenteTemporal{
    -ModuloPercepcion percepcion
    -ModuloRazonamiento razonamiento
    -ModuloAccion accion
    -ModuloAprendizaje aprendizaje
    +actualizarIA()
}

class PortalTemporal{
    +teletransportar()
}

class GrietaTemporal{
    +abrir()
    +cerrar()
}

class Documento{
    +recolectar()
}

class Obstaculo{
    +interactuar()
}

class GestorFisicas{
    -vector~ModeloFisico*~ modelos
    +actualizarFisicas()
}

class ModeloFisico{
    <<abstract>>
    +calcular()
}

class FisicaParabolica
class FisicaOscilatoria
class FisicaTemporal
class FisicaConservacionEnergia

class GestorHabilidades{
    -CadenaMarkov markov
    +activarHabilidad()
}

class CadenaMarkov{
    -vector~vector<double>~ matriz
    -Estado estadoActual
    +obtenerSiguienteEstado()
}

Juego --> GestorNiveles

GestorNiveles --> Nivel

Nivel <|-- NivelGolf
Nivel <|-- NivelLaberinto

Entidad <|-- Chronoa
Entidad <|-- Pelota
Entidad <|-- AgenteTemporal
Entidad <|-- PortalTemporal
Entidad <|-- Obstaculo
Entidad <|-- Documento
Entidad <|-- GrietaTemporal

Chronoa --> GestorHabilidades
GestorHabilidades --> CadenaMarkov

GestorFisicas --> ModeloFisico

ModeloFisico <|-- FisicaParabolica
ModeloFisico <|-- FisicaOscilatoria
ModeloFisico <|-- FisicaTemporal
ModeloFisico <|-- FisicaConservacionEnergia

NivelGolf --> Pelota
NivelGolf --> PortalTemporal
NivelGolf --> Obstaculo
NivelGolf --> GrietaTemporal

NivelLaberinto --> Documento
NivelLaberinto --> AgenteTemporal

```

## Diagrama de flujo y descripción agente IA

```mermaid

flowchart LR

    P[Percepción]

    P --> P1[Detectar Chronoa]
    P --> P2[Detectar grietas]
    P --> P3[Detectar obstáculos]
    P --> P4[Detectar fuentes de energía]

    P --> R[Razonamiento]

    R --> R1[Seleccionar objetivo]
    R --> R2[Evaluar amenazas]
    R --> R3[Calcular ruta]

    R --> A[Acción]

    A --> A1[Patrullar]
    A --> A2[Perseguir]
    A --> A3[Cerrar grieta]
    A --> A4[Atacar]

    A --> AP[Aprendizaje]

    AP --> AP1[Registrar fallos]
    AP --> AP2[Guardar obstáculos peligrosos]
    AP --> AP3[Modificar rutas futuras]

    AP --> P


```

