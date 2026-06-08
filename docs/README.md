# Chronos: Fragmentos del Tiempo

¡CORDIAL SALUDO EN EL NOMBRE DE MI SEÑOR JESUCRISTO!
Te doy la bienvenida al repositorio de **Chronos: Fragmentos del Tiempo**

> [!IMPORTANT]
> **Un recordatorio del autor:** Este proyecto nace como una versión simplificada de un desafío universitario que, debido a los exigentes plazos de tiempo, no pudo materializarse por completo en su momento. La idea original del universo y su concepto base fue el fruto de un gran trabajo en equipo junto a mi estimada compañera **Nataly Orozco**. Este repositorio representa mi esfuerzo personal por retomar, estructurar y dar vida a esa visión.

> [!NOTE]
> **ESTADO DEL PROYECTO: EN DESARROLLO ACTIVO**
> El videojuego se encuentra actualmente en fase de diseño e implementación de su infraestructura base. 



## NOTAS DE RELEASE

Desde este punto en adelante, cualquier commit en main, sera feature compilable en base Fedora KDE usando tanto Clion como QT como entorno de compilación.

Las versiones ejecutables listas para descargar se crearan al finalizar, así que si quieres probar el desarrollo actual debes **clonar y compilar tu mismo**

---

## El Universo de Chronos

Imagina un mundo al borde del colapso cósmico donde los científicos, en un último intento desesperado, activaron una gigantesca barrera temporal para salvarlo. El planeta sobrevivió, pero el tejido del tiempo se rompió en el proceso, dejando a su paso portales, grietas y anomalías físicas impredecibles.

---

## Contenido Neto de los Niveles

En esta aventura acompañamos a **Chronoa Obert**, desenciente directa los científicos quienes debido a la excepcional energía temporal concentrada, han propagado habilidades especiales a sus descendientes.

En la actualizad el viaje de Chronoa está proyectado para dividirse en dos entornos con enfoques de juego completamente diferentes:

* **Nivel 1 (Campos Temporales):** Un estilo de minigolf con perspectiva lateral fija, donde se controla la dirección y potencia de una pelota para interactuar con portales y anomalías. Cuenta además con un evento de supervivencia contrarreloj si el tejido temporal se sobrecarga. 
* **Nivel 2 (El Epicentro):** Una jugabilidad cenital tipo laberinto retro orientada a la exploración, donde el objetivo es evadir patrullas enemigas mientras se recolectan archivos históricos.

> [!NOTE]
> **Nota de Desarrollo:** Es importante aclarar que los niveles en sí mismos **aún no han sido construidos**. Actualmente el foco del desarrollo está concentrado en la creación de la lógica interna y la interfaz de `GameWidget`, la cual se encargará de gestionar dinámicamente los módulos de contexto correspondientes a cada nivel.

---

## Las Reglas del Mundo (Físicas)

Aunque este universo está lleno de fenómenos complejos (como rebotes perfectos, tiros parabólicos o el vaivén de péndulos interactivos), no te aburriré con ecuaciones aquí. Si tienes curiosidad por saber cómo se modelan matemáticamente y se renderizan estas anomalías en un espacio bidimensional, toda la información detallada se encuentra registrada en la **documentación interna del proyecto** incluida en este repositorio.

---

## Estructura del Proyecto

```text
// TODO: La estructura final de directorios (src, include, assets, etc.) 
// será añadida en esta sección una vez consolidada la refactorización final de lo proyectado para este juego.
```

## Colaboración y Experimentación

Este repositorio está abierto para la experimentación personal. Si deseas descargar el código, compilarlo por tu cuenta, trastear con las mecánicas actuales o intentar implementar algún nivel u ocurrencia propia, ten en cuenta que el proyecto se construye a través de **CMakeLists.txt** y requiere el siguiente entorno:

- **Lenguaje:** C++17 (o superior)    
- **Framework:** Qt 6.5


**CUALQUIER APORTE/FEATURE EN ESTA ETAPA SERA RECHAZADO**.

>[!CAUTION]
>Siempre puedes abrir un issue para dejar observaciones o sugerencias constructivas. Sin embargo, no está permitido apropiarse de este código ni usarlo comercialmente sin promover una compensación justificada a cada uno de los autores originales y mutuo acuerdo con los propietarios actuales del repositorio.