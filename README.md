# Algoritmos y Estructuras de Datos II - Ingenieria en Informatica

## Trabajo Final Integrador

### Escenario

La empresa **"SistemaSeguro S.A."** se dedica a la instalación de sistemas de seguridad. Para gestionar las opciones de instalación y los trabajos asociados, se requiere desarrollar un sistema utilizando estructuras de datos dinámicas.

La empresa ofrece a sus clientes una gama de opciones de sistemas de seguridad. Cada opción tiene:
- **Nombre de fantasía.**
- **Tiempo estimado de instalación.**
- **Conjunto de materiales necesarios para su instalación.**

El sistema debe manejar información relacionada con:
- **Costo de la mano de obra**, dependiendo de la ubicación de la instalación y si requiere trabajos en altura (más de 4 metros).
- **Tareas específicas por opción**, organizadas en un orden secuencial y con una duración estimada en horas.
- **Materiales necesarios**, que incluyen código, denominación, unidad, costo y stock actual.

---

### Funcionalidades del sistema

1. **Listar las opciones**  
   Mostrar una lista de todas las opciones disponibles, incluyendo:
   - Nombre.
   - Tiempo de instalación estimado.
   - Costo total (mano de obra y materiales).

2. **Dar de alta opciones**  
   - Ingresar los datos de la opción: nombre, tiempo de instalación estimado, materiales necesarios (código, cantidad, unidad, costo unitario).  
   - Calcular el costo total de la opción: sumar el costo de los materiales y el costo de la mano de obra.  
   - Calcular el tiempo de ejecución total de la opción: sumar la duración de cada tarea.

3. **Dar de alta trabajos**  
   - Seleccionar una opción de la lista existente.  
   - Ingresar la ubicación de la instalación: dirección y si requiere trabajos en altura.  
   - Asignar un técnico disponible.  
   - Generar una orden de trabajo con los datos de la opción, ubicación, técnico asignado y costo total.

4. **Ejecutar trabajos**  
   - Seleccionar una orden de trabajo pendiente.  
   - Marcar tareas como completadas.  
   - Registrar las horas trabajadas por el técnico.  
   - Finalizar el trabajo, actualizando el inventario de materiales y marcando la orden como finalizada.

---

### Estructuras de datos dinámicas utilizadas

- **Pila:** Para manejar las tareas pendientes de una orden de trabajo, en el orden en que deben completarse.  
- **Cola:** Para gestionar las órdenes de trabajo pendientes, en el orden de creación.  
- **Lista enlazada simple:** Para almacenar las opciones disponibles.  
- **Lista enlazada doble:** Para gestionar las tareas de cada opción, permitiendo acceso en ambos sentidos.  
- **Árbol de búsqueda binaria:** Para almacenar y buscar materiales de forma eficiente, utilizando el código como clave.

---

### Consideraciones adicionales

- Consulta y actualización de los datos de materiales, incluyendo:
  - Código.
  - Denominación.
  - Costo.
  - Stock actual.
- Generar informes que incluyan:
  - Cantidad de trabajos realizados.
  - Materiales utilizados.
  - Costos asociados.

---

### Consignas

- Crear las estructuras de datos y los algoritmos/códigos necesarios para almacenar los datos requeridos y representar el escenario.

---

### Presentación

- Este trabajo fue realizado por **4 integrantes** y desarrollado para la carrera de **Ingeniería en Informática** de la **Universidad Gastón Dachary**.  
