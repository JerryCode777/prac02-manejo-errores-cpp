# Casos de prueba

Cada integrante ejecuta los casos de su parte, completa la columna **Resultado** y guarda la captura en `docs/capturas/`.

| ID | Parte | Entrada | Resultado esperado | Resultado | Captura |
|----|-------|---------|--------------------|-----------|---------|
| P1-01 | Práctica 1 | 10 y 2 | `Resultado: 5` + `Operación finalizada.` | | `practica1-correcto.png` |
| P1-02 | Práctica 1 | 10 y 0 | Mensaje de división por cero + `Operación finalizada.` | | `practica1-division-cero.png` |
| P1-03 | Práctica 1 *(extra)* | `abc` | `Debe ingresar un número válido.` | | `practica1-no-numero.png` |
| S-01 | Entrada | Registrar con código `123` | E02 | | `entrada-codigo.png` |
| S-02 | Entrada | Edad `veinte` | E04 | | `entrada-edad-texto.png` |
| S-03 | Entrada | Edad `150` | E05 | | `entrada-edad-rango.png` |
| S-04 | Entrada | Nota `25` | E06 | | `entrada-nota.png` |
| S-05 | Archivo | `registro_alumnos data/no_existe.csv` | E08, inicia vacío | | `archivo-no-encontrado.png` |
| S-06 | Archivo | `registro_alumnos data/alumnos_corrupto.csv` | E09 con número de línea | | `archivo-corrupto.png` |
| S-07 | Archivo | Opción 5 y luego 6 | Guarda y vuelve a cargar los datos | | `archivo-guardar-cargar.png` |
| S-08 | Registro | Buscar `99999999` | E11 | | `registro-no-encontrado.png` |
| S-09 | Registro | Registrar `20231001` (ya existe) | E12 | | `registro-duplicado.png` |
| S-10 | Integración | Opción `9` | E01 | | `menu-opcion-invalida.png` |
| S-11 | Integración | Flujo completo correcto | Registrar, listar, buscar, eliminar sin errores | | `integracion-flujo.png` |
