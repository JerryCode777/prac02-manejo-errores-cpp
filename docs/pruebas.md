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
| S-08 | Registro | Buscar `99999999` | E11 | |
| S-09 | Registro | Registrar `20231001` (ya existe) | E12 | |
| S-10 | Integración | Opción `9` | E01 | |
| S-11 | Integración | Flujo completo correcto | Registrar, listar, buscar, eliminar sin errores | |
