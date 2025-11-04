# Simulación de Partícula en Caja 1D con Pared Móvil e Inelasticidad

Este proyecto implementa una **simulación numérica de una partícula en una caja unidimensional** donde la pared derecha se mueve con velocidad constante y las colisiones pueden ser **inelásticas** según un coeficiente de restitución \(e\).

---

## Características

- Simulación del movimiento 1D de una partícula con colisiones inelásticas.
- Registro de **posición, velocidad y energía cinética** en función del tiempo.
- Generación de **gráficas** de:
  - Posición de la partícula y de la pared vs. tiempo
  - Energía cinética vs. tiempo
- Generación de **animación GIF** combinando posición y energía.
- Contador de colisiones para cuantificar la disipación de energía.

---

## Parámetros de entrada

- Posición inicial de la partícula \(x_0\)
- Velocidad inicial de la partícula \(v_0\)
- Velocidad de la pared derecha \(u\)
- Coeficiente de restitución \(e\) \((0 < e \le 1)\)
- Tiempo inicial \(t_0\) y final \(t_f\)
- Paso de tiempo \(\Delta t\)

---

## Uso

1. Compilar el proyecto:

```bash
make build
