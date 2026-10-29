# Catálogo de errores del sistema

Errores que puede generar el *Sistema de registro de alumnos* y cómo se manejan. En todos los casos **el sistema continúa funcionando**.

| Cód. | Situación | Dónde se detecta | Excepción | Manejo | Mensaje al usuario |
|------|-----------|------------------|-----------|--------|--------------------|
| E01 | Opción de menú inexistente | `main.cpp` | *(ninguna: validación con `if`)* | Se vuelve a mostrar el menú | `Opción no válida. Elija un número del 0 al 6.` |
| E02 | Código sin 8 dígitos | `validarCodigo` | `EntradaInvalidaException` | Se cancela la operación | `Dato inválido -> código: ...` |
| E03 | Nombre vacío o con caracteres no permitidos | `validarNombre` | `EntradaInvalidaException` | Se cancela la operación | `Dato inválido -> nombre: ...` |
| E04 | Edad no numérica (`"veinte"`, `"12abc"`) | `convertirEntero` (`std::invalid_argument`) | `EntradaInvalidaException` | Se cancela la operación | `Dato inválido -> edad: ...` |
| E05 | Edad fuera de rango (15–99) o número demasiado grande | `convertirEntero` (`std::out_of_range`) | `EntradaInvalidaException` | Se cancela la operación | `Dato inválido -> edad: ...` |
| E06 | Nota no numérica o fuera de 0–20 | `convertirNota` | `EntradaInvalidaException` | Se cancela la operación | `Dato inválido -> nota: ...` |
| E07 | Fin de la entrada (Ctrl+D / Ctrl+Z) al pedir un dato | `leerLinea` | `EntradaInvalidaException` | Se cancela la operación | `Dato inválido -> ...` |
| E08 | Archivo de datos inexistente | `cargarAlumnos` | `ArchivoNoEncontradoException` | Al iniciar: registro vacío. En menú: aviso | `No se encontró el archivo ...` |
| E09 | Línea del archivo con campos faltantes o datos inválidos | `cargarAlumnos` | `ArchivoCorruptoException` | Registro vacío + se escribe en `errores.log` | `El archivo ... está dañado en la línea N: ...` |
| E10 | No se puede escribir el archivo | `guardarAlumnos` | `RegistroException` | Aviso + `errores.log` | `No se pudo escribir ...` |
| E11 | Buscar o eliminar un código inexistente | `RegistroAlumnos::buscar/eliminar` | `AlumnoNoEncontradoException` | Aviso | `No existe un alumno con el código ...` |
| E12 | Registrar un código que ya existe | `RegistroAlumnos::agregar` | `AlumnoDuplicadoException` | Aviso | `Ya existe un alumno con el código ...` |
| E13 | Cualquier otro error no previsto | Cualquier módulo | `std::exception` | Mensaje genérico + `errores.log` | `Error inesperado: ...` |

## Práctica 1 · División segura

| Situación | Excepción | Manejo |
|-----------|-----------|--------|
| Divisor igual a 0 | `std::domain_error` (lanzada con `throw`) | Mensaje `Error: no se puede dividir entre cero.` |
| Dato no numérico *(extra)* | `std::invalid_argument` o validación de `std::cin.fail()` | Mensaje `Debe ingresar un número válido.` |
| Siempre | — | El destructor de `MensajeCierre` (RAII) muestra `Operación finalizada.` |
