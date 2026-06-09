# push_swap

Proyecto de la escuela 42 que implementa un algoritmo de ordenación usando dos pilas y un conjunto limitado de operaciones. El objetivo es ordenar una lista de enteros con el mínimo número de movimientos posible.

---

## Descripción

El programa recibe una lista de enteros como argumentos y genera la secuencia mínima de instrucciones necesaria para ordenarlos en la pila `a` de forma ascendente, usando una pila auxiliar `b`.

---

## Operaciones disponibles

| Instrucción | Descripción |
|-------------|-------------|
| `sa` | Intercambia los dos primeros elementos de la pila `a` |
| `sb` | Intercambia los dos primeros elementos de la pila `b` |
| `pa` | Mueve el primer elemento de `b` al tope de `a` |
| `pb` | Mueve el primer elemento de `a` al tope de `b` |
| `ra` | Rota `a` hacia arriba (el primero pasa al final) |
| `rb` | Rota `b` hacia arriba |
| `rr` | `ra` y `rb` simultáneamente |
| `rra` | Rota `a` hacia abajo (el último pasa al principio) |
| `rrb` | Rota `b` hacia abajo |
| `rrr` | `rra` y `rrb` simultáneamente |

---

## Algoritmo

El programa usa estrategias distintas según el tamaño de la entrada:

- **2 elementos** → un simple `sa` si hace falta.
- **3 elementos** → lógica directa con máximo 2 operaciones.
- **4-5 elementos** → se llevan los menores a `b`, se ordena el trío restante con `sort_three`, y se reintegran.
- **≥6 elementos** → algoritmo de coste mínimo (Turkish algorithm):
  1. Se mueven todos los elementos menos 3 a la pila `b`.
  2. Se ordena el trío restante en `a`.
  3. Para cada elemento en `b`, se calcula el coste de llevarlo a su posición correcta en `a` (combinando rotaciones simultáneas cuando es posible).
  4. Se elige siempre el elemento con menor coste total y se inserta.
  5. Al final, se rota `a` para que el mínimo quede en el tope.

---

## Estructura del proyecto

```
push_swap/
├── include/
│   └── push_swap.h       # Definiciones y prototipos
├── lib/
│   ├── libft.h
│   ├── Makefile
│   └── *.c               # Librería libft propia
├── src/
│   ├── main.c            # Punto de entrada
│   ├── algorithm.c       # Lógica de ordenación
│   ├── movements.c       # sa, sb, pa, pb, ra, rb, rra, rrb
│   ├── movements_2.c     # rr, rrr y helpers de movimiento
│   ├── setters.c         # Cálculo de índices, targets y costes
│   ├── getter.c          # Parseo de argumentos y búsqueda de valores
│   ├── checkers.c        # Validación (duplicados, orden, args)
│   ├── utils.c           # fill_stack, free_stack, move_to_top...
│   └── utils_2.c         # stacklen, execute_moves, ft_atol...
├── number_gen.py         # Script auxiliar para generar tests
└── Makefile
```

---

## Compilación

```bash
make        # Compila el ejecutable push_swap
make clean  # Elimina los objetos
make fclean # Elimina objetos y el ejecutable
make re     # Recompila desde cero
```

---

## Uso

```bash
# Con argumentos individuales
./push_swap 4 2 7 1 5

# Con una cadena de números
./push_swap "4 2 7 1 5"

# Ver el número de operaciones generadas
./push_swap 4 2 7 1 5 | wc -l
```

### Generar números de prueba

```bash
# Usando el script incluido
python3 number_gen.py

# Pasarlos directamente al programa
./push_swap $(python3 number_gen.py)
```

### Casos de error

El programa escribe `Error` en stdout y termina en los siguientes casos:

- Argumentos no numéricos
- Números fuera del rango de `int` (< -2147483648 o > 2147483647)
- Números duplicados
- Argumento vacío

---

## Rendimiento esperado

| Elementos | Operaciones máximas (nota máxima) |
|-----------|----------------------------------|
| 3         | ≤ 3 |
| 5         | ≤ 12 |
| 100       | ≤ 700 |
| 500       | ≤ 5500 |

---

## Autor

**tfiz-ben** — estudiante de 42
