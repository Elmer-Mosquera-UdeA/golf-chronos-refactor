# Sistema del Péndulo 2D en el Plano Vertical X-Y

## 1. Definición y Fórmulas del Sistema Propuesto

El sistema modela la cinemática y dinámica de un péndulo simple confinado estrictamente al plano vertical $X-Y$, utilizando una descripción vectorial y angular para su representación gráfica y física.

## A. Capa Kinemática (Geometría Vectorial 2D)

Para mapear el ángulo de oscilación a coordenadas de pantalla en dos dimensiones, el sistema aplica una transformación lineal afín (escala y traslación) sobre un vector de dirección unitario:

- Vector Dirección ($\vec{u}$): Define la orientación espacial del péndulo. Al referenciar el ángulo $\theta$ respecto a la vertical inferior ($0^\circ$ es totalmente hacia abajo), el vector unitario se estructura como:
	$$\vec{u}(\theta) = \begin{bmatrix} \sin(\theta) \\ -\cos(\theta) \end{bmatrix}$$
- Posición Final 2D ($\vec{Pos}_{2D}$): Escala el vector unitario por la longitud de la cuerda $L$ y traslada el origen al punto de suspensión espacial:  
    $$\vec{Pos}_{2D} = \vec{Anclaje} + L \cdot \vec{u}(\theta)$$  
    $$\begin{bmatrix} X_{pos} \\ Y_{pos} \end{bmatrix} = \begin{bmatrix} X_{anc} \\ Y_{anc} \end{bmatrix} + L \cdot \begin{bmatrix} \sin(\theta) \\ -\cos(\theta) \end{bmatrix}$$

## B. Capa Dinámica Linealizada (Solución Analítica)

Para calcular la evolución temporal del ángulo evitando integradores numéricos complejos, se utiliza la solución exacta del sistema linealizado (Oscilador Armónico Simple):

- Frecuencia Natural de Oscilación ($\omega$): Determinada por la aceleración de la gravedad ($g$) y la longitud de la cuerda ($L$):  
    $$\omega = \sqrt{\frac{g}{L}}$$
- Ecuación Temporal de Posición Angular ($\theta(t)$): Supone que el sistema se libera desde el reposo con una amplitud máxima $\theta_{\text{máx}}$:  
    $$\theta(t) = \theta_{\text{máx}} \cdot \cos(\omega \cdot t)$$
- Velocidad Angular en el Espacio de Fases ($\dot{\theta}(t)$): Derivada temporal de la posición angular:  
    $$\dot{\theta}(t) = -\theta_{\text{máx}} \cdot \omega \cdot \sin(\omega \cdot t)$$

---

## 2. Implicaciones del Modelo Lineal

- Isoocronismo del Péndulo: La implicación matemática más severa es que el periodo de oscilación ($T = 2\pi/\omega$) es independiente de la amplitud $\theta_{\text{máx}}$. El péndulo tardará exactamente el mismo tiempo en completar un ciclo si se suelta desde $2^\circ$ que si se suelta desde $90^\circ$.
- Geometría en el Espacio de Fases: Al graficar la posición angular $\theta(t)$ contra la velocidad angular $\dot{\theta}(t)$, las trayectorias dinámicas forman elipses perfectas y concéntricas. Esto implica que el flujo de energía del sistema se comporta como una forma cuadrática ideal donde la energía mecánica total se conserva de manera linealmente proporcional a la amplitud al cuadrado ($E \propto \theta_{\text{máx}}^2$).
- Eficiencia Computacional Absoluta: Al reducir la simulación a funciones trigonométricas directas ($\cos$ y $\sin$), el coste computacional en el ciclo de actualización (`update loop`) pasa de ser $O(N)$ por pasos numéricos a ser $O(1)$ de acceso directo indexado por tiempo.

---

## 3. Problemas Encontrados y Limitaciones Físicas

La transformación directa de una ecuación diferencial física a una solución algebraica linealizada introduce discrepancias geométricas y cinemáticas críticas cuando el sistema opera fuera de condiciones ideales:

## Problema A: El Error del Péndulo Uniforme ($\theta = \omega \cdot t$)

- Descripción: Intentar modelar la dinámica mediante una variación lineal directa respecto al tiempo asume que la aceleración angular es nula ($\ddot{\theta} = 0$).
- Consecuencia: El vector de posición $\vec{Pos}_{2D}$ experimenta una velocidad de barrido angular idéntica en cualquier punto de la trayectoria. Físicamente, el péndulo deja de oscilar (vaivén) y se convierte en un motor rotatorio de $360^\circ$, violando la Ley de Conservación de la Energía bajo campos gravitatorios.

## Problema B: El Desfase por Gran Amplitud (Pérdida de Precisión Real)

- Descripción: La ecuación diferencial real del péndulo es estrictamente no lineal debido a la componente tangencial de la gravedad:  
    $$\ddot{\theta} + \omega^2\sin(\theta) = 0$$  
    La aproximación lineal reemplaza $\sin(\theta) \approx \theta$ basándose en las series de Taylor.
- Consecuencia: A amplitudes elevadas (ej. $\theta_{\text{máx}} = 90^\circ$), el término lineal $\theta$ sobreestima drásticamente la fuerza de restitución real ($\sin(90^\circ) = 1$, mientras que $\theta = 1.57$ radianes, un error del $57\%$). Visualmente, el péndulo simulado por coseno viaja mucho más rápido y se desfasa del comportamiento físico de un péndulo real, el cual debería ralentizarse fuertemente en los extremos.

---

## 4. Soluciones Planteadas para la Transformación

Para transicionar de la compleja ecuación diferencial original a un sistema lineal eficiente sin comprometer drásticamente la fidelidad visual, se establecen las siguientes soluciones técnicas:

## Solución 1: Restricción Operacional de Ángulos Pequeños

- Criterio: Acotar por software o diseño que la amplitud inicial cumpla con el criterio $\theta_{\text{máx}} \le 15^\circ$ ($0.26$ rad).
- Resultado: En este rango operativo, el error matemático de la linealización es menor al $1\%$. Las trayectorias elípticas en el espacio de fases y el arco visualizado en la pantalla $X-Y$ son matemáticamente indistinguibles de una integración física real no lineal.

## Solución 2: Inyección de la Corrección Analítica del Periodo (Fórmula de Borda)

- Criterio: Para permitir amplitudes grandes (como los $90^\circ$ propuestos) utilizando la estructura lineal del coseno sin sufrir el error de desfase temporal, se recalcula la frecuencia natural agregando un factor de corrección de orden superior:  
    $$\omega_{\text{corregida}} = \sqrt{\frac{g}{L}} \cdot \left( 1 + \frac{1}{16}\theta_{\text{máx}}^2 \right)^{-1}$$
- Resultado: Se conserva la simplicidad algebraica de la fórmula $\theta(t) = \theta_{\text{máx}} \cos(\omega_{\text{corregida}} \cdot t)$ eliminando la necesidad de ecuaciones diferenciales en tiempo real, pero el péndulo ahora oscilará al ritmo temporal exacto y ralentizado del sistema real no lineal.

## Solución 3: Separación Funcional del Motor de Software

- Criterio: Dividir la arquitectura del programa en dos módulos independientes acoplados unidireccionalmente:
    
    1. _Módulo Dinámico:_ Ejecuta la aproximación lineal en el espacio de fases para determinar el escalar $\theta$.
    2. _Módulo de Renderizado:_ Recibe $\theta$ y ejecuta las matrices de transformación vectorial afín sobre la pantalla $2D$.
    
---

>[!NOTE]
>La solucion que usaremos es: Solución 2: Inyección de la Corrección Analítica del Periodo (Fórmula de Borda).

_Justificacion: No introduce ningún bucle, integración numérica ni dependencia de N. Por tanto, la complejidad del bucle de actualización permanece O(1), sin penalización alguna por la corrección de grandes amplitudes._

> ==Simulador en desarrollo==