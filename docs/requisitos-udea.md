# Documento de Requisitos - Proyecto Final Videojuego

## Contexto General
- Desarrollo de un videojuego sencillo en C++ con Qt.
- Temática obligatoria: deportiva enmarcada en un universo especial.
- Debe ser interesante, amigable y visualmente agradable.
- Aplicación de POO, memoria dinámica e interfaz gráfica (GUI).

## Requisitos Funcionales

### Jugabilidad y dinámica

- El juego debe incluir al menos dos niveles.
- Cada nivel debe tener una dinámica de interacción notablemente diferenciable.
- Las vistas y dinámicas de los niveles deben ser significativamente diferentes (ej: plataformero, vista lateral fija, scroll, cenital, etc.).
- Uno de los niveles (o un evento dentro de un nivel) debe estar controlado por tiempo (timer).
- Se debe incluir una opción de configuración de dificultad para al menos un nivel.
- La dificultad no puede ser trivial (ej: solo cambiar tiempo o cantidad de ítems).
- El protagonista debe tener al menos dos características que afecten su comportamiento (ej: veloz, pesado, fortachón, etc.).

### Físicas

- Implementar al menos tres modelos físicos diferentes (Movimiento rectilíneo no cuenta).
- Ejemplos: movimientos oscilatorios, parabólicos, etc.
- Las físicas deben estar distribuidas entre niveles y asociadas a obstáculos, eventos o interacciones.
- Las físicas deben ser desarrolladas mediante modelos parametrizables propios.

### Agente inteligente (componente investigativo)

- Incorporar al menos un agente autónomo con comportamiento inteligente.
- El agente debe incluir explícitamente:
  - **Percepción**: detecta un estímulo o evento.
  - **Razonamiento**: interpreta el estímulo y decide una acción.
  - **Acción**: ejecuta una respuesta.
  - **Aprendizaje**: almacena información pasada para mejorar respuestas futuras.

### Interfaz gráfica (Qt)

- La implementación debe usar la interfaz gráfica de Qt.
- Se debe generar un archivo ejecutable del videojuego.
- El código fuente y el ejecutable deben estar en el repositorio.

### Sonido

- Incluir sonido de fondo en al menos un nivel.
- Incluir al menos dos sonidos de eventos.
- Respetar derechos de autor para evitar problemas en YouTube.

### Gestión de proyecto y repositorio

- Usar repositorio con ramas.
- Realizar commits de forma regular (al menos uno cada dos días) para evidenciar evolución.

## Requisitos No Funcionales

### Calidad del producto

- El videojuego debe ser agradable, usable e interesante para el usuario final.
- Debe tener un nivel de dificultad adecuado.

### Documentación y presentación

- **Informe** siguiendo el modelo de desafíos previos, incluyendo:
  - Introducción, contexto, motivación, público objetivo.
  - Planteamiento del problema y necesidad que cubre.
  - Definición general, objetivos, alcance funcional.
  - Especificación de requisitos funcionales y no funcionales.
  - Metodología y planificación.
  - Diseño y arquitectura (diagrama de clases lógica y GUI).
  - Dependencias externas y bibliotecas.
  - Desarrollo e implementación (principales algoritmos).
  - Procedimientos de prueba.
  - Guía de instalación y uso.
  - Resultados y discusión (limitaciones, dificultades, mejoras).
  - Conclusiones y referencias.
  - Anexos (manual de usuario, capturas, fragmentos de código).
- El informe no debe ser generado por IA.
- **Diagrama de clases** completo (capa lógica + GUI). Sin diagrama no hay sustentación.
- Versión resumen del diagrama de clases para discusión ágil en sustentación.
- **Trailer** de máximo 1 minuto promocionando el juego. No generado por IA.
- **Video de sustentación** (YouTube) con:
  - Presentación de la solución (5 min máx.)
  - Demostración de funcionamiento (5 min máx.)
  - Explicación del código fuente (justificando decisiones)
  - Duración total: entre 7 y 20 minutos.
  - Buen sonido y resolución suficiente.
  - No exportar acelerado, respetar tiempos.

### Restricciones técnicas

- Uso obligatorio de POO y memoria dinámica.
- Al menos una herencia propia (que no herede de clases de Qt).
- Se pueden usar contenedores STL o equivalentes de Qt, justificando la decisión.
- Manejo de excepciones en casos necesarios.

## Entregables obligatorios para sustentación

- ~~Cumplimiento de los momentos I, II y III~~.
- Video (sustentación + demo + código).
- Informe completo.
- Diagrama de clases.
- Trailer.
- Código fuente y ejecutable en repositorio.

---

## Lista de verificación de requisitos (checklist)

- [ ] El videojuego está desarrollado en C++ con Qt.
- [ ] Temática: deportiva en un universo especial.
- [ ] Se aplica POO y memoria dinámica.
- [ ] Interfaz gráfica implementada con Qt.
- [ ] Al menos dos niveles con dinámicas diferenciadas.
- [ ] Las vistas de los niveles son significativamente diferentes.
- [ ] Un nivel o evento tiene control por tiempo (timer).
- [ ] Existe opción de configuración de dificultad no trivial.
- [ ] El protagonista tiene al menos dos características especiales.
- [ ] Se implementan al menos tres modelos físicos (no rectilíneos).
- [ ] Las físicas están distribuidas y asociadas a elementos del juego.
- [ ] Las físicas son parametrizables y desarrolladas por el equipo.
- [ ] Se incluye al menos un agente inteligente.
- [ ] El agente inteligente tiene: percepción, razonamiento, acción y aprendizaje.
- [ ] El juego incluye sonido de fondo (al menos en un nivel).
- [ ] El juego incluye al menos dos sonidos de eventos.
- [ ] Se respetan los derechos de autor del sonido.
- [ ] Se genera un archivo ejecutable del juego.
- [ ] El repositorio usa ramas y commits regulares (aprox. cada dos días).
- [ ] Se manejan excepciones en casos necesarios.
- [ ] Se usa al menos una herencia propia (no de Qt).
- [ ] Contenedores (STL o Qt) justificados.
- [ ] El informe completo está presente (no IA).
- [ ] El diagrama de clases (lógica + GUI) está incluido.
- [ ] Existe una versión resumen del diagrama de clases.
- [ ] Se genera un trailer (máx. 1 min, no IA).
- [ ] Se genera un video de sustentación (7-20 min, buena calidad).
- [ ] El video incluye: presentación, demo, explicación de código.
- [ ] Código fuente y ejecutable están en el repositorio.
- [ ] ~~Se cumple con todos los momentos I, II y III.~~