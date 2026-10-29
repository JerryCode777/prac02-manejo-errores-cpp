# Casos de prueba

Cada integrante ejecuta los casos de su parte y verifica que su salida coincida con el **resultado esperado**.

| ID | Parte | Entrada | Resultado esperado | Resultado |
|----|-------|---------|--------------------|-----------|
| P1-01 | Práctica 1 | 10 y 2 | `Resultado: 5` + `Operación finalizada.` | |
| P1-02 | Práctica 1 | 10 y 0 | Mensaje de división por cero + `Operación finalizada.` | |
| P1-03 | Práctica 1 *(extra)* | `abc` | `Debe ingresar un número válido.` | |
| S-01 | Entrada | Registrar con código `123` | E02 | |
| S-02 | Entrada | Edad `veinte` | E04 | |
| S-03 | Entrada | Edad `150` | E05 | |
| S-04 | Entrada | Nota `25` | E06 | |
| S-05 | Archivo | `registro_alumnos data/no_existe.csv` | E08, inicia vacío | |
| S-06 | Archivo | `registro_alumnos data/alumnos_corrupto.csv` | E09 con número de línea | |
| S-07 | Archivo | Opción 5 y luego 6 | Guarda y vuelve a cargar los datos | |
| S-08 | Registro | Buscar `99999999` | E11 | Prueba aislada aprobada: `buscar` lanza `AlumnoNoEncontradoException`. Pendiente de comprobar desde el menú. |
| S-09 | Registro | Registrar `20231001` (ya existe) | E12 | Prueba aislada aprobada: `agregar` lanza `AlumnoDuplicadoException` y no añade el duplicado. Pendiente de comprobar desde el menú. |
| S-10 | Integración | Opción `9` | E01 | |
| S-11 | Integración | Flujo completo correcto | Registrar, listar, buscar, eliminar sin errores | |

## Verificación de la parte de Gabriel

Se probaron directamente las funciones de `registro.cpp` y las excepciones de
`excepciones.cpp`, sin depender de la entrada de datos ni de la carga de archivos.
Las siguientes comprobaciones pasaron:

- Agregar un alumno y recuperarlo por su código.
- Rechazar un código duplicado sin modificar la cantidad de alumnos.
- Lanzar `AlumnoNoEncontradoException` al buscar o eliminar un código inexistente.
- Conservar los alumnos cuando falla una eliminación.
- Eliminar un alumno existente y comprobar que ya no se puede encontrar.
- Verificar los mensajes de las seis clases de excepciones y los valores devueltos
  por `campo()` y `linea()`.

El proyecto compiló con `make` sin errores ni advertencias. Estas comprobaciones
son pruebas aisladas de los módulos de Gabriel; la validación desde el menú y el
flujo integrado S-11 quedan pendientes de completar las partes de los demás módulos.
