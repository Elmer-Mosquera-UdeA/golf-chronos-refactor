# Momento I – Contextualización

## Proyecto Final – Informática 2

# Chronos: Fragmentos del Tiempo

## 1. Evento deportivo base y universo central

El videojuego está inspirado en el deporte del **minigolf**, adaptado al universo ficticio denominado **Chronos**.

Chronos es un planeta que estuvo a punto de ser destruido por un cataclismo espacial de magnitud desconocida. Como último recurso, los científicos del planeta desarrollaron una gigantesca barrera temporal capaz de desacoplar parcialmente el flujo temporal del planeta respecto al resto del universo.

La barrera logró evitar la destrucción de Chronos, pero produjo consecuencias inesperadas. La estructura espacio-temporal del planeta quedó permanentemente alterada y numerosos materiales adquirieron propiedades de conservación energética casi perfecta. Como resultado aparecieron fenómenos anómalos tales como portales temporales, zonas gravitacionales inestables, trayectorias perpetuas, grietas temporales y entidades encargadas de restaurar el equilibrio temporal.

Décadas después de aquel acontecimiento, gran parte del conocimiento sobre la barrera se perdió. El objetivo de la protagonista será recuperar información histórica sobre el evento mientras atraviesa regiones afectadas por dichas anomalías.

---

# 2. Protagonista

La protagonista es **Chronoa**, descendiente de los investigadores que participaron en la construcción de la barrera temporal.

Debido a su herencia genética y a la exposición prolongada a las anomalías de Chronos, desarrolló una sensibilidad especial frente a las alteraciones temporales.

## Característica 1: Temporalmente Veloz

Chronoa puede desacelerar subjetivamente el flujo temporal de su entorno. Desde su perspectiva, el mundo parece moverse más lentamente, permitiéndole reaccionar con mayor precisión y ejecutar acciones con más tiempo de respuesta.

Efectos:

* Incrementa la precisión de juego.
* Facilita el cálculo de trayectorias.
* Permite reaccionar ante amenazas con mayor facilidad.

## Característica 2: Predictiva

Chronoa posee la capacidad de percibir breves fragmentos del futuro inmediato.

Efectos:

* Visualiza parcialmente la trayectoria futura de la pelota.
* Puede anticipar el movimiento de algunos agentes autónomos.
* Facilita la toma de decisiones estratégicas.

---

# 3. Sistema de habilidades temporales

Las habilidades de Chronoa están sujetas a cierta inestabilidad temporal.

Para representar este comportamiento se utilizará una **Cadena de Markov Discreta**, la cual determina cuál será la siguiente habilidad disponible después de cada activación.

El sistema no activa habilidades automáticamente; únicamente establece la probabilidad de transición entre estados.

Los estados considerados son:

* Predicción.
* Veloz.
* Sobrecarga Temporal.
* Desgaste Energético.

La matriz de transición es la siguiente:

| Estado siguiente / Estado actual | Predicción | Veloz | Sobrecarga | Desgaste |
| -------------------------------- | ---------- | ----- | ---------- | -------- |
| Predicción                       | 30%        | 35%   | 25%        | 10%      |
| Veloz                            | 24%        | 45%   | 21%        | 10%      |
| Sobrecarga Temporal              | 34%        | 40%   | 16%        | 10%      |
| Desgaste Energético              | 40%        | 30%   | 20%        | 10%      |

Cada intento de utilización de una habilidad puede producir una transición probabilística hacia otro estado.

En el Nivel 1 solo puede haber una habilidad activa a la vez. Después de utilizar una habilidad, Chronoa deberá esperar **15 segundos** antes de volver a activar otra.

---

# 4. Nivel 1 – Campos Temporales Exteriores

## Sinopsis

Chronoa inicia su recorrido en las regiones periféricas de Chronos. Estas zonas fueron afectadas moderadamente por la barrera temporal y contienen numerosas anomalías físicas que alteran las trayectorias de los objetos.

Durante la exploración, la protagonista deberá superar diversos recorridos de minigolf mientras busca indicios sobre la localización del epicentro donde fue desplegada la barrera.

## Vista

Vista lateral fija.

## Dinámica principal

El jugador controla la dirección y potencia de lanzamiento de la pelota para alcanzar la bandera utilizando la menor cantidad de golpes posible.

La geometría de los escenarios se ve modificada por fenómenos temporales que alteran el recorrido esperado de la pelota.

## Elementos principales

* Pelota de golf.
* Portales temporales.
* Anomalías gravitacionales.
* Obstáculos mecánicos.
* Zonas de alteración temporal.
* Grietas temporales.

## Objetivo

Completar cada recorrido alcanzando la bandera final.

## Retos

* Calcular trayectorias complejas.
* Aprovechar correctamente los portales.
* Evitar obstáculos móviles.
* Adaptarse a cambios físicos producidos por anomalías temporales.
* Resistir los ataques temporales de los agentes cuando aparezcan.

## Funcionamiento general

Durante el desarrollo de la partida, Chronoa podrá utilizar sus habilidades especiales para facilitar el análisis de trayectorias o mejorar sus tiempos de reacción.

Sin embargo, el uso de estas habilidades puede provocar una Sobrecarga Temporal capaz de generar grietas espacio-temporales.

---

# 5. Nivel 2 – Epicentro de la Barrera

## Sinopsis

Tras reunir suficiente información, Chronoa localiza el lugar donde fue desplegada la barrera original.

Las alteraciones temporales son mucho más intensas y el comportamiento de los agentes se vuelve considerablemente más agresivo.

El objetivo principal consiste en recuperar documentos históricos almacenados en antiguos laboratorios abandonados.

## Vista

Vista cenital tipo laberinto, inspirada en la navegación de juegos clásicos como Pac-Man.

## Dinámica principal

Chronoa debe recorrer distintos corredores recolectando documentos mientras evita ser capturada por agentes temporales.

A diferencia del primer nivel, la precisión de lanzamiento deja de ser el elemento principal y la exploración toma un papel predominante.

## Objetivo

Recuperar la totalidad de los documentos distribuidos en el escenario.

## Retos

* Evitar agentes hostiles.
* Gestionar correctamente los tiempos de enfriamiento.
* Encontrar rutas seguras.
* Aprovechar las habilidades temporales para escapar de persecuciones.

## Funcionamiento general

En esta región las habilidades de Chronoa se encuentran estabilizadas.

Las habilidades disponibles son:

* Predicción: enfriamiento de 20 segundos.
* Veloz: enfriamiento de 15 segundos.

Cada habilidad posee un temporizador independiente.

Los agentes patrullan permanentemente el escenario y permanecen en estado hostil durante toda la partida.

---

# 6. Físicas implementadas

## Física 1: Movimiento parabólico

Utilizada principalmente para modelar las trayectorias de la pelota en el Nivel 1.

Variables:

* Velocidad inicial.
* Ángulo de lanzamiento.
* Intensidad gravitacional.

---

## Física 2: Alteración temporal de velocidad

Representa la habilidad Veloz de Chronoa.

La percepción temporal del entorno disminuye permitiendo una mayor capacidad de reacción.

---

## Física 3: Predicción temporal

Consiste en la simulación anticipada de trayectorias futuras para mostrar al jugador posibles recorridos de objetos presentes en el escenario.

---

## Física 4: Conservación energética temporal

Algunos materiales poseen pérdidas energéticas prácticamente nulas, permitiendo rebotes prolongados, trayectorias persistentes y mecanismos de movimiento continuo.

---

## Física 5: Movimiento oscilatorio

Utilizado para representar determinadas anomalías temporales y obstáculos móviles presentes en el entorno.

---

# 7. Componente investigativo: Agente Autónomo

Los agentes temporales son entidades encargadas de restaurar el equilibrio temporal cuando se detectan alteraciones excesivas.

## Percepción

El agente puede detectar:

* Grietas temporales.
* Posición de Chronoa.
* Obstáculos.
* Fuentes de energía.

En el Nivel 2 su percepción se limita a líneas rectas horizontales y verticales.

## Razonamiento

A partir de la información percibida, el agente determina:

* Si debe perseguir a Chronoa.
* Si debe cerrar una grieta temporal.
* Qué ruta seguir.
* Qué obstáculos evitar.

## Acción

El agente puede:

* Desplazarse.
* Perseguir objetivos.
* Atacar a Chronoa.
* Interactuar con grietas temporales.

## Aprendizaje

Cuando el agente pierde toda su energía debido a una interacción negativa con el entorno, registra la causa de su fallo y modifica futuras decisiones de navegación para evitar repetir el mismo error.

De esta manera mejora progresivamente sus rutas y aumenta su probabilidad de alcanzar los objetivos planteados.

---

# 8. Evento controlado por tiempo

Cuando una Sobrecarga Temporal genera una grieta, aparece un agente temporal encargado de restaurar el equilibrio.

Durante los primeros 10 segundos posteriores a su aparición, el agente entra en un estado de agresividad elevada y perseguirá activamente a Chronoa.

Este evento ocurre dentro de los recorridos de minigolf. Mientras el agente se encuentra enfurecido, Chronoa deberá utilizar el entorno y la pelota de golf para impedir que el agente la alcance. Los impactos de la pelota, los obstáculos y las anomalías temporales pueden utilizarse estratégicamente para retrasar o desviar al agente durante el tiempo establecido.

Mientras dure este evento:

* Chronoa dispone de intentos ilimitados.
* El objetivo no es completar el recorrido.
* El objetivo es sobrevivir durante 10 segundos.
* La pelota puede utilizarse como herramienta defensiva para obstaculizar al agente.

Al finalizar los 10 segundos, el agente abandona su estado agresivo y vuelve a su comportamiento normal, permitiendo que la partida continúe con el recorrido de minigolf independientemente de si logró o no cerrar la grieta temporal.
